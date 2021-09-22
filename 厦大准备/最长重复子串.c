#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>

int main(int argc, char *argv[]){
    char str[] = "aabbbbbaaaaaac";
    int max_len = -1; int count_len = 1; int index = -1;
    for(int i=0; i<strlen(str)-1;i++){
        if (str[i+1] == str[i]){
            count_len ++;
        }
        else{
            if (count_len > max_len){
                max_len = count_len;
                index = i - max_len + 2;
            }
            count_len = 1;
        }
    }

    // 最后结尾要再算一遍
    if (count_len > max_len){
        max_len = count_len;
        index = strlen(str) - max_len + 2;
    }
    printf("%d %d",max_len, index);
    return 0;
}