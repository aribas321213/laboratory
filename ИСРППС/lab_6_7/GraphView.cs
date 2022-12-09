using System;
using System.Windows.Forms;

namespace lab6_7
{
    public partial class GraphView : Form, IObserver
    {
        private GraphController controller;
        private GraphModel model;
        double step = 0;
        delegate void SetChartCallback();

        
        public GraphView(GraphModel model)
        {
            InitializeComponent();
            this.model = model;
            this.model.Register(this);
            AttachController(MakeController());
            trackBar3.Value = Convert.ToInt32(this.model.amplitude*100);
            trackBar1.Value = Convert.ToInt32(this.model.frequency * 100);
        }
        public void UpdateState()
        {
            if (this.chart1.InvokeRequired)
            {
                SetChartCallback d = new SetChartCallback(UpdateState);
                this.Invoke(d);
            }
            else
            {
                label4.Text = this.model.amplitude.ToString();
                label5.Text = this.model.frequency.ToString();
                double x = 0;
                chart1.Series[0].Points.Clear();
                chart1.ChartAreas[0].AxisY.Minimum = -10;
                chart1.ChartAreas[0].AxisY.Maximum = 10;
                while (x <= 20)
                {
                    double y = this.model.amplitude * Math.Sin((x + this.step) * this.model.frequency);
                    chart1.Series[0].Points.AddXY(x, y);
                    x += 0.1;
                }
            }
            
            if (model.SwitchedOn)
            {
                step += 0.05;
            }
        }

        public void AttachController(GraphController controller)
        {
            this.controller = controller;
        }

        protected GraphController MakeController()
        {
            return new GraphController(model, this);
        }


        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                controller.SwithOn();
            }
            catch (Exception ex) { MessageBox.Show(ex.Message); }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            controller.SwitchOff();
        }

        private void trackBar3_ValueChanged(object sender, EventArgs e)
        {
            controller.ChangeAmplitude(trackBar3.Value);
        }

        private void trackBar1_ValueChanged(object sender, EventArgs e)
        {
            controller.ChangeFrequency(trackBar1.Value);
        }
    }
}
