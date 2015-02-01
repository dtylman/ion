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
            loadDevices();

        }

        private void loadDevices()
        {
            DataTable table = new DataTable();
            DataModel.Instance.GetDevices(table);            
            this.gridViewDevices.DataSource = table;
        }

        

        private void gridViewDevices_CellDoubleClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex==-1)
            {
                return;
            }
            EditDeviceDialog dialog = new EditDeviceDialog();
            DataGridViewRow row = this.gridViewDevices.Rows[e.RowIndex];
            dialog.setFromRow(row, this.gridViewDevices.Columns);
            dialog.ShowDialog(this);
        }
    }
}
