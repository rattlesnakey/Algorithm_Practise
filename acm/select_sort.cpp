#include<iostream>
using namespace std;

int main(){
    int a[] = {4,5,61,23};
    for(int i=0;i<3;i++){
        int cur_min = a[i];
        int min_idx = i;
        for(int j=i+1;j<4;j++){  // 每次就是去确定下来当前最小值所对应的下角标
            if (a[j]<cur_min){
                cur_min = a[j];
                min_idx = j;
            }
        }
        int temp = a[i];
        a[i] = a[min_idx];
        a[min_idx] = temp;
    }
    for(int i=0;i<4;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}