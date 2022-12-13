namespace Курсач
{
    partial class Form2
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
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.decrypt_text = new System.Windows.Forms.RichTextBox();
            this.encrypt_text = new System.Windows.Forms.RichTextBox();
            this.Decrypt = new System.Windows.Forms.Button();
            this.Encrypt = new System.Windows.Forms.Button();
            this.Cryptoprotocol = new System.Windows.Forms.ComboBox();
            this.label3 = new System.Windows.Forms.Label();
            this.Encrypt_to_file = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.CryptoKey = new System.Windows.Forms.RichTextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.Exit = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(35, 33);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(229, 31);
            this.label1.TabIndex = 0;
            this.label1.Text = "Исходный текст";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label2.Location = new System.Drawing.Point(709, 33);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(296, 31);
            this.label2.TabIndex = 1;
            this.label2.Text = "Шифрованный текст ";
            // 
            // decrypt_text
            // 
            this.decrypt_text.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.decrypt_text.Location = new System.Drawing.Point(41, 105);
            this.decrypt_text.Margin = new System.Windows.Forms.Padding(4);
            this.decrypt_text.Name = "decrypt_text";
            this.decrypt_text.Size = new System.Drawing.Size(313, 504);
            this.decrypt_text.TabIndex = 4;
            this.decrypt_text.Text = "";
            // 
            // encrypt_text
            // 
            this.encrypt_text.BackColor = System.Drawing.SystemColors.Window;
            this.encrypt_text.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.encrypt_text.Location = new System.Drawing.Point(716, 105);
            this.encrypt_text.Margin = new System.Windows.Forms.Padding(4);
            this.encrypt_text.Name = "encrypt_text";
            this.encrypt_text.Size = new System.Drawing.Size(313, 504);
            this.encrypt_text.TabIndex = 5;
            this.encrypt_text.Text = "";
            this.encrypt_text.TextChanged += new System.EventHandler(this.encrypt_text_TextChanged);
            // 
            // Decrypt
            // 
            this.Decrypt.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Decrypt.Location = new System.Drawing.Point(429, 542);
            this.Decrypt.Margin = new System.Windows.Forms.Padding(4);
            this.Decrypt.Name = "Decrypt";
            this.Decrypt.Size = new System.Drawing.Size(219, 68);
            this.Decrypt.TabIndex = 6;
            this.Decrypt.Text = "Расшифровать";
            this.Decrypt.UseVisualStyleBackColor = true;
            this.Decrypt.Click += new System.EventHandler(this.Decrypt_Click);
            // 
            // Encrypt
            // 
            this.Encrypt.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Encrypt.Location = new System.Drawing.Point(429, 466);
            this.Encrypt.Margin = new System.Windows.Forms.Padding(4);
            this.Encrypt.Name = "Encrypt";
            this.Encrypt.Size = new System.Drawing.Size(219, 68);
            this.Encrypt.TabIndex = 7;
            this.Encrypt.Text = "Зашифровать";
            this.Encrypt.UseVisualStyleBackColor = true;
            this.Encrypt.Click += new System.EventHandler(this.Encrypt_Click);
            // 
            // Cryptoprotocol
            // 
            this.Cryptoprotocol.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Cryptoprotocol.FormattingEnabled = true;
            this.Cryptoprotocol.Location = new System.Drawing.Point(429, 161);
            this.Cryptoprotocol.Margin = new System.Windows.Forms.Padding(4);
            this.Cryptoprotocol.Name = "Cryptoprotocol";
            this.Cryptoprotocol.Size = new System.Drawing.Size(219, 37);
            this.Cryptoprotocol.TabIndex = 8;
            this.Cryptoprotocol.SelectedIndexChanged += new System.EventHandler(this.comboBox1_SelectedIndexChanged);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label3.Location = new System.Drawing.Point(451, 109);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(171, 29);
            this.label3.TabIndex = 9;
            this.label3.Text = "Cryptoprotocol";
            // 
            // Encrypt_to_file
            // 
            this.Encrypt_to_file.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Encrypt_to_file.Location = new System.Drawing.Point(716, 634);
            this.Encrypt_to_file.Margin = new System.Windows.Forms.Padding(4);
            this.Encrypt_to_file.Name = "Encrypt_to_file";
            this.Encrypt_to_file.Size = new System.Drawing.Size(315, 68);
            this.Encrypt_to_file.TabIndex = 11;
            this.Encrypt_to_file.Text = "Записать в файл";
            this.Encrypt_to_file.UseVisualStyleBackColor = true;
            // 
            // button1
            // 
            this.button1.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.button1.Location = new System.Drawing.Point(41, 647);
            this.button1.Margin = new System.Windows.Forms.Padding(4);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(315, 68);
            this.button1.TabIndex = 12;
            this.button1.Text = "Записать в файл";
            this.button1.UseVisualStyleBackColor = true;
            // 
            // CryptoKey
            // 
            this.CryptoKey.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.CryptoKey.Location = new System.Drawing.Point(429, 280);
            this.CryptoKey.Name = "CryptoKey";
            this.CryptoKey.Size = new System.Drawing.Size(219, 130);
            this.CryptoKey.TabIndex = 13;
            this.CryptoKey.Text = "";
            this.CryptoKey.TextChanged += new System.EventHandler(this.CryptoKey_TextChanged);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label4.Location = new System.Drawing.Point(471, 248);
            this.label4.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(130, 29);
            this.label4.TabIndex = 14;
            this.label4.Text = "Crypto Key";
            // 
            // Exit
            // 
            this.Exit.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Exit.Location = new System.Drawing.Point(845, 746);
            this.Exit.Margin = new System.Windows.Forms.Padding(4);
            this.Exit.Name = "Exit";
            this.Exit.Size = new System.Drawing.Size(184, 53);
            this.Exit.TabIndex = 15;
            this.Exit.Text = "Exit";
            this.Exit.UseVisualStyleBackColor = true;
            this.Exit.Click += new System.EventHandler(this.Exit_Click);
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.ClientSize = new System.Drawing.Size(1067, 812);
            this.Controls.Add(this.Exit);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.CryptoKey);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.Encrypt_to_file);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.Cryptoprotocol);
            this.Controls.Add(this.Encrypt);
            this.Controls.Add(this.Decrypt);
            this.Controls.Add(this.encrypt_text);
            this.Controls.Add(this.decrypt_text);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "Form2";
            this.Text = "Шифровка/Дешифровка";
            this.Load += new System.EventHandler(this.Form2_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.RichTextBox decrypt_text;
        private System.Windows.Forms.RichTextBox encrypt_text;
        private System.Windows.Forms.Button Decrypt;
        private System.Windows.Forms.Button Encrypt;
        private System.Windows.Forms.ComboBox Cryptoprotocol;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button Encrypt_to_file;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.RichTextBox CryptoKey;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button Exit;
    }
}