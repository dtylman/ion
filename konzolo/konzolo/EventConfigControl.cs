using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ION
{
    namespace Konzolo
    {
        public partial class EventConfigControl : UserControl
        {
            private IonProperties properties;
            private string name;

            public EventConfigControl(String name, IonProperties properties)
            {
                InitializeComponent();
                this.properties = properties;
                this.name = name;
                this.lblName.Text = Strings.ResourceManager.GetString(name);
                this.toolTip.SetToolTip(this, Strings.ResourceManager.GetString(name + "_desc"));
                this.chkMail.Checked = Boolean.Parse(properties.Get(String.Format("ion.events.{0}.mail", name)));
                this.chkSave.Checked = Boolean.Parse(properties.Get(String.Format("ion.events.{0}.save", name)));
                this.chkSyslog.Checked = Boolean.Parse(properties.Get(String.Format("ion.events.{0}.syslog", name)));
            }


            internal void apply()
            {
                properties.Set(String.Format("ion.events.{0}.mail", name), this.chkMail.Checked);
                properties.Set(String.Format("ion.events.{0}.save", name), this.chkSave.Checked);
                properties.Set(String.Format("ion.events.{0}.syslog", name), this.chkSyslog.Checked);
            }
        }
    }
}