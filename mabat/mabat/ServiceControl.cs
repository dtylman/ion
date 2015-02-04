using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;


namespace mabat
{
    public partial class ServiceControl : UserControl
    {
        public ServiceControl()
        {
            InitializeComponent();
            LogTailControl ltc = new LogTailControl(AppDomain.CurrentDomain.BaseDirectory, "ion.log");
            ltc.Dock = DockStyle.Fill;
            groupBoxLogger.Controls.Add(ltc);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string configFile = Path.Combine(AppDomain.CurrentDomain.BaseDirectory,"config","ion.config.json");
            StreamReader reader = new StreamReader(configFile);            
            JsonSerializer serializer = new JsonSerializer();
            JObject json =(JObject)serializer.Deserialize(reader, typeof(JObject));
            json["logging"]["loggers"]["root"]["level"] = "debug";
            reader.Close();

            StreamWriter writer = new StreamWriter(configFile);
            serializer.Serialize(writer, json);
            //MyAccount.EmployeeID = (string)o["employeeid"][0];

            
            
        }
    }
}
