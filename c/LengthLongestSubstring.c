#include "stdio.h"

int longestSubs(char* s){
	int head=0,tail=0, max=0;
	for(;s[head]!='\0';head++){
		for(int i=tail;i<head;i++){
			if(s[head] == s[i]){
				tail = i+1;
			}
		}
		if(head-tail+1 > max){
			max = head-tail+1;
		}
	}
	return max;
}

int main(){
	char tests[5][50000] = {
		"",
		"a",
		"aa",
		"aba",
		"abcddc"
	};
	for(int i=0;i<5;i++){
		printf("%d\n",longestSubs(tests[i]));
	}

	return 0;
}
