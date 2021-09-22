//C(m,n)
#include<iostream>
using namespace std;
typedef long long LL;

int ans = 1;
// LL C(int m,int n) {
// int k=1;//相当于 C(m,n) LL ans=1;
// while(k<=n) {
//     ans=((m-k+1)*ans)/k;
//     k++; 
//     }
// return ans; 
// }

LL C(int m, int n){
    int temp = m;
    for(int i=1;i<=n;i++){
        ans = ans*temp/i;
        temp--;
    }
    return ans;
}

int main(){
    cout<<C(4,2);
    return 0;
}