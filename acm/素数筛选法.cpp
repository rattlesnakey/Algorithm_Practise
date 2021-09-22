#include<iostream>
using namespace std;
int non_prime[10001];
int prime_index = 0;
int store_prime[10001];
int main(){
    for(int i=2;i<=10000;i++){
        if(non_prime[i] == 1)continue;  // 确实不是素数
        // 是素数
        store_prime[prime_index++] = i;
        for(int j = i*i;j<=10000;j += i){
            non_prime[j] = 1;
        }
    }
    int count = 0;
    for(int k=0;k<prime_index;k++){
        if(count == 5)break;
        cout<<store_prime[k]<<endl;
        count ++;
    }
    return 0;
}