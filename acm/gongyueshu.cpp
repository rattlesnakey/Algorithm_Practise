#include<iostream>
using namespace std;
int n,m;
int main(){
    cin>>n>>m;
    int a = n;
    int b = m;
    while(n!=0){
        int temp = m%n;
        m = n;
        n = temp;
    }
    cout<<"最大公约数:"<<m<<endl;
    cout<<"最小公倍数:"<<a*b/m;
    return 0;
}