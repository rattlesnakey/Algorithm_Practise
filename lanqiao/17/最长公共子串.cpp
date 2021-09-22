#include<iostream>
#include<string>
using namespace std;

int dp[100][100];
int main(){
    string a, b;
    a = "abcdefg";
    b= "bcd";
    for(int i=1;i<=a.size();i++){
        for(int j=1;j<=b.size();j++){
            if(a[i-1] == b[j-1]){  // dp的i,j和 字符串的ij不一样
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    int max_ = -100;
    for(int i=1;i<=a.size();i++){
        for(int j=1;j<=b.size();j++){
            if (dp[i][j] > max_){
                max_ = dp[i][j];
            }
        }
    }
    cout<< max_;
    return 0;
}