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
            string dbFile = System.IO.Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "ion.db");
            this.connection = new SQLiteConnection("Data Source=" + dbFile);
            this.connection.Open();
            createBindingSources();
        }

        private void createBindingSources()
        {
            this.deviceTypesBindingSource = new DeviceTypeBindingSource();
            this.deviceVendorBindingSource = new DeviceVendorBindingSource();
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
            String sql = "SELECT ip.mac, ip, last_seen, thing.type, thing.name, thing.vendor, " +
            "thing.os, desc, oui.vendor as hw_vendor " +
                "FROM ip LEFT JOIN thing ON ip.mac=thing.mac " +
                "LEFT JOIN oui ON substr(ip.mac,0,9)=oui.prefix";
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
