#include<iostream>
#include<vector>
using namespace std;



int trap(int height[]) {
    //if (height.empty()) return 0;
    int n = 9;
    int res = 0;
    // 数组充当备忘录
    vector<int> l_max(n), r_max(n);
    // 初始化 base case
    l_max[0] = height[0];
    r_max[n - 1] = height[n - 1];
    // 从左向右计算 l_max
    for (int i = 1; i < n; i++) // 从第二个开始
        l_max[i] = max(height[i], l_max[i - 1]);
    // 从右向左计算 r_max
    for (int i = n - 2; i >= 0; i--) //从倒数第二个开始
        r_max[i] = max(height[i], r_max[i + 1]);
    // 计算答案
    for (int i = 0; i < n - 1; i++) 
        res += min(l_max[i], r_max[i]) - height[i];
    return res;
}

int main(){
    int a[] = {4,3,2,1,3,0,5,0,1};// 12
    cout<<trap(a);
    return 0;
}