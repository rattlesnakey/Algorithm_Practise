#include<iostream>
using namespace std;
int n,m;
bool conflict[7][7];
int ans;
int up[7];
int pow(int x, int y){  // 如果是只有顶面不同的话，中间的这些都相同的话，中间就不能都是4种了，只能是最后一个乘以4
    int temp_result = 1;
    for(int i=1;i<=y;i++){
        temp_result = temp_result * x;
    }
    return temp_result;
}

void dfs(int upp, int num){
    if(num == n ){  // 这边不是n+1，而是n自己尝试一下，这边就相当于是每个叶子结点是一种解
        ans += 4;
        //ans += pow(4,n);
        return;
    }
    for(int i=1;i<=6;i++){
        if(conflict[upp][i]) continue;  //这边相当于是先选底面
        dfs(up[i], num+1);  // 已经选好了当前的这一个了
    }

}
// 这个应该是有问题的应该是每次都要加上4的n次方
int main(){
    up[1] = 4;
    up[2] = 5;
    up[3] = 6;
    up[4] = 1;
    up[5] = 2;
    up[6] = 3;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        conflict[x][y] = true;
        conflict[y][x] = true;
    }
    for(int i=1;i<=6;i++){
        dfs(i,1);
    }
    // cout<<ans*4;
    //cout<<ans;
    return 0;
}