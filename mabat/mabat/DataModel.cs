using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SQLite;
using System.Windows.Forms;

namespace mabat
{
    public class DataModel
    {
        private static DataModel instance = new DataModel();
        private SQLiteConnection connection = null;
        
        private DataModel()
        {
            string dbFile = System.IO.Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "ion.db");
            this.connection = new SQLiteConnection("Data Source=" + dbFile);
            this.connection.Open();

        }

        internal static DataModel Instance
        {
            get
            {
                return instance;
            }
        }

        public void GetThings(DataTable table)
        {
            String sql = "SELECT ip.mac, ip, last_seen, thing.type, thing.name, thing.vendor, " +
            "thing.os, desc, oui.vendor as hw_vendor " +
                "FROM ip LEFT JOIN thing ON ip.mac=thing.mac " +
                "LEFT JOIN oui ON substr(ip.mac,0,9)=oui.prefix " +
                "ORDER BY ip.mac";
            SQLiteDataAdapter adapter = new SQLiteDataAdapter(sql, this.connection);
            adapter.Fill(table);
        }

        internal void GetEvents(DataTable table, string mac)
        {
            String sql = "SELECT * FROM event WHERE mac = '" + mac + "'";
            SQLiteDataAdapter adapter = new SQLiteDataAdapter(sql, this.connection);
            adapter.Fill(table);
        }

        internal void UpdateThing(string mac, string type, string vendor, string os, string desc)
        {
            //TABLE thing (mac TEXT NOT NULL,type TEXT, name TEXT, vendor TEXT, os TEXT, desc TEXT)", now;
            SQLiteCommand command = this.connection.CreateCommand();
            command.CommandText = "UPDATE thing SET type=?, vendor=?, os=?, desc=? WHERE mac=?";
            command.Parameters.Add(new SQLiteParameter(DbType.String, (object)type));            
            command.Parameters.Add(new SQLiteParameter(DbType.String, (object)vendor));
            command.Parameters.Add(new SQLiteParameter(DbType.String, (object)os));
            command.Parameters.Add(new SQLiteParameter(DbType.String, (object)desc));
            command.Parameters.Add(new SQLiteParameter(DbType.String, (object)mac));
            int rows = command.ExecuteNonQuery();
            if (rows == 0 )
            {
                command = this.connection.CreateCommand();
                command.CommandText = "INSERT INTO thing (mac,type,vendor,os,desc) VALUES (?,?,?,?,?)";
                command.Parameters.Add(new SQLiteParameter(DbType.String, (object)mac));
                command.Parameters.Add(new SQLiteParameter(DbType.String, (object)type));
                command.Parameters.Add(new SQLiteParameter(DbType.String, (object)vendor));
                command.Parameters.Add(new SQLiteParameter(DbType.String, (object)os));
                command.Parameters.Add(new SQLiteParameter(DbType.String, (object)desc));                
                command.ExecuteNonQuery();
            }
        }

        internal void DeleteThing(string mac)
        {
            SQLiteCommand command = this.connection.CreateCommand();
            command.CommandText = "DELETE FROM thing WHERE mac=?";            
            command.Parameters.Add(new SQLiteParameter(DbType.String, (object)mac));
            command.ExecuteNonQuery();
            command = this.connection.CreateCommand();
            command.CommandText = "DELETE FROM ip WHERE mac=?";
            command.Parameters.Add(new SQLiteParameter(DbType.String, (object)mac));
            command.ExecuteNonQuery();            
        }
    }
}
