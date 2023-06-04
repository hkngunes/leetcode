#include <iostream>
#include <cassert>
using namespace std;


//[1,2,3,4,5,6,8.9] --> 7, s=8
//[3,4,6,7,8] --> 5, s=5

int find(int *arr, size_t s){
	if(s<4){
		for(int i=1;i<s;i++){
			if(arr[i]-arr[i-1] != 1) return arr[i]-1;
		}
		return 0;
	}

	if(arr[s/2]-arr[0] != s/2){
		return find(arr, s/2+1);
	}
	else{
		return find(arr+s/2, s/2+(s%2));
	}
	return 0;
}

int main(){
	int a1[] = {1,2,3,5,6,7,8,9};
	int a2[] = {1,2,3,4,5,6,8,9};
	int a3[] = {1,3};
	int a4[] = {1,3,4,5,6,7,8};
	int a5[] = {4,5,6,7,9};
	assert(find(a1, 8)==4);
	cout << "check 1" << endl;
	assert(find(a2, 8)==7);
	cout << "check 2" << endl;
	assert(find(a3, 2)==2);
	cout << "check 3" << endl;
	assert(find(a4, 7)==2);
	cout << "check 4" << endl;
	assert(find(a5, 5)==8);
	cout << "check 5" << endl;
	return 0;
}
