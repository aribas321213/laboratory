using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab_8
{
    class sipleClass {
        public sipleClass(){}
    }
    class mainClass_1 <T> {
        public mainClass_1(){}
        public void m(T t){
            Console.WriteLine(t.ToString());
        }
        public void m(){ 
            Console.WriteLine(val.ToString()); 
        }
        public T val { set; get; }
    }

    class mainClass_2 <T1, T2, T3> {
        public mainClass_2(){}
        public void m(T2 t2) { Console.WriteLine(t2.ToString());}
        public void m(T3 t3) { Console.WriteLine(t3.ToString());}
        public void swap(ref T1 t1, ref T1 t2){
            T1 temp = t1;
            t1 = t2;
            t2 = temp;
        }
        public  T1 t1 { set; get;}
        public  T2 t2 { set; get;}
        public  T3 t3  { set; get;}
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            mainClass_1<string> a_str = new mainClass_1<string>();
            a_str.m("String For Test");
            
            mainClass_1<int> a_int = new mainClass_1<int>();
            a_int.m(4*9);

            mainClass_1<sipleClass> a_simple = new mainClass_1<sipleClass>();
            a_simple.m(new sipleClass());

            mainClass_2 <mainClass_1<string>, 
                         mainClass_1<sipleClass>, 
                         sipleClass> a_ = new mainClass_2<mainClass_1<string>, 
                                                          mainClass_1<sipleClass>, 
                                                          sipleClass>();
            a_.t3 = new sipleClass();

            a_str.val = "testStr_2";
            var v = new mainClass_1<string>();
            v.val = "strForSwap";

            Console.WriteLine("Before swap:");
            a_str.m();
            v.m();
            
            a_.swap(ref a_str, ref v);

            Console.WriteLine("After swap:");
            a_str.m();
            v.m();
           
            Console.ReadKey();
        }
    }
}
