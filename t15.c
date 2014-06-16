#include <stdio.h>
#include <stdlib.h>
struct Node{
    long value;
    struct Node *next;
};
struct Node * findK(struct Node *head, long k){
    if(head == NULL||k==0)
        return NULL;
    struct Node *end =head;
    struct Node *start = head;
    for(int i=0;i<k-1;i++){
        if(end->next != NULL)
            end = end->next;
        else
            return NULL;        
    }
    while(end ->next != NULL){
        end = end->next;
        start = start->next;
    }
    return start;
}
int main(void){
    int  n,k;
    while(scanf("%d%d",&n,&k)!=EOF){       
        struct Node *head = NULL;
        struct Node *p= NULL;
        for(int i=0;i<n;i++){
            struct Node *q = (struct Node *)malloc(sizeof(struct Node));
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
        struct Node *kNode = findK(head,k);
        if(kNode)
            printf("%ld\n",kNode->value);
        else 
            printf("NULL\n");
    }
}
