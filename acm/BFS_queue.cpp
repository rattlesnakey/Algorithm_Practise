/* 
最短路径BFS
*/
#include<iostream>
#include<queue>
using namespace std;
int A,B,n;
typedef struct node{
    int index;
    int cur_step;
    node(int idx, int c_step){
        index = idx;
        cur_step = c_step;
    }
} node;

int main(){
    cin>>n>>A>>B;
    queue<node > q_list;
    q_list.push(node(A,0));  // A的下角标和当前的step
    while(!q_list.empty()){
        node cur_node = q_list.front();  // front只是取出来
        q_list.pop();  // 取完记得pop
        int cur_index = cur_node.index;
        int cur_step = cur_node.cur_step;
        if (cur_index == B){
            cout<<cur_step<<endl;
            break;
        }
        if (cur_index - 1>=0){
            q_list.push(node(cur_index-1,cur_step+1));
        }
        if (cur_index +1 <=n){
            q_list.push(node(cur_index+1,cur_step+1));
        }
        if (cur_index * 2 <=n){
            q_list.push(node(cur_index*2,cur_step+1));
        }
    }
    return 0;
}