//
//  main.c
//  ElementaryMathematics
//
//  Created by 杨磊 on 2019/12/6.
//  Copyright © 2019 Yang To. All rights reserved.
//
/*
 2x+4y=18
 x+y=6
 */
#include <stdio.h>
#include <math.h>
#include <string.h>

int ABS(int a);
double POW(double a, int b);
int gcd(int a,int b);


int main(int argc, const char * argv[]) {
    
//    double i=0;
//            double sums=4;
//            while (sums<3.1415926 || sums>3.1315927){
//                i+=1;
//                sums=sums-4/(4*i-1)+4/(4*i+1);
//    //            System.out.println("当前i="+i+" PI: "+sums);
//            }
//    printf("%lf\n",i);
//    double lmt=100.0;
//    for (double x=-lmt; x<=lmt; x+=0.1) {
//        //        printf("%d",cnt);
//        for (double y=-lmt; y<=lmt; y+=0.1) {
//            //            printf("%d",cnt);
//            for (double z=-lmt; z<=lmt; z+=0.1) {
//                if ( ((x/(x-5))-1) == (2/x) ) {
//                    printf("x=%lf y=%lf z=%lf\n",x,y,z);
//                }
//                    }
//                    }
//                    }

//    int a,b;
//    scanf("%d%d",&a,&b);
//    //最小公倍数等于两数相乘除以最大公约数
//    printf("最大公约数:%d 最小公倍数%d",gcd(a, b),(a*b)/gcd(a, b));

    return 0;
}
int ABS(int a){
    return a>0?a:(-a);
}
double POW(double a, int b)
{
    double r = 1;
    printf("%.0lf的%d次方:\n",a,b);
    for (double i = 0; i < b; ++i){
        r *= a; //等价 r = r*a
        printf("第%.0lf次 R=%.0lf\n",i,r);
    }
    return r;
}
int gcd(int a,int b){
    if (b==0) {
        return a;
    }else if (b!=0){
        return gcd(b, a%b);
    }
    return 0;
}

