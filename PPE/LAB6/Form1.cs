using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using WP_LAB_6;

namespace Lab6
{
    public partial class Form1 : Form
    {

        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            string text = richTextBox1.Text;
            richTextBox2.Text += text;
            richTextBox2.Text += " ";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            richTextBox2.Clear();
        }

        private void richTextBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {
       
        }

        private void button3_Click(object sender, EventArgs e)
        {
            richTextBox2.ForeColor = Color.Red;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            richTextBox2.ForeColor = Color.Green;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            richTextBox2.ForeColor = Color.Blue;
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
           DialogResult dr = MessageBox.Show("Do you want to close the program?", "Alert", MessageBoxButtons.YesNo, MessageBoxIcon.Warning);
           if (dr == DialogResult.No)
           {
               e.Cancel = true;
           }
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click_1(object sender, EventArgs e)
        {

        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void changeBkgColorToolStripMenuItem_Click(object sender, EventArgs e)
        {
            changeBkgColor();
        }

        private void aboutToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            Form2 dialog = new Form2();
            dialog.ShowDialog();
        }

        protected override bool ProcessCmdKey(ref Message msg, Keys keyData)
        {
            if (keyData == (Keys.Control | Keys.Space))
            {
                changeBkgColor();
                return true;
            }

            if (keyData == (Keys.Control | Keys.W))
            {
                this.Close();
                return true;
            }

            if (keyData == (Keys.F12))
            {
                Form2 dialog = new Form2();
                dialog.ShowDialog();
                return true;
            }
            return base.ProcessCmdKey(ref msg, keyData);
        }

        private void changeBkgColor()
        {
            int red, green, blue;
            Random rnd = new Random();
            red = rnd.Next(0, 256);
            green = rnd.Next(0, 256);
            blue = rnd.Next(0, 256);
            this.BackColor = Color.FromArgb(red, green, blue);
        }
    }
}
