#include<iostream>
#include<vector>
using namespace std;
// 尽量都去设置成全局变量
vector<int > v = {2,-3,0,10,12,1};
int partion(int low, int high){
    int pivot = v[low];
    while(low<high){
        while(v[high]>=pivot && high>low) high--;
        if (high>low) v[low] = v[high];
        while(v[low]<=pivot && high>low) low++;
        if (high>low) v[high] = v[low];
    }
    v[low] = pivot;
    return low;
}
void qs(int low, int high){
    if (low<high){  // 注意，这里在调用整体的递归的时候也要判断
        int mid = partion(low, high);
        qs(low, mid-1);
        qs(mid+1,high);
    }

}
int main(){
    // 这边记得是length-1
    qs(0, v.size()-1);  // 注意这边要size-1
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    return 0;
}