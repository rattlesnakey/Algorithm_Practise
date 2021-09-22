#include<iostream>
using namespace std;

int ans;
// 方法1
void dfs(int n, int step){  // 这种就是涉及到每一次不同的选择，就可以暴力递归
    if (n<0)return;
    if(n == 0 && step%2 == 0){
        ans++;
        return;
    }
    dfs(n-1, step+1);
    dfs(n-2, step+1);
    return;
}
// 方法2
int left_step[40];
int right_step[40];
int main(){
    // dfs(39,0);
    //dp 的话一般都是初始0，1，2三个阶段
    left_step[1] = 1;
    left_step[2] = 1;
    right_step[1] = 0;
    right_step[2] = 1;
    for(int i=3;i<=39;i++){
        left_step[i] = right_step[i-1] + right_step[i-2]; // 一步和两步过来的
        right_step[i] = left_step[i-1] + left_step[i-2];
    }
    cout<<right_step[39];
    // cout<<ans;
}