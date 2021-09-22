#include<iostream>
using namespace std;

int cnt;
void check(int x){
    while(x){
        int cur_num = x%10;
        if (cur_num == 2){
            cnt++;
        }
        x /= 10;
    }
}
int main(){
    for(int i=1;i<=2020;i++){
        check(i);
    }
    cout<<cnt;
    return 0;
}