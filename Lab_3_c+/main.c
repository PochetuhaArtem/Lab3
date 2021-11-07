#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>

double F(double x)
{
    return pow(x,3)-0.2*pow(x,2)+0.5*x+1.5;
}

void Dump(double xi,double fault,int n,double Timer)
{
    printf("xi = %lf\n",xi);
    printf("Fault  = %lf\n",fault);
    printf("Count of iterations = %d\n",n);
    printf("Calculation time = %lf\n",Timer);
}

int main()
{
    //My function y=pow(x,3)-0.2*pow(x,2)+0.5*x+1.5
    double x1, x2,xi,timer,fault;
    unsigned int N, n = 0,var;
    char i;
    printf("1 - chord method\n2 - half chord method\n");
    scanf("%d",&var);
    switch(var)
    {
    case 1:
      do
      {
        printf("Left limit: \n");
        scanf("%lf",&x1);
        printf("Right limit: \n");
        scanf("%lf",&x2);
      }
      while(F(x1)>0 && F(x2)<0);
      printf("Fault: \n");
      scanf("%lf",&fault);
      printf("Max count of iterations: \n");
      clock_t T1 = clock();
      scanf("%d",&N);
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
            printf("The maximum number of iterations is reached\n");
            printf("Press ESC to finish the calculation \nor press any key to continue the calculation\n");
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
        Dump(xi,fabs (F(xi)),n,(double)(T2 - T1) / CLOCKS_PER_SEC);
       break;
    case 2:
      do
      {
        printf("Left limit: \n");
        scanf("%lf",&x1);
        printf("Right limit: \n");
        scanf("%lf",&x2);
      }
      while(F(x1)>0 && F(x2)<0);
      printf("Fault: \n");
      scanf("%lf",&fault);
      printf("Max count of iterations: \n");
      clock_t T11 = clock();
      scanf("%d",&N);
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
            printf("The maximum number of iterations is reached\n");
            printf("Press ESC to finish the calculation \nor press any key to continue the calculation\n");
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
      clock_t T22 = clock();
      Dump(xi,fabs (F(xi)),n,(double)(T22 - T11) / CLOCKS_PER_SEC);
      break;
      }

    return 0;
}


