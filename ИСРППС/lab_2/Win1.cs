using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab_2
{
    public partial class Win1 : Form
    {
        private bool[] answers = new bool[7];
        int points;
        public Win1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string name;
            string surname;
            string patronymic;
            points = 0;
            try
            {
                name = textBox1.Text;
                surname = textBox2.Text;
                patronymic = textBox3.Text;
                if (name == "" || surname == "" || patronymic == "")
                {
                    MessageBox.Show("Введите ФИО");
                }
                else
                {
                    points = 0;
                    var radioButtons = groupBox1.Controls.OfType<RadioButton>();
                    foreach (RadioButton radioButton in radioButtons)
                    {
                        if (radioButton.Checked) { if (radioButton.Text == "Казанская губерния") { answers[0] = true; } }
                    }
                    if (numericUpDown1.Value == 1743) { answers[1] = true; }
                    if (comboBox1.Text == "Казанская гимназия") { answers[2] = true; }
                    radioButtons = groupBox7.Controls.OfType<RadioButton>();
                    foreach (RadioButton radioButton in radioButtons)
                    {
                        if (radioButton.Checked) { if (radioButton.Text == "1779") { answers[3] = true; } }
                    }
                    string s = "";
                    foreach (int indexChecked in checkedListBox1.CheckedIndices)
                    {
                        s += checkedListBox1.Items[indexChecked].ToString();
                    }
                    if (s == "СенаторКазначейМинистр юстиции") { answers[4] = true; }
                    var checkButtons = groupBox8.Controls.OfType<CheckBox>();
                    s = "";
                    foreach (CheckBox checkButton in checkButtons)
                    {
                        if (checkButton.Checked) { s += checkButton.Text; }
                    }
                    if (s == "Развивал реалистический языкСоединил слова \"высокие\" и \"низкие\"") { answers[5] = true; }
                    radioButtons = groupBox9.Controls.OfType<RadioButton>();
                    foreach (RadioButton radioButton in radioButtons)
                    {
                        if (radioButton.Checked) { if (radioButton.Text == "Необходимости свободы для творчества") { answers[6] = true; } }
                    }

                    foreach (var answer in answers)
                    {
                        if (answer)
                        {
                            points++;
                        }
                    }

                    Test t = new Test(points, name, surname, patronymic);
                    t.Show();
                    if (!t.is_open)
                    {
                        this.Close();
                    }
                    
                }
            }
            catch
            {
                DialogResult result = MessageBox.Show("Ошибка ввода.\n" + "Проверьте правильность введенных данных.\n" + "Повторить?",
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

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton1.Checked)
            {
                answers[0] = true;
            }
        }

        private void radioButton13_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton13.Checked)
            {
                answers[0] = false;
            }
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton13.Checked)
            {
                answers[0] = false;
            }
        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            
            foreach (GroupBox gb in this.Questions.Controls.OfType<GroupBox>())
            {
                foreach (Label lb in gb.Controls.OfType<Label>())
                {
                    lb.Font = new Font("Microsoft Sans Serif", trackBar1.Value);
                }
            }
        }
    }
}
