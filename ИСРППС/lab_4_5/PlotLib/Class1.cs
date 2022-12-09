using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;

namespace PlotLib
{
    public abstract class MainFunction
    {
        public abstract double Value(double x);
    }

    public class FunctionSin : MainFunction
    {
        public override double Value(double x)
        {
            return Math.Sin(x);
        }
    }

    public class FunctionCos : MainFunction
    {
        public override double Value(double x)
        {
            return Math.Cos(x);
        }
    }
    public abstract class AbstractFactory
    {
        public abstract MainFunction DefineFunction();
        public abstract Panel CreatePlot(Point p);
    }


    // "ConcreteFactory1" 

    public class ConcreteFactory1 : AbstractFactory
    {
        public override MainFunction DefineFunction()
        {
            return new FunctionSin();
        }
        public override Panel CreatePlot(Point p)
        {
            Panel pn = new Panel()
            {
                BackColor = Color.LightCoral,
                Location = p,
                Width = 600,
                Height = 400,
                Padding = new Padding(10, 10, 10, 10),
            };
            return pn;
        }
    }



    // "ConcreteFactory2" 

    public class ConcreteFactory2 : AbstractFactory
    {
        public override MainFunction DefineFunction()
        {
            return new FunctionCos();
        }
        public override Panel CreatePlot(Point p)
        {
            return new Panel()
            {
                BackColor = Color.LightGreen,
                Location = p,
                Width = 600,
                Height = 400,
                Padding = new Padding(10, 10, 10, 10),
            };
        }
    }

    public class Plot
    {
        MainFunction Func;
        public Panel plot;
        public Plot(AbstractFactory factory, Point p)
        {
            double x = 0;
            this.Func = factory.DefineFunction();
            plot = factory.CreatePlot(p);
            System.Windows.Forms.DataVisualization.Charting.Chart ch = new System.Windows.Forms.DataVisualization.Charting.Chart()
            {
                Dock = System.Windows.Forms.DockStyle.Fill,
            };
            ch.ChartAreas.Add(new System.Windows.Forms.DataVisualization.Charting.ChartArea());
            ch.Series.Add("График");
            ch.Series["График"].ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Spline;
            ch.Series["График"].Points.Clear();
            ch.ChartAreas[0].AxisY.Minimum = -3;
            ch.ChartAreas[0].AxisY.Maximum = 3;
            while (x <= 20)
            {
                double y = Func.Value(x); ;
                ch.Series["График"].Points.AddXY(x, y);
                x += 0.1;
            }

            plot.Controls.Add(ch);
        }
    }
}
