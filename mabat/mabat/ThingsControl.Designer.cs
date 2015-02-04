﻿namespace mabat
{
    partial class ThingsControl
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
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle1 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle2 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle3 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle4 = new System.Windows.Forms.DataGridViewCellStyle();
            this.splitContainer = new System.Windows.Forms.SplitContainer();
            this.groupBoxThings = new System.Windows.Forms.GroupBox();
            this.gridViewThings = new System.Windows.Forms.DataGridView();
            this.ColumnImage = new System.Windows.Forms.DataGridViewImageColumn();
            this.contextMenuStripThings = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.editToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.deleteAllToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.reloadToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.groupBoxEvents = new System.Windows.Forms.GroupBox();
            this.gridViewEvents = new System.Windows.Forms.DataGridView();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.toggleAuthorizeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer)).BeginInit();
            this.splitContainer.Panel1.SuspendLayout();
            this.splitContainer.Panel2.SuspendLayout();
            this.splitContainer.SuspendLayout();
            this.groupBoxThings.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.gridViewThings)).BeginInit();
            this.contextMenuStripThings.SuspendLayout();
            this.groupBoxEvents.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.gridViewEvents)).BeginInit();
            this.SuspendLayout();
            // 
            // splitContainer
            // 
            this.splitContainer.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer.Location = new System.Drawing.Point(0, 0);
            this.splitContainer.Name = "splitContainer";
            this.splitContainer.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // splitContainer.Panel1
            // 
            this.splitContainer.Panel1.Controls.Add(this.groupBoxThings);
            // 
            // splitContainer.Panel2
            // 
            this.splitContainer.Panel2.Controls.Add(this.groupBoxEvents);
            this.splitContainer.Size = new System.Drawing.Size(744, 517);
            this.splitContainer.SplitterDistance = 248;
            this.splitContainer.TabIndex = 1;
            // 
            // groupBoxThings
            // 
            this.groupBoxThings.Controls.Add(this.gridViewThings);
            this.groupBoxThings.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBoxThings.Location = new System.Drawing.Point(0, 0);
            this.groupBoxThings.Name = "groupBoxThings";
            this.groupBoxThings.Size = new System.Drawing.Size(744, 248);
            this.groupBoxThings.TabIndex = 1;
            this.groupBoxThings.TabStop = false;
            this.groupBoxThings.Text = "My Things";
            // 
            // gridViewThings
            // 
            this.gridViewThings.AllowUserToAddRows = false;
            dataGridViewCellStyle1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(220)))), ((int)(((byte)(255)))), ((int)(((byte)(255)))));
            this.gridViewThings.AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
            this.gridViewThings.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.DisplayedCells;
            this.gridViewThings.AutoSizeRowsMode = System.Windows.Forms.DataGridViewAutoSizeRowsMode.AllCells;
            this.gridViewThings.BackgroundColor = System.Drawing.SystemColors.ControlLightLight;
            this.gridViewThings.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.gridViewThings.ColumnHeadersBorderStyle = System.Windows.Forms.DataGridViewHeaderBorderStyle.Single;
            dataGridViewCellStyle2.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle2.BackColor = System.Drawing.SystemColors.ControlLightLight;
            dataGridViewCellStyle2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle2.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle2.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle2.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle2.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.gridViewThings.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
            this.gridViewThings.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.gridViewThings.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.ColumnImage});
            this.gridViewThings.ContextMenuStrip = this.contextMenuStripThings;
            this.gridViewThings.Dock = System.Windows.Forms.DockStyle.Fill;
            this.gridViewThings.EditMode = System.Windows.Forms.DataGridViewEditMode.EditProgrammatically;
            this.gridViewThings.Location = new System.Drawing.Point(3, 16);
            this.gridViewThings.MultiSelect = false;
            this.gridViewThings.Name = "gridViewThings";
            this.gridViewThings.ReadOnly = true;
            this.gridViewThings.RowHeadersVisible = false;
            this.gridViewThings.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.gridViewThings.ShowCellErrors = false;
            this.gridViewThings.ShowEditingIcon = false;
            this.gridViewThings.ShowRowErrors = false;
            this.gridViewThings.Size = new System.Drawing.Size(738, 229);
            this.gridViewThings.TabIndex = 0;
            this.gridViewThings.CellDoubleClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.gridViewDevices_CellDoubleClick);
            this.gridViewThings.RowEnter += new System.Windows.Forms.DataGridViewCellEventHandler(this.gridViewDevices_RowEnter);
            this.gridViewThings.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.gridViewThings_KeyPress);
            // 
            // ColumnImage
            // 
            this.ColumnImage.HeaderText = "";
            this.ColumnImage.Name = "ColumnImage";
            this.ColumnImage.ReadOnly = true;
            this.ColumnImage.Width = 5;
            // 
            // contextMenuStripThings
            // 
            this.contextMenuStripThings.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.editToolStripMenuItem,
            this.toolStripMenuItem1,
            this.deleteAllToolStripMenuItem,
            this.toolStripSeparator1,
            this.reloadToolStripMenuItem,
            this.toolStripSeparator2,
            this.toggleAuthorizeToolStripMenuItem});
            this.contextMenuStripThings.Name = "contextMenuStripThings";
            this.contextMenuStripThings.Size = new System.Drawing.Size(166, 126);
            // 
            // editToolStripMenuItem
            // 
            this.editToolStripMenuItem.Name = "editToolStripMenuItem";
            this.editToolStripMenuItem.Size = new System.Drawing.Size(165, 22);
            this.editToolStripMenuItem.Text = "Edit";
            this.editToolStripMenuItem.Click += new System.EventHandler(this.editToolStripMenuItem_Click);
            // 
            // toolStripMenuItem1
            // 
            this.toolStripMenuItem1.Name = "toolStripMenuItem1";
            this.toolStripMenuItem1.Size = new System.Drawing.Size(165, 22);
            this.toolStripMenuItem1.Text = "Delete";
            this.toolStripMenuItem1.Click += new System.EventHandler(this.toolStripMenuItem1_Click);
            // 
            // deleteAllToolStripMenuItem
            // 
            this.deleteAllToolStripMenuItem.Name = "deleteAllToolStripMenuItem";
            this.deleteAllToolStripMenuItem.Size = new System.Drawing.Size(165, 22);
            this.deleteAllToolStripMenuItem.Text = "Delete All";
            this.deleteAllToolStripMenuItem.Click += new System.EventHandler(this.deleteAllToolStripMenuItem_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(162, 6);
            // 
            // reloadToolStripMenuItem
            // 
            this.reloadToolStripMenuItem.Name = "reloadToolStripMenuItem";
            this.reloadToolStripMenuItem.Size = new System.Drawing.Size(165, 22);
            this.reloadToolStripMenuItem.Text = "Reload";
            this.reloadToolStripMenuItem.Click += new System.EventHandler(this.reloadToolStripMenuItem_Click);
            // 
            // groupBoxEvents
            // 
            this.groupBoxEvents.Controls.Add(this.gridViewEvents);
            this.groupBoxEvents.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBoxEvents.Location = new System.Drawing.Point(0, 0);
            this.groupBoxEvents.Name = "groupBoxEvents";
            this.groupBoxEvents.Size = new System.Drawing.Size(744, 265);
            this.groupBoxEvents.TabIndex = 1;
            this.groupBoxEvents.TabStop = false;
            this.groupBoxEvents.Text = "My Events";
            // 
            // gridViewEvents
            // 
            this.gridViewEvents.AllowUserToAddRows = false;
            dataGridViewCellStyle3.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(220)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.gridViewEvents.AlternatingRowsDefaultCellStyle = dataGridViewCellStyle3;
            this.gridViewEvents.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.AllCells;
            this.gridViewEvents.AutoSizeRowsMode = System.Windows.Forms.DataGridViewAutoSizeRowsMode.AllCells;
            this.gridViewEvents.BackgroundColor = System.Drawing.SystemColors.ControlLightLight;
            this.gridViewEvents.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.gridViewEvents.ColumnHeadersBorderStyle = System.Windows.Forms.DataGridViewHeaderBorderStyle.Single;
            dataGridViewCellStyle4.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle4.BackColor = System.Drawing.SystemColors.ControlLightLight;
            dataGridViewCellStyle4.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle4.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle4.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle4.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle4.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.gridViewEvents.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle4;
            this.gridViewEvents.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.gridViewEvents.Dock = System.Windows.Forms.DockStyle.Fill;
            this.gridViewEvents.Location = new System.Drawing.Point(3, 16);
            this.gridViewEvents.Name = "gridViewEvents";
            this.gridViewEvents.ReadOnly = true;
            this.gridViewEvents.RowHeadersVisible = false;
            this.gridViewEvents.ShowCellErrors = false;
            this.gridViewEvents.ShowEditingIcon = false;
            this.gridViewEvents.ShowRowErrors = false;
            this.gridViewEvents.Size = new System.Drawing.Size(738, 246);
            this.gridViewEvents.TabIndex = 0;
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(162, 6);
            // 
            // toggleAuthorizeToolStripMenuItem
            // 
            this.toggleAuthorizeToolStripMenuItem.Name = "toggleAuthorizeToolStripMenuItem";
            this.toggleAuthorizeToolStripMenuItem.Size = new System.Drawing.Size(165, 22);
            this.toggleAuthorizeToolStripMenuItem.Text = "Toggle Authorize";
            // 
            // ThingsControl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.splitContainer);
            this.Name = "ThingsControl";
            this.Size = new System.Drawing.Size(744, 517);
            this.splitContainer.Panel1.ResumeLayout(false);
            this.splitContainer.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer)).EndInit();
            this.splitContainer.ResumeLayout(false);
            this.groupBoxThings.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.gridViewThings)).EndInit();
            this.contextMenuStripThings.ResumeLayout(false);
            this.groupBoxEvents.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.gridViewEvents)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.SplitContainer splitContainer;
        private System.Windows.Forms.GroupBox groupBoxThings;
        private System.Windows.Forms.DataGridView gridViewThings;
        private System.Windows.Forms.DataGridViewImageColumn ColumnImage;
        private System.Windows.Forms.GroupBox groupBoxEvents;
        private System.Windows.Forms.DataGridView gridViewEvents;
        private System.Windows.Forms.ContextMenuStrip contextMenuStripThings;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem deleteAllToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem editToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripMenuItem reloadToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStripMenuItem toggleAuthorizeToolStripMenuItem;

    }
}
