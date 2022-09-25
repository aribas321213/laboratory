using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab_2_1
{
    class A
    {
        private B b = new B();
        private C c = new C();
        public A() { }
        public void mA()
        {
            Console.WriteLine("method of A");
        }
        public B bA
        {
            get { Console.Write("get b ->"); return b; }
        }
        public C cA
        {
            get { Console.Write("get c ->"); return c; }
        }
    }

    class B
    {
        private D d = new D();
        public B() { }
        public void mB()
        {
            Console.WriteLine(" method of B");
        }
        public D dA
        {
            get { Console.Write("get d ->"); return d; }
        }
    }

    class C
    {
        private J j = new J();
        private E e = new E();
        public C()
        {
            this.c_val = 0;
        }
        public void mC()
        {
            Console.WriteLine(" method of C");
        }
        public E eA
        {
            get { Console.Write("get e ->"); return e; }
        }
        public J jA
        {
            get { Console.Write("get j ->"); return j; }
        }
        public int c_val { set; get; }
    }

    class D
    {
        public D() { }
        public void mD()
        {
            Console.WriteLine(" method of D");
        }
    }

    class E
    {
        private D d = new D();
        public E() { }
        public void mE()
        {
            Console.WriteLine(" method of E");
        }

        public D dA
        {
            get { Console.Write("get d ->"); return d; }
        }
    }

    class J
    {
        private K k = new K();
        public J() { }
        public void mJ()
        {
            Console.WriteLine(" method of J");
        }

        public K kA
        {
            get { Console.Write("get k ->"); return k; }
        }
    }
    class K
    {
        public K() { }
        public void mK()
        {
            Console.WriteLine(" method of K");
        }
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            A a = new A();
            a.mA();
            a.bA.mB();
            a.cA.mC();

            a.bA.dA.mD();
            a.cA.jA.mJ();
            a.cA.eA.mE();

            a.cA.jA.kA.mK();

            Console.WriteLine($"a.cA.c_val: {a.cA.c_val}");
            a.cA.c_val = 15;
            Console.WriteLine($"a.cA.c_val: {a.cA.c_val}");

            Console.ReadKey();
        }
    }
}
