#include<iostream>
#include<algorithm>
using namespace std;

int a[] = {0,5,4,2,3,11,34,1};  // 7个数，第一个数是用来填充待会调整的时候，待调整的根节点所在的位置

void heap_adjust(int a[], int k, int len){  // 数组，待调整的子树根节点k，最后结点的下角标
    a[0] = a[k];
    for(int i=2*k;i<=len;i*=2){  // 每次乘以2就是每次往下一层
        int cur_max_idx = -1;
        if(i<=len && i+1<=len){  // 注意，因为第一个位置是暂存的，所以是等于len
            if (a[i]<a[i+1]){
                cur_max_idx = i+1;
            }
            else{
                cur_max_idx = i;
            }
        }
        if(i<=len && i+1>len){
            cur_max_idx = i;
        }
        // 这边不要有小于i<len了，max_idx会被重新赋值
        if(a[0]<a[cur_max_idx]){  // 就是循环网上移动的感觉
            a[k] = a[cur_max_idx];
            k = cur_max_idx;
        }
        else{
            break;
        }
    }
    a[k] = a[0];
}

void build_heap(int a[], int len){  // 从最后一个非叶子结点 len/2开始调整
    for(int i=len/2;i>=1;i--){
        heap_adjust(a, i, len);
    }
}

void heap_sort(int a[], int len){
    build_heap(a, len);
    cout<<a[1]<<" ";
    // 最后一个元素和堆顶进行交换
    for(int i=len;i>=2;i--){

        // 排好的就放到最后面去
        swap(a[1],a[i]);
        // 都是调整以第一个数作为根节点的子树, 然后只要处理到i-1的位置就行
        heap_adjust(a, 1, i-1);
        cout<<a[1]<<" ";
    }
}

int main(){
    heap_sort(a, 7);
    return 0;
}