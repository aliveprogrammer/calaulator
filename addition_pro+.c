#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define DMAX 110000000 //max digits
//format of input file
//x\n\ny\n
char *x=NULL;
char *y=NULL;
char *result=NULL;
FILE *finput=NULL;
FILE *foutput=NULL;
int cx,cy;//count x;count y (avoid use too much strlen)

void process_clock(struct timespec,struct timespec);

//x point to the small one,y point to the big one
void split_addition(){
	char *px=x+cx;//point to 0 
	char *py=y+cy;
	char *pr=result+cy+1;//point to 0 (file pointer at one byte after data space)
	unsigned long mx,my,mr;
	int len=19;//len shows the length of the data that will put into the result
	int sig_overflow=0;
	int digits=0;//digits of unit
	char unit[21]={0};
	while(1){
		if(px>=x+19){
//			printf("case1\n");
			len=19,px-=19,py-=19;
			if(strcmp(px,"9223372036854775807")>0||strcmp(py,"9223372036854775807")>0)
				px++,py++,len=18;
		}else if(py>=y+19){
//			printf("case2\n");
			len=19,py-=19;
			if(strcmp(py,"9223372036854775807")>0)
				py++,len=18;
			px=x;
		}else{
//			printf("case3\n");
			len=py-y;
			if(len==0)
				break;
			px=x,py=y;
		}

		mx=atol(px),my=atol(py);
		mr=mx+my+sig_overflow;
		sig_overflow=0;

		digits=sprintf(unit,"%lu",mr);
//		printf("unit: %s\n",unit);
		if(digits>len)
			sig_overflow=1;
		
		memcpy(pr-digits,unit,digits);
		pr-=len;

		*px=0,*py=0;
//		printf("px:%p py:%p x:%p y:%p\n",px,py,x,y);
	}
	fwrite(result+1-sig_overflow,cy+sig_overflow,1,foutput);
	printf("run end\n");
	return;	
}

int main(){
	struct timespec time1 = {0, 0}; 
	struct timespec time2 = {0, 0};
	clock_gettime(CLOCK_REALTIME, &time1);
	finput=fopen("input.txt","r");
	foutput=fopen("output.txt","w");
	if(finput==NULL)
		return 0;
	x=(char *)calloc(1,DMAX);
	y=(char *)calloc(1,DMAX);
	
	fgets(x,DMAX,finput);	
	fgetc(finput);
	fgets(y,DMAX,finput);

	cx=strlen(x),cy=strlen(y);
	x[--cx]=0;
	y[--cy]=0;	
	if(cx>cy){
		char *pbackup=x;
		x=y;
		y=pbackup;
		cx=strlen(x),cy=strlen(y);
	}
	printf("x:%ld   y:%ld\n",cx,cy);

	result=(char *)malloc(cy+2);
	memset(result,48,cy+1);
	split_addition();
	free(x),free(y),free(result);
	fclose(finput),fclose(foutput);
	clock_gettime(CLOCK_REALTIME, &time2);
        process_clock(time1,time2);
	return 0;

}


void process_clock(struct timespec time1,struct timespec time2){
    long a1=time1.tv_sec,a2=time1.tv_nsec;
    long b1=time2.tv_sec,b2=time2.tv_nsec;
    long result1,result2;
    if(b1<=a1){
        if(b1==a1){
            if(b2<a2)
                printf("time error!\n");
        }else{
            printf("time error!\n");
        }
    }
    if(b2>=a2){
        result2=b2-a2;
        result1=b1-a1;
    }else{
        result2=b2+1000000000-a2;
        result1=b1-1-a1;
    }
    printf("time: %ld.%ld\n",result1,result2);
}
