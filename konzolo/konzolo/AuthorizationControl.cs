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
        public partial class AuthorizationControl : UserControl
        {
            public AuthorizationControl()
            {
                InitializeComponent();
                reload();
                Paint += AuthorizationControl_Paint;
            }

            void AuthorizationControl_Paint(object sender, PaintEventArgs e)
            {
                reload();
            }



            private void reload()
            {
                DataTable table = new DataTable();
                DataModel.Instance.GetAuthorized(table);
                this.dataGridView.DataSource = table;
            }

            private void btnAdd_Click(object sender, EventArgs e)
            {
                DataModel.Instance.AuthorizeMAC(this.txtMAC.Text);
                reload();
            }

            private void btnRemove_Click(object sender, EventArgs e)
            {
                removeMac();

            }

            private void removeMac()
            {
                if (this.dataGridView.SelectedRows.Count > 0)
                {
                    String mac = this.dataGridView.SelectedRows[0].Cells[0].Value.ToString();
                    DataModel.Instance.UnAuthorizeMAC(mac);
                    reload();
                }
            }

            private void removeToolStripMenuItem_Click(object sender, EventArgs e)
            {
                removeMac();
            }
        }
    }
}