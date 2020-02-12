#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

void up_heap(vector<int>& arr, int p, int n) {
    while(p&&arr[p]>arr[(p-1)/2]) {
        swap(arr[p],arr[(p-1)/2]);
        p=(p-1)/2;
    }
}

void down_heap(vector<int>& arr, int p,int n) {
    while(p*2+1<n) {
        if(p*2+2<n&&arr[p*2+2]>arr[p*2+1]) {
            swap(arr[p],arr[p*2+2]);
            p=p*2+2;
        } else {
            swap(arr[p],arr[p*2+1]);
            p=p*2+1;
        }
    }
    up_heap(arr,p,n);
}

void make_myheap(vector<int>& arr,int n) {
    for(int i=(n-2)/2; i>=0; i--) {
        down_heap(arr,i,n);
    }
}

void heap_sort(vector<int>& arr) {
    make_myheap(arr,arr.size());
    int n=arr.size();
    while(--n) {
        swap(arr[0],arr[n]);
        down_heap(arr,0,n);
    }
}

int main() {
    while(1) {
        cout<<"<<<<<<<<<<<<<<<<<<<"<<endl;
        vector<int> arr;
        int n;
        cin>>n;
        while(n--) {
            int x;
            cin>>x;
            arr.push_back(x);
        }
        heap_sort(arr);
        for(auto x:arr)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}

/*
2
2 1
2
1 2
1
1
3
1 2 3
3
1 3 2
3
2 1 3
3
2 3 1
3
3 1 2
3
3 2 1
*/
