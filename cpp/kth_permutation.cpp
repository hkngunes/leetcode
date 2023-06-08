#include <iostream>
#include <string>
using namespace std;

int perm(int k){
	if(k<= 1) return 1;
	return k*perm(k-1);
}

string KthPermutation(int n, int k){
	string ret = "";
	string temp = "";
	for(int i = 1;i<=n;i++) temp += char(i+0x30);
	int p = perm(n);
	for(int i = 0;i<n;i++){
		int m = 1;
		if(temp.size()<=1 || k <= 1){
			ret += temp;
			break;
		}
		p /= (n-i);
		while(m*p < k) m++;
		k -= ((m-1)*p);
		ret += temp[m-1];
		temp.erase(m-1,1);
	}
	return ret;
}


int main(){
	cout << KthPermutation(6,468) << endl;
	return 0;
}
