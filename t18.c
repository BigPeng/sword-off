#include <stdio.h>
#include <stdlib.h>
#define N 10001
struct Tree{
    int value;
    struct Tree *left;
    struct Tree *right;
};
typedef struct Tree Tree;

Tree *nodes[N];
Tree *readTree(int n){
    if(n == 0)//nodes使用的全局变量，n==0时应该返回空而不是nodes[0]
        return NULL;
    for(int i=0;i<n;i++){//读所有结点
        nodes[i] = (Tree *)malloc(sizeof(Tree));
        scanf("%d",&(nodes[i]->value));
    }
    for(int i=0;i<n;i++){//链接每个结点的左右孩子
        int c;
        scanf("%d",&c);
        nodes[i]->left=NULL;//先假设每个孩子都为空
        nodes[i]->right = NULL;
        for(int j=0;j<c;j++){
            int index;
            scanf("%d",&index);
            if(j==0)
                nodes[i]->left = nodes[index-1];
            if(j==1)
                nodes[i]->right = nodes[index-1];
        }
    }
    return nodes[0];
}
int doesHasTree(Tree *a,Tree *b){
    if(b == NULL)//这句必须放在a==NULL之前
        return 1;
    if(a == NULL)
        return 0;
//    printf("a->value:%d,b->value:%d\n",a->value,b->value);
    if(a->value != b->value)
        return 0;
    return doesHasTree(a->left,b->left) && doesHasTree(a->right,b->right);
}
int hasTree(Tree *a,Tree *b){
    if(a==NULL||b==NULL)
        return 0;
    int result = 0;
    if(a->value == b->value){
        result = doesHasTree(a,b);//找到一个相等结点，可能包含该子树
    //    printf("doesHasTree:%d\n",result);
    }
    if(result==0)
        result = hasTree(a->left,b);//在a的左子树查找
    if(result==0)
        result = hasTree(a->right,b);//在a的右子树查找
    return result;

    
}
int main(void){
    int m,n;
    while(scanf("%d%d",&m,&n) != EOF){
        Tree *t1 = readTree(m); 
        Tree *t2 = readTree(n); 
        if(hasTree(t1,t2))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
