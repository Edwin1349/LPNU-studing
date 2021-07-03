#include <stdio.h>
#include <string.h>
int main ()
{
  int i=0,k=0;
  char str[255],str1[255];
  gets(str);
  strcpy(str1,str);
  char * pch, * pch1;
  pch = strtok (str," ,.-");
  pch1 = strtok (str1," ,.-");
  for(;pch[i]!='\0';i++){   
  }
  int len=strlen(pch1);
  while (pch != NULL){
    int len2=strlen(pch);
    for(int j=0;j<i;j++){   
        if(pch1[j]==pch[j]&&len==len2)
            k++;       
    }
    if(k==i){
        printf ("%s\n",pch);
        }
    k=0;
    pch = strtok (NULL, " ,.-");
  }
}


