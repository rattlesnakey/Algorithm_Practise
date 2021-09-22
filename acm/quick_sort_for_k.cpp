
#include<iostream>
using namespace std;
int flag;
int partition(int a[], int low, int high, int k){ 
    int pivot = a[low];
    while(low<high){
        while(low<high && a[high]>=pivot) --high;
        a[low] = a[high];
        while(low<high && a[low]<=pivot) ++low;
        a[high] = a[low];
    }
    a[low] = pivot;
    if (low  == 6 - k) {
        cout<<a[low]<<"---------------";
        flag = 1;
    }
    return low;
}

void quick_sort(int a[], int low, int high, int k){  // 一进来就要注意边界的判断
    if (flag) return ;
    if (low<high){  // low要记得小于high, low = high就不要了，就只有一个数字，就不需要排序了
    int loc = partition(a, low, high, k);
    quick_sort(a, low, loc-1, k);
    quick_sort(a, loc+1, high, k);
    } 
    if(low == high && low == 6 - k) {  // 有些是low == high的情况，因为有些传进来已经low == high了，这些是不需要排序的
        cout<<a[low]<<"-----------------";  // 因为有些数在前面已经被调换位置了
        flag = 1;
    }
}

int main(){
    int a[6] = {3,4,5,8,1,0};
    quick_sort(a, 0, 5, 4);
    for(int i=0;i<6;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}