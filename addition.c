#include <stdio.h>
//logic: calculate like math
char x[10000]={0};
char y[10000]={0};
char m[10001]={0};//result

int count(char *pc){
	int i;
	for(i=9999;*(pc+i)==0;i--){}
	return i;
}

void add(){
	int r=count(x);
	int s=count(y);
	int h,cr,i=0;//cr: each calculate result
	for(;;i++){
		if(r-i<0){
			if(s-i<0){
				break;
			}else{
				cr=*(y+s-i)-48;
			}
		}else if(s-i<0){
			cr=*(x+r-i)-48;
		}else{
			cr=*(x+r-i)+*(y+s-i)-96;
		}
		if(cr+*(m+10000-i)>=10){
			*(m+10000-i)+=cr-10;
			*(m+9999-i)=1;
		}else{
			*(m+10000-i)+=cr;
		}
	}
	
	for(i=0;;i++){
		if(*(m+i)!=0){
			for(h=0;;h++){
				*(m+h)=*(m+i+h)+48;
				if(h+i==10000)
					return;	
			}
		}	
	}
}

int main(){
	printf("Input 'a'+'b'\n");
	scanf("%s %s",x,y);
	add();
	printf("%s\n",m);
	return 0;
}
