#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int father[100];

struct edge{
    int u,v;  // 边的左右顶点
    int weight;
    edge(int x, int y, int w):u(x),v(y),weight(w){};  // 这里就不需要再重新struct了, 因为构造函数不需要任何东西了
};

bool cmp(edge x, edge y){
    return x.weight < y.weight;
}



/*
int find_father(int father[], int x){
    while(x!=father[x]){
        x=father[x];
    }
    return x;
}
*/

int find_father(int father[], int x){
    int a = x;  // 相当于是用a再走一遍
    while(x!=father[x]){
        x=father[x];
    }
    // 下面这个主要是把沿路的father都赋值成最后的祖先
    while(a!=father[a]){
        int z = a;  // 你用来放
        a = father[a];  // 我先走
        father[z] = x;
    }
    return x;
}

void kruskal(vector<edge> &e, int vertix_num, int edge_num){
    for(int i=0;i<vertix_num;i++){  // 记得初始化father！！
        father[i] = i;
    }
    sort(e.begin(), e.end(), cmp);
    int cur_edge_num = 0;
    int cur_weight_num = 0;
    for(int i=0;i<edge_num;i++){
        int f1 = find_father(father,e[i].u);
        int f2 = find_father(father,e[i].v);
        if(f1!=f2){
            father[f2] = f1;  // 注意，这里是赋值父亲结点！！
            cur_edge_num ++;  //相当于把这条边加入进来
            cur_weight_num += e[i].weight;
            if (cur_edge_num == vertix_num - 1){
                break;
            }
        }
        
    }
    if(cur_edge_num < vertix_num - 1){
        cout<<"没有找到"<<endl;
    }
    else{
        cout<<cur_weight_num<<endl;
    }
}
int main(){
    vector<edge > E;// 旧版本不能直接初始化
    // E.push_back(edge(0,1,4));
    // E.push_back(edge(1,2,1));
    // E.push_back(edge(2,3,6));
    // E.push_back(edge(3,4,5));
    // E.push_back(edge(0,4,1));
    // E.push_back(edge(0,5,2));
    // E.push_back(edge(1,5,3));
    // E.push_back(edge(2,5,5));
    // E.push_back(edge(3,5,4));
    // E.push_back(edge(4,5,3));
    // int n = 6;
    // int m = 10;
    freopen("kruskal_in.txt","r",stdin);
    // n个顶点
    int n;
    // m条边
    int m;
    int i,j,w;
    cin>>n;
    cin>>m;
    // 初始化m条边列表
    while(cin>>i>>j>>w){
        E.push_back(edge(i,j,w));
    }
    kruskal(E, n, m);
    return 0;
}