#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//format of input file
//x\n\ny\n
char *x=NULL;
char *y=NULL;
FILE *finput=NULL;
FILE *foutput=NULL;
int cx,cy;//count x;count y (avoid use too much strlen)

//x point to the small one,y point to the big one
void split_addition(){
	char *px=x+cx;//point to 0
	char *py=y+cy;
	unsigned long mx,my,mr;
	int len=19;
	int sig_overflow=0;
	int sig_end=0;//0 means end not reach;1 means x end;2 means y end;3 means both end
	int digits=0;//digits of the result
	char unit[21]={0};
	while(1){
		if(px>=x+19){
			printf("case1\n");
			len=19,px-=19,py-=19;
			if(strcmp(px,"9223372036854775807")>0||strcmp(py,"9223372036854775807")>0)
				px++,py++,len=18;
		}else if(py>=y+19){
			printf("case2\n");
			len=19,py-=19;
			if(strcmp(py,"9223372036854775807")>0)
				py++,len=18;
			px=x;
		}else{
			printf("caswe3\n");
			len=py-y;
			if(len==0)
				break;
			px=x,py=y;
		}

		mx=atol(px),my=atol(py);
		mr=mx+my+sig_overflow;
		sig_overflow=0;

		sprintf(unit,"%lu",mr);
		printf("unit:%s\n",unit);
		digits=strlen(unit);
		if(digits>len)
			sig_overflow=1;

		printf("len:%d digits:%d\n",len,digits);
		fseek(foutput,-(digits-sig_overflow),SEEK_CUR);
		printf("t1:%ld\n",ftell(foutput));
		fputs(unit+sig_overflow,foutput);
		printf("t2:%ld\n",ftell(foutput));
		fseek(foutput,-len,SEEK_CUR);
		printf("t3:%ld\n",ftell(foutput));

		*px=0,*py=0;
		printf("px:%p py:%p x:%p y:%p\n",px,py,x,y);
	}

	if(sig_overflow){

	}

	printf("run end\n");
	
}

int main(){
	finput=fopen("input.txt","r");
	foutput=fopen("output.txt","w");
	if(finput==NULL)
		return 0;
	x=(char *)calloc(1,100000);
	y=(char *)calloc(1,100000);
	
	fgets(x,100000,finput);	
	fgetc(finput);
	fgets(y,100000,finput);
	x[strlen(x)-1]=0;
	y[strlen(y)-1]=0;
	cx=strlen(x),cy=strlen(y);
	
	if(cx>cy){
		char *pbackup=x;
		x=y;
		y=pbackup;
	}

	cx=strlen(x),cy=strlen(y);

	char *zero=(char *)malloc(cy+1);
	memset(zero,48,cy+1);
	fwrite(zero,cy+1,1,foutput);//file pointer at one byte after data space
	printf("start t:%ld\n",ftell(foutput));
	printf("x:%d   y:%d\n",strlen(x),strlen(y));
	split_addition();
	return 0;

}