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
            DataModel.Instance().GetDevices(table);
            this.gridViewDevices.AutoGenerateColumns = false;
            this.gridViewDevices.DataSource = table;
        }

        private void gridViewDevices_EditingControlShowing(object sender, DataGridViewEditingControlShowingEventArgs e)
        {
            ComboBox cb = e.Control as ComboBox;
            if (cb != null)
            {
                cb.DropDownStyle = ComboBoxStyle.DropDown;
            }
        }

        private void gridViewDevices_CellValidating(object sender, DataGridViewCellValidatingEventArgs e)
        {
             DataGridViewComboBoxColumn column = (this.gridViewDevices.Columns[e.ColumnIndex] as DataGridViewComboBoxColumn);
            if (column==null)
            {
                return;
            }
            if (!column.Items.Contains(e.FormattedValue)) {
                column.Items.Add(e.FormattedValue);
            }
        }
    }
}
