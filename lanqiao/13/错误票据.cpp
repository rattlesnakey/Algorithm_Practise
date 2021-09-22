#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
using namespace std;

int n;

int main(){
    cin>>n;
    getchar();
    for(int i=0;i<n;i++){
        int temp_buff[100] = {-1};
        string temp;
        getline(cin,temp);
        stringstream s (temp);
        int temp_int;
        int index = 0;
        while(s>>temp_int){  // 应该是反向的了
            temp_buff[index++] = temp_int;
        }
        sort(temp_buff,temp_buff+index);  // 记得再排一下序
        int idx1,idx2;
        int flag1 = 0;
        int flag2 = 0;

        for(int j=1;j<index;j++){
            if (flag1&&flag2)break;
            if (temp_buff[j] == temp_buff[j-1]){
                idx1 = j;
                flag1 = 1;
            }
            if(temp_buff[j] == temp_buff[j-1]+2){
                idx2 = j;
                flag2 = 1;
            }
        }
        cout<<temp_buff[idx1] <<" "<<temp_buff[idx2]-1<<endl;
    }
    return 0;
}