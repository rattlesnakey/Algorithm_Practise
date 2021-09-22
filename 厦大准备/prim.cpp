#include<iostream>
#include<map>
#include<vector>
#include<algorithm>  // fill函数在这里面，memset在cstdlib里
using namespace std;

const int INF = 1000000;
struct node{
    int u;
    int dis;
    node(int x, int y):u(x), dis(y){};  // 存的是右顶点和值
};
int sum;
int n;
vector<vector<node> >m(10);  // 邻接表, 注意，不要写错了，是vector<vector>,不是像map那样的，外层vector的index就是左顶点，所以node只需要存储右顶点就可以了
// vector<int> d(n);  // 与S集合的最小距离，记得先开辟出来，才能使用index进行引用
bool include[100];
int main(int argc, const char *argv[]){
    freopen("in.txt", "r", stdin);  // C++注意要用双引号
    cin>>n;  // 与S集合的最小距离，记得先开辟出来，才能使用index进行引用
    vector<int> d(n);
    int temp_i, temp_j, temp_d;
    //scanf("%d %d %d",&temp_i,&temp_j,&temp_d)!=EOF
    while(cin>>temp_i>>temp_j>>temp_d){
        m[temp_i].push_back(node(temp_j,temp_d));
    }
    // vector<node > temp;
    // temp.push_back(node(4,1));
    // temp.push_back(node(5,2));
    // temp.push_back(node(1,4));
    // m.push_back(temp);
    // temp.clear();

    // temp.push_back(node(0,4));
    // temp.push_back(node(5,3));
    // temp.push_back(node(2,6));
    // m.push_back(temp);
    // temp.clear();

    // temp.push_back(node(1,6));
    // temp.push_back(node(3,6));
    // temp.push_back(node(5,5));
    // m.push_back(temp);
    // temp.clear();

    // temp.push_back(node(2,6));
    // temp.push_back(node(4,4));
    // temp.push_back(node(5,5));
    // m.push_back(temp);
    // temp.clear();

    // temp.push_back(node(0,1));
    // temp.push_back(node(5,3));
    // temp.push_back(node(3,4));
    // m.push_back(temp);
    // temp.clear();

    // temp.push_back(node(0,2));
    // temp.push_back(node(1,3));
    // temp.push_back(node(2,5));
    // temp.push_back(node(3,5));
    // temp.push_back(node(4,3));
    // m.push_back(temp);

    
    fill(d.begin(),d.end(),INF);  // algorithm算法里
    d[0] = 0; // 一开始设根节点为0

    for(int i=0;i<n;i++){  // 一共要选n个点进来
        int cur_min = INF;
        int cur_min_idx = -1;
        for(int j=0;j<n;j++){
            if(d[j]<cur_min && include[j]!=true){  // 还没进来的点里面去选最小值
                cur_min = d[j];
                cur_min_idx = j;
            }
        }
        if(cur_min == INF){
            return -1;  // 没有最小的值了
        }
        include[cur_min_idx] = true;
        sum += d[cur_min_idx];
        vector<node >temp_vec = m[cur_min_idx];
        for(int k=0;k<m[cur_min_idx].size();k++){
            int next = temp_vec[k].u;
            if(temp_vec[k].dis<d[next]){  // 这边就只需要边的距离就行，因为边的距离就等价于到集合的距离了
                d[next] = temp_vec[k].dis;
            }
        }
    }
    cout<<sum;
    return 0;
}