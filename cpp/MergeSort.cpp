#include<bits/stdc++.h>
using namespace std;

const int maxn=1111;
int buf[maxn],arr[maxn];
void merge_sort(int arr[],int n){
    int s=2;
    while(s/2<n){
        for(int i=0;i<n;i+=s){
            int st1=i,st2=i+(s>>1);
            int ed1=st2,ed2=min(n,i+s),p=0;
            while(st1<ed1&&st2<ed2){
                if(arr[st1]<arr[st2]) buf[p++]=arr[st1++];
                else buf[p++]=arr[st2++];
            }
            while(st1<ed1) buf[p++]=arr[st1++];
            while(st2<ed2) buf[p++]=arr[st2++];
            for(int j=0;j<p;j++){
                arr[i+j]=buf[j];
            }
        }
        s<<=1;
    }
}

int main()
{
    int n;
    while(scanf("%d",&n)==1){
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        merge_sort(arr,n);
        for(int i=0;i<n;i++){
            printf("%d%c",arr[i],i==n-1?'\n':' ');
        }
    }
	return 0;
}

/*
4 1 2 3 4
4 1 2 4 3
4 1 3 2 4
4 1 3 4 2
4 1 4 2 3
4 1 4 3 2
4 2 1 3 4
4 2 1 4 3
4 2 3 1 4
4 2 3 4 1
4 2 4 1 3
*/
