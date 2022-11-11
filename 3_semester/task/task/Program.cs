using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task
{
    class Squadron{
        public delegate void Message(string message);
        public event Message Notify;
        public Squadron(int n){
            this.N = n;
            ships = new Ship[N];
        }
        public void Fire(){
            if (size != 0){
                for (int i = 0; i < size; i++){
                    ships[i].fire();
                }
            }
            else{
                Notify?.Invoke($"Сейчас эскадрилия пустая");
            }
        }
        public void Fire<T>()
        {
            if (size != 0)
            {
                for (int i = 0; i < size; i++)
                {
                    if (ships[i] is T){
                        ships[i].fire();
                    }
                }
            }
            else
            {
                Notify?.Invoke($"Сейчас эскадрилия пустая");
            }
        }
        public void ShowConsist(){
            if (size != 0){
                Notify?.Invoke($"Сейчас в эскадрилию входят:");
                for (int i = 0; i < size; i++){
                    ships[i].getName();
                }
            }
            else{
                Notify?.Invoke($"Сейчас эскадрилия пустая");
            }
        }
        public void addShip(Ship s){
            if (size < N){
                ships[size] = s;
                size++;
            }
            else{
                Notify?.Invoke($"Достигнуто максимальное кол-во кораблей в эскадрилии");
            }
            
        }
        public void getSize(){
            Notify?.Invoke($"Сейчас в эскадрилии {this.size} кораблей");
        }
        private Ship[] ships = null;
        private int N = 0;
        private int size = 0;
    }

    public abstract class Ship{
        public delegate void Msg(string message);
        public event Msg Notify;
        public Ship(){}
        public void fire(){
            Notify?.Invoke($"{this.name} выстрелил");
        }
        public void getName(){
            Notify?.Invoke($"{this.name}");
        }
        protected string name { set; get;}
    }
    public class Aerocarrier : Ship{
        public Aerocarrier(){
            this.name = "Авианосец";
        }
    }
    public class Сruiser : Ship{
        public Сruiser(){
            this.name = "Крейсер";
        }
    }
    public class LandingShip : Ship{
        public LandingShip(){
            this.name = "Десантный корабль";
        }
    }
    public class Destroyer : Ship{
        public Destroyer(){
            this.name = "Эсминец";
        }
    }
    public class Frigate : Ship{
        public Frigate(){
            this.name = "Фригат";
        }
    }
    public class Corvette : Ship{
        public Corvette(){
            this.name = "Корвет";
        }
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            Squadron sq = null;

            

            void DisplayMessage(string message) => Console.WriteLine(message);

            Console.WriteLine("МОДЕЛИРОВАНИЕ МОРСКИХ УЧЕНИЙ");
            Console.WriteLine("----------------------------");
            int k = 1;

            Console.WriteLine("Меню:");
            Console.WriteLine("1. Создать эскадрилию");
            Console.WriteLine("0. Выйти");
            Console.Write("Введите, что вы хотите сделать: ");
            k = Convert.ToInt32(Console.ReadLine());
            int n = 0;
            while(k != 0){
                switch (k){
                    case 1:
                        Console.Write("Введите максимальное колл-во кораблей в эскадрилии: ");
                        n = Convert.ToInt32(Console.ReadLine());
                        sq = new Squadron(n);
                        sq.Notify += DisplayMessage;
                        break;
                    case 2:
                        sq.ShowConsist();
                        break;
                    case 3:
                        Console.WriteLine("Вы можете добавить следующие виды кораблей:");
                        Console.WriteLine("1. Авианосец");
                        Console.WriteLine("2. Крейсер");
                        Console.WriteLine("3. Десантный корабль");
                        Console.WriteLine("4. Эсминец");
                        Console.WriteLine("5. Фригат");
                        Console.WriteLine("6. Корвет");
                        Console.Write("Введите номер типа корабля, который вы хотите добавить: ");
                        int c = Convert.ToInt32(Console.ReadLine());
                        Ship s = null;
                        switch (c){
                            case 1: s = new Aerocarrier();break;
                            case 2: s = new Сruiser();break;
                            case 3: s = new LandingShip();break;
                            case 4: s = new Destroyer();break;
                            case 5: s = new Frigate();break;
                            case 6: s = new Corvette();break;
                        }
                        s.Notify += DisplayMessage;
                        sq.addShip(s);
                        break;
                    case 4:
                        sq.Fire();
                        break;
                    case 5:
                        Console.WriteLine("Вы можете выбрать следующие виды кораблей:");
                        Console.WriteLine("1. Авианосец");
                        Console.WriteLine("2. Крейсер");
                        Console.WriteLine("3. Десантный корабль");
                        Console.WriteLine("4. Эсминец");
                        Console.WriteLine("5. Фригат");
                        Console.WriteLine("6. Корвет");
                        Console.Write("Введите номер типа корабля, который должен выстрелить: ");
                        c = Convert.ToInt32(Console.ReadLine());
                        switch (c){
                            case 1: sq.Fire<Aerocarrier>();break;
                            case 2: sq.Fire<Сruiser>();break;
                            case 3: sq.Fire<LandingShip>();break;
                            case 4: sq.Fire<Destroyer>();break;
                            case 5: sq.Fire<Frigate>();break;
                            case 6: sq.Fire<Corvette>();break;
                        }
                        break;
                    case 6:
                        sq.getSize();
                        break;
                    case 0:
                        break;
                }
                Console.WriteLine("-----------------------------------------------------");
                Console.WriteLine("Меню:");
                Console.WriteLine("1. Пересоздать эскадрилию");
                Console.WriteLine("2. Показать состав эскадрилии");
                Console.WriteLine("3. Добавить корабль");
                Console.WriteLine("4. Команда 'ОГОНЬ' для всех кораблей");
                Console.WriteLine("5. Команда 'ОГОНЬ' для определенного типа кораблей");
                Console.WriteLine("6. Вывести текущий размер эскадрилии");

                Console.WriteLine("0. Выйти");
                Console.WriteLine("-----------------------------------------------------");
                Console.Write("Введите, что вы хотите сделать: ");
                k = Convert.ToInt32(Console.ReadLine());
            }
        
        }
    }
}
