#include <stdio.h>
#include <stdlib.h>
struct Node{
    long value;
    struct Node *next;
};
typedef struct Node Node;
Node *reverse(Node *head){
    if(head == NULL||head->next == NULL)
        return head;//为空或者只有一个元素
    Node *p = head;
    Node *q = head->next;
    while(q){
        Node *tmp = q->next;
        q->next = p;
        p = q;
        q = tmp;
    }
    head->next = NULL;
    return p;
    
}
int main(void){
    int  n;
    while(scanf("%d",&n)!=EOF){       
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
        scanf("\n");//换行
        Node *kNode = reverse(head);
        if(kNode==NULL)
            printf("NULL\n");
        else{
            for(int i=0;i<n;i++){
                printf("%ld%c",kNode->value,i==n-1?'\n':' ');
                kNode = kNode->next;
            }
        }
        
    }
    return 0;
}
