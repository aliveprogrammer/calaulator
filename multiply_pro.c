#include <stdio.h>

char up[20000]={0};
char down[20000]={0};
char a[10000];
char b[10000];
char ab_copy[10000]={0};
char upa[10001]={0};
char downa[10000]={0};
char rem[20002]={0};
char rem_copy[20002]={0};
char rea[10002];
char rea_copy[10002]={0};
int ca,cb,cpp,db,cab;
char *pp,*ps;
//Count: One less than the real data
//copy: cpb->cpa

int count(char *pc,int di){
    int i;
	for(i=di;i>=0;i--){
		if(*(pc+i)!=0){
			break;
		}
	}
	return i;
}

int pare_basic(){
    int i;
	ca=count(a,9999);
    cb=count(b,9999);
    printf("\n%d digits multiply %d digits\n\n",ca+1,cb+1);
	if(ca>cb){
		return 1;
	}else{
		return 0;
	}
}

int pare_pro(){
    int i;
    int crea=count(rea,10001);
    if(crea<cpp){
        return 0;
    }
    for(i=0;i<=ca;i++){
			if(*(rea+i)>*(pp+i)){
				return 1;
			}
            if(*(rea+i)<*(pp+i)){
                return 0;
            }
		}
    return 2;    
}

void add(char *pa,char *pb,char *pc,int cpa,int cpb,int cpc){
    int i,r=0,j;
    for(i=0;;i++){
		if(cpa-i<0){
			if(cpb-i<0){
				break;
			}else{
				r=*(pb+cpb-i)-48;
			}
		}else if(cpb-i<0){
			r=*(pa+cpa-i)-48;
		}else{
			r=*(pa+cpa-i)+*(pb+cpb-i)-96;
		}
		if(*(pc+cpc-i)+r>=10){
			*(pc+cpc-i)+=r-10;
			*(pc+cpc-i-1)=1;
			}else{
			*(pc+cpc-i)+=r;
			}
		}
        for(i=0;;i++){
		    if(*(pc+i)!=0){
			    for(j=0;i+j<=cpc;j++){
				    *(pc+j)=*(pc+i+j)+48;
				    *(pc+i+j)=0;
			    }
                break;
            }    
        }
}

void devide_two(char *pd,int ud){
    int i,j=0;
    db=1;
    char dv[20001]={0};
    for(i=0;;i++){
        *(pd+i)-=48;
        if(*(pd+i)+dv[j]>=2){
            dv[j]+=*(pd+i);
        }else if(*(pd+i)==1){
            dv[j]=10;
            if(j!=0){
                dv[j]=0;
                dv[j+1]=10;
                j++;
            }
            continue;
        }else if(*(pd+i)==0){
            dv[j]=0;
        }else{
            *(pd+i)=0;
            if(dv[j]!=0){
                db=0;     
                if(ud){
                    dv[j-1]+=2;
                } 
            }  
            break;
        }
        if(dv[j]%2!=0){
            dv[j]--;
            dv[j+1]=10;
        }
        j++;
    }
    for(i=0;i<j;i++){
        *(pd+i)=dv[i]/2+48;
    }
    *(pd+i)=0; 
}

void copy(char *cpa,char *cpb,int crd){
    int i;
    for(i=0;i<=crd;i++){
        *(cpa+i)=*(cpb+i);
        *(cpb+i)=0;
    }
}

int main(){
    int i,pap;
    char one[1]={0}; 
    one[0]=49;
    printf("Input a*b\n");
    scanf("%s %s",a,b);
    if(*(a+10000)!=0){
        printf("Error:overflow!!!\n");
        return 0;
    }
    if(*(b+10000)!=0){
        printf("Error:overflow!!!\n");
        return 0;
    }
    if(pare_basic()){
        for(i=0;i<=ca;i++){
            *(up+i)=*(a+i);
        }
        upa[0]=49;
        for(i=0;i<=cb;i++){
            *(up+ca+i+1)=48;
            *(upa+1+i)=48;
        }
        pp=b;
        ps=a;
        cpp=cb;
    }else{
        for(i=0;i<=cb;i++){
            *(up+i)=*(b+i);
        }
        upa[0]=49;
        for(i=0;i<=ca;i++){
            *(up+cb+i+1)=48;
            *(upa+1+i)=48;
        }
        pp=a;
        ps=b;
        cpp=ca;
    }
    down[0]=48;
    downa[0]=48;
    copy(ab_copy,ps,9999);
    devide_two(ab_copy,0);
    cab=count(ab_copy,9999);
    for(;;){
        add(upa,downa,rea,count(upa,10000),count(downa,9999),10001);
        add(up,down,rem,count(up,19999),count(down,19999),20001);
        devide_two(rea,0);
        if(db){
            devide_two(rem,1);
        }else{
            devide_two(rem,1);
            add(rem,ab_copy,rem_copy,count(rem,20001),cab,20001);
            copy(rem,rem_copy,20001); 
            add(rea,one,rea_copy,count(rea,10001),0,10001);
            copy(rea,rea_copy,10001);
        }
        pap=pare_pro();  
        if(pap==2){
            printf("%s\n%s",rem,rea);
            return 0;
        }else if(pap==1){
            copy(up,rem,19999);
            copy(upa,rea,10001);
        }else{
            copy(down,rem,19999);
            copy(downa,rea,10001);
        }
        
    }
}