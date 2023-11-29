#include <stdio.h>

int main(){
    long int num1 = 0, num2 = 0;
    long int *p = NULL;

    p = &num1; *p = 2; ++num2; num2 += *p;

    p = &num2; ++*p;

    printf("%ld %ld\n", num1, num2);
    printf("%ld %ld\n", *p, *p+num2);
    return 0;
}