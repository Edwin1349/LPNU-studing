#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a1;
void print(int *arr)
{
    for(int i=0;i<a1;i++){
        printf("%d ",arr[i]);
    }
}
void bubble(int *arr)
{
    for(int i=0;i<a1-1;i++){
        for(int j=0;j<a1-i-1;j++){
            if(arr[j]<arr[j+1]){
                int tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    }
}
int main()
{
   int q;
   scanf("%d",&a1);
   int arr[a1];
   srand(time(0));
   for(int i=0;i<a1;i++) {
    arr[i]=1+rand()%9;
    }
   print(arr);
   printf("\n");
   scanf("%d",&q);
   if(q>a1){
    q%=(a1); 
   }
   else if(q<0){
    q+=a1;
   }
   for(int i=q;i>=0;i--){
    printf("%d ",arr[i]);
   }
   for(int i=a1-1;i>q;i--){
    printf("%d ",arr[i]);
   }
   printf("\n");
   int k=0;
   for(int i=0;i<a1;i++){
    if(arr[i]%2!=0){
        arr[i]=0;
        k++;
        }
   }
   print(arr);
   bubble(arr);
   a1-=k;
   printf("\n");
   print(arr);
   printf("\n");
   scanf("%d",&q);
   if(q>a1){
    q%=(a1); 
   }
   else if(q<0){
    q+=a1;
   }
   for(int i=q;i>=0;i--){
    printf("%d ",arr[i]);
   }
   for(int i=a1-1;i>q;i--){
    printf("%d ",arr[i]);
   }    
}
