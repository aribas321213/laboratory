using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab_1
{
    public partial class Result : Form
    {
        public Result()
        {
            InitializeComponent();
        }
        public Result(string r)
        {
            InitializeComponent();
            this.textBox2.Text = r;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
