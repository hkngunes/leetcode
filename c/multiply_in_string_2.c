#include "stdio.h"
#include "stdlib.h"
char* strMlpDigit(char *num, char n){
	char* res;
	int n1, n2, m=0, s_num=0;
	while(*(num+s_num)!='\0') s_num++;
	res = malloc(s_num+2);
	*(res+s_num+1) = '\0';
	n1 = (int)(n-0x30);
	for(int i = s_num-1; i>=0;i--){
		n2 = (int)(*(num+i)-0x30);
		m = m + (n1*n2)%10;
		*(res+i+1) = (char)(m+0x30);
		m = (n1*n2)/10;
	}
	*res = (char)(m+0x30);
	return res;
}

char* strSum(char* num1, char* num2){
	int s_n1=0,s_n2=0,r = 0,s_r;
	char* res;
	while(*(num1+s_n1)!='\0') s_n1++;
	while(*(num2+s_n2)!='\0') s_n2++;
	if(s_n1 >= s_n2)
		s_r = s_n1+1;
	else
		s_r = s_n2+1;
	res = malloc(s_r+1);
	*(res+s_r) = '\0';
	for(int i = 1; i<s_r; i++){
		int d1, d2;
		if(s_n1-i < 0) d1 = 0;
		else d1 = (int)(*(num1+s_n1-i)-0x30);
		if(s_n2-i < 0) d2 = 0;
		else d2 = (int)(*(num2+s_n2-i)-0x30);
		*(res+s_r-i) = (char)((d1+d2+r)%10 +0x30);
		r = (d1+d2+r)/10;
	}
	*res = (char)(r+0x30);
	return res;
}

char * strSftLeft(char* num){
	char*res;
	int s_n=0;
	while(*(num+s_n)!='\0') s_n++;
	res = malloc(s_n+2);
	*(res+s_n+1) = '\0';
	*(res+s_n) = '0';
	for(int i = s_n-1; i>=0;i--){
		*(res+i) = *(num+i);
	}
	return res;
}

char* strMlp(char* num1, char* num2){
	char* res, *sum,  *num;
	int s_num1 = 0;
	while(*(num1+s_num1)!='\0') s_num1++;
	sum = strMlpDigit(num2, *(num1+s_num1-1));
	for(int i = s_num1-2;i>=0;i--){
		num = strMlpDigit(num2, *(num1+i));
		for(int j=s_num1-1;j>i;j--)
			num = strSftLeft(num);
		sum = strSum(num, sum);
	}
	return sum;
}
int main(){
	char tests[3][2][10]={
	{"999","999"},
	{"123","456"},
	{"5","0"}
	};
	for(int i=0;i<3;i++){
		printf("main: %s\n",strMlp(tests[i][0],tests[i][1]));
	}
	return 0;
}
