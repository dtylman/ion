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
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.splitContainer2 = new System.Windows.Forms.SplitContainer();
            this.groupBoxLogger = new System.Windows.Forms.GroupBox();
            this.groupBoxEvents = new System.Windows.Forms.GroupBox();
            this.groupBoxServer = new System.Windows.Forms.GroupBox();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer2)).BeginInit();
            this.splitContainer2.Panel1.SuspendLayout();
            this.splitContainer2.Panel2.SuspendLayout();
            this.splitContainer2.SuspendLayout();
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
            this.splitContainer2.SplitterDistance = 227;
            this.splitContainer2.TabIndex = 0;
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
            // groupBoxEvents
            // 
            this.groupBoxEvents.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBoxEvents.Location = new System.Drawing.Point(0, 0);
            this.groupBoxEvents.Name = "groupBoxEvents";
            this.groupBoxEvents.Size = new System.Drawing.Size(452, 238);
            this.groupBoxEvents.TabIndex = 0;
            this.groupBoxEvents.TabStop = false;
            this.groupBoxEvents.Text = "Events Settings";
            // 
            // groupBoxServer
            // 
            this.groupBoxServer.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBoxServer.Location = new System.Drawing.Point(0, 0);
            this.groupBoxServer.Name = "groupBoxServer";
            this.groupBoxServer.Size = new System.Drawing.Size(227, 238);
            this.groupBoxServer.TabIndex = 0;
            this.groupBoxServer.TabStop = false;
            this.groupBoxServer.Text = "Server Settings";
            // 
            // ServiceControl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.splitContainer1);
            this.Name = "ServiceControl";
            this.Size = new System.Drawing.Size(683, 503);
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            this.splitContainer2.Panel1.ResumeLayout(false);
            this.splitContainer2.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer2)).EndInit();
            this.splitContainer2.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.SplitContainer splitContainer2;
        private System.Windows.Forms.GroupBox groupBoxServer;
        private System.Windows.Forms.GroupBox groupBoxEvents;
        private System.Windows.Forms.GroupBox groupBoxLogger;
    }
}
