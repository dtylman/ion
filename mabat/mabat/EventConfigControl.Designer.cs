namespace mabat
{
    partial class EventConfigControl
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
            this.lblName = new System.Windows.Forms.Label();
            this.chkSave = new System.Windows.Forms.CheckBox();
            this.chkMail = new System.Windows.Forms.CheckBox();
            this.chkSyslog = new System.Windows.Forms.CheckBox();
            this.toolTip = new System.Windows.Forms.ToolTip(this.components);
            this.SuspendLayout();
            // 
            // lblName
            // 
            this.lblName.AutoSize = true;
            this.lblName.Location = new System.Drawing.Point(3, 7);
            this.lblName.Name = "lblName";
            this.lblName.Size = new System.Drawing.Size(35, 13);
            this.lblName.TabIndex = 0;
            this.lblName.Text = "label1";
            // 
            // chkSave
            // 
            this.chkSave.AutoSize = true;
            this.chkSave.Location = new System.Drawing.Point(161, 6);
            this.chkSave.Name = "chkSave";
            this.chkSave.Size = new System.Drawing.Size(59, 17);
            this.chkSave.TabIndex = 3;
            this.chkSave.Text = "Enable";
            this.chkSave.UseVisualStyleBackColor = true;
            // 
            // chkMail
            // 
            this.chkMail.AutoSize = true;
            this.chkMail.Location = new System.Drawing.Point(237, 6);
            this.chkMail.Name = "chkMail";
            this.chkMail.Size = new System.Drawing.Size(82, 17);
            this.chkMail.TabIndex = 4;
            this.chkMail.Text = "Send E-mail";
            this.chkMail.UseVisualStyleBackColor = true;
            // 
            // chkSyslog
            // 
            this.chkSyslog.AutoSize = true;
            this.chkSyslog.Location = new System.Drawing.Point(340, 6);
            this.chkSyslog.Name = "chkSyslog";
            this.chkSyslog.Size = new System.Drawing.Size(115, 17);
            this.chkSyslog.TabIndex = 5;
            this.chkSyslog.Text = "Save to system log";
            this.chkSyslog.UseVisualStyleBackColor = true;
            // 
            // toolTip
            // 
            this.toolTip.IsBalloon = true;
            // 
            // EventConfigControl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.Controls.Add(this.chkSyslog);
            this.Controls.Add(this.chkMail);
            this.Controls.Add(this.chkSave);
            this.Controls.Add(this.lblName);
            this.Name = "EventConfigControl";
            this.Size = new System.Drawing.Size(455, 28);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblName;
        private System.Windows.Forms.CheckBox chkSave;
        private System.Windows.Forms.CheckBox chkMail;
        private System.Windows.Forms.CheckBox chkSyslog;
        private System.Windows.Forms.ToolTip toolTip;
    }
}
