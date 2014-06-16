#include <stdio.h>
#include <string.h>
//最大的位数
#define N 100
char number[N];
/******对字符串表示的数字序列加1操作**********/
int increment(char *number,int n){
    int carry = 0;
    for(int i = n-1; i>=0; i--){
        int num = number[i] - '0' + carry;
        if(i == n-1)//在最后一位上加1
            num ++;
        if(num < 10){//进位结束
            number[i] = '0' + num;
            break;
        }else{
            if(i == 0)//溢出，已经达到了最大值
                return 0;
            num -= 10;
            carry = 1;
            number[i] = '0' + num;
        }
    }
    return 1;
}
/**********打印字符串表示的数字，必须以\0结束；忽略前面的0*****/
void printNumber(char *number){
    char *p = number;
    while(*p == '0')//跳过前面的0
        p ++;
    while(*p)
        printf("%c",*(p++));
    printf("\n");
}

void print1toN(int n){
    if(n <= 0)
        return;
    memset(number,'0',n);
    number[n] = '\0';
    while(increment(number,n))
        printNumber(number);
}
int main(void){
    int n;
    while(scanf("%d\n",&n) != EOF)
        print1toN(n);
    return 0;
}
