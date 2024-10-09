#include<stdio.h>
int main()

{

      char *name[5];
int i;

      name[0]="anshad";
      name[1]="farzin";
      name[2]="muflih";
      name[3]="dilbar";
      name[4]="iqbal";



      for(i=4;i>=0;i--){
    printf("%s\n",name[i]);
}

return 0;
}

