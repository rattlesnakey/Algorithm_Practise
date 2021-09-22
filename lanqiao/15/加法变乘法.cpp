#include<iostream>
using namespace std;

int main(){
    for(int i=1;i<=46;i++){  // 45 46 47 48 49
        for(int j=i+2;j<=48;j++){
            if(i*(i+1)+j*(j+1)-((j+j+1)+(i+i+1)) == 2015-1225){
                cout<<i<<" "<<j<<endl;
            }
        }
    }  

    return 0;
}