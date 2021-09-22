#include<iostream>
#include<string>
using namespace std;

int dp[7][7];
int main(){
    string a, b;
    a = "abcfbc";
    b = "abfcab";
    for(int i=1;i<=a.size();i++){   // dp数组的下角标从1开始，dp数组的下角标就是确确实实的表示第几个元素, 因为刚好就1～n
        for(int j=1;j<=b.size();j++){
            if(a[i-1] == b[j-1]){  //这边要减1才能取string对应的元素出来
                dp[i][j] = dp[i-1][j-1] + 1;
            } 
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout<<dp[6][6];
    return 0;
}