#include <stdio.h>
#include "string.h"

int lenLastWord(char* s){
	int len = 0;
	for(size_t i = (int)strlen(s); i>0;i--){
		if(*(s+i-1)==' '){
			if(len>0) break;
			else continue;
		}
		len++;
	}
	return len;
}

int main(){
	char* s[5] = {	"   g",
			" ",
			"a",
			"hakangunes",
			"  ha  gu  "
			};
	for(int i = 0; i<5;i++)
		printf("%d\n",lenLastWord(s[i]));
	return 0;
}
