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
    public partial class ServiceControl : UserControl
    {
        public ServiceControl()
        {
            InitializeComponent();
            LogTailControl ltc = new LogTailControl(AppDomain.CurrentDomain.BaseDirectory, "ion.log");
            ltc.Dock = DockStyle.Fill;
            groupBoxLogger.Controls.Add(ltc);
        }
    }
}
