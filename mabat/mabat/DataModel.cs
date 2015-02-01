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
        private DeviceTypeBindingSource deviceTypesBindingSource = null;
        private DeviceVendorBindingSource deviceVendorBindingSource = null;

        private DataModel()
        {
            this.connection = new SQLiteConnection("Data Source=C:\\Users\\danny\\src\\snuffler\\snuffapp\\zakif.db");
            this.connection.Open();
            createTables();
            createBindingSources();
        }

        private void createBindingSources()
        {
            this.deviceTypesBindingSource = new DeviceTypeBindingSource();
            this.deviceVendorBindingSource = new DeviceVendorBindingSource();
        }


        private void createTables()
        {
            createHostDescTable();
            createMACVendorTable();
        }

        private void createMACVendorTable()
        {
            if (!tableExists("mac_vendor"))
            {
                SQLiteCommand command = this.connection.CreateCommand();
                command.CommandText = "CREATE TABLE mac_vendor (prefix TEXT NOT NULL, vendor TEXT NOT NULL)";
                command.ExecuteNonQuery();
                command = this.connection.CreateCommand();
                command.CommandText = "CREATE UNIQUE INDEX pk_mac_vendor ON mac_vendor (prefix ASC)";
                command.ExecuteNonQuery();
            }
        }

        private void createHostDescTable()
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

        internal static DataModel Instance
        {
            get
            {
                return instance;
            }
        }

        public void GetDevices(DataTable table)
        {
            String sql = "SELECT host_desc.type as type, "+
            "host_desc.vendor, host_desc.os as os, "+
            "host.hostname, host.os as host_os, ip.last_seen, " +
            "ip.mac ,ip.ip , host_desc.desc " +
            "FROM ip LEFT JOIN host ON ip.mac=host.mac " +
            "LEFT JOIN host_desc ON ip.mac=host_desc.mac";
            SQLiteDataAdapter adapter = new SQLiteDataAdapter(sql, this.connection);            
            adapter.Fill(table);
        }



        public DeviceTypeBindingSource DeviceTypeDataSource
        { 
            get
            {
                return this.deviceTypesBindingSource;
            }
        }


        public DeviceVendorBindingSource DeviceVendorDataSource
        {
            get
            {
                return this.deviceVendorBindingSource;
            }
        }
            
    }
}
