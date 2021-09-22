#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int x[100];
int y[100];
int c[100];
int main(int argc, char *argv[]){
    string a,b;
    cin >>a>>b;
    int alength = a.length();
    int blength = b.length();
    for(int i=0; i<alength;i++){
        x[alength-1-i] = a[i] - '0';
    }
    for(int i=0; i<alength;i++){
        y[blength-1-i] = b[i] - '0';
    }
    int max_length = max(alength, blength);
    int jinwei = 0;
    for(int i=0;i<max_length;i++){
        int temp = x[i]+y[i] + jinwei;
        c[i] = temp%10;
        jinwei = temp/10;
        if (i == (max_length -1) && jinwei == 1){
            max_length = max_length + 1;
            c[max_length-1] = 1;
        }
    }
    for(int i=max_length-1;i>=0;i--){
        cout<<c[i];
    }
    return 0;
}