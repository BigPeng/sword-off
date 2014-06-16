#include <stdio.h>
#include <stdlib.h>
struct Node{
    long value;
    struct Node *next;
};
typedef struct Node Node;

Node *read(int n){
    Node *head = NULL;
    Node *p= NULL;
    for(int i=0;i<n;i++){
        Node *q = (Node *)malloc(sizeof(Node));
        long v;
        scanf("%ld",&v);
        q->next = NULL;
        q->value = v;
        if(head == NULL){
            head = q;
            p = head;
         }else{
             p->next = q;
             p = q;
          }        
    }
    return head;
}
void print(Node *kNode,int n){
    if(kNode==NULL)
        printf("NULL\n");
    else{
        for(int i=0;i<n;i++){
            printf("%ld%c",kNode->value,i==n-1?'\n':' ');
            kNode = kNode->next;
         }
    }
}
Node *merge(Node *a,Node *b){
    if(a == NULL)
        return b;
    if(b == NULL)
        return a;
    Node *m = NULL;
    Node *head = NULL;
    if(a->value<b->value){
        head = a;
        a = a->next;
    }else{
        head = b;
        b = b->next;
    }
    m = head;
    while(a && b){
        if(a->value < b->value){
            m->next = a;
            m = a;
            a = a->next;
        }else{
            m->next = b;
            m = b;
            b = b->next;
        }            
    }
    if(a)
        m->next = a;
    if(b)
        m->next = b;
    return head;
}
int main(void){
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF){
        Node *heada = read(m);
        Node *headb = read(n);
        Node *head = merge(heada,headb);
        print(head,m+n);
    }
    return 0;

}
