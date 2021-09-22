#include<iostream>
using namespace std;

int partition(int a[], int low, int high){ 
    int pivot = a[low];
    while(low<high){
        while(low<high && a[high]>=pivot) --high;
        if (low < high) a[low] = a[high];
        while(low<high && a[low]<=pivot) ++low;
        if (low < high) a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}
void quick_sort(int a[], int low, int high){
    if (low<high){  // low要记得小于high, low = high就不要了，就只有一个数字，就不需要排序了
    int loc = partition(a, low, high);
    quick_sort(a, low, loc-1);
    quick_sort(a, loc+1, high);
    }
}

int main(){
    int a[6] = {3,4,5,8,1,0};
    quick_sort(a, 0, 5);
    for (int i=0;i<6;i++){
        cout<<a[i]<< " ";
    }
    return 0;
}