#include <stdio.h>
//base on addition
char x[1000]={0};
char y[1000]={0};
char m[2001]={0};//result
char d[2001]={0};//process save
int sx,sy,i,cr,j,c,cx,cd,g;
char *pm,*po;

int count(char *pc,int di){
	for(i=di;i>=0;i--){
		if(*(pc+i)!=0){
			break;
		}
	}
	return i;
}

int pare(){
	int a=count(x,999);
	int b=count(y,999);
	int i;
	if(a>b){
		return 1;
	}else if(a==b){
		for(i=0;i<=a;i++){
			if(*(x+i)>*(y+i)){
				return 1;
			}
		}
	}else{
		return 0;
	}
	return 0;
}

void add(){
	for(i=0;;i++){
		if(cx-i<0){
			if(cd-i<0){
				break;
			}else{
				cr=*(d+cd-i)-48;
			}
		}else if(cd-i<0){
			cr=*(pm+cx-i)-48;
		}else{
			cr=*(pm+cx-i)+*(d+cd-i)-96;
		}
		if(*(m+2000-i)+cr>=10){
			*(m+2000-i)+=cr-10;
			*(m+1999-i)=1;
			}else{
			*(m+2000-i)+=cr;
			}
		}
	for(i=0;;i++){
		if(*(m+i)!=0){
			for(j=0;i+j<=2000;j++){
				*(d+j)=*(m+i+j)+48;
				*(m+i+j)=0;
			}
			cd=count(d,2000);
			c=count(po,999);
			break;
		}
	}
}


int m1(){
	for(i=0;i<=c;i++){
		if(*(po+c-i)>48){
			*(po+c-i)-=1;
			return 1;
		}
		if (c==i){
			return 0;
		}
		*(po+c-i)=57;
		if(c-i==1){
			if(*(po+c-1-i)==49){
				*(po+c-1-i)=57;
				*(po+c)=0;
				return 1;
			}		
		}		
	}
}

int mult(){
	cd=count(d,2000);
	if(g){
		pm=x;
		po=y;
		c=count(y,999);
		cx=sx;
	}else{
		pm=y;
		po=x;
		c=count(x,999);
		cx=sy;
	}	
	//key point
	for(;m1();){
		add();
	}
} 


int main(){
	printf("Input 'a'*'b'\n");
	scanf("%s %s",x,y);
	sx=count(x,999);
	sy=count(y,999);
	if(pare()){
		g=1;
	}else{
		g=0;
	}
	mult(0);
	printf("%s",d);
	return 0;
}