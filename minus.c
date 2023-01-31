#include <stdio.h>

char res[1000]={0};
char ok[1000]={0};

int chr(char *pf){
	int i=999;
	for(;i>=0;i--){
		if(*(pf+i)!=0){
			return i;
		} 
	}
}

int pare(char *pa,char *pb){
	int i;
	if(chr(pa)>chr(pb)){
		return 1;
	}else if(chr(pa)==chr(pb)){
		for(i=0;i<=999;i++){
			if(*(pa+i)>*(pb+i)){
				return 1;
			}
		}	
		return 0;
	}else{
		return 0; 
	}
}

char *minus(char *px,char *py,int a,int b){
	int g=0,t=0;
	for(;;g++){
		if(b-g<0){
			if(a-g<0){
				break;
			}else{
				t=*(px+a-g)-48;
			}	
		}else{
			t=*(px+a-g)-*(py+b-g);
		}
		printf("%d\n",t);
		if(t+*(res+999-g)<0){
			*(res+999-g)+=t+10;
			*(res+998-g)-=1;
		}else{
			*(res+999-g)+=t;
		}
	}
	for(g=0;g<=999;g++){
		if(*(res+g)!=0){
			for(t=0;g<=999;g++){
				*(ok+t)=*(res+g)+48;
				t++;
			}
		}
	}	
	return ok;	
}

int main(){
	char x[1000]={0};
	char y[1000]={0};
	printf("Input'a'-'b'\n");
	scanf("%s %s",x,y);
	if(pare(x,y)){
		printf("+%s\n",minus(x,y,chr(x),chr(y)));
	}else{
		printf("-%s\n",minus(y,x,chr(y),chr(x)));
	}
}
