#include "stdio.h"
 int maxSubArray(int* nums, int numSize){
	int *head = nums, *tail=nums;
	int sum = *head;
	int max = *head;
	for(int i = 1; i< numSize;i++){
		tail = tail+1;
		sum += *tail;
		while((*head < 0 || 0-*tail > *head) && head < tail){
			sum -= *head;
			head = head +1;
		}
		if(sum>max){
			max = sum;
		}
	}
 	return max;
}

int main(){
	int a[6] = {1,2,3,4,-5,11};
	int max = maxSubArray(a,6);
	printf("The result: %d", max);
	return max;
}
