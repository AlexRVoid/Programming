namespace Lab3Sharp
{
    partial class MainWindow
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.Product = new System.Windows.Forms.GroupBox();
            this.Add_product = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.product_quantity_info = new System.Windows.Forms.TextBox();
            this.warehouse_cell_info = new System.Windows.Forms.TextBox();
            this.product_id_info = new System.Windows.Forms.TextBox();
            this.product_info = new System.Windows.Forms.TextBox();
            this.Serialization = new System.Windows.Forms.Label();
            this.Deserialization = new System.Windows.Forms.Label();
            this.Serialization_Type = new System.Windows.Forms.ComboBox();
            this.Deserialization_Type = new System.Windows.Forms.ComboBox();
            this.Serialize = new System.Windows.Forms.Button();
            this.Deserialize = new System.Windows.Forms.Button();
            this.listProduct = new System.Windows.Forms.ListView();
            this.Product.SuspendLayout();
            this.SuspendLayout();
            // 
            // Product
            // 
            this.Product.Controls.Add(this.Add_product);
            this.Product.Controls.Add(this.label4);
            this.Product.Controls.Add(this.label3);
            this.Product.Controls.Add(this.label2);
            this.Product.Controls.Add(this.label1);
            this.Product.Controls.Add(this.product_quantity_info);
            this.Product.Controls.Add(this.warehouse_cell_info);
            this.Product.Controls.Add(this.product_id_info);
            this.Product.Controls.Add(this.product_info);
            this.Product.Location = new System.Drawing.Point(389, 38);
            this.Product.Name = "Product";
            this.Product.Size = new System.Drawing.Size(435, 369);
            this.Product.TabIndex = 1;
            this.Product.TabStop = false;
            this.Product.Text = "Product";
            // 
            // Add_product
            // 
            this.Add_product.Font = new System.Drawing.Font("Arial", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.Add_product.Location = new System.Drawing.Point(320, 312);
            this.Add_product.Name = "Add_product";
            this.Add_product.Size = new System.Drawing.Size(94, 41);
            this.Add_product.TabIndex = 8;
            this.Add_product.Text = "Add";
            this.Add_product.UseVisualStyleBackColor = true;
            this.Add_product.Click += new System.EventHandler(this.Add_product_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Arial", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.label4.Location = new System.Drawing.Point(26, 241);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(177, 22);
            this.label4.TabIndex = 7;
            this.label4.Text = "Количество товара";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Arial", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.label3.Location = new System.Drawing.Point(26, 164);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(137, 22);
            this.label3.TabIndex = 6;
            this.label3.Text = "Ячейка склада";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Arial", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.label2.Location = new System.Drawing.Point(26, 90);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(193, 44);
            this.label2.TabIndex = 5;
            this.label2.Text = "Индитификационный\r\nномер товара";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Arial", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.label1.Location = new System.Drawing.Point(26, 20);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(63, 22);
            this.label1.TabIndex = 4;
            this.label1.Text = "Товар";
            // 
            // product_quantity_info
            // 
            this.product_quantity_info.Font = new System.Drawing.Font("Arial", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.product_quantity_info.Location = new System.Drawing.Point(231, 241);
            this.product_quantity_info.Multiline = true;
            this.product_quantity_info.Name = "product_quantity_info";
            this.product_quantity_info.Size = new System.Drawing.Size(183, 51);
            this.product_quantity_info.TabIndex = 3;
            // 
            // warehouse_cell_info
            // 
            this.warehouse_cell_info.Font = new System.Drawing.Font("Arial", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.warehouse_cell_info.Location = new System.Drawing.Point(231, 164);
            this.warehouse_cell_info.Multiline = true;
            this.warehouse_cell_info.Name = "warehouse_cell_info";
            this.warehouse_cell_info.Size = new System.Drawing.Size(183, 51);
            this.warehouse_cell_info.TabIndex = 2;
            // 
            // product_id_info
            // 
            this.product_id_info.Font = new System.Drawing.Font("Arial", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.product_id_info.Location = new System.Drawing.Point(231, 90);
            this.product_id_info.Multiline = true;
            this.product_id_info.Name = "product_id_info";
            this.product_id_info.Size = new System.Drawing.Size(183, 51);
            this.product_id_info.TabIndex = 1;
            // 
            // product_info
            // 
            this.product_info.Font = new System.Drawing.Font("Arial", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.product_info.Location = new System.Drawing.Point(231, 20);
            this.product_info.Multiline = true;
            this.product_info.Name = "product_info";
            this.product_info.Size = new System.Drawing.Size(183, 51);
            this.product_info.TabIndex = 0;
            // 
            // Serialization
            // 
            this.Serialization.AutoSize = true;
            this.Serialization.Font = new System.Drawing.Font("Arial", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.Serialization.Location = new System.Drawing.Point(389, 437);
            this.Serialization.Name = "Serialization";
            this.Serialization.Size = new System.Drawing.Size(111, 22);
            this.Serialization.TabIndex = 5;
            this.Serialization.Text = "Serialization";
            // 
            // Deserialization
            // 
            this.Deserialization.AutoSize = true;
            this.Deserialization.Font = new System.Drawing.Font("Arial", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.Deserialization.Location = new System.Drawing.Point(389, 512);
            this.Deserialization.Name = "Deserialization";
            this.Deserialization.Size = new System.Drawing.Size(133, 22);
            this.Deserialization.TabIndex = 6;
            this.Deserialization.Text = "Deserialization";
            // 
            // Serialization_Type
            // 
            this.Serialization_Type.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.Serialization_Type.Font = new System.Drawing.Font("Arial", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.Serialization_Type.FormattingEnabled = true;
            this.Serialization_Type.Location = new System.Drawing.Point(550, 437);
            this.Serialization_Type.Name = "Serialization_Type";
            this.Serialization_Type.Size = new System.Drawing.Size(172, 30);
            this.Serialization_Type.TabIndex = 7;
            // 
            // Deserialization_Type
            // 
            this.Deserialization_Type.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.Deserialization_Type.Font = new System.Drawing.Font("Arial", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.Deserialization_Type.FormattingEnabled = true;
            this.Deserialization_Type.Location = new System.Drawing.Point(550, 512);
            this.Deserialization_Type.Name = "Deserialization_Type";
            this.Deserialization_Type.Size = new System.Drawing.Size(172, 30);
            this.Deserialization_Type.TabIndex = 8;
            // 
            // Serialize
            // 
            this.Serialize.Font = new System.Drawing.Font("Arial", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.Serialize.Location = new System.Drawing.Point(737, 437);
            this.Serialize.Name = "Serialize";
            this.Serialize.Size = new System.Drawing.Size(114, 30);
            this.Serialize.TabIndex = 9;
            this.Serialize.Text = "Serialize";
            this.Serialize.UseVisualStyleBackColor = true;
            this.Serialize.Click += new System.EventHandler(this.Serialize_Click);
            // 
            // Deserialize
            // 
            this.Deserialize.Font = new System.Drawing.Font("Arial", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.Deserialize.Location = new System.Drawing.Point(737, 512);
            this.Deserialize.Name = "Deserialize";
            this.Deserialize.Size = new System.Drawing.Size(114, 30);
            this.Deserialize.TabIndex = 10;
            this.Deserialize.Text = "Deserialize";
            this.Deserialize.UseVisualStyleBackColor = true;
            this.Deserialize.Click += new System.EventHandler(this.Deserialize_Click);
            // 
            // listProduct
            // 
            this.listProduct.Font = new System.Drawing.Font("Arial", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.listProduct.Location = new System.Drawing.Point(21, 38);
            this.listProduct.Name = "listProduct";
            this.listProduct.Size = new System.Drawing.Size(316, 504);
            this.listProduct.TabIndex = 11;
            this.listProduct.UseCompatibleStateImageBehavior = false;
            this.listProduct.View = System.Windows.Forms.View.List;
            this.listProduct.SelectedIndexChanged += new System.EventHandler(this.listProduct_SelectedIndexChanged);
            // 
            // MainWindow
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ControlDark;
            this.ClientSize = new System.Drawing.Size(863, 582);
            this.Controls.Add(this.listProduct);
            this.Controls.Add(this.Deserialize);
            this.Controls.Add(this.Serialize);
            this.Controls.Add(this.Deserialization_Type);
            this.Controls.Add(this.Serialization_Type);
            this.Controls.Add(this.Deserialization);
            this.Controls.Add(this.Serialization);
            this.Controls.Add(this.Product);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.Name = "MainWindow";
            this.Text = "Учёт товаров на складе";
            this.Load += new System.EventHandler(this.MainWindow_Load);
            this.Product.ResumeLayout(false);
            this.Product.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private GroupBox Product;
        private Label label4;
        private Label label3;
        private Label label2;
        private Label label1;
        private TextBox product_quantity_info;
        private TextBox warehouse_cell_info;
        private TextBox product_id_info;
        private TextBox product_info;
        private Label Serialization;
        private Label Deserialization;
        private ComboBox Serialization_Type;
        private ComboBox Deserialization_Type;
        private Button Serialize;
        private Button Deserialize;
        private Button Add_product;
        private ListView listProduct;
    }
}