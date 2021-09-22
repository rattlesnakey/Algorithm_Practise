#include<iostream>
using namespace std;

bool judge_int(float a){
    return a -int(a) == 0;
}

int main(){
    int n;
    cin>>n;
    for(int a=0;a<n/4;a++){
        for(int b = a;a*a+b*b<=n/2;b++){
            for(int c =b;a*a+b*b+c*c<=3*n/4;c++){
                int d = n-(a*a+b*b+c*c);
                if (judge_int(sqrt(d))){
                    cout<<a<<" "<<b<<" "<<c<<" "<<sqrt(d)<<" ";
                    return 0;
                }
            }
        }
    }

    return 0;
}