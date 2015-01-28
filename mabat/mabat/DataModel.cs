using System;
using System.Data;
using System.Data.SQLite;

namespace mabat
{
    public class DataModel
    {
        private static DataModel instance = new DataModel();
        private SQLiteConnection connection = null;

        private DataModel()
        {
            this.connection = new SQLiteConnection("Data Source=C:\\Users\\danny\\src\\snuffler\\snuffapp\\zakif.db");
            this.connection.Open();
            createTables();
        }

        private void createTables()
        {            
            if (!tableExists("host_desc"))
            {
                SQLiteCommand command = this.connection.CreateCommand();
                command.CommandText = "CREATE TABLE host_desc (mac TEXT NOT NULL, type TEXT NOT NULL, vendor TEXT, os TEXT, desc TEXT)";
                command.ExecuteNonQuery();
                command = this.connection.CreateCommand();
                command.CommandText = "CREATE UNIQUE INDEX pk_host_desc ON host_desc (mac ASC)";
                command.ExecuteNonQuery();
            }
        }

        private bool tableExists(string tableName)
        {
            SQLiteCommand command = this.connection.CreateCommand();
            command.CommandText = String.Format("SELECT 1 FROM sqlite_master WHERE type='table' AND name='{0}'", tableName);
            return (command.ExecuteScalar() != null);
        }

        internal static DataModel Instance()
        {
            return instance;
        }

        public void GetDevices(DataTable table)
        {
            String sql = "SELECT ip.mac,ip.ip, ip.last_seen,host.hostname, host.os, host_desc.type, " +
            "host_desc.vendor, host_desc.os, host_desc.desc FROM ip LEFT JOIN host ON ip.mac=host.mac " +
            "LEFT JOIN host_desc ON ip.mac=host_desc.mac";
            SQLiteDataAdapter adapter = new SQLiteDataAdapter(sql, this.connection);
            adapter.Fill(table);
        }
    }
}
