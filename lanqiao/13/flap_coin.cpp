#include<iostream>
#include<set>
#include<queue>
#include<string>
using namespace std;

typedef struct statelevel{
    string str;
    int level;
    statelevel(string s, int l):str(s),level(l){}
} node;


int main(int argc, char *argv[]){
    string a, b;
    cin>>a>>b;
    queue<node > q;
    q.push(node(a,0));
    set<string > s;

    while(!q.empty()){
        node cur_node = q.front();
        q.pop();
        string temp_str = cur_node.str;
        if(cur_node.str == b){
            cout<<cur_node.level<<endl;
            break;
        }
        for(int i=0;i<a.size()-1;i++){
            if(temp_str[i] == '*'){
                temp_str[i] = 'o';
            }
            else if (temp_str[i]=='o'){
                temp_str[i] = '*';
            }
            else if(temp_str[i+1] == '*'){
                temp_str[i+1] = 'o';
            }
            else if (temp_str[i+1]=='o'){
                temp_str[i+1] = '*';
            }
            if (find(s.begin(),s.end(),temp_str) == s.end()){
                s.insert(temp_str);
                q.push(node(temp_str, cur_node.level+1));
            }
        }

    }
    return 0;
}