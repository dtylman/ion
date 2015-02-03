using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace mabat
{
    public partial class EditDeviceDialog : Form
    {
        public EditDeviceDialog()
        {
            InitializeComponent();            
            this.cmbType.DataSource = DataModel.Instance.DeviceTypeDataSource;
            this.cmbVendor.DataSource = DataModel.Instance.DeviceVendorDataSource;
        }
        
        internal void setFromRow(DataGridViewRow row, DataGridViewColumnCollection columns)
        {
            this.cmbType.Text = getText(row, columns, DeviceDataRow.Type);
            this.cmbVendor.Text = getText(row, columns, DeviceDataRow.Vendor);
            this.cmbOS.Text = getText(row, columns, DeviceDataRow.OS);
            this.txtDesc.Text = getText(row, columns, DeviceDataRow.DESC);
            this.txtMAC.Text = getText(row, columns, DeviceDataRow.MAC);
            this.txtName.Text = getText(row, columns, DeviceDataRow.Name);
        }

        private string getText(DataGridViewRow row, DataGridViewColumnCollection columns, string columnName)
        {
            Object value = row.Cells[columns[DeviceDataRow.DisplayName(columnName)].Index].Value;
            if (value != null)
            {
                return value.ToString();
            }
            return String.Empty;
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            Close(); 
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
