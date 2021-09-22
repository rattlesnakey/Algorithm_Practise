#include<iostream>
#include<vector>
using namespace std;
int result[5];
int w[5] = { 0 , 2 , 3 , 4 , 5 };			//商品的体积2、3、4、5
int v[5] = { 0 , 3 , 4 , 5 , 6 };			//商品的价值3、4、5、6
int bagV = 8;					        //背包大小
int dp[5][9] = { { 0 } };			        //动态规划表
void find_path(int x, int y){  // 找路径的话，记得要从后往前找
    if(dp[x][y] == dp[x-1][y]){  // 从最后一个项目往前，如果这个项目没选
        result[x] = 0;
        find_path(x-1,y);  // 就去看下一个项目有没有选
    }
    else if (y-w[x]>=0 &&  dp[x][y] == dp[x - 1][y - w[x]] + v[x]){  // 这个else if 好像是必须的，如果只是else的话就不对
        result[x] = 1;
        find_path(x-1,y-w[x]);
    }
    return;
}

int main(){
    for(int i=1;i<=4;i++){
        for(int j=0;j<=8;j++){  // 列数就是背包的大小, 背包容量从0开始
            if (j>=w[i]){  // 可以装的下才去弄，注意，这边是大于等于
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[4][8]<<endl;
    find_path(4,8);
    for(int i=1;i<=4;i++){
        cout<<result[i]<<" ";
    }
    return 0;
}