using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CourseWork
{
    public partial class Form1 : Form
    {
        private Grid grid;
        GridControl controller;

        enum buttonOption { none, select_vert}
        buttonOption mouseNow;

        public Form1(Grid grid)
        {
            this.grid = grid;
            InitializeComponent();
            this.controller = new GridControl(this, grid, pictureBox1.Width, pictureBox1.Height);
            pictureBox1.Image = controller.GetBitmap();
            mouseNow = buttonOption.none;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                int n = Convert.ToInt32(this.textBox1.Text);
                grid.reshape_grid(n);
                controller.drawGrid();
                pictureBox1.Image = controller.GetBitmap();
            }
            catch
            {
                MessageBox.Show("Задайте коректный размер!");
            }
            
        }

        private void button2_Click(object sender, EventArgs e)
        {
            mouseNow = buttonOption.select_vert;
        }

        private void pictureBox1_MouseClick(object sender, MouseEventArgs e)
        {
            switch (mouseNow)
            {
                case buttonOption.select_vert:
                    controller.selectMainVert(e.X, e.Y);
                    pictureBox1.Image = controller.GetBitmap();
                    mouseNow = buttonOption.none;
                    break;
            }
        }
    }
}
