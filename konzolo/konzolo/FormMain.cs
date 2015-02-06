using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SQLite;
namespace ION
{
    namespace Konzolo
    {
        public partial class FormMain : Form
        {
            public FormMain()
            {
                InitializeComponent();
                ThingsControl dc = new ThingsControl();
                dc.Dock = DockStyle.Fill;
                this.tabPageThings.Controls.Add(dc);
                ConfigControl sc = new ConfigControl();
                sc.Dock = DockStyle.Fill;
                this.tabPageService.Controls.Add(sc);
                AuthorizationControl ac = new AuthorizationControl();
                ac.Dock = DockStyle.Fill;
                this.tabPageAuthorization.Controls.Add(ac);
            }

            private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
            {
                AboutBox aboutBox = new AboutBox();
                aboutBox.ShowDialog(this);
            }

            private void exitToolStripMenuItem_Click(object sender, EventArgs e)
            {
                Close();
            }


        }
    }
}