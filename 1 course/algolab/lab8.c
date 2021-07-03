#include<stdio.h>
#include<string.h>
typedef struct {
    char pib[50];
    char address[50];
    char date[50];
    char rate[50];
} STUDENT;
char str[255];
char str1[255];
char str2[255];
char *istr; 
char *jstr;
int n,s;
void fillj(STUDENT masj[n]){
     FILE *emp2;
     emp2=fopen("emp2.txt","rt");
     int j=0;
     while(fgets(str,255,emp2) != NULL){
      strcpy(str2,str);
      jstr=strtok(str2," ");
      for(;jstr != NULL;j++){
        strcpy(masj[j].pib,jstr);
        jstr=strtok(NULL," ");
        strcpy(masj[j].address,jstr);
        jstr=strtok(NULL," ");
        strcpy(masj[j].date,jstr);
        jstr=strtok(NULL," ");
        strcpy(masj[j].rate,jstr);
        jstr=strtok(NULL," ");
      }
    }
    fclose(emp2);
}
void filli(STUDENT masi[n]){
    FILE *emp;
    emp=fopen("emp.txt","rt");
    fclose(emp);
    emp=fopen("emp.txt","rt");
    int i=0;
    s=0;
    while(fgets(str,255,emp) != NULL){
    s++;
      strcpy(str1,str);
      istr=strtok(str1," ");
      for(;istr != NULL;i++){
        strcpy(masi[i].pib,istr);
        istr=strtok(NULL," ");
        strcpy(masi[i].address,istr);
        istr=strtok(NULL," ");
        strcpy(masi[i].date,istr);
        istr=strtok(NULL," ");
        strcpy(masi[i].rate,istr);
        istr=strtok(NULL," ");
      } 
    }
    fclose(emp);
}
void add(STUDENT *masi){
    FILE *emp;
    int k=0;
    char pib[54]="pib:";
    char name[50];
    scanf("%s",name);
    strcat(pib,name);
    int i=0;
    for(;strcmp(masi[i].pib,pib) != 0;i++){
        //if(){
        //}
    }
    printf("%d",i);
    emp=fopen("emp.txt","wt");
    for(;i<s;i++){
        fprintf(emp,"%s ",masi[i].pib);
        fprintf(emp,"%s ",masi[i].address);
        fprintf(emp,"%s ",masi[i].date);
        fprintf(emp,"%s",masi[i].rate);
    }
    printf("pib(student):");
    scanf("%s",masi[s].pib);
    fprintf(emp,"pib:%s ",masi[s].pib);
    printf("address(student):");
    scanf("%s",masi[s].address);
    fprintf(emp,"address:%s ",masi[s].address);
    printf("date(student):");
    scanf("%s",masi[s].date);
    fprintf(emp,"date:%s ",masi[s].date);
    printf("rate(student):");
    scanf("%s",masi[s].rate);
    fprintf(emp,"rate:%s",masi[s].rate);
    for(;i<s;i++){
        fprintf(emp,"%s ",masi[i].pib);
        fprintf(emp,"%s ",masi[i].address);
        fprintf(emp,"%s ",masi[i].date);
        fprintf(emp,"%s",masi[i].rate);
    }
    fclose(emp);
}
int main(void){
    FILE *emp;
    FILE *emp2;
    emp=fopen("emp.txt","wt");
    emp2=fopen("emp2.txt","wt");
    printf("Enter num of students:");
    scanf("%d",&n);
    STUDENT masi[n];
    STUDENT masj[n];
    for(int i=0;i<n;i++){
       printf("pib(student N%d)",i);
        scanf("%s",masi[i].pib);
        fprintf(emp,"pib:%s",masi[i].pib);
        fprintf(emp2,"pib:%s",masi[i].pib);
       printf("address(student N%d)",i);
        scanf("%s",masi[i].address);
        fprintf(emp," address:%s",masi[i].address);
        fprintf(emp2," address:%s",masi[i].address);
       printf("date(student N%d)",i);
        scanf("%s",masi[i].date);
        fprintf(emp," date:%s",masi[i].date);
        fprintf(emp2," date:%s",masi[i].date);
       printf("rate(student N%d)",i);
        scanf("%s",masi[i].rate);
        fprintf(emp," rate:%s\n",masi[i].rate);
        fprintf(emp2," rate:%s\n",masi[i].rate);
    }
    fclose(emp);
    fclose(emp2);
    int k=0;
    filli(masi);
    fillj(masj);
    emp=fopen("emp.txt","wt");
     for(int m=0;m<n;m++){
       for(int a=0;a<n;a++){
         if(strcmp(masi[m].date,masj[a].date) == 0){  
           k++;
         }
       }
       if(k <2 ){
          fprintf(emp,"%s ",masi[m].pib);
          fprintf(emp,"%s ",masi[m].address);
          fprintf(emp,"%s ",masi[m].date);
          fprintf(emp,"%s",masi[m].rate);
          k=0;  
        }
        else{
        }
        k=0;
     }
     fclose(emp);
     filli(masi);
     add(masi);
}     

