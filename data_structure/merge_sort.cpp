#include<iostream>
using namespace std;

int n = 7;
void merge(int a[], int low, int high){
    int i,j,k;
    int *b = (int*)malloc((n+1)*sizeof(int ));
    int mid = (low+high) / 2;
    for (i=low;i<=high;i++){
        b[i] = a[i];  // 复制过来, 因为要在原来的a上面修改
    }
    // 因为已经复制一份出来了，所以直接拿a去被赋值
    for(i = low, j = mid + 1,k = low;i<=mid&&j<=high;k++){ 
        if(b[i]<b[j]){
            a[k] = b[i];
            i++;
        }
        else{
            a[k] = b[j];
            j++;
        }
    }
    while(i<=mid){
        a[k++] = b[i++];
    }
    while(j<=high){
        a[k++] = b[j++];
    }
}


void merge_sort(int a[], int low, int high){
    if (low>=high)return; // 这边要大于等于，如果没有等于的话，那么在等于的情况下会一直递归下去, 也就是mid和low一直都是相等的,merge_sort(a, low, mid)就一直往下递归出不来
    // 这边就是会一直往一个方向走，直到被划分成了只有一个元素的情况
    int mid = (low+high)/2;
    merge_sort(a, low, mid);  // 这边记得要把mid包括进来
    merge_sort(a, mid+1, high);
    // 两个都是只有一个元素的话就是两个元素各自进行了一下merge处理
    merge(a, low, high);
}


int main(){
    int a[] = {4,5,6,1,-1,20,3};
    merge_sort(a, 0, n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}