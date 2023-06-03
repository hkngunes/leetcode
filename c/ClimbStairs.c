#include "stdio.h"

int factorial(int n){
	if(n<=1)
		return 1;
	return n*factorial(n-1);
}
int permutation(int n, int m){
	int mul = 1,k=m;
	if(n-m>m) k = n-m;
	for(int i = n;i>k;i--){
		mul*=i;
	}
	return mul/factorial(n-k);
}
int climbStairs(int n){
	int k=n/2,m=n/2,sum=0;
	if(n%2){
		k=m+1;
	}
	for(int i = n; i>=k;i--){
		sum+=permutation(i,n-i);
	}
	return sum;
}



int main(){
	for(int n=1;n<10;n++){
		printf("%d, ",climbStairs(n));
	}
	return 0;
}
