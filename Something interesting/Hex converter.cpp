/*不支持小数*/

#include<stdio.h>
#include<math.h>

void system_changing(int num,int system)
{
	int i=0,a[100];
	for(;num!=0;i++){
		a[i]=num%system;num/=system;
	}
	for(int i1=i;i1>0;i1--) printf("%d",a[i1-1]);
	printf("\n");
}

void nb_system_changing(int num,int system)
{
    int i=0;char a[100];
	for(;num!=0;i++){
		if(num%system<10) a[i]=num%system+'0';
		else a[i]=num%system+'a'-10;
		num/=system;
	}
	for(int i1=i;i1>0;i1--) printf("%c",a[i1-1]);
	printf("\n");
}

int ten_changing(int num,int system)
{
	int result=0;
	for(int i=0;num!=0;i++){
		if((num-num/10*10)>=system){
		printf("**请输入正确的进制!**");return -1;
		}
		result+=(num-num/10*10)*pow(system,i);
		num/=10;
	}
	return result;
}

int main()
{
	int num=0,a=0,b=0;
	
	printf("请输入您希望转化的数字:");
	scanf("%d",&num);
	printf("请输入当前数字的进制:");
	scanf("%d",&a);
	printf("输入您希望转化的目标进制 (如二进制则输入2):");
	scanf("%d",&b);
	
	if(a<=0||b<=0) {printf("自己玩去!");return 0;}
	if(num==0) printf("0");
	if(num<0) {num*=-1;printf("-");}
	
	if(a!=10){
	    num=ten_changing(num,a);
    	if(num==-1) return 0;
	}
	
    if(b<=10) {system_changing(num,b);return 0;}
	if(b<=32) nb_system_changing(num,b);
	else printf("自己算去!");
	
	return 0;
}
