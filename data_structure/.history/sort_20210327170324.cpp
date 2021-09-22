#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;

typedef struct student{
    char number[100];
    char name[100];
    int age;
    char sex[5];
} student, * studentL;

bool cmp(student x, student y){
    return strcmp(x.number, y.number)<0;
}

int n;
int t;
student buffer[100];

void print_data(student x){
    cout<<x.number<<" "<<x.name<<" "<<x.sex<<" "<<x.age;
}
int main(int argc, char *argv[]){
    while(scanf("%d", &n)!=EOF){
        for(int i=0;i<n;i++){
            cin>>buffer[i].number>>buffer[i].name>>buffer[i].sex>>buffer[i].age;
        }
    }
    sort(buffer,buffer+n,cmp);  //就地直接排好序了
    scanf("%d",&t);
    char temp_num[100];
    while(t-- !=0 ){

        int base = 0;int top = n-1;
        scanf("%s", temp_num);
        int mid = (base + top)/2;
        if (strcmp(buffer[mid].number, temp_num)==0){
            
        }
    }
    return 0;
}