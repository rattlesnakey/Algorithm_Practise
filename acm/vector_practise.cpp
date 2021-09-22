#include<iostream>
#include<vector>
using namespace std;
int ans[14] = {0};
int main(int argc, char *argv[]){
    vector<vector<int> > vec_temp(4, vector<int> (3,0));  // 这个里面就不需要再指定名称了
    for(int i=0;i<vec_temp.size();i++){
        for (int j=0; j<vec_temp[i].size();j++){
            cout<< vec_temp[i][j]<<" ";
        }
        cout<<endl;
    }
    vector<vector<int> > vec;
    for(int i =0;i<4;i++){
        vector<int > x (i+1,i+1);
        vec.push_back(x);
    }
    for(int i=0;i<vec.size();i++){
        for (int j=0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    vec.clear(); // 直接清空，但是内存里面的内容不清空，所以这里处理的应该只是指针而已
    for(int i=0;i<vec.size();i++){
        for (int j=0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}