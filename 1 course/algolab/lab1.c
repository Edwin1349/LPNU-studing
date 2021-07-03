#include<stdio.h>
#include<math.h>
int main(void)
{
	float a=1000,b=0.0001,c;
	c=(pow(a+b,2)-(pow(a,2)+(2*a*b)))/pow(b,2);
	double ad=1000,bd=0.0001,c;
	cd=(pow(ad+bd,2)-(pow(ad,2)+(2*ad*bd)))/pow(bd,2);
	printf("Float:%f\nDouble:%f\n",c,cd);
	return(0);

}
