#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int* plusOne(int* d, int dS, int* rS){
	int p=1,i=dS-1, s;
	int *r = malloc((dS+1)*sizeof(int));
	do{
	if(p!=0){
		s = d[i]+p;
		r[i+1] = s%10;
		p = s/10;
	}
	else{
		r[i+1]=d[i];
	}
		i--;
	}while(i>=0);
	if(p!=0){
		*r = p;
		*rS = dS+1;
	}
	else{
		*rS = dS;
		r += 1;
	}
	return r;
}

int main(){
	int arr[3] = {9,9,9};
	int a=0,* rS=&a;
	int* r = plusOne(arr, 3, rS);
	for(int i=0;i<*rS;i++){
		printf("%d, ",r[i]);
	}
	return 0;
}
