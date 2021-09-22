#include<iostream>
using namespace std;
#define MAX(x,y) (x>y?x:y)
#define mem(a,b) memset(a,b,sizeof(a))


int main(){
    int a[10];
    mem(a,1);  //  好像只能memset 0和-1两种
    cout<<a[0];
    return 0;
}