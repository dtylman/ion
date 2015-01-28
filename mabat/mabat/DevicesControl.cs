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
    public partial class DevicesControl : UserControl
    {
        public DevicesControl()
        {
            InitializeComponent();
            DataTable table = new DataTable();
            DataModel.Instance().GetDevices(table);
            this.gridViewDevices.DataSource = table;
        }
    }
}
