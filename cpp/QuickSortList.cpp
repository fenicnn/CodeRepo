#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int val=0):val(val),next(nullptr) {}
};
pair<Node*,Node*> qsort(Node* head) {
    if(!head)
        return make_pair(nullptr,nullptr);
    Node thead[2];
    Node *pre[2]= {&thead[0],&thead[1]};
    Node *p=head->next;
    head->next=nullptr;
    while(p) {
        int cur=0;
        if(p->val>=head->val)
            cur=1;
        pre[cur]->next=p;
        pre[cur]=pre[cur]->next;
        p=p->next;
    }
    pre[0]->next=pre[1]->next=nullptr;
    pair<Node*,Node*> lef=qsort(thead[0].next);
    pair<Node*,Node*> rig=qsort(thead[1].next);
    pair<Node*,Node*> ret=make_pair(head,head);
    if(lef.second!=nullptr) {
        (lef.second)->next=head;
        ret.first=lef.first;
    }
    if(rig.first!=nullptr) {
        head->next=rig.first;
        ret.second=rig.second;
    }
    return ret;
}
void print(Node* head) {
    while(head) {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main() {
    while(1) {
        int n;
        cin>>n;
        Node thead = Node(0);
        Node* pre=&thead;
        for(int i=0; i<n; i++) {
            int x;
            cin>>x;
            pre->next=new Node(x);
            pre=pre->next;
        }
        pair<Node*,Node*> ret=qsort(thead.next);
        print(ret.first);
    }
    return 0;
}
