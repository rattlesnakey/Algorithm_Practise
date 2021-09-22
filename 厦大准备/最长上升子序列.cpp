#include<iostream>
#include<vector>
using namespace std;
// 一个是最长上升子序列，一个是上升子序列的和最大
int max_count[100];
int prefix_index_count[100];
int prefix_index_sum[100];
int max_sum[100];
int sum_max = -1;
int count_max = -1;
int sum_max_index = -1;
int count_max_index = -1;


// 注意，c++中如果要初始化除0之外的其他值，必须用memset
int main(){
    memset(prefix_index_count, -1, sizeof(prefix_index_count));  // memset自带就有了，memset(a, value, sizeof(a));
    memset(prefix_index_sum, -1, sizeof(prefix_index_sum));  // prefix 一开始都要初始化为-1，因为找路径的时候终止条件就是-1
    int a[] = {9,10,11,1,2,3,4,5}; 
    // dp一般都是要去进行初始化的，要记得
    for(int i=0;i<10;i++){
        max_count[i] = 1;  // 一开始每个上升序列的个数只有它自己本身
        max_sum[i] = a[i]; // 一开始每个上升序列的和值就是他自己
    }
    // cout<<prefix_index_count[2]<<endl;
    for(int i=0;i<10;i++){
        for(int j=0;j<i;j++){
            if (a[i] > a[j] && max_count[i]<max_count[j]+1){  //遍历所有前缀，找最大
                max_count[i] = max_count[j] + 1;
                prefix_index_count[i] = j;  // 记录前缀
            }
            if (max_count[i] > count_max){  // 保存整个当中最大的
                count_max = max_count[i];
                count_max_index = i;
            }
            if (a[i] > a[j] && max_sum[i]<max_sum[j]+a[i]){
                max_sum[i] = max_sum[j] + a[i];
                prefix_index_sum[i] = j;
            }
            if (max_sum[i] > sum_max){
                sum_max = max_sum[i];
                sum_max_index = i;
            }
        }
    }
    vector<int > count_route;
    vector<int > sum_route;
    cout<<"最长上升子序列长度:"<<max_count[count_max_index]<<endl;
    cout<<prefix_index_count[3]<<endl;
    count_route.push_back(a[count_max_index]);
    while(prefix_index_count[count_max_index] != -1){
        count_max_index = prefix_index_count[count_max_index];
        count_route.push_back(a[count_max_index]);
    }
    cout<<count_route.size()<<endl;
    for(int i = count_route.size()-1;i>=0;i--){
        if (i == 0) cout<< count_route[i]<<endl;
        else cout<<count_route[i]<<" ";
    }


    cout<<"和值最大上升子序列和值:"<<max_sum[sum_max_index]<<endl;
    sum_route.push_back(a[sum_max_index]);// 第一个值先进来
    while(prefix_index_sum[sum_max_index] != -1){
        sum_max_index = prefix_index_sum[sum_max_index];
        sum_route.push_back(a[sum_max_index]);  
    }
    // 最后再倒序输出回来就可以了
    for(int i = sum_route.size()-1;i>=0;i--){
        if (i == 0) cout<< sum_route[i]<<endl;
        else cout<<sum_route[i]<<" ";
    }
    return 0;
}