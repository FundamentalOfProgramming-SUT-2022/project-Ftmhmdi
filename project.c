#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void creatfile(char *ad){
    FILE* ff;
    ff=fopen("ad","w");
    fclose(ff);
}
int main(){
    char a[51];
    //gets(a);
    char b[]=" ";
    char *cmnd=strtok(a, b);
   // printf("%s\n",cmnd);
    char *cmnd1=strtok(NULL, b);
    //printf("%s",cmnd1);
    creatfile(*cmnd1);
    return 0;
}