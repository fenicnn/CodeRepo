#include<bits/stdc++.h>
using namespace std;

//����CPU�Ǵ��ģʽ����С��ģʽ
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
