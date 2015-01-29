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
            this.columnType = new System.Windows.Forms.DataGridViewComboBoxColumn();
            this.ColumnVendor = new System.Windows.Forms.DataGridViewComboBoxColumn();
            this.columnOS = new System.Windows.Forms.DataGridViewComboBoxColumn();
            this.columnHostname = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.columnDetectedOS = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.columnLastSeen = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.columnMAC = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.columnIP = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.columnDesc = new System.Windows.Forms.DataGridViewTextBoxColumn();
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
            this.ColumnImage,
            this.columnType,
            this.ColumnVendor,
            this.columnOS,
            this.columnHostname,
            this.columnDetectedOS,
            this.columnLastSeen,
            this.columnMAC,
            this.columnIP,
            this.columnDesc});
            this.gridViewDevices.Dock = System.Windows.Forms.DockStyle.Fill;
            this.gridViewDevices.Location = new System.Drawing.Point(0, 0);
            this.gridViewDevices.MultiSelect = false;
            this.gridViewDevices.Name = "gridViewDevices";
            this.gridViewDevices.Size = new System.Drawing.Size(744, 300);
            this.gridViewDevices.TabIndex = 0;
            this.gridViewDevices.CellValidating += new System.Windows.Forms.DataGridViewCellValidatingEventHandler(this.gridViewDevices_CellValidating);
            this.gridViewDevices.EditingControlShowing += new System.Windows.Forms.DataGridViewEditingControlShowingEventHandler(this.gridViewDevices_EditingControlShowing);
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
            // columnType
            // 
            this.columnType.DataPropertyName = "type";
            this.columnType.DisplayStyle = System.Windows.Forms.DataGridViewComboBoxDisplayStyle.ComboBox;
            this.columnType.HeaderText = "Device Type";
            this.columnType.Items.AddRange(new object[] {
            "Phone",
            "TV",
            "Computer",
            "Other"});
            this.columnType.Name = "columnType";
            this.columnType.Resizable = System.Windows.Forms.DataGridViewTriState.True;
            this.columnType.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.Automatic;
            // 
            // ColumnVendor
            // 
            this.ColumnVendor.DataPropertyName = "vendor";
            this.ColumnVendor.DisplayStyle = System.Windows.Forms.DataGridViewComboBoxDisplayStyle.ComboBox;
            this.ColumnVendor.HeaderText = "Device Vendor";
            this.ColumnVendor.Name = "ColumnVendor";
            this.ColumnVendor.Resizable = System.Windows.Forms.DataGridViewTriState.True;
            this.ColumnVendor.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.Automatic;
            // 
            // columnOS
            // 
            this.columnOS.DataPropertyName = "os";
            this.columnOS.DisplayStyle = System.Windows.Forms.DataGridViewComboBoxDisplayStyle.ComboBox;
            this.columnOS.HeaderText = "OS";
            this.columnOS.Name = "columnOS";
            this.columnOS.Resizable = System.Windows.Forms.DataGridViewTriState.True;
            this.columnOS.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.Automatic;
            // 
            // columnHostname
            // 
            this.columnHostname.DataPropertyName = "hostname";
            this.columnHostname.HeaderText = "Hostname";
            this.columnHostname.Name = "columnHostname";
            this.columnHostname.ReadOnly = true;
            // 
            // columnDetectedOS
            // 
            this.columnDetectedOS.DataPropertyName = "host_os";
            this.columnDetectedOS.HeaderText = "Detected OS";
            this.columnDetectedOS.Name = "columnDetectedOS";
            this.columnDetectedOS.ReadOnly = true;
            // 
            // columnLastSeen
            // 
            this.columnLastSeen.DataPropertyName = "last_seen";
            this.columnLastSeen.HeaderText = "Last Seen";
            this.columnLastSeen.Name = "columnLastSeen";
            this.columnLastSeen.ReadOnly = true;
            // 
            // columnMAC
            // 
            this.columnMAC.DataPropertyName = "mac";
            this.columnMAC.HeaderText = "MAC Address";
            this.columnMAC.Name = "columnMAC";
            this.columnMAC.ReadOnly = true;
            // 
            // columnIP
            // 
            this.columnIP.DataPropertyName = "ip";
            this.columnIP.HeaderText = "Last IP Address";
            this.columnIP.Name = "columnIP";
            this.columnIP.ReadOnly = true;
            // 
            // columnDesc
            // 
            this.columnDesc.DataPropertyName = "desc";
            this.columnDesc.HeaderText = "Description";
            this.columnDesc.Name = "columnDesc";
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
        private System.Windows.Forms.DataGridViewComboBoxColumn columnType;
        private System.Windows.Forms.DataGridViewComboBoxColumn ColumnVendor;
        private System.Windows.Forms.DataGridViewComboBoxColumn columnOS;
        private System.Windows.Forms.DataGridViewTextBoxColumn columnHostname;
        private System.Windows.Forms.DataGridViewTextBoxColumn columnDetectedOS;
        private System.Windows.Forms.DataGridViewTextBoxColumn columnLastSeen;
        private System.Windows.Forms.DataGridViewTextBoxColumn columnMAC;
        private System.Windows.Forms.DataGridViewTextBoxColumn columnIP;
        private System.Windows.Forms.DataGridViewTextBoxColumn columnDesc;
    }
}
