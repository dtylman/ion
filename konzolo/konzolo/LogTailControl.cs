using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ION
{
    namespace Konzolo
    {
        public partial class LogTailControl : UserControl
        {
            private FileSystemWatcher watcher = new FileSystemWatcher();
            private StreamReader reader = null;

            public LogTailControl(String path, String fileName)
            {
                InitializeComponent();
                if (File.Exists(Path.Combine(path, fileName)))
                {
                    InitStream(path, fileName);
                    InitWatcher(path, fileName);
                    this.Enabled = true;
                }
                else
                {
                    this.listBoxLog.Items.Add("NO LOG FILE FOUND");
                    this.listBoxLog.Items.Add("Error: NO LOG FILE FOUND");
                    this.Enabled = false;
                }
            }

            private void InitStream(string path, string fileName)
            {
                this.reader = new StreamReader(new FileStream(Path.Combine(path, fileName), FileMode.Open, FileAccess.Read, FileShare.ReadWrite));
                this.reader.BaseStream.Seek(0, SeekOrigin.End);
            }

            private void InitWatcher(String path, String fileName)
            {
                watcher.Path = path;
                watcher.Filter = fileName;
                watcher.NotifyFilter = NotifyFilters.LastWrite;
                watcher.Changed += watcher_Changed;
                watcher.EnableRaisingEvents = true;
            }

            private void addLine(String line)
            {
                int overload = listBoxLog.Items.Count - 1024;
                for (int index = 0; index < overload; ++index)
                {
                    this.listBoxLog.Items.RemoveAt(index);
                }
                this.listBoxLog.Items.Add(line);
                this.listBoxLog.SelectedIndex = listBoxLog.Items.Count - 1;
                this.listBoxLog.SelectedIndex = -1;
            }

            void watcher_Changed(object sender, FileSystemEventArgs e)
            {
                string line = "";
                while ((line = reader.ReadLine()) != null)
                {
                    if (this.listBoxLog.InvokeRequired)
                    {
                        this.listBoxLog.Invoke((MethodInvoker)delegate
                        {
                            addLine(line);
                        });
                    }


                }

            }

            private void listBoxLog_DrawItem(object sender, DrawItemEventArgs e)
            {
                if (e.Index == -1)
                {
                    return;
                }

                e.DrawBackground();
                Brush brush = Brushes.Black;

                String line = this.listBoxLog.Items[e.Index].ToString();
                if (!this.Enabled)
                {
                    brush = Brushes.Gray;
                }
                else if (line.Contains("error"))
                {
                    brush = Brushes.Red;
                }
                e.Graphics.DrawString(line, e.Font, brush, e.Bounds, StringFormat.GenericDefault);
                e.DrawFocusRectangle();
            }

            private void checkBoxStop_CheckedChanged(object sender, EventArgs e)
            {
                this.watcher.EnableRaisingEvents = !this.checkBoxStop.Checked;
            }

            private void copyToolStripMenuItem_Click(object sender, EventArgs e)
            {
                StringBuilder sb = new StringBuilder();
                foreach (Object s in listBoxLog.SelectedItems)
                {
                    sb.Append(s.ToString());
                    sb.Append("\r\n");
                }
                Clipboard.SetText(sb.ToString());
            }

        }
    }
}