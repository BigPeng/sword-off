#include <stdio.h>
int invalid = 0;
double powerUnsigned(double base,unsigned int exponent){
    double result = 1.0;
    for(int i=0;i<exponent;i++)
        result *= base;
    return result;
}
/***有递归求幂次方***/
double powerRecursion(double base,unsigned int exponent){
    if(exponent == 0)
        return 1;
    if(exponent == 1)
        return base;
    double result = powerRecursion(base,exponent >> 1);
    result *= result;
    if(exponent & 0x1 == 1)
        result *= base;
    return result;
}
int equal(double a,double b){
    double diff = a - b;
    if(diff > -0.0000001 && diff < 0.0000001)
        return 1;
    return 0;
}
double power(double base,int exponent){
    //printf("%f %d\n",base,exponent);
    if(equal(base,0.0) && exponent <= 0){
        invalid = 1;
        return 0.0;
    }
    unsigned int absExp;
    if (exponent >=0)
        absExp = (unsigned int)(exponent);
    else
        absExp = (unsigned int)(-exponent);
    //double result = powerUnsigned(base,absExp);
    double result = powerRecursion(base,absExp);
    if (exponent < 0) 
        return 1.0/result;
    return result;
    
}
int main(void){
    double base;
    int exponent;
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        scanf("%lf %d\n",&base,&exponent);
        invalid = 0;
        double result = power(base,exponent);
        if (invalid==1)
            printf("INF\n");
        else
            printf("%.2ef\n",result);
    }
    return 0;
}
