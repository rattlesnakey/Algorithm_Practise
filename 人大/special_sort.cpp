#include<iostream>
using namespace std;
int vec_for_count[100];

int main(){
    freopen("in.txt","r", stdin);
    // FILE *f = fopen("in.txt","r");
    int vec_for_loc[100];
    int temp;
    int idx = 0;
    while(cin>>temp){
        if (vec_for_count[temp] == 0){ // 第一次出现
            vec_for_loc[idx++] = temp;
            
        }
        vec_for_count[temp]++; //统计个数
    }
    for(int i=0;i<idx;i++){
        for (int j=0;j<vec_for_count[temp];j++){
            cout<<vec_for_loc[i]<<" ";
        }
    }
    return 0;
}