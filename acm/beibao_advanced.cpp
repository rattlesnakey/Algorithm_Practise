#include<iostream>
using namespace std;
int w[] = {0,10, 3, 4, 5};
int v[] = {0,3, 4, 6, 7};
//第i个物品对应的个数
int mount[] = {0,5,1,2,1};
int m = 10;
int n = 4;
int dp[5][11];

int main(){
    for(int i=1;i<=4;i++){
        for(int j=0;j<=10;j++){
            for(int k=0;k<=mount[i];k++){  //  每一个商品的n种选择都要考虑, 也就是说选0个，选1个，选2个，这些所有的我都要考虑
                if(j>=w[i]*k){  
                    dp[i][j] = max(dp[i-1][j-(w[i]*k)]+k*v[i],dp[i][j]);  
                    // 这里应该是只能是dp[i][j], 因为在k = 0的时候相当于就是dp[i-1][j]没选这个物品了，而且因为一开始过来处理dp[i][j], dp[i][j]肯定是0，所以dp[i][j]一开始值肯定也是被dp[i-1][j]初始化
                    // 这边dp[i][j]也是为了不断地进行比较
                }
            }
        }
    }
    cout<<dp[4][10];
    return 0;
}
