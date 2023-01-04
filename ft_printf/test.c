#include<stdio.h>
#include <limits.h>
#include <math.h>

void main (void)
{
    printf("================type====================\n");
    printf("1. 십진수로 출력: % -d \n", 123);
    printf("2. 부호있는 십진수로 출력: %i \n", 123);
    printf("3. 부호없는 8진수로 출력: %o \n", 123);
    printf("4. 부호없는 십진수로 출력: %u \n", 123);
    printf("5. 부호없는 16진수로 출력(소문자): %x \n", 123);
    printf("6. 부호없는 16진수로 출력(대문자): %X \n", 123);    
    printf("7. 부동 소수점 표기로 출력: %f \n",123.45);
    printf("8. 지수형 표기로 출력(소문자): %e  \n",123.45);
    printf("9. 지수형 표기로 출력(대문자):  %E \n",123.45);
    printf("10. 간단한 표기로 출력(소문자): %g \n",123.45);
    printf("11. 간단한 표기로 출력(대문자): %G \n",123.45);
    printf("12. 문자 출력: %c \n",'a');
    printf("13. 문자열 출력: %s \n", "Hello");
    printf("14. 퍼센트 문자 출력: %%\n");
    printf("15. 메모리 주소 출력: %p \n","Hello");
    printf("16. long long 형식 출력: %lld\n", 0x123456789012345);    
 
    printf("================flag====================\n");
    printf("1. flag 지정하지 않고 10진수로 출력: %8d \n",123);
    printf("2. flag에 -를 지정하여 10진수로 출력: %-8d \n", 123);
    printf("3. flag에 +를 지정하여 10진수로 출력: %+d\n",123);
    printf("4. flag 지정하지 않고 8진수로 출력: %o\n",123);
    printf("5. flag에 #을 지정하여 8진수로 출력: %#o\n",123);
    printf("6. flag 지정하지 않고 16진수로 출력:%X\n",123);
    printf("7. flag에 #을 지정하여 16진수로 출력:%#X\n",123);
 
    printf("===========width와 .prec, modifier ======\n");
    printf("1.flag #을 지정하여 16진수로 출력(대문자): %#X \n",0x123456);
    printf("2.flag #, modifier h를 지정하여 16진수로 출력(대문자): %#hX \n",0x123456);
    printf("3.flag #, width 12 지정하여 16진수로 출력(대문자): %#12X \n",0x123456);
    printf("4.flag #, width 012 지정하여 16진수로 출력(대문자): %#012X \n",0x123456);
    printf("5. .prec를 .3을 지정하여 부동 소수점 표기로 출력: %.3f \n",123.456789);
    
 
    printf("===========long long 타입 출력 ===========\n");
    printf("lld 사용: %lld\n", 1234567890123);
 
    printf("========pow(10.0,-50)출력======\n");
    printf("Lf 사용:%.50Lf\n", pow(10.0,-50));    

    printf("==================test==================\n");
    printf("%- 7d\n", 5);
    printf("%- 7d\n", -5);
    printf("%%%     -7.8s\n", 0);

    printf("%-7d\n", 123);
    printf("%-7 d\n", 123);
    printf("% % \n", 123);
    printf("% d\n", -12345);
}

/*
1. 십진수로 출력:  123 
2. 부호있는 십진수로 출력: 123 
3. 부호없는 8진수로 출력: 173 
4. 부호없는 십진수로 출력: 123 
5. 부호없는 16진수로 출력(소문자): 7b 
6. 부호없는 16진수로 출력(대문자): 7B 
7. 부동 소수점 표기로 출력: 123.450000 
8. 지수형 표기로 출력(소문자): 1.234500e+02  
9. 지수형 표기로 출력(대문자):  1.234500E+02 
10. 간단한 표기로 출력(소문자): 123.45 
11. 간단한 표기로 출력(대문자): 123.45 
12. 문자 출력: a 
13. 문자열 출력: Hello 
14. 퍼센트 문자 출력: %
15. 메모리 주소 출력: 01366D4C 
16. long long 형식 출력: 81985529205302085
================flag====================
1. flag 지정하지 않고 10진수로 출력:      123 
2. flag에 -를 지정하여 10진수로 출력: 123      
3. flag에 +를 지정하여 10진수로 출력: +123
4. flag 지정하지 않고 8진수로 출력: 173
5. flag에 #을 지정하여 8진수로 출력: 0173
6. flag 지정하지 않고 16진수로 출력:7B
7. flag에 #을 지정하여 16진수로 출력:0X7B
===========width와 .prec, modifier ======
1.flag #을 지정하여 16진수로 출력(대문자): 0X123456 
2.flag #, modifier h를 지정하여 16진수로 출력(대문자): 0X3456 
3.flag #, width 12 지정하여 16진수로 출력(대문자):     0X123456 
4.flag #, width 012 지정하여 16진수로 출력(대문자): 0X0000123456 
5. .prec를 .3을 지정하여 부동 소수점 표기로 출력: 123.457 
===========long long 타입 출력 =========== 
lld 사용:1234567890123 
========pow(10.0,-50)출력======
Lf 사용:0.00000000000000000000000000000000000000000000000001
*/