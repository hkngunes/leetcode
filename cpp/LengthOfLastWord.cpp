#include <iostream>
#include <string>
using namespace std;

int lenLastWord(string s){
	int len = 0;
	for(int i = s.size()-1; i >= 0;i--){
		if(s[i] == ' '){
			if(len > 0) break;
			else continue;
		}
		len++;
	}
	return len;
}

int main(){
	string s = "hakan gunes  ";
	cout << lenLastWord(s);
	return 0;
}
