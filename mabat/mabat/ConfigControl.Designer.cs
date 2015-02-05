namespace mabat
{
    partial class ConfigControl
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(ConfigControl));
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.splitContainer2 = new System.Windows.Forms.SplitContainer();
            this.groupBoxServer = new System.Windows.Forms.GroupBox();
            this.groupBoxEvents = new System.Windows.Forms.GroupBox();
            this.groupBoxLogger = new System.Windows.Forms.GroupBox();
            this.lblOffline = new System.Windows.Forms.Label();
            this.txtOffline = new System.Windows.Forms.MaskedTextBox();
            this.txtEvents = new System.Windows.Forms.MaskedTextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.cmbLogLevel = new System.Windows.Forms.ComboBox();
            this.label3 = new System.Windows.Forms.Label();
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.btnApply = new System.Windows.Forms.ToolStripButton();
            this.label1 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer2)).BeginInit();
            this.splitContainer2.Panel1.SuspendLayout();
            this.splitContainer2.Panel2.SuspendLayout();
            this.splitContainer2.SuspendLayout();
            this.groupBoxServer.SuspendLayout();
            this.toolStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // splitContainer1
            // 
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.Location = new System.Drawing.Point(0, 0);
            this.splitContainer1.Name = "splitContainer1";
            this.splitContainer1.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add(this.splitContainer2);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add(this.groupBoxLogger);
            this.splitContainer1.Size = new System.Drawing.Size(683, 503);
            this.splitContainer1.SplitterDistance = 238;
            this.splitContainer1.TabIndex = 4;
            // 
            // splitContainer2
            // 
            this.splitContainer2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer2.Location = new System.Drawing.Point(0, 0);
            this.splitContainer2.Name = "splitContainer2";
            // 
            // splitContainer2.Panel1
            // 
            this.splitContainer2.Panel1.Controls.Add(this.groupBoxServer);
            // 
            // splitContainer2.Panel2
            // 
            this.splitContainer2.Panel2.Controls.Add(this.groupBoxEvents);
            this.splitContainer2.Size = new System.Drawing.Size(683, 238);
            this.splitContainer2.SplitterDistance = 192;
            this.splitContainer2.TabIndex = 0;
            // 
            // groupBoxServer
            // 
            this.groupBoxServer.Controls.Add(this.label4);
            this.groupBoxServer.Controls.Add(this.label1);
            this.groupBoxServer.Controls.Add(this.toolStrip1);
            this.groupBoxServer.Controls.Add(this.label3);
            this.groupBoxServer.Controls.Add(this.cmbLogLevel);
            this.groupBoxServer.Controls.Add(this.label2);
            this.groupBoxServer.Controls.Add(this.txtEvents);
            this.groupBoxServer.Controls.Add(this.txtOffline);
            this.groupBoxServer.Controls.Add(this.lblOffline);
            this.groupBoxServer.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBoxServer.Location = new System.Drawing.Point(0, 0);
            this.groupBoxServer.Name = "groupBoxServer";
            this.groupBoxServer.Size = new System.Drawing.Size(192, 238);
            this.groupBoxServer.TabIndex = 0;
            this.groupBoxServer.TabStop = false;
            this.groupBoxServer.Text = "Server Settings";
            // 
            // groupBoxEvents
            // 
            this.groupBoxEvents.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBoxEvents.Location = new System.Drawing.Point(0, 0);
            this.groupBoxEvents.Name = "groupBoxEvents";
            this.groupBoxEvents.Size = new System.Drawing.Size(487, 238);
            this.groupBoxEvents.TabIndex = 0;
            this.groupBoxEvents.TabStop = false;
            this.groupBoxEvents.Text = "Events Settings";
            // 
            // groupBoxLogger
            // 
            this.groupBoxLogger.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBoxLogger.Location = new System.Drawing.Point(0, 0);
            this.groupBoxLogger.Name = "groupBoxLogger";
            this.groupBoxLogger.Size = new System.Drawing.Size(683, 261);
            this.groupBoxLogger.TabIndex = 0;
            this.groupBoxLogger.TabStop = false;
            this.groupBoxLogger.Text = "Logger";
            // 
            // lblOffline
            // 
            this.lblOffline.AutoSize = true;
            this.lblOffline.Location = new System.Drawing.Point(7, 20);
            this.lblOffline.Name = "lblOffline";
            this.lblOffline.Size = new System.Drawing.Size(66, 13);
            this.lblOffline.TabIndex = 0;
            this.lblOffline.Text = "Offline Time:";
            // 
            // txtOffline
            // 
            this.txtOffline.Location = new System.Drawing.Point(79, 20);
            this.txtOffline.Mask = "00";
            this.txtOffline.Name = "txtOffline";
            this.txtOffline.Size = new System.Drawing.Size(27, 20);
            this.txtOffline.TabIndex = 1;
            // 
            // txtEvents
            // 
            this.txtEvents.Location = new System.Drawing.Point(97, 57);
            this.txtEvents.Mask = "00";
            this.txtEvents.Name = "txtEvents";
            this.txtEvents.Size = new System.Drawing.Size(26, 20);
            this.txtEvents.TabIndex = 2;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(10, 57);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(82, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "Keep events for";
            // 
            // cmbLogLevel
            // 
            this.cmbLogLevel.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmbLogLevel.FormattingEnabled = true;
            this.cmbLogLevel.Items.AddRange(new object[] {
            "debug",
            "information",
            "notice",
            "error",
            "warning"});
            this.cmbLogLevel.Location = new System.Drawing.Point(79, 94);
            this.cmbLogLevel.Name = "cmbLogLevel";
            this.cmbLogLevel.Size = new System.Drawing.Size(100, 21);
            this.cmbLogLevel.TabIndex = 4;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(13, 94);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(54, 13);
            this.label3.TabIndex = 5;
            this.label3.Text = "Log Level";
            // 
            // toolStrip1
            // 
            this.toolStrip1.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.btnApply});
            this.toolStrip1.Location = new System.Drawing.Point(3, 210);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(186, 25);
            this.toolStrip1.TabIndex = 6;
            this.toolStrip1.Text = "toolStrip";
            // 
            // btnApply
            // 
            this.btnApply.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.btnApply.Image = ((System.Drawing.Image)(resources.GetObject("btnApply.Image")));
            this.btnApply.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.btnApply.Name = "btnApply";
            this.btnApply.Size = new System.Drawing.Size(42, 22);
            this.btnApply.Text = "Apply";
            this.btnApply.Click += new System.EventHandler(this.btnApply_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(129, 60);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(29, 13);
            this.label1.TabIndex = 7;
            this.label1.Text = "days";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(112, 23);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(43, 13);
            this.label4.TabIndex = 8;
            this.label4.Text = "minutes";
            // 
            // ConfigControl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.splitContainer1);
            this.Name = "ConfigControl";
            this.Size = new System.Drawing.Size(683, 503);
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            this.splitContainer2.Panel1.ResumeLayout(false);
            this.splitContainer2.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer2)).EndInit();
            this.splitContainer2.ResumeLayout(false);
            this.groupBoxServer.ResumeLayout(false);
            this.groupBoxServer.PerformLayout();
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.SplitContainer splitContainer2;
        private System.Windows.Forms.GroupBox groupBoxServer;
        private System.Windows.Forms.GroupBox groupBoxEvents;
        private System.Windows.Forms.GroupBox groupBoxLogger;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.ToolStripButton btnApply;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ComboBox cmbLogLevel;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.MaskedTextBox txtEvents;
        private System.Windows.Forms.MaskedTextBox txtOffline;
        private System.Windows.Forms.Label lblOffline;
    }
}
