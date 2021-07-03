#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a1,a2;
void cd(int *b)
{   
    int z=0;
    for(int w=0;w<a1;w+=1){
      int i=0+z;
      if(z>=a2){
        i=a2-1;
      }
      for(;i<a1*a2;i+=a2){            
        int t=0;
        for(int j=(a1*a2)+z;j<a1*a2*2;j+=a1){   
          if(b[i]==b[j]){   
            for(;t<a2;t++){
              if(z<a2){
                printf("%d  ",b[i-z+t]);
              }
              if(z>=a2){
                printf("%d ",b[i-(a2-1)+t]);
              }
            } 
            printf("\n"); 
          }
        }        
      }
      z++;
  }
}
int main()
{   
    int k=0;
    srand(time(0));
    scanf("%d",&a1);
    scanf("%d",&a2);
    int a[a1][a2];
    int b[a1*a2*2];
    for(int i=0;i<a1;i++){   
      for(int j=0;j<a2;j++){
        printf("a[%d][%d]",i,j);
        scanf("%d",&a[i][j]);
      }
    }
    for(int i=0;i<a1;i++){   
      for(int j=0;j<a2;j++){
        if(a[i][j]<10)
          printf("%d  ",a[i][j]);
        if(a[i][j]>=10)
          printf("%d ",a[i][j]);         
      }
      printf("\n");  
    }
    int y;
    for(int i=0;i<a1;i++){    
      printf("Enter row:");
      scanf("%d",&y);
      for(int j=0;j<a2;j++){
        b[k]=a[y-1][j];
        k++;
      }
    }
    for(int i=0;i<a2;i++){   
      printf("Enter column:");
      scanf("%d",&y);
      for(int j=0;j<a1;j++){    
        b[k]=a[j][y-1];
        k++;
      }     
    }
    for(int q=0;q<a1*a2*2;q++){
      printf("%d ",b[q]);
    }
    printf("\n");
    cd(b);
}
