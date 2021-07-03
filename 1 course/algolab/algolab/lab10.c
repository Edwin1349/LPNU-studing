#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct {
    char str[50];
} STR;
int main(void){
    STR *q;
    int n;
    int k;
    scanf("%d",&n);
    q = malloc(n*sizeof(q));
    for(int i=0;i<n;i++){
      scanf("%s",q[i].str);
    }
    for(int i=0;i<n;i++){
      printf("%s\n",q[i].str);
    } 
    while(1){
      q = realloc(q,n*sizeof(q));
      scanf("%d",&k);
      strcpy(q[n].str,q[k].str);
      n+=1;
      for(int i=0;i<n;i++){
        printf("%s\n",q[i].str);
      } 
    }
    free(q); 
}
