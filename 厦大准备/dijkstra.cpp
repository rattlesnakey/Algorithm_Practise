#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int INF = 999999;
struct node{  // 也是一样，只保存右顶点和权值就可以了
    int v;
    int dis;
    node(int x, int y):v(x), dis(y){};
};
int n; // vetice_num
int m; // edge_num
bool include[100];
int main(){
    FILE *f = NULL;
    f = fopen("read.txt","r");
    fscanf(f,"%d",&n);  // 第一个参数是指针别忘了
    fscanf(f,"%d",&m);
    vector<vector<node> >e(n+1);  // 里面的node有n+1个，先创建好才能被index引用
    vector<int>d(n+1);
    fill(d.begin(),d.end(),INF);  // fill 函数用起来
    d[1] = 0;  // 和prim算法一样，也都是需要有一个distance数组的
    for(int i=0;i<m;i++){  // 和prim 算法一样，都是要构建一个邻接表，我觉得dijkstra构建的邻接表比较好，就是一开始要把邻接表的index都建好才行
        int x,y,w;
        fscanf(f,"%d %d %d",&x,&y,&w);
        e[x].push_back(node(y,w));
    }
    for(int i=1;i<=n;i++){
        // 每次从d里面选一个最小值
        int cur_min = INF;
        int cur_min_idx = -1;
        for(int j=1;j<=n;j++){
            if(include[j]!=true && d[j]<cur_min){  // 从没进来的里面选最小
                cur_min_idx = j;
                cur_min = d[cur_min_idx];
            }
        }
        if(cur_min_idx == -1){
            break;  // 已经没有点可以加进来了，其他那些点都是远点达不到的
        }
        include[cur_min_idx] = true;  // 加入进来
        // 这边上半部分和prim算法真的是一摸一样
        // 更新
        vector<node> temp_vec = e[cur_min_idx];
        for(int k=0;k<e[cur_min_idx].size();k++){
            int temp_v = temp_vec[k].v;
            int temp_dis = temp_vec[k].dis;
            if(d[cur_min_idx] + temp_dis < d[temp_v]){
                d[temp_v] = d[cur_min_idx] + temp_dis;  // prim是只加一个，就是直接加那个边就可以了，dijkstra的话是要加到原点的距离，所以得把原点到当前最短距离节点的距离也加上去才可以
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<d[i]<<" ";
    }
    return 0;
}