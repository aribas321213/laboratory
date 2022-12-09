using System;

namespace lab6_7
{
    public class GraphView2 : IObserver 
    {
        private GraphModel model;

        public GraphView2(GraphModel model)
        {
            this.model = model;
            this.model.Register(this);
        }

        public void UpdateState()
        {
            if (model.SwitchedOn)
            {
                Console.WriteLine($"Current Amplitude: {this.model.amplitude}");
                Console.WriteLine($"Current Frequency: {this.model.frequency}");
            }
                
        }
    }
}