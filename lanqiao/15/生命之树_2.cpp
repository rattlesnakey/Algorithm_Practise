// 做不出来
#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;
int n;
int father[100];
int w[100];
int s[100];  // 分别代表每个连通图的和
struct edge{
    int u,v;
    edge(int x, int y):u(x), v(y){};
};

int find_father(int father[], int x){
    int a = x;
    while(x!=father[x]){
        x = father[x];
    }
    while (a!=father[a]){
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}
int get_max_sum(){  // 当前时刻，每个连通子图的和中最大的那个和
    int cur_max = -1;
    // for(int i=0;i<n;i++){
    //     s[father[i]] += w[i];  // 同属于一个父亲结点的都加到一个地方去
    // }
    for(int i=0;i<n;i++){
        if(s[i]>cur_max){
            cur_max = s[i];
        }
    }
    return cur_max;
}

int main(){
    cin >> n;
    vector<edge> e;
    int max_sum = -1;
    for(int i=1;i<=n;i++){
        int temp_w;
        cin>> temp_w;
        w[i] = temp_w;
        s[i] = 0;
        father[i] = i;
    }
    for(int i=0;i<n-1;i++){
        int temp_u, temp_v;
        cin>>temp_u>>temp_v;
        e.push_back(edge(temp_u, temp_v));
    }
    // 去看同一个father下面结点的和
    for(int i=0;i<n-1;i++){
        int cur_u = e[i].u;
        int cur_v = e[i].v;
        int u_father = find_father(father, cur_u);
        int v_father = find_father(father, cur_v);
        if(u_father != v_father){
            father[u_father] = v_father;
            // s[u_father] = s[u_father] + s[v_father];  // 把和值也合并起来
            // int temp_max = get_max_sum();
            // if (temp_max>max_sum){
            //     max_sum = temp_max;
            // }
        }
    }
//     // 应该等全部的连通图都构建好以后再去找，因为，可能最大值只是连通结点中的几个
//     // cout<<max_sum;
//     for(int i=1;i<=n;i++){
//         cout<<find_father(father, i)<< " "; // 全部是同一个祖先
//     }
//     map<int, set<int> > all_set;
//     for(int i=1;i<=n;i++){ // 每一个终极father 代表一个最小连通图
//         all_set[find_father(father, i)].insert(i);
//     }
// // 先定义类型，再定义iterator，然后都是begin和end
//     for(map<int,set<int> >::iterator it = all_set.begin();it !=all_set.end();it++){
//         set<int> cur_set = it->second;
//         for(int i=0;i<n-1;i++){
//         if (cur_set.count(e[i].u) && cur_set.count(e[i].v)){

//         }
//         }
//         for(set<int >::iterator i = it->second.begin();i != it->second.end();i++){

//         }
//     }
    return 0;
}