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


namespace ION
{
    namespace Konzolo
    {
        public partial class ConfigControl : UserControl
        {
            private IonProperties properties;
            public ConfigControl()
            {
                InitializeComponent();
                this.properties = new IonProperties();
                EventsControl ec = new EventsControl(properties);
                ec.Dock = DockStyle.Fill;
                groupBoxEvents.Controls.Add(ec);
                LogTailControl ltc = new LogTailControl(AppDomain.CurrentDomain.BaseDirectory, "ion.log");
                ltc.Dock = DockStyle.Fill;
                groupBoxLogger.Controls.Add(ltc);

                this.txtEvents.Text = this.properties.Get("ion.eventsage");
                this.txtOffline.Text = this.properties.Get("ion.offline-interval");
                this.cmbLogLevel.Text = this.properties.Get("logging.loggers.root.level");

            }

            private void btnApply_Click(object sender, EventArgs e)
            {
                this.properties.Set("ion.eventsage", this.txtEvents.Text);
                this.properties.Set("ion.offline-interval", this.txtOffline.Text);
                this.properties.Set("logging.loggers.root.level", this.cmbLogLevel.Text);
                this.properties.Save();
            }

        }
    }
}