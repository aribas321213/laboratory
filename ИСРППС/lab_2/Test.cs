using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Reflection.Emit;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab_2
{
    public partial class Test : Form
    {
        public bool is_open = true;
        public Test()
        {

            InitializeComponent();
        }

        public Test(int p, string name, string surname, string patronymic )
        {

            InitializeComponent();
            label3.Text = name;
            label2.Text = surname;
            label4.Text = patronymic;
            switch (p)
            {
                case 7: label6.Text = "Оценка: 5";break;
                case 6: label6.Text = "Оценка: 5-"; break;
                case 5: label6.Text = "Оценка: 4"; break;
                case 4: label6.Text = "Оценка: 4-"; break;
                case 3: label6.Text = "Оценка: 3"; break;
                case 2: label6.Text = "Оценка: 3-"; break;
                case 1: label6.Text = "Оценка: 2"; break;
                case 0: label6.Text = "Оценка: 2"; break;
            }
            label7.Text = "Кол-во баллов: " + p.ToString() + " из 7";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
