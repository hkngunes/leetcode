#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> plusOne(vector<int>& digits){
	int r = 0, sum = 0;
	int i = (int)digits.size()-1;
	r = (digits[i]+1)/10;
	digits[i] = (digits[i]+1)%10;
	i--;
	for(; i>=0;i--){
		sum = digits[i]+r;
		r = sum/10;
		digits[i] = sum%10;
	}
	if(r!=0){
		digits.insert(digits.begin(),r);
	}
	return digits;
}

int main(){
	vector<int> arr{9,9,9,9};
	string str ="";
	arr = plusOne(arr);
	str += "[";
	for(int i = 0;i<arr.size();i++){
		str += to_string(arr.at(i));
		str += ", ";
	}
	str.pop_back();
	str.pop_back();
	str.push_back(']');
	cout << str;
	return 0;
}
