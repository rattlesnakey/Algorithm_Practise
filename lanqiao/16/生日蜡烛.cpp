#include<iostream>
using namespace std;



int main(){
    for(int i=1;i<=100;i++){
        int sum = 0;
        for(int j=i;j<=100;j++){
            sum += j;
            if (sum == 236){
                cout<<i;
                return 0;
            }
            if(sum>236){
                break;
            }
        }
    }
    return 0;
}
