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
    public partial class EventConfigControl : UserControl
    {        
        public EventConfigControl(EventConfigItem eventConfigItem)
        {
            InitializeComponent();
            this.lblName.Text = eventConfigItem.DisplayName;            
            this.toolTip.SetToolTip(this, eventConfigItem.DisplayName);
            this.chkMail.Checked = eventConfigItem.Mail;
            this.chkSave.Checked = eventConfigItem.Save;
            this.chkSyslog.Checked = eventConfigItem.Syslog;
        }

    }
}
