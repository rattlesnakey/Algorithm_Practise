#include<iostream>
#include<algorithm>  // swap在里面
using namespace std;

int a[] = {0,5,4,2,3,11,34,1};  // 7个数
// k就是调整以k为根的这棵树，所以一开始建最大堆的时候是len/2开始，后面每次取出来堆顶重新调整的时候就是都是最上面为根结点的这棵树了
void headadjust(int a[], int k, int len){  // 要比到最后，所以要有len
    a[0] = a[k];  // a[0]的值等最后的k(根节点确定以后)再去放，a[0]是一个暂时存放的空间，也就是书上说的那个额外的空间
    // 把第一个人拿出来
    for(int i=k*2;i<=len;i*=2){  // 这边是i*=2就是每次下去一层
        int cur_max_idx = -1;  // 每进入新的一层确实都要重新选当层的最大值
        // if((i+1<=len && a[i]>a[i+1])){
        //     cur_max_idx = i;
        // }
        // else if (i+1 < len){
        //     cur_max_idx = i;
        // }
        // else {cur_max_idx = i+1;}
        if (i+1<=len && a[i+1]>a[i]){
            cur_max_idx = i+1;
        }
        else{
            cur_max_idx = i;
        }
        // 所有人一个一个地去和第一个人比较，比他大的，就往前走，k就是他要往前走到的位置
        if (a[cur_max_idx] > a[0]){  // 一直都是和a[0]这个值进行比较，就是计算每一层的时候，都是去和a[0]值进行比较，直到比a[0]小的时候，才把当前的a[0]，也就是被调整的这个值放到对应的地方
            a[k] = a[cur_max_idx];  // a[k]的值已经提前给出去了，所以可以被赋值
            k = cur_max_idx;  
            // k是在树中一直往下层走的指针
            // 比当前要被调整的值a[0]来的大的，都往上调，哪个值被调上去了，那么那个值的那个位置就会被下一个值替换
            // 这个k就是用来指明当前这个a[0]值，也就是被调整的这个值，到底要放到哪个节点下面
           
        }
        else {break;}  // 当它的孩子都没他大的时候就结束了
    }
    // 相当于中间都是交换指针，最后才是实质交换
    a[k] = a[0];
}
// void headadjust(int a[], int k, int len){  // 我前面那个写错了
//     a[0] = a[k];  // a[0]的值等最后的k(根节点确定以后)再去放
//     for(int i=k*2;i<=len;i*=2){
//         if(i<len&&a[i]<a[i+1]) i++;
//         if(a[0]>a[i])break;
//         else{
//             a[k]=a[i];
//             k=i;
//         }
//     }
//     a[k] = a[0];
// }

void build_max_heap(int a[], int len){  // 第一次建的时候从最后一个根节点建，而且只需要建一次就行，后面就只需要调整
    for(int i=len/2;i>0;i--){
        headadjust(a, i, len);
    }
}

void heapsort(int a[]){
    build_max_heap(a,7);
    cout<<a[1]<<" ";
    for(int i=7;i>1;i--){  // 待构建最大堆的元素列表的最后一个元素，最后一个元素开始和堆顶替换
        swap(a[1],a[i]);
        headadjust(a,1,i-1);// 从第一个元素开始调整，因为最后一个元素已经交换上去了，所待排序的个数就减少一个
        cout<<a[1]<<" ";  // 一直都是输出堆顶的元素
    }
}
int main(){
    heapsort(a);
    return 0;
}