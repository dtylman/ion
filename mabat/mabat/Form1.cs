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

namespace mabat
{
    public partial class FormMain : Form
    {
        private SQLiteConnection connection = null;

        public FormMain()
        {
            InitializeComponent();            
            connection = new SQLiteConnection("Data Source=zakif.db");
            connection.Open();
            reload();
        }
       
        private void button1_Click(object sender, EventArgs e)
        {
            reload();           
        }

        private void reload()
        {
            try
            {

                SQLiteDataAdapter adapter = new SQLiteDataAdapter();
                adapter.SelectCommand = new SQLiteCommand("select * from ip", connection);
                DataTable table = new DataTable();
                adapter.Fill(table);
                this.dataGridIPs.DataSource = table;
            }
            catch(SQLiteException ex)
            {                
                MessageBox.Show (ex.Message,"Error",MessageBoxButtons.OK,MessageBoxIcon.Error);
            }
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            deleteTable();
        }

        private void deleteTable()
        {
            try
            {
                SQLiteCommand command = connection.CreateCommand();
                command.CommandText = "DELETE FROM ip";
                command.ExecuteNonQuery();
                command.Dispose();
            }
            catch (SQLiteException ex)
            {
                MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            reload();
        }

        private void btnReload_Click(object sender, EventArgs e)
        {            
            reload();
        }

        private void btnDelete_Click_1(object sender, EventArgs e)
        {
            deleteTable();
        }

        
    }
}
