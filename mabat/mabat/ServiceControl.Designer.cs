namespace mabat
{
    partial class ServiceControl
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
            this.groupBoxLogger = new System.Windows.Forms.GroupBox();
            this.SuspendLayout();
            // 
            // groupBoxLogger
            // 
            this.groupBoxLogger.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.groupBoxLogger.Location = new System.Drawing.Point(0, 299);
            this.groupBoxLogger.Name = "groupBoxLogger";
            this.groupBoxLogger.Size = new System.Drawing.Size(683, 204);
            this.groupBoxLogger.TabIndex = 0;
            this.groupBoxLogger.TabStop = false;
            this.groupBoxLogger.Text = "Server Log";
            // 
            // ServiceControl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.groupBoxLogger);
            this.Name = "ServiceControl";
            this.Size = new System.Drawing.Size(683, 503);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBoxLogger;
    }
}
