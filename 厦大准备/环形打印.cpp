#include <stdio.h>
#include <iostream>

using namespace std;
/*
    测试平台：win7-32bit g++
*/
const int N = 100;
int arr[N][N];

int main(){
    int n;
    cin >> n;
    int index, i, j;
    i = j = 0;
    index = 1;
    int round = 0;
    while(index <= n*n){
        while(arr[i][j] == 0 && j < n - round)
            arr[i][j ++] = index ++;
        j --; //回退一格
        i ++; //下移一行

        while(arr[i][j] == 0 && i < n - round)
            arr[i++][j] = index ++;
        i --;
        j --;

        while(arr[i][j] == 0 && j >= 0 + round)
            arr[i][j --] = index ++;
        j ++;
        i --;

        while(arr[i][j] == 0 && i >= 0 + round)
            arr[i --][j] = index ++;
        i ++;
        j ++;
    }
    round++;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if (j == n-1){
                printf("%d\n",arr[i][j]);
            }
            else{
                printf("%d ",arr[i][j]);
            }
        }
    }
    cout << endl;
    return 0;
}