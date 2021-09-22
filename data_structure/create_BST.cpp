#include<iostream>
#include<vector>
using namespace std;

typedef struct node{
    int data;
    node *left_child;
    node *right_child;
}node, *node_point;
int flag = 0;
void insert_node(node_point cur_node, node_point pre_node, int x){  // 我觉得可以带一个当前结点的上一个结点的指针
    if (flag == 1)return;
    if (cur_node == NULL ){
        node_point new_data;
        new_data->data = x;
        new_data->left_child = NULL;
        new_data->right_child = NULL;
        if(x>pre_node->data){
            pre_node->right_child = new_data;
        }
        else{
            pre_node->left_child = new_data;
        }
        flag = 1;
    }
    if (x>cur_node->data) insert_node(cur_node->right_child, cur_node,x);
    if (x<=cur_node->data)insert_node(cur_node->left_child, cur_node, x);
}

void pre_order(node_point t){
    cout<<t->data;
    if(t->left_child != NULL){
        pre_order(t->left_child);
    }
    if(t->right_child != NULL){
        pre_order(t->right_child);
    }
}
int v[10];
int main(){
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int temp_num;
        cin>>temp_num;
        v[i] = temp_num;
        cout<<temp_num<<i<<' ';

    }
    cout<<1;
    cout<<v[0];
    cout<<2;
    node_point root;
    root->data = v[0];
    root->left_child = NULL;
    root->right_child = NULL;
    node_point init_pre = NULL;  // 相当于是-1
    for(int i=1;i<n;i++){
        flag = 0;
        insert_node(root, init_pre, v[i]);
    }
    pre_order(root);
    return 0;
}