using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Windows.Forms;

namespace CourseWork
{
    public class Node
    {
        public PointF position;
        public List<Edge> NodeEdges;
        public bool is_selected;

        public Node(PointF pos)
        {
            this.position = pos;
            this.NodeEdges = new List<Edge>();
            this.is_selected = false;
        }
        public void Switch_select()
        {
            this.is_selected = !this.is_selected;
        }
    }
    public class Edge
    {
        public Node NodeFrom;
        public Node NodeTo;

        public Edge(Node n1, Node n2)
        {
            this.NodeFrom = n1;
            this.NodeTo = n2;
        }
    }
    public class Grid
    {
        public Node[,] Nodes;
        public List<Edge> Edges;
        private Node main_Node = null;
        public int size = 0;
        public Node Main_Node
        {
            get { return main_Node; }
            set { main_Node = value; }
        }
        public Grid(int n)
        {
            this.size = n;
            Nodes = new Node[n, n];
            Edges = new List<Edge>();
            float x = 20, y = 20;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Nodes[i,j] = new Node(new PointF(x,y));
                    x += 40;
                }
                y += 40;
                x = 20;
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n-1; j++)
                {
                    this.Edges.Add(new Edge(Nodes[i, j], Nodes[i, j+1]));
                    Nodes[i, j].NodeEdges.Add(this.Edges.Last());
                    Nodes[i, j+1].NodeEdges.Add(this.Edges.Last());
                }
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n - 1; j++)
                {
                    this.Edges.Add(new Edge(Nodes[j, i], Nodes[j + 1, i]));
                    Nodes[j, i].NodeEdges.Add(this.Edges.Last());
                    Nodes[j + 1,i].NodeEdges.Add(this.Edges.Last());
                }
            }
        }

        // Функция пересоздания решетки с новыми размерами
        public void reshape_grid(int n)
        {
            this.size = n;
            Nodes = new Node[n, n];
            Edges = new List<Edge>();
            float x = 20, y = 20;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Nodes[i, j] = new Node(new PointF(x, y));
                    x += 40;
                }
                y += 40;
                x = 20;
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n - 1; j++)
                {
                    this.Edges.Add(new Edge(Nodes[i, j], Nodes[i, j + 1]));
                    Nodes[i, j].NodeEdges.Add(this.Edges.Last());
                    Nodes[i, j + 1].NodeEdges.Add(this.Edges.Last());
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n - 1; j++)
                {
                    this.Edges.Add(new Edge(Nodes[j, i], Nodes[j + 1, i]));
                    Nodes[j, i].NodeEdges.Add(this.Edges.Last());
                    Nodes[j + 1, i].NodeEdges.Add(this.Edges.Last());
                }
            }
        }
    }
}
