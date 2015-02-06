namespace ION
{
    namespace Konzolo
    {
        partial class EditThingDialog
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

            #region Windows Form Designer generated code

            /// <summary>
            /// Required method for Designer support - do not modify
            /// the contents of this method with the code editor.
            /// </summary>
            private void InitializeComponent()
            {
                this.components = new System.ComponentModel.Container();
                this.lblType = new System.Windows.Forms.Label();
                this.lblVendor = new System.Windows.Forms.Label();
                this.lblOS = new System.Windows.Forms.Label();
                this.cmbVendor = new System.Windows.Forms.ComboBox();
                this.cmbOS = new System.Windows.Forms.ComboBox();
                this.cmbType = new System.Windows.Forms.ComboBox();
                this.txtName = new System.Windows.Forms.TextBox();
                this.txtMAC = new System.Windows.Forms.TextBox();
                this.lblName = new System.Windows.Forms.Label();
                this.lblMAC = new System.Windows.Forms.Label();
                this.lblDesc = new System.Windows.Forms.Label();
                this.txtDesc = new System.Windows.Forms.TextBox();
                this.groupBox = new System.Windows.Forms.GroupBox();
                this.pnlButtons = new System.Windows.Forms.Panel();
                this.btnCancel = new System.Windows.Forms.Button();
                this.btnSave = new System.Windows.Forms.Button();
                this.dataModelBindingSource = new System.Windows.Forms.BindingSource(this.components);
                this.groupBox.SuspendLayout();
                this.pnlButtons.SuspendLayout();
                ((System.ComponentModel.ISupportInitialize)(this.dataModelBindingSource)).BeginInit();
                this.SuspendLayout();
                // 
                // lblType
                // 
                this.lblType.AutoSize = true;
                this.lblType.Location = new System.Drawing.Point(14, 33);
                this.lblType.Name = "lblType";
                this.lblType.Size = new System.Drawing.Size(76, 15);
                this.lblType.TabIndex = 0;
                this.lblType.Text = "Device Type:";
                // 
                // lblVendor
                // 
                this.lblVendor.AutoSize = true;
                this.lblVendor.Location = new System.Drawing.Point(14, 65);
                this.lblVendor.Name = "lblVendor";
                this.lblVendor.Size = new System.Drawing.Size(49, 15);
                this.lblVendor.TabIndex = 1;
                this.lblVendor.Text = "Vendor:";
                // 
                // lblOS
                // 
                this.lblOS.AutoSize = true;
                this.lblOS.Location = new System.Drawing.Point(14, 96);
                this.lblOS.Name = "lblOS";
                this.lblOS.Size = new System.Drawing.Size(107, 15);
                this.lblOS.TabIndex = 2;
                this.lblOS.Text = "Operating System:";
                // 
                // cmbVendor
                // 
                this.cmbVendor.AutoCompleteMode = System.Windows.Forms.AutoCompleteMode.Suggest;
                this.cmbVendor.AutoCompleteSource = System.Windows.Forms.AutoCompleteSource.ListItems;
                this.cmbVendor.FormattingEnabled = true;
                this.cmbVendor.Location = new System.Drawing.Point(143, 61);
                this.cmbVendor.Name = "cmbVendor";
                this.cmbVendor.Size = new System.Drawing.Size(196, 23);
                this.cmbVendor.TabIndex = 2;
                // 
                // cmbOS
                // 
                this.cmbOS.AutoCompleteMode = System.Windows.Forms.AutoCompleteMode.Suggest;
                this.cmbOS.AutoCompleteSource = System.Windows.Forms.AutoCompleteSource.ListItems;
                this.cmbOS.FormattingEnabled = true;
                this.cmbOS.Location = new System.Drawing.Point(143, 92);
                this.cmbOS.Name = "cmbOS";
                this.cmbOS.Size = new System.Drawing.Size(196, 23);
                this.cmbOS.TabIndex = 3;
                // 
                // cmbType
                // 
                this.cmbType.AutoCompleteMode = System.Windows.Forms.AutoCompleteMode.Suggest;
                this.cmbType.AutoCompleteSource = System.Windows.Forms.AutoCompleteSource.ListItems;
                this.cmbType.FormattingEnabled = true;
                this.cmbType.Location = new System.Drawing.Point(143, 30);
                this.cmbType.Name = "cmbType";
                this.cmbType.Size = new System.Drawing.Size(196, 23);
                this.cmbType.TabIndex = 1;
                // 
                // txtName
                // 
                this.txtName.Location = new System.Drawing.Point(143, 123);
                this.txtName.Name = "txtName";
                this.txtName.ReadOnly = true;
                this.txtName.Size = new System.Drawing.Size(196, 21);
                this.txtName.TabIndex = 4;
                // 
                // txtMAC
                // 
                this.txtMAC.Location = new System.Drawing.Point(143, 153);
                this.txtMAC.Name = "txtMAC";
                this.txtMAC.ReadOnly = true;
                this.txtMAC.Size = new System.Drawing.Size(196, 21);
                this.txtMAC.TabIndex = 5;
                // 
                // lblName
                // 
                this.lblName.AutoSize = true;
                this.lblName.Location = new System.Drawing.Point(14, 127);
                this.lblName.Name = "lblName";
                this.lblName.Size = new System.Drawing.Size(44, 15);
                this.lblName.TabIndex = 8;
                this.lblName.Text = "Name:";
                // 
                // lblMAC
                // 
                this.lblMAC.AutoSize = true;
                this.lblMAC.Location = new System.Drawing.Point(14, 157);
                this.lblMAC.Name = "lblMAC";
                this.lblMAC.Size = new System.Drawing.Size(105, 15);
                this.lblMAC.TabIndex = 9;
                this.lblMAC.Text = "Network Identifier:";
                // 
                // lblDesc
                // 
                this.lblDesc.AutoSize = true;
                this.lblDesc.Location = new System.Drawing.Point(14, 188);
                this.lblDesc.Name = "lblDesc";
                this.lblDesc.Size = new System.Drawing.Size(72, 15);
                this.lblDesc.TabIndex = 11;
                this.lblDesc.Text = "Description:";
                // 
                // txtDesc
                // 
                this.txtDesc.Location = new System.Drawing.Point(17, 213);
                this.txtDesc.Name = "txtDesc";
                this.txtDesc.Size = new System.Drawing.Size(322, 21);
                this.txtDesc.TabIndex = 6;
                // 
                // groupBox
                // 
                this.groupBox.Controls.Add(this.txtDesc);
                this.groupBox.Dock = System.Windows.Forms.DockStyle.Fill;
                this.groupBox.Location = new System.Drawing.Point(0, 0);
                this.groupBox.Name = "groupBox";
                this.groupBox.Size = new System.Drawing.Size(355, 294);
                this.groupBox.TabIndex = 13;
                this.groupBox.TabStop = false;
                this.groupBox.Text = "Properties";
                // 
                // pnlButtons
                // 
                this.pnlButtons.Controls.Add(this.btnCancel);
                this.pnlButtons.Controls.Add(this.btnSave);
                this.pnlButtons.Dock = System.Windows.Forms.DockStyle.Bottom;
                this.pnlButtons.Location = new System.Drawing.Point(0, 243);
                this.pnlButtons.Name = "pnlButtons";
                this.pnlButtons.Size = new System.Drawing.Size(355, 51);
                this.pnlButtons.TabIndex = 14;
                // 
                // btnCancel
                // 
                this.btnCancel.Location = new System.Drawing.Point(113, 10);
                this.btnCancel.Name = "btnCancel";
                this.btnCancel.Size = new System.Drawing.Size(87, 27);
                this.btnCancel.TabIndex = 8;
                this.btnCancel.Text = "Cancel";
                this.btnCancel.UseVisualStyleBackColor = true;
                this.btnCancel.Click += new System.EventHandler(this.btnCancel_Click);
                // 
                // btnSave
                // 
                this.btnSave.Location = new System.Drawing.Point(17, 10);
                this.btnSave.Name = "btnSave";
                this.btnSave.Size = new System.Drawing.Size(87, 27);
                this.btnSave.TabIndex = 7;
                this.btnSave.Text = "Save";
                this.btnSave.UseVisualStyleBackColor = true;
                this.btnSave.Click += new System.EventHandler(this.btnSave_Click);
                // 
                // dataModelBindingSource
                // 
                this.dataModelBindingSource.DataSource = typeof(ION.Konzolo.DataModel);
                // 
                // EditThingDialog
                // 
                this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
                this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
                this.ClientSize = new System.Drawing.Size(355, 294);
                this.Controls.Add(this.pnlButtons);
                this.Controls.Add(this.lblDesc);
                this.Controls.Add(this.lblMAC);
                this.Controls.Add(this.lblName);
                this.Controls.Add(this.txtMAC);
                this.Controls.Add(this.txtName);
                this.Controls.Add(this.cmbType);
                this.Controls.Add(this.cmbOS);
                this.Controls.Add(this.cmbVendor);
                this.Controls.Add(this.lblOS);
                this.Controls.Add(this.lblVendor);
                this.Controls.Add(this.lblType);
                this.Controls.Add(this.groupBox);
                this.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
                this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
                this.KeyPreview = true;
                this.Name = "EditThingDialog";
                this.Text = "Thing Stuff";
                this.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.EditThingDialog_KeyPress);
                this.groupBox.ResumeLayout(false);
                this.groupBox.PerformLayout();
                this.pnlButtons.ResumeLayout(false);
                ((System.ComponentModel.ISupportInitialize)(this.dataModelBindingSource)).EndInit();
                this.ResumeLayout(false);
                this.PerformLayout();

            }

            #endregion

            private System.Windows.Forms.Label lblType;
            private System.Windows.Forms.Label lblVendor;
            private System.Windows.Forms.Label lblOS;
            private System.Windows.Forms.ComboBox cmbVendor;
            private System.Windows.Forms.ComboBox cmbOS;
            private System.Windows.Forms.ComboBox cmbType;
            private System.Windows.Forms.TextBox txtName;
            private System.Windows.Forms.TextBox txtMAC;
            private System.Windows.Forms.Label lblName;
            private System.Windows.Forms.Label lblMAC;
            private System.Windows.Forms.Label lblDesc;
            private System.Windows.Forms.TextBox txtDesc;
            private System.Windows.Forms.GroupBox groupBox;
            private System.Windows.Forms.Panel pnlButtons;
            private System.Windows.Forms.Button btnCancel;
            private System.Windows.Forms.Button btnSave;
            private System.Windows.Forms.BindingSource dataModelBindingSource;
        }
    }
}