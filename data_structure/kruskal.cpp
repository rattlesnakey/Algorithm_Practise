#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct edge{
    int left,right;
    int weight;
    edge(int x, int y, int w):left(x),right(y),weight(w){};
};

int find_father(vector<int> &father, int x){
    int a = x;
    // 它的父亲是它自己的话就结束
    while(x!=father[x]){
        x = father[x];
    }
    // 把它过来的这一路的结点的father都赋值成刚才最后找到的
    while(a != father[a]){
        // 相当于z是工作指针，a是回溯指针
        // a用来给出路径上的所有结点，z用来赋值
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

bool cmp(edge x, edge y){
    return x.weight>y.weight;
}

int main(){
    freopen("kruskal_in.txt","r",stdin);
    // n个顶点
    int n;
    // m条边
    int m;
    int i,j,w;
    cin>>n;
    cin>>m;
    // 初始化m条边列表
    vector<edge > e(m);
    while(cin>>i>>j>>w){
        cout<<i<<j<<w<<endl;
        e.push_back(edge(i,j,w));
    }
    // 从大到小排列
    sort(e.begin(),e.end(),cmp);

    // 初始化father矩阵
    vector<int >father(n);
    for(int i=0;i<n;i++){
        father[i] = i;
    }

    int sum = 0;
    int count = 0;
    // 遍历所有的边，选n-1条边进来
    for(int i=0;i<e.size();i++){
        edge cur_edge = e[i];
        int cur_left = cur_edge.left;
        int cur_right = cur_edge.right;
        int left_father = find_father(father,cur_left);
        int right_father = find_father(father,cur_right);
        if(left_father != right_father){
            father[left_father] = right_father;
            sum += cur_edge.weight;
            count ++;
        }
        // 找到n-1条边就出去
        if (count == n-1){
            break;
        }
    }
    cout<<sum<<endl;
    return 0;
}