#include<iostream>
using namespace std;
int cnt;

int gcd(int x, int y){
    if(y == 0){
        return x;
    }
    return gcd(y, x%y);
}
bool judge(int x, int y){
    int b = gcd(x,y);
    if (b==1){
        cnt++;
    }
}
int main(){
    for(int i=1;i<=2020;i++){
        for(int j=1;j<=2020;j++){
            judge(i,j);
        }
    }
    cout<<cnt;
}