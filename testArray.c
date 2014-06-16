#include <stdio.h>

int main(void){
    int a[5]={1,2,3,4,5};
    *(a+5)=100;
    printf("%d\n",*(a+1));
    printf("%d\n",*(&a));
    int (*p)[5] = &a;
    printf("%d\n",**(p+1));
}
