using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab_4_1
{
    public interface A  {
        void mA();
        int fA();
    }

    // Специализация + Расширение 
    public class B : A {
        public B() { 
            this.v_1 = 10; 
            this.v_2 = 20;  
        }
        protected int v_1 { set; get;}
        public int v_2 { set; get;}
        public virtual int f() {
            Console.WriteLine("class B f() ");
            return 0;
        }
        public void mA() { 
            this.v_1 = this.v_1 * this.v_1; 
        }
        public int fA() { 
            return this.v_2 + 1;
        }
    }
    public class D : B {
        public D(){ 
            this.v_3 = 33; 
        }
        public int v_3 {set; get;}
        public override int f() {
            Console.WriteLine("class D f() ");
            return base.f() + 10; 
        }
        public int fD() { 
            return this.v_1 * this.v_3;
        }
    }

    // Спецификация
    public abstract class C : A  {
        public void mC(int a){ 
            this.v_1 = a; 
        }
        public abstract int fC();
        public void mA() { this.v_1 = this.v_1 * 10; }
        public int fA() { return this.v_1; }
        private int v_1 = 22;  
    }
    public class E : C  {
        public E() { }
        public override int fC(){ 
            Console.WriteLine("fC()");
            return 0;
        }
    }
    public class J : C {
        public J() { }
        public override int fC() {
            Console.WriteLine("fC()");
            return 1 + this.fA(); 
        }
    }

    // Конструирование
    public class F{
        public F() { 
            this.v_1 = 1; 
        }
        protected int v_1 { set; get;}
        public int f() {
            return v_1;
        }
    }
    public class K : F {
        public K() { 
            this.v_2 = 2; 
        }
        private int v_2 { set; get;}
        public int f() {
            return v_2 + v_1;
        }
    }


    internal class Program
    {
        static void Main(string[] args)
        {


            A a = new B();
            B b = new B();
            Console.WriteLine("    Специализация + расширение");
            Console.WriteLine($"class B b.f() {b.f()}");
            Console.WriteLine($"class B v_2 {b.v_2}");
            a.mA();
            Console.WriteLine($"intrface A fA() {a.fA()}");

            b = new D();
            a = b;

            Console.WriteLine($"class D b.f() {b.f()}");
            Console.WriteLine($"class D v_2 {b.v_2}");
            Console.WriteLine($"class D v_3 {((D)b).v_3}");
            Console.WriteLine($"class D fD() {((D)b).fD()}");


            Console.WriteLine("    Спецификация");
            C c = null;
            c = new E();
            Console.WriteLine("class C c.fC() {0}", c.fC());

            c = new J();
            Console.WriteLine("class C c.fC() {0}", c.fC());


            Console.WriteLine("    Конструирование");
            F f = new F();
            Console.WriteLine($"class F f.f() {f.f()}");
            f = new K();
            Console.WriteLine($"class K f.f() {((K)f).f()}");

            Console.ReadKey();
        }
    }
}
