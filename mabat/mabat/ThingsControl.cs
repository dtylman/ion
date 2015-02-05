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
    public partial class ThingsControl : UserControl
    {
        public ThingsControl()
        {
            InitializeComponent();
            this.gridViewThings.ColumnAdded += gridViewThings_ColumnAdded;
            this.gridViewEvents.ColumnAdded += gridViewEvents_ColumnAdded;
            loadThings();
        }


        void gridViewEvents_ColumnAdded(object sender, DataGridViewColumnEventArgs e)
        {
            e.Column.HeaderText = Strings.ResourceManager.GetString("events_"+e.Column.Name);
        }

        void gridViewThings_ColumnAdded(object sender, DataGridViewColumnEventArgs e)
        {
            e.Column.HeaderText = Strings.ResourceManager.GetString("things_"+e.Column.Name);
        }

        private void loadThings()
        {
            DataTable table = new DataTable();
            DataModel.Instance.GetThings(table);            
            this.gridViewThings.DataSource = table;
        }
        
        private void loadEvents(string mac)
        {
            DataTable table = new DataTable();
            DataModel.Instance.GetEvents(table,mac);
            this.gridViewEvents.DataSource = table;            
        }

        private void gridViewDevices_CellDoubleClick(object sender, DataGridViewCellEventArgs e)
        {            
            EditThing(e.RowIndex);            
        }

        private void EditThing(int rowIndex)
        {
            if (rowIndex== -1)
            {
                return;
            }
            string type = SelectedThingWithDefault(rowIndex, ThingDataRow.Type);
            string vendor = SelectedThingWithDefault(rowIndex, ThingDataRow.Vendor);
            string os = SelectedThingWithDefault(rowIndex, ThingDataRow.OS);
            string desc = SelectedThingWithDefault(rowIndex, ThingDataRow.DESC);
            string mac = SelectedThingWithDefault(rowIndex, ThingDataRow.MAC);
            string name = SelectedThingWithDefault(rowIndex, ThingDataRow.Name);
            EditThingDialog dialog = new EditThingDialog(type, vendor, os, desc, mac, name);
            DialogResult res = dialog.ShowDialog(this);
            if (res==DialogResult.OK)
            {
                loadThings();
            }
        }

        private string SelectedThingWithDefault(int rowIndex, string columnName)
        {
            String value = SelectedThing(rowIndex, columnName);
            if (value==null)
            {
                return "";
            }
            return value;
        }

        private void gridViewDevices_RowEnter(object sender, DataGridViewCellEventArgs e)
        {
            String mac = SelectedThing(e.RowIndex, ThingDataRow.MAC);
            if (mac != null)
            {
                loadEvents(mac);
            }
        }

        private string SelectedThing(int rowIndex, string columnName)
        {
            if (rowIndex==-1)
            {
                return null; 
            }
            int columnIndex = gridViewThings.Columns[columnName].Index;
            return gridViewThings.Rows[rowIndex].Cells[columnName].Value as string;            
        }

        private void gridViewThings_KeyPress(object sender, KeyPressEventArgs e)
        {                   
            if (e.KeyChar==(char)Keys.Enter)
            {
                if (this.gridViewThings.SelectedRows.Count>0)
                {
                    int index = this.gridViewThings.SelectedRows[0].Index;
                    EditThing(index-1); //index move forwared on enter
                    e.Handled = true;
                }
            }
        }

        private void editToolStripMenuItem_Click(object sender, EventArgs e)
        {
            int index = GetSelectedThing();
            if (index!=-1)
            {
                EditThing(index);
            }
        }

        private int GetSelectedThing()
        {
            if (this.gridViewThings.SelectedRows.Count > 0)
            {
                return this.gridViewThings.SelectedRows[0].Index;
            }
            return -1;
        }

        private void toolStripMenuItem1_Click(object sender, EventArgs e)
        {
            int index = GetSelectedThing();
            if (index!=-1)
            {
                DeleteThing(index);
            }
        }

        private void DeleteThing(int rowIndex)
        {
            string mac= SelectedThing(rowIndex, ThingDataRow.MAC);
            if (mac != null)
            {
                DialogResult res = MessageBox.Show(this, "Delete thing with MAC " + mac + "?" , "Are you sure?", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
                if (res == DialogResult.Yes)
                {
                    try
                    {
                        DataModel.Instance.DeleteThing(mac);
                        loadThings();
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show(this, "Failed to delete: " + ex.Message ,"Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    }
                }
            }
        }

        private void deleteAllToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Not implemented");
        }

        private void reloadToolStripMenuItem_Click(object sender, EventArgs e)
        {
            loadThings();
        }


    }
}
