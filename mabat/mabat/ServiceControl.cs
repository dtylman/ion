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
            IonProperties properties = new IonProperties();
            AddEventsConfigControl(new EventConfigItem("ip_online", properties));
            AddEventsConfigControl(new EventConfigItem("not_authorized", properties));
            AddEventsConfigControl(new EventConfigItem("thing_online", properties));
            AddEventsConfigControl(new EventConfigItem("thing_offline", properties));

            LogTailControl ltc = new LogTailControl(AppDomain.CurrentDomain.BaseDirectory, "ion.log");
            ltc.Dock = DockStyle.Fill;
            groupBoxLogger.Controls.Add(ltc);
        }

        private void AddEventsConfigControl(EventConfigItem eventConfigItem)
        {
            EventConfigControl eventConfigControl = new EventConfigControl(eventConfigItem);
            eventConfigControl.Dock = DockStyle.Top;
            this.groupBoxEvents.Controls.Add(eventConfigControl);
        }

        private void btnApply_Click(object sender, EventArgs e)
        {

        }

        
    }
}
