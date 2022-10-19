using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab_7
{
    class J {
        public J() {
            Console.WriteLine("     Create class J()");
            this.v = 0;
        }
        public J(int v) {
            Console.WriteLine("     Create class J(int v)");
            this.v = v;
        }
        private int v;
        public int f() { return v; }   
    }

    class K { 
        public K() { }
        public void m( J j ){ 
            Console.WriteLine(" class A client m() {0}", j.f()); 
        }
    } 

    internal class Program
    {
        static void Main(string[] args)
        {
            K k = new K();
            J j_1 = new J();
            k.m(j_1);
            J j_2 = new J(10);
            k.m(j_2);
                        
            Console.ReadKey();
        }
    }
}
