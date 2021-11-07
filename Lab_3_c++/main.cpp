#include <iostream>
#include <math.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

using namespace std;

class MyFunction
{
public:
    double F(double x)
    {
        return pow(x,3)-0.2*pow(x,2)+0.5*x+1.5;
    }

    void CinArguments()
    {
        cout<<"1 - метод хорд\n2 - метод половинного деления"<<endl;
        cin>>var;
        do
        {
        cout<<"Введите левую границу: "<<endl;
        cin>>x1;
        cout<<"Введите правую границу: "<<endl;
        cin>>x2;
        }
        while(F(x1)>0 && F(x2)<0);
        cout<<"Введите максимальное количество иттераций: "<<endl;
        cin>>N;
        cout<<"Введите погрешность: "<<endl;
        cin>>fault;
    }

    void Calc()
    {
        switch(var)
        {
            case 1:
                 ChordaMethod();
                 Dump();
            break;
            case 2:
                 halfDivMethod();
                 Dump();
            break;
        }
    }

    void Dump()
    {
        cout<<"Xi = "<<xi<<endl;
        cout<<"Похибка = "<<fault<<endl;
        cout<<"Количество иттераций  = "<<n<<endl;
        cout<<"Время нахождения решения = "<<timer<<endl;
    }

    void ChordaMethod()
    {
        clock_t T1 = clock();
      do
      {
         xi=(x1+x2)/2;
         if( F(xi) >  0 )
         {
            x2=xi;
         }
        else
        {
            x1=xi;
        }
        if(n==N)
        {
            cout<<"Максимальное количество иттераций было достигнуто"<<endl;
            Dump();
            cout<<"Нажмите ESC для прекращения расчетов, для продолжения нажмите любую клавишу"<<endl;
            i = getch();
            if((int)i==27)
            {
                system("cls");
                break;
            }
            else
            {
             system("cls");
            }
        }
        n++;
      }
      while ( fabs (F(xi)) > fault );
      clock_t T2 = clock();
      timer = (double)(T2 - T1) / CLOCKS_PER_SEC;
    }
    void halfDivMethod()
    {
             clock_t T1 = clock();
      do
      {
         xi=((F(x2)*x1) - (F(x1)*x2))/(F(x2) - F(x1));
         if( F(xi) >  0 )
         {
            x2=xi;
         }
        else
        {
            x1=xi;
        }
        if(n==N)
        {
            cout<<"Максимальное количество иттераций было достигнуто"<<endl;
            Dump();
            cout<<"Нажмите ESC для прекращения расчетов, для продолжения нажмите любую клавишу"<<endl;
            i = getch();
            if((int)i==27)
            {
                system("cls");
                break;
            }
            else
            {
             system("cls");
            }
        }
        n++;
      }
      while ( fabs (F(xi)) > fault );
      clock_t T2 = clock();
      timer = (double)(T2 - T1) / CLOCKS_PER_SEC;
    }
protected:
    char i;
    double x1,x2,xi,timer,fault;
    unsigned int N, n = 0,var;
};

int main()
{
    setlocale(LC_ALL, "Russian");
    MyFunction func;
    func.CinArguments();
    func.Calc();
    return 0;
}
