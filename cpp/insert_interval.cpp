#include <iostream>
using namespace std;


// [[1,3],[6,7],[8,9],[10,15]], [1,8]

int** insertInterval(int** ints, size_t intSize, int * newInt, size_t* retIntSize){
	int ** retInt = new int[intSize+1][2];
	size_t i = intSize/2;
	size_t d = intSize/2;
	*retIntSize = intSize;
	while(1){
		d = d/2;
		if(d==0){
			retIntSize += 1;
			mem
		}
		if(ints[i][0] > newInt[1]) i = i-d;
		else if(ints[i][1] < newInt[0]) i = i+d;
		else{
			if(ints[i][0] < newInt[0] && ints[i][1] > newInt[1]){
				return ints;
			}

			else if(ints[i][0] > newInt[0] && ints[i][1] < newInt[1]){
				ints[i][0] = newInt[0];
				ints[i][1] = newInt[1];
				return ints;
			}
			else{
				if(ints[i][0] < newInt[0]){
					memcpy(retInt, ints, 2*i*sizeof(int));
					size_t j = i;
					while(ints[j][1] < newInt[1]) j++;
					if(ints[j][0] < newInt[1]){
						retIntSize -= (j-i);
						retInt[i][0] = ints[i][0];
						retInt[i][1] = ints[j][1];
						memcpy(retInt+i+1, ints+j+1, 2*(intSize-j-1)*sizeof(int));
					}
					else{
						retIntSize -= (j-i-1);
						retInt[i][0] = ints[i][0];
						retInt[i][1] = newInt[1];
						memcpy(retInt+i+1, ints+j, 2*(intSize-j)*sizeof(int));
					}
				else{
					size_t j = i;
					while(ints[j][0] > newInt[0]) j--;
					if(ints[j][1] > newInt[0]){
						retIntSize -= (i-j);
						memcpy(retInt,ints,2*j*sizeof(int));
						retInt[j][0] = ints[j][0];
						retInt[j][1] = ints[i][1];
						memcpy(retInt+j+1, ints+i+1, 2*(intSize-i-1)*sizeof(int));
					}
					else{
						retIntSize -= (j-i-1);
						memcpy(retInt,ints,2*(j+1)*sizeof(int));
						retInt[j+1][0] = newInt[0];
						retInt[j+1][1] = ints[i][1];
						memcpy(retInt+j+1, ints+i+1, 2*(intSize-i-1)*sizeof(int));
					}
				}
			}

		}

	}
	return retInt;
}


int main(){
	size_t intSize = 4;
	int intvls[intSize][2] = {{1,3},{5,7},{8,9},{13,15}};
	int newInt[2]={4,8};
	int ** retIntrvl = insertInterval(ints, intSize, newInt);

	return 0;
}
