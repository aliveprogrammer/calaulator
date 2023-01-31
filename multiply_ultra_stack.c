#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define MAX 50001
char a[MAX]={0},b[MAX]={0},res[2*MAX]={0};
int ia[MAX/9+1]={0},ib[MAX/9+1]={0};
int cia,cib;
int count(char *pc){
    int i;
    for(i=MAX;i>=0;i--){
        if(*(pc+i)!=0){
            break;
        }
    }
    return i;
}

void add_ultra(int la,int lb,char *multiplier,int count){
    int i,r,line=2*MAX-1-la*9-lb*9;
//    printf("%d %d %d\n",la,lb,count);
    for(i=0;i<=count;i++){
        r=*(res+line)+*(multiplier+count-i)-48;
//        printf("%d %d %d %d\n",line,r,*(res+line),*(multiplier+count-i));
        if(r>=10){
            *(res+line)=r-10;
            *(res+line-1)+=1;
        }else{
            *(res+line)=r;
        }
        line--;
    }
    return;
}

void multiply_ultra(){
    int lA,lB;
    long resulti=0;
    char unit[18]={0};
    for(lA=0;lA<cia;lA++){
        for(lB=0;lB<cib;lB++){
            resulti=(long)(*(ib+lB))*(*(ia+lA));
//            printf("%d %d %ld\n",*(ib+lB),*(ia+lA),resulti);
            add_ultra(lA,lB,unit,sprintf(unit,"%ld",resulti)-1);
        }
    }
    return;
}
//read pi~pi-8
int char_integer(char *pi,int amount){
    int result=0;
    for(int i=0;*(pi-i)!=0;i++){
        if(i>8)
        break;
//        printf("%d %c\n",i,*(pi-i));
        result+=(*(pi-i)-48)*(int)pow(10.0,(double)i);
    }
    return result;
}

int char_mix_int(char *source,int *dest){
    int limit=count(source);
    for(int i=limit;i>=0;i-=9){
        *(dest+(limit-i)/9)=char_integer(source+i,9);
//        printf("%d  %d\n",i,*(dest+i));
    }
    return limit/9+1;
}

int main(){
    int i;
    clock_t start,end;
    printf("Input\n");
    scanf("%s %s",a,b);
    start=clock();
    cia=char_mix_int(a,ia);
    cib=char_mix_int(b,ib);
    multiply_ultra();
    for(i=0;i<2*MAX;i++)
        if(*(res+i)!=0)
            for(;i<2*MAX;i++)
               printf("%hhd",*(res+i));
    putchar('\n');
    end=clock();
    printf("%.6lf",(end-start)*1./CLOCKS_PER_SEC);
}
