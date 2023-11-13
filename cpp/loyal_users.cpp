#include "iostream"
using namespace std;

typedef struct _VisitStc{
    unsigned int timeStamp;
    unsigned int pageId;
    unsigned int costumerId;
}Visit;

Visit logFile1[] = {
    {112, 221, 331},
    {113, 222, 331},
    {114, 223, 332},
    {115, 224, 333},
    {116, 221, 333},
    {116, 222, 334},
    {117, 224, 331},
    {118, 225, 335},
    {118, 225, 335},
    {118, 225, 335},
    {118, 225, 335},
    {118, 226, 335},
    {119, 228, 332}
};

Visit logFile2[] = {
    {111, 222, 331},
    {112, 222, 331},
    {112, 223, 332},
    {112, 223, 333},
    {113, 224, 333},
    {113, 222, 334},
    {115, 222, 331},
    {116, 223, 335},
    {116, 222, 335},
    {116, 223, 335},
    {116, 223, 336},
    {116, 223, 337},
    {117, 225, 332}
};

void swap(Visit* v1, Visit* v2){
    Visit temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}

void quickSort(Visit* logs, int size){
    int p = 0;
    
    if(size<=1) return;
    for(int i=0;i<size-1;i++){
        if(logs[i].costumerId < logs[size-1].costumerId){
            if(i!=p){
                swap(&logs[i],&logs[p]);
            }
            p++;
        }
    }
    swap(&logs[p],&logs[size-1]);
    quickSort(logs, p);
    quickSort(&logs[p+1], size-p-1);
}

int searchVisit(Visit* logs, int size, int cosId){
    if(size==0) return -1;
    if(logs[size/2].costumerId==cosId) return size/2;
    if(logs[size/2].costumerId > cosId) return searchVisit(logs, size/2, cosId);
    int res = searchVisit(&logs[size/2+1],size/2-1,cosId);
    if(res==-1)return -1;
    return size/2+1+res;
}

void findLoyalUsers(Visit* logs1, int s1,Visit* logs2, int s2){
    int i=0,j=0;
    bool done1=false, done2=false;

    if(s1<=1 || s2 <= 1) return;

    quickSort(logs1, s1);
    quickSort(logs2, s2);

    while(i<s1 && j<s2){
        done1=done2=false;
        while(i<s1-1 && logs1[i].costumerId != logs1[i+1].costumerId) i++;
        if(i==s1-1) break;
        while(i<s1-1 && logs1[i].costumerId == logs1[i+1].costumerId) {
            if(logs1[i].pageId != logs1[i+1].pageId){
                done1=true;
            }
            i++;
        }
        i++;
        if(done1){
            j = searchVisit(logs2, s2, logs1[i-1].costumerId);
            if(j!=-1){
                while(j>0 && logs2[j-1].costumerId == logs2[j].costumerId) j--; //Get to first found index
                while(j<s2 && logs2[j].costumerId == logs2[j+1].costumerId) {
                    if(logs2[j].pageId != logs2[j+1].pageId){
                        done2=true;
                    }
                    j++;
                }
                j++;
            }

        }
        if(done1&&done2){
            cout<<logs1[i-1].costumerId << endl;
        }
    }
}

int main(){
    Visit* logs1 = logFile1; 
    Visit* logs2 = logFile2;
    int s1 = sizeof(logFile1)/sizeof(Visit);
    int s2 = sizeof(logFile2)/sizeof(Visit);
    findLoyalUsers(logs1, s1,logs2,s2);
    return 0;
}