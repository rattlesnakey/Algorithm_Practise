#include<iostream>
using namespace std;

int main(){
    int sum = 1;
    int cur_num = 1;
    for(int i=2;i<=100;i++){
        cur_num = cur_num + i;
        sum += cur_num;
    }
    cout<<sum;
    return 0;
}