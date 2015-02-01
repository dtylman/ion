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
            this.gridViewDevices = new System.Windows.Forms.DataGridView();
            this.panelDetail = new System.Windows.Forms.Panel();
            this.gridViewEvents = new System.Windows.Forms.DataGridView();
            this.ColumnImage = new System.Windows.Forms.DataGridViewImageColumn();
            this.panelMaster.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.gridViewDevices)).BeginInit();
            this.panelDetail.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.gridViewEvents)).BeginInit();
            this.SuspendLayout();
            // 
            // panelMaster
            // 
            this.panelMaster.Controls.Add(this.gridViewDevices);
            this.panelMaster.Dock = System.Windows.Forms.DockStyle.Top;
            this.panelMaster.Location = new System.Drawing.Point(0, 0);
            this.panelMaster.Name = "panelMaster";
            this.panelMaster.Size = new System.Drawing.Size(744, 300);
            this.panelMaster.TabIndex = 0;
            // 
            // gridViewDevices
            // 
            this.gridViewDevices.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.gridViewDevices.AutoSizeRowsMode = System.Windows.Forms.DataGridViewAutoSizeRowsMode.DisplayedHeaders;
            this.gridViewDevices.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.gridViewDevices.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.ColumnImage});
            this.gridViewDevices.Dock = System.Windows.Forms.DockStyle.Fill;
            this.gridViewDevices.Location = new System.Drawing.Point(0, 0);
            this.gridViewDevices.MultiSelect = false;
            this.gridViewDevices.Name = "gridViewDevices";
            this.gridViewDevices.Size = new System.Drawing.Size(744, 300);
            this.gridViewDevices.TabIndex = 0;
            this.gridViewDevices.CellDoubleClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.gridViewDevices_CellDoubleClick);
            // 
            // panelDetail
            // 
            this.panelDetail.Controls.Add(this.gridViewEvents);
            this.panelDetail.Location = new System.Drawing.Point(3, 306);
            this.panelDetail.Name = "panelDetail";
            this.panelDetail.Size = new System.Drawing.Size(727, 185);
            this.panelDetail.TabIndex = 1;
            // 
            // gridViewEvents
            // 
            this.gridViewEvents.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.gridViewEvents.Dock = System.Windows.Forms.DockStyle.Fill;
            this.gridViewEvents.Location = new System.Drawing.Point(0, 0);
            this.gridViewEvents.Name = "gridViewEvents";
            this.gridViewEvents.Size = new System.Drawing.Size(727, 185);
            this.gridViewEvents.TabIndex = 0;
            // 
            // ColumnImage
            // 
            this.ColumnImage.HeaderText = "";
            this.ColumnImage.Name = "ColumnImage";
            this.ColumnImage.ReadOnly = true;
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
            ((System.ComponentModel.ISupportInitialize)(this.gridViewDevices)).EndInit();
            this.panelDetail.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.gridViewEvents)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panelMaster;
        private System.Windows.Forms.Panel panelDetail;
        private System.Windows.Forms.DataGridView gridViewDevices;
        private System.Windows.Forms.DataGridView gridViewEvents;
        private System.Windows.Forms.DataGridViewImageColumn ColumnImage;
    }
}
