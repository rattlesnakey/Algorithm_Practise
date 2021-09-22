#include<iostream>
using namespace std;

int main(){
    int a[] = {8,7,6,5,4,3,2,1};
    int n = 8;
    for(int i=0;i<n-1;i++){  // n-1趟
        int flag = false;  // 这一趟有没有交换
        for(int j=0;j<n-i-1;j++){
            if (a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = true;
            }
        }
        if(!flag)break;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}