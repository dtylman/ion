using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
namespace ION
{
    namespace Konzolo
    {
        public partial class EditThingDialog : Form
        {
            public EditThingDialog(string type, string vendor, string os, string desc, string mac, string name)
            {
                InitializeComponent();
                this.cmbType.Items.AddRange(new ThingTypes(type).ToArray());
                this.cmbType.Text = type;
                this.cmbVendor.Items.AddRange(new ThingVendors(vendor).ToArray());
                this.cmbVendor.Text = vendor;
                this.cmbOS.Items.AddRange(new ThingOS(os).ToArray());
                this.cmbOS.Text = os;
                this.txtDesc.Text = desc;
                this.txtMAC.Text = mac;
                this.txtName.Text = name;
            }

            private void btnSave_Click(object sender, EventArgs e)
            {
                Save();
            }

            private void Save()
            {
                try
                {
                    DataModel.Instance.UpdateThing(this.txtMAC.Text,
                        this.cmbType.Text, this.cmbVendor.Text, this.cmbOS.Text, this.txtDesc.Text);
                    DialogResult = DialogResult.OK;
                    Close();
                    //MessageBox.Show(this, "Thing Saved", "Information", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
                catch (Exception ex)
                {
                    String message = "Cannot save thing: " + ex.Message;
                    MessageBox.Show(this, message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }

            private void btnCancel_Click(object sender, EventArgs e)
            {
                Cancel();

            }

            private void Cancel()
            {
                DialogResult = DialogResult.Cancel;
                Close();
            }

            private void EditThingDialog_KeyPress(object sender, KeyPressEventArgs e)
            {
                if (e.KeyChar == (char)Keys.Escape)
                {
                    Cancel();
                    e.Handled = true;
                }
            }


        }
    }
}