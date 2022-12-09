using System;
using System.Collections.Generic;
using System.Runtime.Serialization.Formatters;
using System.Text;

namespace lab6_7
{
    public class GraphController
    {
        private GraphModel model;
        private GraphView view;

        public GraphController(GraphModel model, GraphView view)
        {
            this.model = model;
            this.view = view;
        }
        public void SwithOn()
        {
            model.SwitchedOn = true;
        }
        public void SwitchOff()
        {
            model.SwitchedOn = false;
        }
        public void ChangeAmplitude(int value)
        {
            model.amplitude = Convert.ToDouble(value) / 100;
        }
        public void ChangeFrequency(int value)
        {
            model.frequency = Convert.ToDouble(value) / 100;
        }
    }
}
