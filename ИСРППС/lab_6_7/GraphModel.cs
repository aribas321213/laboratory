using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.Timers;
using static System.Windows.Forms.AxHost;

namespace lab6_7
{
    public class GraphModel
    {
        private Timer timer;
        public double amplitude = 1;
        public double frequency = 1;
        private bool switchedOn;

        public GraphModel()
        {
            switchedOn = false;
            timer = new Timer();
            timer.AutoReset = true;
            timer.Enabled = true;
            timer.Interval = 100;
            timer.Elapsed += new ElapsedEventHandler(timer_Elapsed);
        }

        public bool SwitchedOn
        {
            get { return switchedOn; }
            set
            {
                switchedOn = value;
                if (value)
                {
                    UpdateObservers();
                }
            }
        }


        private void timer_Elapsed(object sender, ElapsedEventArgs e)
        {
            UpdateObservers();
        }

        private ArrayList listeners = new ArrayList();

        public void Register(IObserver o)
        {
            listeners.Add(o);
            o.UpdateState();
        }

        public void Deregister(IObserver o)
        {
            listeners.Remove(o);
        }

        public void UpdateObservers()
        {
            foreach (IObserver ob in listeners)
            {
                ob.UpdateState();
            }
        }
    }
}
