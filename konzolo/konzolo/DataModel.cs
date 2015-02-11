﻿using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SQLite;
using System.Windows.Forms;

namespace ION
{
    namespace Konzolo
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
                String sql = "SELECT ip.mac, ip, datetime(last_seen,'unixepoch','localtime') as last_seen, " +
                "thing.type, thing.name, thing.vendor, " +
                "thing.os, desc, oui.vendor as hw_vendor , case when  authorized.mac is null then 'no' else 'yes' end as auth " +
                "    FROM ip LEFT JOIN thing ON ip.mac=thing.mac " +
                "    LEFT JOIN oui ON substr(ip.mac,0,9)=oui.prefix " +
                "LEFT JOIN authorized on ip.mac=authorized.mac " +
                "ORDER BY ip.mac";
                SQLiteDataAdapter adapter = new SQLiteDataAdapter(sql, this.connection);
                adapter.Fill(table);
            }

            internal void GetEvents(DataTable table, string mac)
            {
                String sql = "SELECT datetime(time,'unixepoch','localtime') as time,name,ip,details FROM event WHERE mac = '" + mac + "' ORDER BY time";
                SQLiteDataAdapter adapter = new SQLiteDataAdapter(sql, this.connection);
                adapter.Fill(table);
                foreach (DataRow row in table.Rows)
                {
                    row["name"] = Strings.ResourceManager.GetString(row["name"].ToString());
                }
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
                if (rows == 0)
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

            internal void GetAuthorized(DataTable table)
            {
                String sql = "SELECT mac FROM authorized";
                SQLiteDataAdapter adapter = new SQLiteDataAdapter(sql, this.connection);
                adapter.Fill(table);
            }

            internal void AuthorizeMAC(string mac)
            {
                SQLiteCommand command = this.connection.CreateCommand();
                command.CommandText = "INSERT INTO authorized (mac) VALUES (?)";
                command.Parameters.Add(new SQLiteParameter(DbType.String, (object)mac));
                command.ExecuteNonQuery();
            }

            internal void UnAuthorizeMAC(string mac)
            {
                SQLiteCommand command = this.connection.CreateCommand();
                command.CommandText = "DELETE FROM authorized WHERE mac=?";
                command.Parameters.Add(new SQLiteParameter(DbType.String, (object)mac));
                command.ExecuteNonQuery();
            }
        }
    }
}