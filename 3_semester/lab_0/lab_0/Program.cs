using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab_0
{
    class Fraction
    {
        private int numerator;
        private int denominator;
        public Fraction()
        {
            this.numerator = 1;
            this.denominator = 1;
        }
        private static int gcd(int a, int b)
        {
            while (b != 0)
            {
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }

        private static int lcm(int a, int b)
        {
            return (a / gcd(a, b)) * b;
        }

        public Fraction(int n, int d)
        {
            this.numerator = n;
            if (d != 0)
            {
                this.denominator = d;
            }
            else
            {
                throw new NullReferenceException("Denominator can`t be 0");
            }
        }
        public string view()
        {
            return $"({this.numerator}/{this.denominator})";
        }
        public void reverse()
        {
            int a = this.numerator;
            int b = this.denominator;
            this.numerator = b;
            this.denominator = a;
        }
        public void negative()
        {
            this.numerator = this.numerator * (-1);
        }

        public int get_integer_part()
        {
            return (int)(this.numerator / this.denominator);
        }

        // Multiply
        public static Fraction operator *(Fraction f1, int num)
        {
            return (new Fraction(f1.numerator * num, f1.denominator));
        }
        public static Fraction operator *(int num, Fraction f1)
        {
            return (new Fraction(f1.numerator * num, f1.denominator));
        }
        public static Fraction operator *(Fraction f1, Fraction f2)
        {
            return (new Fraction(f1.numerator * f2.numerator, f1.denominator * f2.denominator));
        }

        // Sum
        public static Fraction operator +(Fraction f1, int num)
        {
            return (new Fraction(f1.numerator + num * f1.denominator, f1.denominator));
        }
        public static Fraction operator +(int num, Fraction f1)
        {
            return (new Fraction(f1.numerator + num * f1.denominator, f1.denominator));
        }
        public static Fraction operator +(Fraction f1, Fraction f2)
        {
            int l = lcm(f1.denominator, f2.denominator);
            int m1 = l / f1.denominator;
            int m2 = l / f2.denominator;
            return (new Fraction(f1.numerator * m2 + f2.numerator * m1, l));
        }

        public static Fraction operator -(Fraction f1, int num)
        {
            return (new Fraction(f1.numerator - num * f1.denominator, f1.denominator));
        }
        public static Fraction operator -(int num, Fraction f1)
        {
            return (new Fraction(f1.numerator - num * f1.denominator, f1.denominator));
        }
        public static Fraction operator -(Fraction f1, Fraction f2)
        {
            int l = lcm(f1.denominator, f2.denominator);
            int m1 = l / f1.denominator;
            int m2 = l / f2.denominator;
            return (new Fraction(f1.numerator * m2 - f2.numerator * m1, l));
        }

        // Power 
        public static Fraction operator ^(Fraction f1, int num)
        {
            int n = (int)System.Math.Pow(f1.numerator, num);
            int d = (int)System.Math.Pow(f1.denominator, num);
            return (new Fraction(n, d));
        }
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            Fraction f1 = new Fraction(1, 2);

            Fraction f2 = new Fraction(4, 5);

            Console.WriteLine($"f1 = {f1.view()}, f2 = {f2.view()};");

            Console.WriteLine($"{f1.view()} + {f2.view()} = {(f1 + f2).view()}");
            Console.WriteLine($"{f1.view()} + {3} = {(f1 + 3).view()}");
            Console.WriteLine($"{f1.view()} * {f2.view()} = {(f1 * f2).view()}");
            Console.WriteLine($"{-3} * {f2.view()} = {((-3) * f2).view()}");
            Console.WriteLine($"{f2.view()} - {f1.view()} = {(f2 - f1).view()}");
            Console.WriteLine($"{f1.view()} ^ {2} = {(f1 ^ 2).view()}");
            Console.WriteLine($"The integer part of {(f1 + f2).view()}: {(f1 + f2).get_integer_part()}");
            f2.negative();
            Console.WriteLine($"Negative f2: {f2.view()}");

            Console.ReadKey();

        }
    }
}
