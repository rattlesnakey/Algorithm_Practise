#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct node{
    int j;
    int d;
    node(int x, int y):j(x),d(y){};
}node;
const int INF = 1000000;
int main(){
    int n;
    freopen("in.txt","r",stdin);
    cin>>n;
    // 邻接表
    vector<vector<node> >m(n);
    // U集合到剩下的各个点的最小距离
    vector<int >dis(n);
    // 用algorithm里面fill函数来初始化
    fill(dis.begin(),dis.end(),INF);
    int i,j,d;
    while(cin>>i>>j>>d){
        m[i].push_back(node(j,d));
    }

    // 一开始把到起点的距离设为0，以便把起点先通过dis数组选进来到U里
    dis[0] = 0;

    // 用来记录已经进入U集合的点
    vector<bool> include(n);
    fill(include.begin(),include.end(),false);
    int sum = 0;
    // 只要选入n个顶点进来就结束
    for(int i=0;i<n;i++){
        int cur_min_index = -1;
        int cur_min = INF;

        // 每一次都是去遍历dis数组找最短距离
        for(int j=0;j<dis.size();j++){
            if(dis[j]<cur_min && include[j]==false){
                cur_min_index = j;
                cur_min = dis[j];
            }
        }

        // 没找到
        if (cur_min_index == -1){
            return -1;
        }

        include[cur_min_index] = true;
        sum += cur_min;

        // 把它的邻接点取出来
        vector<node> temp_vec = m[cur_min_index];
        for(int k=0;k<temp_vec.size();k++){
            int temp_j = temp_vec[k].j;
            int temp_d = temp_vec[k].d;
            if(temp_d < dis[temp_j]){
                // 更新U到这个点的距离
                // 这个距离直接就是temp_d, 因为是到集合的
                dis[temp_j] = temp_d;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}