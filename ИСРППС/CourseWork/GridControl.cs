using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CourseWork
{
    public class GridControl
    {
        Bitmap bitmap;
        Pen pen1;
        Pen pen2;
        Graphics gr;
        Graphics g;
        public float X;
        public int R = 10;
        private Grid grid;
        private Form1 view;
        public GridControl(Form1 view, Grid model, int width, int height)
        {
            this.grid = model;
            this.view = view;

            bitmap = new Bitmap(width, height);
            gr = Graphics.FromImage(bitmap);
            gr.Clear(Color.White);
            g = Graphics.FromImage(bitmap);
            g.Clear(Color.White);
            pen1 = new Pen(Color.DarkGray, 2);
            pen2 = new Pen(Color.Black, 2); // цвет прямой и дуг
            X = 0;
        }
        public Bitmap GetBitmap()
        {
            return bitmap;
        }

        public void drawVertex(Node node)
        {
            if (node.Equals(grid.Main_Node))
            {
                gr.FillEllipse(Brushes.Red, (node.position.X - R), (node.position.Y - R), 2 * R, 2 * R);
            }
            else
            {
                gr.FillEllipse(Brushes.LightGray, (node.position.X - R), (node.position.Y - R), 2 * R, 2 * R);
            }

            gr.DrawEllipse(pen1, (node.position.X - R), (node.position.Y - R), 2 * R, 2 * R);
        }
        public void drawEdge(Edge E)
        {
            float x1 = E.NodeFrom.position.X, x2 = E.NodeFrom.position.Y, y1 = E.NodeTo.position.X, y2 = E.NodeTo.position.Y ;
            
            gr.DrawLine(this.pen2, x1, x2, y1, y2);
        }

        public void drawGrid()
        {
            gr.Clear(Color.White);
            for (int i = 0; i < grid.Edges.Count; i++)
            {
                drawEdge(grid.Edges[i]);
            }
            for (int i = 0; i < grid.size; i++)
            {
                for (int j = 0; j < grid.size; j++)
                {
                    drawVertex(grid.Nodes[i, j]);
                }
            }
        }

        public void selectMainVert(int x, int y)
        {
            for (int i = 0; i < grid.size; i++)
            {
                for (int j = 0; j < grid.size; j++)
                {
                    if (Math.Pow((grid.Nodes[i,j].position.X - x), 2) + Math.Pow((grid.Nodes[i, j].position.Y - y), 2) <= this.R * this.R)
                    {
                        grid.Main_Node = grid.Nodes[i, j];
                    }
                }
            }

            this.drawGrid();
            
        }

    }
}
