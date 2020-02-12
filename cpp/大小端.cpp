#include<bits/stdc++.h>
using namespace std;

//测试CPU是大端模式还是小端模式
void checkCPU()
{
    union MyUnion
    {
        int a;
        char c;
    }test;
    //cout << sizeof(test)<<endl;
    test.a = 1;
    if (test.c == 1)
        cout << "little endian" << endl;
    else
        cout << "big endian" << endl;
}

int main(){
    checkCPU();
    return 0;
}
