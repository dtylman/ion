using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace mabat
{
    public partial class EventsControl : UserControl
    {
        private IonProperties properties;        

        public EventsControl(IonProperties properties)
        {
            InitializeComponent();
            this.properties = properties;
            AddEventsConfigControl("ip_online");
            AddEventsConfigControl("ip_offline");
            AddEventsConfigControl("not_authorized");
            AddEventsConfigControl("thing_online");
            AddEventsConfigControl("thing_offline");
        }

        private void AddEventsConfigControl(String name)
        {
            EventConfigControl eventConfigControl = new EventConfigControl(name, properties);
            eventConfigControl.Dock = DockStyle.Top;
            this.Controls.Add(eventConfigControl);
        }

        private void btnApply_Click(object sender, EventArgs e)
        {
            try
            {
                foreach (Control control in Controls)
                {
                    EventConfigControl ecc = control as EventConfigControl;
                    if (ecc != null)
                    {
                        ecc.apply();
                    }
                }
                properties.Save();
                MessageBox.Show(this, "Configuration Saved","Information",MessageBoxButtons.OK,MessageBoxIcon.Information);
            }
            catch (Exception ex)
            {
                MessageBox.Show(this, ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
