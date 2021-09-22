#include<iostream>
using namespace std;
int main(){
    int a = 2;
    int b = 8;
    int ans = 1;
    while(b){
        if(b%2 == 1){
            ans *= a;
        }
        a *= a;  // 这边就是不用循环，而是一次一次乘方过去
        b = b/2;
    }
    cout<<ans<<endl;
    return 0;
}