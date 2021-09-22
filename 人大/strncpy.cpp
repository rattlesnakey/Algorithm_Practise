#include<iostream>
#include<string.h>
using namespace std;

char * my_strncpy1(char *dest, const char *src, int count){
    while(count && (*dest++=*src++)){  // 如果只有while循环的话，那么就要在后面加分号
        count--;
    }  // 会把src的'\0'复制过去，如果长度短的话，src没有全部都复制过去的话，其实用的就是dest的'\0'
    *dest++ = '\0'; // 这个是我觉得可以自己加上去的，就是不管是长还是短，还是等于，最后都给他加一个'\0'
    // 下面这个我觉得其实考试可以不用写其实
    // if(count>0){
    //     while(--count){
    //         *dest++ = '\0'; // 记得每个语句写分号
    //     }
    // }
    return dest;
}

char * my_strncpy2(char *dest, const char *src, int count){
    int final_count;
    if (count>=strlen(src)+1){
        final_count = strlen(src);  // src就是有几个字符，长度就是多少
    }
    else final_count = count;
    for(int i=final_count;i>0;i--){
        *dest++ = *src++;
    }
    * dest++ = '\0';
    return dest;
}

char * my_strncpy3(char *dest, const char *src, int count){
    int final_count;
    if (count>=strlen(src)+1){
        final_count = strlen(src);  // src就是有几个字符，长度就是多少
    }
    else final_count = count;
    int i = 0;
    while(i<final_count){
        *dest++ = *src++;
        i++;
    }
    * dest++ = '\0';
    return dest;
}

int main(){
    char y[10];
    char x[] = "abcd";
    my_strncpy3(y,x,2);
    cout<<y<<endl;
    return 0;
}
