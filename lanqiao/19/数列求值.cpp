#include<iostream>
using namespace std;

unsigned long long int dp[100000000];
int main(){
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    for(int i=4;i<=20190324;i++){
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3])%10000;  // 记得要每次求余数，要不就会超出正数的范围，返回的值就是错的
    }
    cout<<dp[20190324]<<endl;
    return 0;
}