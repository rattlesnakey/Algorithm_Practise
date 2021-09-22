#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct node{
    int j;
    int weight;
    node(int x, int y):j(x), weight(y){};
}node;
const int INF = 100000;

int main(){
    int n,m; // 顶点个数和边的个数
    freopen("dijkstra.txt","r",stdin);
    cin>>n>>m;
    vector<vector<node> >e(n+1);  // 顶点从1开始，所以需要n+1个位置
    vector<int> d(n+1);
    fill(d.begin(),d.end(),INF);
    d[1] = 0; // 从第一个顶点开始
    vector<bool> include(n+1);
    fill(include.begin(),include.end(),false);
    // 存边
    for(int i=0;i<m;i++){
        int k,j,w;
        cin>>k>>j>>w;
        e[k].push_back(node(j,w));
    }
    // 计算出到其他每个顶点的最短距离，也就是要include进来n个顶点
    for(int i=1;i<=n;i++){
        int cur_min = INF;
        int cur_min_idx = -1;
        // 找最小
        for (int j=1;j<=n;j++){
            if (include[j]!=true && d[j] < cur_min){
                cur_min = d[j];
                cur_min_idx = j;
            }
        }
        // 没找到，只要里面有一轮没有找到的话，就提前结束了
        if (cur_min_idx == -1){
            return -1;
        }
        // 记得要include赋值一下
        include[cur_min_idx] = true;
        vector<node> temp_vec = e[cur_min_idx];
        for(int k=0;k<temp_vec.size();k++){
            int right_node = temp_vec[k].j;
            int cur_weight = temp_vec[k].weight;
            // 踩着当前进来的最短的点
            if(d[cur_min_idx] + cur_weight < d[right_node]){
                d[right_node] = d[cur_min_idx] + cur_weight;
            }
        }

        
    }
    for(int i=1;i<=n;i++){
        cout<<d[i]<<" ";
    }
    cout<<endl;
    return 0;
}