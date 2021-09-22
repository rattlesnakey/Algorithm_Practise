#include<iostream>
using namespace std;

int fast_mi(int n, int m){
    int ans = 1;
    int temp = n;
    while(m!=0){
        if((m & 1)== 1){  // 且来看最后一位
            ans *= temp;
        }
        temp = temp * temp;
        m = m>>1; // 向右移动一位
    }
    return ans;
}
int main(){
    cout<<fast_mi(3,2);
    
    return 0;
}