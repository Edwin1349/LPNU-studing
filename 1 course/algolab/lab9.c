#include<stdio.h>
#include<string.h>
#include<ctype.h>
typedef struct {
    char word[50];
} WORDI;
typedef struct {
    char word[50];
} WORDJ;
int b1=0,b2=0;
char str[255];
char str1[255];
char str2[255];
int main()
{ 
    char *istr; 
    char *jstr;
    FILE *in;
    FILE *out;
    char cmp[50];
    WORDI masi[50];
    WORDJ masj[50]; 
    in=fopen("in.txt","rt");
    out=fopen("out.txt","at");
    while(fgets(str,255,in) != NULL){
    int i=0,j=0, k=0;
      strcpy(str1,str);
      istr=strtok(str1," ,.-");
      for(;istr != NULL;i++){
        strcpy(masi[i].word,istr);
        int n=strlen(masi[i].word);
        for(int q=0;q<n;q++){
          if(isdigit(masi[i].word[q])){
            b2++;
          }
        }
        if(b2>b1){
          b1=b2;
          strcpy(cmp,masi[i].word);
        }
          b2=0;
        istr=strtok(NULL," ,.-");
      }
      strcpy(str2,str);
      //printf("STR1(2)%s",str2);
      jstr=strtok(str2," ,.-\n \0");
      for(;jstr != NULL;j++){
        strcpy(masj[j].word,jstr);
        jstr=strtok(NULL," ,.-\n \0");
      }
      for(int m=0;m<i;m++){
        for(int n=0;n<j;n++){
          if(strcmp(masi[m].word,masj[n].word) == 0){  
          k++;
          }
        }
        if(k>=2 && i>1){
          //printf("%s",str);
          fputs(str,out);
          k=0;
          break;
        }
        else{
          //printf("---\n");
        }
        k=0;
      }
    }
    printf("%s",cmp);
    fclose(in);
    fclose(out);
}
