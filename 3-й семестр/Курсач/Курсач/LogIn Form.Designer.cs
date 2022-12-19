namespace Курсач
{
    partial class LogInForm
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.Login = new System.Windows.Forms.Button();
            this.User_name = new System.Windows.Forms.TextBox();
            this.User_pass = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.Exit = new System.Windows.Forms.Button();
            this.checkPass = new System.Windows.Forms.CheckBox();
            this.SuspendLayout();
            // 
            // Login
            // 
            this.Login.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Login.Location = new System.Drawing.Point(32, 343);
            this.Login.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Login.Name = "Login";
            this.Login.Size = new System.Drawing.Size(184, 53);
            this.Login.TabIndex = 1;
            this.Login.Text = "LogIn";
            this.Login.UseVisualStyleBackColor = true;
            this.Login.Click += new System.EventHandler(this.Login_Click);
            // 
            // User_name
            // 
            this.User_name.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.User_name.Location = new System.Drawing.Point(32, 111);
            this.User_name.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.User_name.Name = "User_name";
            this.User_name.Size = new System.Drawing.Size(601, 36);
            this.User_name.TabIndex = 2;
            this.User_name.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // User_pass
            // 
            this.User_pass.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.User_pass.Location = new System.Drawing.Point(32, 235);
            this.User_pass.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.User_pass.Name = "User_pass";
            this.User_pass.Size = new System.Drawing.Size(601, 36);
            this.User_pass.TabIndex = 3;
            this.User_pass.TextChanged += new System.EventHandler(this.textBox2_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(24, 58);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(174, 39);
            this.label1.TabIndex = 4;
            this.label1.Text = "Username";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label2.Location = new System.Drawing.Point(24, 175);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(167, 39);
            this.label2.TabIndex = 5;
            this.label2.Text = "Password";
            // 
            // Exit
            // 
            this.Exit.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Exit.Location = new System.Drawing.Point(260, 343);
            this.Exit.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Exit.Name = "Exit";
            this.Exit.Size = new System.Drawing.Size(184, 53);
            this.Exit.TabIndex = 6;
            this.Exit.Text = "Exit";
            this.Exit.UseVisualStyleBackColor = true;
            this.Exit.Click += new System.EventHandler(this.button2_Click);
            // 
            // checkPass
            // 
            this.checkPass.AutoSize = true;
            this.checkPass.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.checkPass.Location = new System.Drawing.Point(449, 279);
            this.checkPass.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.checkPass.Name = "checkPass";
            this.checkPass.Size = new System.Drawing.Size(177, 24);
            this.checkPass.TabIndex = 7;
            this.checkPass.Text = "Показать пароль";
            this.checkPass.UseVisualStyleBackColor = true;
            this.checkPass.CheckedChanged += new System.EventHandler(this.checkBox1_CheckedChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(675, 428);
            this.Controls.Add(this.checkPass);
            this.Controls.Add(this.Exit);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.User_pass);
            this.Controls.Add(this.User_name);
            this.Controls.Add(this.Login);
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "Form1";
            this.Text = "Логин";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button Login;
        private System.Windows.Forms.TextBox User_name;
        private System.Windows.Forms.TextBox User_pass;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button Exit;
        private System.Windows.Forms.CheckBox checkPass;
    }
}

