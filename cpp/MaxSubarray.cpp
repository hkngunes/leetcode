#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums){
	int tail = 0, max = nums[0], sum = nums[0];
	for(int i = 1; i< nums.size(); i++){
		sum += nums[i];
		while(tail < i && (nums[tail] < 0 || sum < 0)){
			sum-= nums[tail];
			tail += 1;
		}
		if(max < sum) max = sum;
	}
	return max;
}

int main(){
	vector<int> nums = {1,-2,3,-2,4};
	cout << maxSubArray(nums);
	return 0;
}
