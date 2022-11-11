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
    public partial class MainWindow : Form
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            

            int num1, ss1, ss2;

            try{
                ss1 = Convert.ToInt32(comboBox1.Text);
                ss2 = Convert.ToInt32(comboBox2.Text);
                num1 = Convert.ToInt32(textBox1.Text, ss1);
                string num2 = Convert.ToString(num1, ss2);

                Result res = new Result(num2);
                res.Show();

            }
            catch 
            {
                if (comboBox1.Text == "")
                    MessageBox.Show("Выберете с.с. для первого числа!");
                if (comboBox2.Text == "")
                    MessageBox.Show("Выберете с.с. для второго числа!");
                if (textBox1.Text == "")
                    MessageBox.Show("Введите число!");
                else
                {
                    DialogResult result = MessageBox.Show("Ошибка ввода.\n" + "Неверный формат данных.\n" + "Повторить?",
                                "Ошибка", MessageBoxButtons.YesNo,
                                MessageBoxIcon.Error, MessageBoxDefaultButton.Button1);
                    switch (result)
                    {
                        case DialogResult.Yes:
                            textBox1.Text = "";
                            break;
                        case DialogResult.No:
                            this.Close();
                            break;
                    }
                }
            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            Instruction instruction = new Instruction();
            instruction.Show();
        }

    }
}
