#include<iostream>
#include<string>
#include<vector>
using namespace std;


vector<int> get_next(string b){
    // int next[3];
    vector<int > next(b.length(), -1); // 前面是n, 后面才是-1
    int j = 0; int k = -1;  // j是后面的指针，k是前面的指针
    int length = b.length();
    // next[0]一开始是等于 -1，next[1]才是0，-1只是用来判断而已，因为最后存的都是k++
    // 这个是从0开始啦，j相当于是后缀，k相当于是前缀
    while (j<length){  // j小于模式串的length
        if (k == -1 || b[j] == b[k]){  // next[k]的话，其实是看k-1的元素的值的，反正就是如果当前相等的话，才去给它的下一位赋值
            ++j;
            ++k;
            next[j] = k;  // k == -1的话，相当于就都是直接赋值为0，因为k == -1的时候，k++ 就等于0
        }
        else{
            k = next[k];  // 没有合适的前缀的话就一直回溯
        }

    }
    return next;

        while (j<length){  // j小于模式串的length
        if (k == -1 || b[j] == b[k]){  // next[k]的话，其实是看k-1的元素的值的，反正就是如果当前相等的话，才去给它的下一位赋值
            ++j;
            ++k;
            if (b[j]!=b[k]) next[j] = k;  // 只有两个要比较的值不同才可以
            else next[j] = next[k];  // 跳过，就跳到下一个K
        }
        else{
            k = next[k];  // 没有合适的前缀的话就一直回溯
        }


}

void print_v(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
void kmp(string a, string b){
    vector<int > next = get_next(b);
    int i = 0; int j = 0;  // i 是主串上面的，j是子串下面的
    // int length = a.length();
    int a_length = a.size();  // size必须提前取出来，如果第一次执行完后，第二次再执行a.size()的话，就不是原来的那个长度了
    int b_length = b.size();
    while((i < a_length) && (j < b_length)){  // 这边注意也要b<b.length, 因为b要通过length出来
        if (j == -1 || a[i] == b[j]){
            i++;
            j++;
        }
        else{
            j = next[j];
        }
    }
    print_v(next);cout<<endl;
    if (j == b.size()){  // i 是匹配到的位置的主串的最后一个元素
        cout<< i - b.length() + 1;
    }
}

int main(){
    // "BBC_ABCDAB_ABCDABCDABDE", "ABCDABD"
    string a = "BBC_ABCDAB_ABCDABCDABDE";
    string b = "ABCDABD";
    // cout<<b.length();
    get_next(b);
    kmp(a, b);
    return 0;
}
