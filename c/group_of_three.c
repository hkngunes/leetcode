#include "stdio.h"
void stringGroupOfThree(char* org, char* res){
	int i = 0;
	int k = 0;
	for(;org[i]!='\0';i++){
		if(org[i] == ' ' || org[i] == '-')
			continue;
		res[k++]=org[i];
		if(k%4==3 && org[i+1]!= '\0' ){
			res[k++] = ' ';
		}
	}
	if(res[k-2]==' '){
		res[k-2]=res[k-3];
		res[k-3]=' ';
	}
	res[k]='\0';
}

int main(){
	char test_strs[5][60]={
		"HAKA",
		"hakn gun-es",
		"a",
		" ",
		"-"
	};
	char res[100];
	for(int i=0;i<5;i++){
		stringGroupOfThree(test_strs[i],res);
		printf("%s\n",res);
	}
	return 0;
}
