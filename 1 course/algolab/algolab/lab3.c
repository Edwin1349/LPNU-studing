#include <stdio.h>
#include <cs50.h>
#include <math.h>
double SUM(int x)
{   
    double e=2.72,a,p,z;
    int i;
    for(i=x;i<x+7;i++)
    {
        p=pow(i,2);
        z=pow(e,-sqrt((double)i));
        a+=p*z;
        //printf("%f)%d\n",a,x);
     }
    return a;
}
int main()
{
    int n=GetInt();
    double s=SUM(n);
    printf("%f\n",s);
}
