#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// vector<int> a;  // 用01的方式来决定到底哪个格子要哪个格子不要
int ans;

int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void dfs(int temp[3][4], int i, int j){  // 二位数组的话，需要明确的写出来
    temp[i][j] = 0;
    for(int k=0;k<4;k++){
        int tx = i + dir[k][0];
        int ty = j + dir[k][1];
        if(tx>=0 && tx<=2 && ty>=0 && ty<=3 && temp[tx][ty]==1){
            dfs(temp, tx,ty);
        }

    }
}

bool check(vector<int> a){
    int cnt = 0;  // 
    int temp[3][4] = {0};
    // memset(temp,0,sizeof(temp));
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            if(a[i*4+j] == 1){
                temp[i][j] = a[i*4+j];
            }
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            if(temp[i][j]==1){
                dfs(temp, i, j);
                cnt++;
            }
        }
    }
    if(cnt == 1){  //直接连通，没有第二个1了
        return true;
    }
    else{
        return false;
    }
}
void print_a(vector<int> a){
    for(int i=0;i<12;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){ 
    vector<int> a(12);  // 用01的方式来决定到底哪个格子要哪个格子不要
    for(int i=0;i<12;i++){
        if(i<=6){
            a[i] = 0;
        }
        else{
            a[i] = 1;
        }
    }
    do{  // 前面是1，permute不起来，好奇怪
        if(check(a)){
            // print_a(a);
            ans++;
        }
    }while(next_permutation(a.begin(),a.end()));
    cout<<ans;
    return 0;
}