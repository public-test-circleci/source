using System;

namespace MethodHidingInCSharp
{
    class Student
    {
        public String FirstName;
        public String LastName;
        public void PrintName()
        {
            Console.WriteLine(FirstName + " " + LastName);
        }
    }

    class DiplomaStudent : Student
    {
        public new void PrintName()
        {
            Console.WriteLine(FirstName + " " + LastName + " - Diploma Student");
            Console.WriteLine("Invoke the parent method with using base keyword:");
            base.PrintName();
        }
    }

    class GraduateStudent : Student
    {
        public new void PrintName()
        {
            Console.WriteLine(FirstName + " " + LastName + " - Graduate Student");
            Console.WriteLine("Invoke the parent method with using base keyword:");
            base.PrintName();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            DiplomaStudent ds = new DiplomaStudent();
            ds.FirstName = "Sam";
            ds.LastName = "Fisher";
            ds.PrintName();

            GraduateStudent gs = new GraduateStudent();
            gs.FirstName = "Aiden";
            gs.LastName = "Pearce";
            gs.PrintName();

            Console.WriteLine("\nInvoke the parent method with typecaste the child class variable:");
            ((Student)ds).PrintName();
            ((Student)gs).PrintName();

            Student ds1 = new DiplomaStudent();
            ds1.FirstName = "Sam";
            ds1.LastName = "Fisher";
            ds1.PrintName();

            Student gs1 = new GraduateStudent();
            gs1.FirstName = "Aiden";
            gs1.LastName = "Pearce";
            gs1.PrintName();

            Console.WriteLine("\nInvoke the parent method with base class reference to the child class variable:");
            ds1.PrintName();
            gs1.PrintName();
        }
    }
}
