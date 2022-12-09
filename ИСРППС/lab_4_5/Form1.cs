using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Windows.Forms;
using PlotLib;

namespace lab_4_5
{
    public partial class Form1 : Form
    {
        List<Plot> plots;
        Label lb;
        public Form1()
        {
            InitializeComponent();
            plots = new List<Plot>();
            lb = label1;
            this.panel2.Controls.Clear();
            this.panel2.Controls.Add(lb);
        }

        private void создатьГрафикSinToolStripMenuItem_Click(object sender, EventArgs e)
        {
            lb.Hide();
            Point p;
            if (this.plots.Count == 0)
            {
                p = new Point(10, 10);
            }
            else
            {
                p = new Point(plots.Last().plot.Location.X, plots.Last().plot.Location.Y + plots.Last().plot.Height + 10);
            }
            Console.WriteLine(plots.Count);

            Plot pl = new Plot(ConcreteFactory1.Instance, p);
            plots.Add(pl);
            this.panel2.Controls.Add(pl.plot);
        }

        private void создатьГрафикCosToolStripMenuItem_Click(object sender, EventArgs e)
        {
            lb.Hide();
            Point p;
            if (this.plots.Count == 0)
            {
                p = new Point(10, 10);
            }
            else
            {
                p = new Point(plots.Last().plot.Location.X, plots.Last().plot.Location.Y + plots.Last().plot.Height + 10);
            }
            Console.WriteLine(plots.Count);

            Plot pl = new Plot(ConcreteFactory2.Instance, p);
            plots.Add(pl);
            this.panel2.Controls.Add(pl.plot);
        }

        private void очиститьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.panel2.Controls.Clear();
            this.plots.Clear();
            this.panel2.Controls.Add(lb);
            lb.Show();
        }
    }
}
