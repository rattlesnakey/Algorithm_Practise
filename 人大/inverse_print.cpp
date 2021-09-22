#include<iostream>
#include<string.h>
using namespace std;

typedef struct node{
    int data;
    node* left_child;
    node* right_child;
};

int result[100];
int idx = 0;
void transverse(node* t){
    if (t!=NULL){
        result[idx++] = t->data;
        transverse(t->left_child);
        transverse(t->right_child);
    }
}
int main(){
    for(int i = idx-1;i>0;i--){
        cout<<result[i]<<" ";
    }
    return 0;
}
