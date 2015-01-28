namespace mabat
{
    partial class DevicesControl
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
            this.panelMaster = new System.Windows.Forms.Panel();
            this.panelDetail = new System.Windows.Forms.Panel();
            this.gridViewDevices = new System.Windows.Forms.DataGridView();
            this.gridViewEvents = new System.Windows.Forms.DataGridView();
            this.panelMaster.SuspendLayout();
            this.panelDetail.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.gridViewDevices)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.gridViewEvents)).BeginInit();
            this.SuspendLayout();
            // 
            // panelMaster
            // 
            this.panelMaster.Controls.Add(this.gridViewDevices);
            this.panelMaster.Location = new System.Drawing.Point(12, 12);
            this.panelMaster.Name = "panelMaster";
            this.panelMaster.Size = new System.Drawing.Size(696, 177);
            this.panelMaster.TabIndex = 0;
            // 
            // panelDetail
            // 
            this.panelDetail.Controls.Add(this.gridViewEvents);
            this.panelDetail.Location = new System.Drawing.Point(26, 249);
            this.panelDetail.Name = "panelDetail";
            this.panelDetail.Size = new System.Drawing.Size(654, 242);
            this.panelDetail.TabIndex = 1;
            // 
            // gridViewDevices
            // 
            this.gridViewDevices.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.gridViewDevices.Location = new System.Drawing.Point(16, 12);
            this.gridViewDevices.Name = "gridViewDevices";
            this.gridViewDevices.Size = new System.Drawing.Size(677, 150);
            this.gridViewDevices.TabIndex = 0;
            // 
            // gridViewEvents
            // 
            this.gridViewEvents.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.gridViewEvents.Location = new System.Drawing.Point(3, 3);
            this.gridViewEvents.Name = "gridViewEvents";
            this.gridViewEvents.Size = new System.Drawing.Size(631, 190);
            this.gridViewEvents.TabIndex = 0;
            // 
            // DevicesControl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.panelDetail);
            this.Controls.Add(this.panelMaster);
            this.Name = "DevicesControl";
            this.Size = new System.Drawing.Size(744, 517);
            this.panelMaster.ResumeLayout(false);
            this.panelDetail.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.gridViewDevices)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.gridViewEvents)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panelMaster;
        private System.Windows.Forms.Panel panelDetail;
        private System.Windows.Forms.DataGridView gridViewDevices;
        private System.Windows.Forms.DataGridView gridViewEvents;
    }
}
