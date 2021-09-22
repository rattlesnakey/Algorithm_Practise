#include<iostream>
using namespace std;

int main(){
    char str[100];
    int flag = 1;
    while(scanf("%s",str)!=EOF){
        for(int i=0;i<strlen(str)/2+1;i++){
            if(str[i] != str[strlen(str)-1-i]){
                flag = 0;
            }
        }
    if(flag)cout<<"true"<<endl;
    else cout<<"false"<<endl;
    }

}