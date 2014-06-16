#include <stdio.h>
#define N 10000
/**********判断是否是奇数****/
int isOdd(int num){
    return num % 2 == 1;
}
/****将f(d)为1的数放在f(d)为0的数的前面**/
void reorder(int *data, int n,int (*f)(int)){
    int pivot = *data;
    int *low = data;
    int *high = data + (n-1);
    while(low < high){
        while(low < high && !f(*high))//这种去非操作不会造成死循环，比如f(d)是判断f是否>=0，虽然在low指针会原地踏步，但high指针可以扫过它
            high --;
        while(low < high && f(*low))
            low ++;
       if(low < high){
            int temp = *high;
            *high = *low;
            *low = temp;
       }
    }
    //*low = pivot;
}

void reorder2(int * data,int *help,int n){
    int oddNum = 0;
    for(int i=0;i<n;i++){
        if(isOdd(data[i]))
            help[oddNum++]= data[i];
    }
    for(int i=0;i<n;i++){
        if(!isOdd(data[i]))
            help[oddNum++]= data[i];
    }

}
int main(void){
    int n;
    int data[N];
    int help[N];
    while(scanf("%d\n",&n) != EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&data[i]);
        }
        reorder2(data,help,n);
        //reorder(data,n,isOdd);
        for(int i=0;i<n;i++){
            printf("%d%c",help[i],i==n-1?'\n':' ');
        }
    }
}
