#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;

struct ratio_{
    int fenzi;
    int fenmu;
    ratio_(int x, int y):fenzi(x), fenmu(y){};
};
vector<ratio_> v;
ll gcd(ll x, ll y){
    if(y ==0){
        return x;
    }
    else {
        return gcd(y,x%y);
    }
}
bool check_int(float a, float b){
    return a-int(a)==0 && b-int(b) == 0;  //就是看float值-int值是不是相等的来判断就可以了
}
int get_pow(int x, int y){
    for(int i=1;i<40;i++){
        float kai_x = pow(x,1/i);
        float kai_y = pow(y,1/i);
        cout<<kai_x<<" -- "<<kai_y<<endl;;
        if (check_int(kai_x, kai_y)){
            cout<<"---"<<i<<endl;
            int flag = 1;
            for(int j=1;j<v.size();j++){  // 从第二个比例开始
                int cur_fenzi_pow = pow(v[j].fenzi,1/i);
                int cur_fenmu_pow = pow(v[j].fenmu,1/i);
                if (check_int(cur_fenmu_pow, cur_fenzi_pow)){
                    continue;
                }
                else{
                    flag = 0;
                    break;
                }
            }
            if (flag == 1){
                cout<<kai_x<<"/"<<kai_y;
                return 1;
            }
        }
    }
    return -1;
}

int data_drop[100];
int main(){
    int n;
    cin>>n;
    ll data[100];
    for(int i=0;i<n;i++){
        cin>>data[i];
    }
    sort(data, data+n);
    int idx = 0;
    // memset(data_drop, -1, sizeof(data_drop));
    // cout<<data_drop[0];
    for(int i=0;i<n-1;i++){  // 去重
        if(data[i+1] != data[i] && i==0){
            data_drop[idx++] = data[i];
            data_drop[idx++] = data[i+1];
        }
        if(data[i+1]!= data[i]&&i!=0){
            data_drop[idx++] = data[i+1];
        }
        else{
            continue;
        }
    }
    for(int i=0;i<idx-1;i++){
        int gongyueshu = gcd(data_drop[i+1],data_drop[i]);
        v.push_back(ratio_(data_drop[i+1]/gongyueshu,data_drop[i]/gongyueshu));
    }
    get_pow(v[0].fenzi,v[0].fenmu);
    // cout<<v[0].fenzi<<" "<<v[0].fenmu;
    return 0;
}