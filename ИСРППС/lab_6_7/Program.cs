using System;
using System.Windows.Forms;

namespace lab6_7
{
    class Program
    {
        static void Main()
        {
            Console.WriteLine("START");
            Application.EnableVisualStyles();

            GraphModel model = new GraphModel();
            GraphView view = new GraphView(model);
            GraphView2 view2 = new GraphView2(model);

            Application.Run(view);
        }
    }
}
