namespace Курсач
{
    partial class CryptoProtocolForm
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
            this.Decrypt_to_file = new System.Windows.Forms.Button();
            this.CryptoKey1 = new System.Windows.Forms.RichTextBox();
            this.Exit = new System.Windows.Forms.Button();
            this.CryptoKey2 = new System.Windows.Forms.RichTextBox();
            this.Key2 = new System.Windows.Forms.Label();
            this.Key1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(26, 27);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(186, 25);
            this.label1.TabIndex = 0;
            this.label1.Text = "Исходный текст";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label2.Location = new System.Drawing.Point(532, 27);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(241, 25);
            this.label2.TabIndex = 1;
            this.label2.Text = "Шифрованный текст ";
            // 
            // decrypt_text
            // 
            this.decrypt_text.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.decrypt_text.Location = new System.Drawing.Point(31, 85);
            this.decrypt_text.Name = "decrypt_text";
            this.decrypt_text.Size = new System.Drawing.Size(236, 410);
            this.decrypt_text.TabIndex = 4;
            this.decrypt_text.Text = "";
            // 
            // encrypt_text
            // 
            this.encrypt_text.BackColor = System.Drawing.SystemColors.Window;
            this.encrypt_text.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.encrypt_text.Location = new System.Drawing.Point(537, 85);
            this.encrypt_text.Name = "encrypt_text";
            this.encrypt_text.Size = new System.Drawing.Size(236, 410);
            this.encrypt_text.TabIndex = 5;
            this.encrypt_text.Text = "";
            this.encrypt_text.TextChanged += new System.EventHandler(this.encrypt_text_TextChanged);
            this.encrypt_text.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.encrypt_text_KeyPress);
            // 
            // Decrypt
            // 
            this.Decrypt.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Decrypt.Location = new System.Drawing.Point(323, 526);
            this.Decrypt.Name = "Decrypt";
            this.Decrypt.Size = new System.Drawing.Size(164, 55);
            this.Decrypt.TabIndex = 6;
            this.Decrypt.Text = "Расшифровать";
            this.Decrypt.UseVisualStyleBackColor = true;
            this.Decrypt.Click += new System.EventHandler(this.Decrypt_Click);
            // 
            // Encrypt
            // 
            this.Encrypt.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Encrypt.Location = new System.Drawing.Point(323, 465);
            this.Encrypt.Name = "Encrypt";
            this.Encrypt.Size = new System.Drawing.Size(164, 55);
            this.Encrypt.TabIndex = 7;
            this.Encrypt.Text = "Зашифровать";
            this.Encrypt.UseVisualStyleBackColor = true;
            this.Encrypt.Click += new System.EventHandler(this.Encrypt_Click);
            // 
            // Cryptoprotocol
            // 
            this.Cryptoprotocol.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.Cryptoprotocol.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Cryptoprotocol.FormattingEnabled = true;
            this.Cryptoprotocol.Location = new System.Drawing.Point(322, 85);
            this.Cryptoprotocol.Name = "Cryptoprotocol";
            this.Cryptoprotocol.Size = new System.Drawing.Size(165, 32);
            this.Cryptoprotocol.TabIndex = 8;
            this.Cryptoprotocol.SelectedIndexChanged += new System.EventHandler(this.comboBox1_SelectedIndexChanged);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label3.Location = new System.Drawing.Point(338, 43);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(132, 24);
            this.label3.TabIndex = 9;
            this.label3.Text = "Cryptoprotocol";
            // 
            // Encrypt_to_file
            // 
            this.Encrypt_to_file.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Encrypt_to_file.Location = new System.Drawing.Point(552, 526);
            this.Encrypt_to_file.Name = "Encrypt_to_file";
            this.Encrypt_to_file.Size = new System.Drawing.Size(236, 55);
            this.Encrypt_to_file.TabIndex = 11;
            this.Encrypt_to_file.Text = "Записать в файл";
            this.Encrypt_to_file.UseVisualStyleBackColor = true;
            this.Encrypt_to_file.Click += new System.EventHandler(this.Encrypt_to_file_Click);
            // 
            // Decrypt_to_file
            // 
            this.Decrypt_to_file.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Decrypt_to_file.Location = new System.Drawing.Point(31, 526);
            this.Decrypt_to_file.Name = "Decrypt_to_file";
            this.Decrypt_to_file.Size = new System.Drawing.Size(236, 55);
            this.Decrypt_to_file.TabIndex = 12;
            this.Decrypt_to_file.Text = "Записать в файл";
            this.Decrypt_to_file.UseVisualStyleBackColor = true;
            this.Decrypt_to_file.Click += new System.EventHandler(this.button1_Click);
            // 
            // CryptoKey1
            // 
            this.CryptoKey1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.CryptoKey1.Location = new System.Drawing.Point(322, 284);
            this.CryptoKey1.Margin = new System.Windows.Forms.Padding(2);
            this.CryptoKey1.Name = "CryptoKey1";
            this.CryptoKey1.Size = new System.Drawing.Size(165, 64);
            this.CryptoKey1.TabIndex = 13;
            this.CryptoKey1.Text = "";
            this.CryptoKey1.TextChanged += new System.EventHandler(this.CryptoKey_TextChanged);
            this.CryptoKey1.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.CryptoKey1_KeyPress);
            // 
            // Exit
            // 
            this.Exit.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Exit.Location = new System.Drawing.Point(634, 606);
            this.Exit.Name = "Exit";
            this.Exit.Size = new System.Drawing.Size(138, 43);
            this.Exit.TabIndex = 15;
            this.Exit.Text = "Exit";
            this.Exit.UseVisualStyleBackColor = true;
            this.Exit.Click += new System.EventHandler(this.Exit_Click);
            // 
            // CryptoKey2
            // 
            this.CryptoKey2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.CryptoKey2.Location = new System.Drawing.Point(322, 387);
            this.CryptoKey2.Margin = new System.Windows.Forms.Padding(2);
            this.CryptoKey2.Name = "CryptoKey2";
            this.CryptoKey2.Size = new System.Drawing.Size(165, 64);
            this.CryptoKey2.TabIndex = 16;
            this.CryptoKey2.Text = "";
            this.CryptoKey2.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.CryptoKey2_KeyPress);
            // 
            // Key2
            // 
            this.Key2.AutoSize = true;
            this.Key2.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Key2.Location = new System.Drawing.Point(367, 361);
            this.Key2.Name = "Key2";
            this.Key2.Size = new System.Drawing.Size(0, 24);
            this.Key2.TabIndex = 17;
            this.Key2.Click += new System.EventHandler(this.label5_Click);
            // 
            // Key1
            // 
            this.Key1.AutoSize = true;
            this.Key1.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Key1.Location = new System.Drawing.Point(367, 258);
            this.Key1.Name = "Key1";
            this.Key1.Size = new System.Drawing.Size(0, 24);
            this.Key1.TabIndex = 18;
            // 
            // CryptoProtocolForm
            // 
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.None;
            this.AutoSize = true;
            this.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.ClientSize = new System.Drawing.Size(821, 660);
            this.Controls.Add(this.Key1);
            this.Controls.Add(this.Key2);
            this.Controls.Add(this.CryptoKey2);
            this.Controls.Add(this.Exit);
            this.Controls.Add(this.CryptoKey1);
            this.Controls.Add(this.Decrypt_to_file);
            this.Controls.Add(this.Encrypt_to_file);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.Cryptoprotocol);
            this.Controls.Add(this.Encrypt);
            this.Controls.Add(this.Decrypt);
            this.Controls.Add(this.encrypt_text);
            this.Controls.Add(this.decrypt_text);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.MaximizeBox = false;
            this.Name = "CryptoProtocolForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.WindowsDefaultBounds;
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
        private System.Windows.Forms.Button Decrypt_to_file;
        private System.Windows.Forms.RichTextBox CryptoKey1;
        private System.Windows.Forms.Button Exit;
        private System.Windows.Forms.RichTextBox CryptoKey2;
        private System.Windows.Forms.Label Key2;
        private System.Windows.Forms.Label Key1;
    }
}