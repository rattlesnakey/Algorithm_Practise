#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i =1;i<=n;i++){
        string space = string (n-i,' ');  // string里面不能是双引号，是单引号 
        string alpha = string (2*i - 1,'A' + i -1);   
    }
    return 0;
}