namespace mabat
{
    partial class LogTailControl
    {
        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary> 
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.listBoxLog = new System.Windows.Forms.ListBox();
            this.toolStrip = new System.Windows.Forms.ToolStrip();
            this.checkBoxStop = new System.Windows.Forms.CheckBox();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.copyToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.contextMenuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // listBoxLog
            // 
            this.listBoxLog.ContextMenuStrip = this.contextMenuStrip1;
            this.listBoxLog.Dock = System.Windows.Forms.DockStyle.Fill;
            this.listBoxLog.DrawMode = System.Windows.Forms.DrawMode.OwnerDrawFixed;
            this.listBoxLog.Font = new System.Drawing.Font("Microsoft Sans Serif", 8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.listBoxLog.FormattingEnabled = true;
            this.listBoxLog.Location = new System.Drawing.Point(0, 25);
            this.listBoxLog.Name = "listBoxLog";
            this.listBoxLog.SelectionMode = System.Windows.Forms.SelectionMode.MultiExtended;
            this.listBoxLog.Size = new System.Drawing.Size(780, 555);
            this.listBoxLog.TabIndex = 0;
            this.listBoxLog.DrawItem += new System.Windows.Forms.DrawItemEventHandler(this.listBoxLog_DrawItem);
            // 
            // toolStrip
            // 
            this.toolStrip.Location = new System.Drawing.Point(0, 0);
            this.toolStrip.Name = "toolStrip";
            this.toolStrip.Size = new System.Drawing.Size(780, 25);
            this.toolStrip.TabIndex = 1;
            this.toolStrip.Text = "toolStrip1";
            // 
            // checkBoxStop
            // 
            this.checkBoxStop.AutoSize = true;
            this.checkBoxStop.Location = new System.Drawing.Point(15, 3);
            this.checkBoxStop.Name = "checkBoxStop";
            this.checkBoxStop.Size = new System.Drawing.Size(51, 19);
            this.checkBoxStop.TabIndex = 2;
            this.checkBoxStop.Text = "Stop";
            this.checkBoxStop.UseVisualStyleBackColor = true;
            this.checkBoxStop.CheckedChanged += new System.EventHandler(this.checkBoxStop_CheckedChanged);
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.copyToolStripMenuItem});
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(103, 26);
            // 
            // copyToolStripMenuItem
            // 
            this.copyToolStripMenuItem.Name = "copyToolStripMenuItem";
            this.copyToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.copyToolStripMenuItem.Text = "Copy";
            this.copyToolStripMenuItem.Click += new System.EventHandler(this.copyToolStripMenuItem_Click);
            // 
            // LogTailControl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.checkBoxStop);
            this.Controls.Add(this.listBoxLog);
            this.Controls.Add(this.toolStrip);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Name = "LogTailControl";
            this.Size = new System.Drawing.Size(780, 580);
            this.contextMenuStrip1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox listBoxLog;
        private System.Windows.Forms.ToolStrip toolStrip;
        private System.Windows.Forms.CheckBox checkBoxStop;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ToolStripMenuItem copyToolStripMenuItem;
    }
}
