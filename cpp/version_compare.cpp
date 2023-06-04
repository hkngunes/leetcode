#include <iostream>
#include <cassert>
using namespace std;

//v1=1.1.2, v2=1.1.2.1 --> v2>v1 --> -1
//v1=1.0.0, v2=1.0.0 -->   v2=v1 --> 0
//v1=2.0.1, v2=2.1.0 -->   v2<v1 --> 1

int verComp(const char* v1, const char* v2){
	int i=0,j=0;
	int n1=0,n2=0;
	while(1){
		n1 *= 10; n2 *= 10;
		n1 += (int)(*(v1+i)-0x30);
		n2 += (int)(*(v2+j)-0x30);
		if(n1>n2) return 1;
		if(n2>n1) return -1;
		i++; j++;
		if(*(v1+i)=='.'){ i++; n1=0;}
		if(*(v2+j)=='.'){ j++; n2=0;}
		if(*(v1+i)=='\0' && *(v2+j)=='\0') return 0;
		if(*(v1+i)=='\0') return -1;
		if(*(v2+j)=='\0') return 1;
		if(i>100) break;
	}
	return -2;
}

int main(){
	assert(verComp("1.0.1", "1.0.1")==0);
	cout << "test 1 ok" << endl;
	assert(verComp("1", "0")==1);
	cout << "test 2 ok" << endl;
	assert(verComp("1.0.2", "1.0.3")==-1);
	cout << "test 3 ok" << endl;
	assert(verComp("1.0.1.1", "1.0.1")==1);
	cout << "test 4 ok" << endl;
	return 0;
}
