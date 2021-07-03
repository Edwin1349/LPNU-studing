#include<stdio.h>
#include<math.h>
void scan(int *n)
{
    for(int i=0;i<2;i++){
      scanf("%d",&n[i]);
    }
}
float square(int *a,int *b,int *c)
{
    float m[3],n[3],p[3],S,P;
    for(int i=0;i<2;i++){
      m[i]=b[i]-a[i];
      //printf("%.2f ",m[i]);
    }
    for(int i=0;i<2;i++){
      n[i]=c[i]-b[i];
      //printf("%.2f ",n[i]);
    }
    for(int i=0;i<2;i++){
      p[i]=a[i]-c[i];
      //printf("%.2f ",p[i]);
    }
    m[2]=sqrt(pow(m[0],2)+pow(m[1],2));
    //printf("%.2f ",m[2]);
    n[2]=sqrt(pow(n[0],2)+pow(n[1],2));
    //printf("%.2f ",n[2]);
    p[2]=sqrt(pow(p[0],2)+pow(p[1],2));
    //printf("%.2f ",p[2]);
    P=(m[2]+n[2]+p[2])/2;
    S=sqrt(P*(P-m[2])*(P-n[2])*(P-p[2]));
    return S;
    
}
void square1()
{
    int n;
    scanf("%d",&n);
    int a[n][2];
    for(int i=0;i<n;i++){
      for(int j=0;j<2;j++){
        printf("a[%d][%d]\n",i,j);
        scanf("%d",&a[i][j]);
      }   
    }
    float b[n],p=0;
    int z[2],x[2],y[2],k;
    z[0]=a[0][0];
    z[1]=a[0][1];
    printf("z(%d,%d)\n",z[0],z[1]);
    for(int i=0;i<n;i++){
      b[i]=sqrt(pow(a[i][0]-a[0][0],2)+pow(a[i][1]-a[0][1],2));
      if(b[i]>p){
        //p=b[i];
        k=i;
        x[0]=a[k][0];
        x[1]=a[k][1];
      }
    }
    printf("x(%d,%d)\n",x[0],x[1]);
    for(int i=1;i<n;i++){
      if(i != k){
        y[0]=a[i][0];
        y[1]=a[i][1];
        printf("y(%d,%d)\n",y[0],y[1]);
        float S=square(z,x,y);    
        printf("%.2f)\n",S);
      }
    }    
}
int main()
{
    int a[2],b[2],c[2];
    float S;
    scan(a);
    scan(b);
    scan(c);
    S=square(a,b,c);
    printf("%.2f \n",S);
    square1();
}
