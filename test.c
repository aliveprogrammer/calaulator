#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mainv(){
    unsigned long a=0xffffffffffffffff;
    a=a/2;
    printf("%lu",a);
    return 0;
}

int maidn(){
    char pa[100]="123456789";
    char pb[100]={0};
    memcpy(pb,pa,8);
    printf("%s\n",pb);
    return 0;
}

int main(){
    FILE *ftest=fopen("input.txt","w");
    for(int i=0;i<10000;i++){
        
    }
}