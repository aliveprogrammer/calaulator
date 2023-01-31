#include <stdio.h>
#include <time.h>
//pa:big ; pb:small
char a[10000];
char b[10000];
char rea[20000]={0};
char rem[20000]={0};
int ca,cb;
char *pa,*pb;

int count(char *pc,int di){
    int i;
	for(i=di;i>=0;i--){
		if(*(pc+i)!=0){
			break;
		}
	}
	return i;
}


void pare(){
    int i;
    pa=a;
    pb=b;
    ca=count(a,9999);
    cb=count(b,9999);
    if(ca<cb){
		pa=b;
        pb=a;
        i=ca;
        ca=cb;
        cb=i;
	}else{
		return;
	}
}

int count_max(char *pcm,int dm){
    int i;
    for(i=0;i<=dm;i++){
        if(*(pcm+i)!=0){
            return dm-i+1;
        }
    }
}

void one_digit_multiply(int n){
    int x=*(pb+cb-n)-48,i,c;
    for(i=0;i<ca+1+n;i++){
        *(rea+19999-i)=0;
    }
    for(i=0;i<=ca;i++){
        c=*(pa+ca-i);
        c*=x;
        if(c+*(rea+19999-n-i)>=10){
            *(rea+19999-n-i)+=c;
            *(rea+19999-n-i-1)=*(rea+19999-n-i)/10;
            *(rea+19999-n-i)%=10;
        }else{
            *(rea+19999-n-i)+=c;
        }
    }

}

//po:rem ; pp:rea
void add_max(int mr){
    int i,r;
    for(i=0;i<mr;i++){
		r=*(rem+19999-i)+*(rea+19999-i);
		if(r>=10){
			*(rem+19999-i)=r-10;
			*(rem+19999-i-1)+=1;
			}else{
			*(rem+19999-i)=r;
			}
	}
}

int main(){
    int i,cm;
    clock_t start,end;
    printf("Input a*b\n");
    scanf("%s %s",a,b);
    start=clock();
    pare();
    for(i=0;i<=ca;i++){
        *(pa+i)-=48;
    }
    for(i=0;i<=cb;i++){
        one_digit_multiply(i);
        add_max(count_max(rea,19999));
    }
    cm=count_max(rem,19999);
    for(i=0;i<cm;i++){
        printf("%hhd",*(rem+19999-cm+1+i));
    }
    printf("\n");
    end=clock();
    printf("%.6lf",(end-start)*1./CLOCKS_PER_SEC);
    return 0;
}
