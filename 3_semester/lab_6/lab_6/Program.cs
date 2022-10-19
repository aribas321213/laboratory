using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab_6
{
    class D {
        public D(){ 
            N = 2; 
            this.e = new E[N];
        }
        public D(int N){
            this.N = N;
            this.e = new E[N];
        }
        public void setE(E e){ 
            if (size < N){ 
                this.e[size] = e; 
                size++; 
            } 
        }
        public E getByIndex(int index) {
            if (index < size) {
                return e[index];
            }
            Console.WriteLine("Index more than size!");
            return null;
        }
      
        private int N = 0;
        private E[] e = null; 
        private int size = 0;
    }

    class E {
        public E(){
            Console.WriteLine("    Create E");
        }
        public E(D d){ 
            Console.WriteLine("    Create E");
            d.setE(this);
        } 
        public E(D d, int v){ 
            Console.WriteLine("    Create E");
            d.setE(this);
            this.v = v;
        }     
        public int f(){ 
            return v; 
        }
        private int v = 1; 
        public D d { set; get;}
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            D d  = new D(5);

            E e_1 = new E();
            d.setE(e_1);
            e_1.d = d;
            Console.WriteLine(" e_1.d.getByIndex(0).f() = {0}", e_1.d.getByIndex(0).f());

            Console.WriteLine(" d.getByIndex(0).f() = {0}", d.getByIndex(0).f());
            E e_2 = new E(d);
            Console.WriteLine(" d.getByIndex(1).f() = {0}", d.getByIndex(1).f());
            E e_3 = new E(d, 99);
            Console.WriteLine(" d.getByIndex(2).f() = {0}", d.getByIndex(2).f());

            Console.ReadKey();
        }
    }
}
