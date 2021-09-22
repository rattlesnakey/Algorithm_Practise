#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

void printVec(vector<int> nums)
{
    for (int i = 0; i < nums.size(); ++i)
        cout << nums[i] << " ";
    cout << endl;
}
void heap(void)
{
    int nums_temp[] = {8, 3, 4, 8, 9, 2, 3, 4, 10};
    vector<int> nums(nums_temp, nums_temp + 9);
    cout << "make_heap之前: ";
    printVec(nums);

    cout << "(默认(less))make_heap: ";
    make_heap(nums.begin(), nums.end());  // 默认是最大堆，也就是less
    printVec(nums);

    cout << "(less)make_heap: ";
    make_heap(nums.begin(), nums.end(), less<int> ());  // less<int > 和 greater<int>是相对的
    printVec(nums);  // num数组原地变成heap了

    cout << "(greater)make_heap: ";
    make_heap(nums.begin(), nums.end(), greater<int> ());
    printVec(nums);

    cout << "此时，nums为小顶堆 greater" << endl;
    cout << "push_back(3)" << endl;
    nums.push_back(3);  // 现在本地的vector push 整个重新push_heap
    cout << "默认(less)push_heap 此时push_heap失败: ";
    push_heap(nums.begin(), nums.end());
    printVec(nums);
    cout << "push_heap为greater 和make_heap一致，此时push_heap成功: ";
    push_heap(nums.begin(), nums.end(), greater<int>());
    printVec(nums);
    cout << "(greater,不然会失败)pop_heap: ";
    pop_heap(nums.begin(), nums.end(),greater<int>());  // pop_heap 会pop到num的最后一个元素，然后num在pop_back出来
    printVec(nums);
    cout << "pop_back(): ";
    int r = nums.back();
    nums.pop_back();
    printVec(nums);
    cout<<"r:"<<r;
}
int main(){
    vector<int > a {1,2,5,4};
    set<int >b {2,3,4};
    set<int >c {4,5,6};
    auto it = is_sorted_until(a.begin(),a.end());
    vector<int > r;
    cout<< *it<<endl;
    // cout<<is_sorted_until(a.begin(),a.end());
    
	int iarr1[]={1,2,3,3,4,5,6,7};
	int iarr2[]={1,4,3,9,10};
	multiset<int> iset1(begin(iarr1),end(iarr1));  //好像要multiset才可以，然后普通的数组的话可以直接begin(a), end(a)
	multiset<int> iset2(begin(iarr2),end(iarr2));
	vector<int> ivec(10);  
	auto iter=set_union(iset1.begin(),iset1.end(),iset2.begin(),iset2.end(),ivec.begin());	//ivec为：2,3,5,6,7
	//ivec.resize(iter-ivec.begin());//重新确定ivec大小
    cout<<ivec[0];
    cout<<"----------------------"<<endl;
    // heap();
    a.insert(a+1,3);
    
	return 0;
}