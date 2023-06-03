#include "stdio.h"
#include "stdlib.h"
char* multiplyInString(char *n1, char *n2){
	int d1, d2, p1,p2,p3,s_n1=0,s_n2,s_s;
	char* s;
	while(*(n1+s_n1)!='\0')s_n1++;
	while(*(n2+s_n2)!='\0')s_n2++;
	s_s=s_n1+s_n2+1;
	s = malloc(s_s);
	s[s_s-1]='\0';
	for(int i=0;i<s_s-1;i++){
		s[i]='0';
	}

	for(int i=s_n2-1;i>=0;i--){
		d2 = (int)(*(n2+i)-0x30);
		for(int j=s_n1-1;j>=0;j--){
			d1 = (int)(*(n1+j)-0x30);
			p1 = (int)(*(s+i+j+1)-0x30);
			*(s+i+j+1)=(char)((p1+d1*d2)%10+0x30);
			p2 = (int)(*(s+i+j)-0x30);
			*(s+i+j) = (char)((p2+(p1+d1*d2)/10)%10+0x30);
			if(i+j >0){
				p3 = (int)(*(s+i+j-1)-0x30);
				*(s+i+j-1) = (char)((p3+(p2+(p1+d1*d2)/10)/10)%10+0x30);
			}
		}
	}
	printf("result: %s\n",s);
	return s;
}

int main(){
	char tests[3][2][10]={
	{"999","999"},
	{"123","456"},
	{"5","123456"}
	};
	for(int i=0;i<3;i++){
		printf("main: %s\n",multiplyInString(tests[i][0],tests[i][1]));
	}
	return 0;
}
