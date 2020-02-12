#include<bits/stdc++.h>
using namespace std;

char* strcat(char* dst, const char* src){
    char *ret=dst;
    assert(dst!=NULL&&src!=NULL);
    while(*dst) dst++;
    while(*dst++=*src++);
    return ret;
}
char* strcpy(char *dst, const char *src){
    assert(dst!=NULL&&src!=NULL);
    char *ret=dst;
    while((*dst++=*src++)!='\0');
    return ret;
}
size_t strlen(const char* str){
    assert(str!=NULL);
    const char* ed=str;
    while(*ed++);
    return ed-str-1;
}
int strcmp(const char *src, const char *dst){
    int ret=0;
    assert(src!=NULL&&dst!=NULL);
    while(!(ret=*(unsigned char*)src-*(unsigned char*)dst)&&*dst!='\0'){
        src++;
        dst++;
    }
    if(ret<0) ret=-1;
    else if(ret>0) ret=1;
    return ret;
}
void *memcpy(void *dst,void *src,size_t len){
    assert(dst!=NULL&&src!=NULL);
    void *ret=dst;
    if(dst<=src||dst>=(char*)src+len){
        while(len--){
            *(char*)dst=*(char*)src;
            dst=(char*)dst+1;
            src=(char*)src+1;
        }
    }else{
        dst=(char*)dst+len-1;
        src=(char*)src+len-1;
        while(len--){
            *(char*)dst=*(char*)src;
            dst=(char*)dst-1;
            src=(char*)src-1;
        }
    }
    return ret;
}
int main(){
    char str[]="Hello";
    printf("%d\n",strlen(str));
    return 0;
}
