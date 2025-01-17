﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab_2_2
{
    class A
    {
        public A() { }
        public class B
        {
            public B() { }
            public class D
            {
                public D() { }
                public void mD()
                {
                    Console.WriteLine(" method of D");
                }
            }
            public void mB()
            {
                Console.WriteLine(" method of B");
            }
            public D dA
            {
                get { Console.Write("get d ->"); return d; }
            }
            private D d = new D();
        }

        public class C
        {
            public C()
            {
                this.c_val = 0;
            }
            public class E
            {
                public E() { }
                public void mE()
                {
                    Console.WriteLine(" method of E");
                }
            }
            public class J
            {
                public J() { }
                public class K
                {
                    public K() { }
                    public void mK()
                    {
                        Console.WriteLine(" method of K");
                    }
                }
                public void mJ()
                {
                    Console.WriteLine(" method of J");
                }
                public K kA
                {
                    get { Console.Write("get k ->"); return k; }
                }
                private K k = new K();
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
            private J j = new J();
            private E e = new E();
        }

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
        private B b = new B();
        private C c = new C();
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            A a = new A();

            Console.WriteLine($"a.cA.c_val: {a.cA.c_val}");
            a.cA.c_val = 15;
            Console.WriteLine($"a.cA.c_val: {a.cA.c_val}");


            a.mA();
            a.bA.mB();
            a.cA.mC();

            a.bA.dA.mD();
            a.cA.jA.mJ();
            a.cA.eA.mE();

            a.cA.jA.kA.mK();

            Console.ReadKey();


        }
    }
}
