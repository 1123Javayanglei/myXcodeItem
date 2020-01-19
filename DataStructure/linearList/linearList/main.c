//
//  main.c
//  linearList
//
//  Created by 杨磊 on 2019/12/19.
//  Copyright © 2019 Yang To. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 101 //存储空间初始分配量

#define OK 1

#define ERROR 0

#define TRUE 1

#define FALSE 0

typedef int  Status; //Status 函数的类型，其值是函数结果状态代码

typedef int  ElemType; //ElemType 类型根据情况而定

typedef struct{
    ElemType data[MAXSIZE]; //d数组存储数据元素，最大值为MAXSIZE
    /*
     线性表从1开始数，所以第n元素的下标为 n-1
     1 2 3 4 5 6 7 8 9 (elem)
     0 1 2 3 4 5 6 7 8 (index)
     */
    int length; //线性表当前长度
}SqList; // 创建别名

void ListPrint(SqList *seq){
    printf("顺序表当前长度为%d\n",seq->length);
    for (int i=1; i<=seq->length; i++) {
        printf("%d ",seq->data[i]);
    }
    printf("\n");
}

void init(SqList *seq){ //初始化
    seq->data[0]=0;
    seq->length=0;
}

Status GetElem(SqList *L,int i){
    /*
     GetElem 函数说明: 如果没有就返回0，如果有就返回这个值
     初始条件: 顺序线性表L已存在  1<=i<=L>ListLength(L)
     */

    if (L->length==0 || i<1 || i>L->length) { //判断i是否在数组的下标范围
        return ERROR;
    }

//    *e=L.data[i-1]; //线性表下标
    return L->data[i];
}

Status ListInsert(SqList *L ,int i,ElemType e){
    /*
     ListInsert设计思路
     在L表中的i位置插入e

      若插入位置不合理，抛出异常
      如果线性表长度大于等于数组长度，则抛出异常或动态增加容量
      从最后一个元素开始向前遍历到第i个元素，分别将他们都后移一个位置
      要插入的元素放入位置i处
      表长加1
     */
    if (L->length==MAXSIZE) { //如果是最大下标，顺序线性表已经满了
        return ERROR;
    }
    if (i<1 || i>L->length+1){ //i不在范围内时
        return ERROR;
    }
    if(i<=L->length){ //插入位置不在表尾
        for (int k=L->length; k>=i-1; k--) {
            L->data[k+1]=L->data[k]; //插入位置的所有元素向后移动一位
        }
    }
    L->data[i]=e; //新元素插入
    L->length++;  //数组长度+1
    return OK;
}

Status ListDelete(SqList *L,int i){
    /*
     ListDelete 思路：
     删除l表的第i个元素
      如果删除位置不合理，抛出异常
      取出要删除的元素
      从删除元素位置遍历到最后一个元素位置，分别将它们向前移动一位
      表的长度减1
     */
    if (L->length==0) {  //表的长度为0
        return ERROR;
    }
    if (i<1 || i>L->length) { //删除位置不合法
        return ERROR;
    }
//    *e=L->data[i-1];  //取出删除元素
    if (i<L->length) {
        for (int k=i+1; k<=L->length; k++) {
            L->data[k-1]=L->data[k];  //从删除元素的位置到最后一个元素的位置，都想前移动一位
        }
    }
    L->length--;
    return OK;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    SqList *p=(SqList*)malloc(sizeof(SqList));
    init(p);
    for (int i=1; i<=10; i++) {
        ListInsert(p, i, i);
    }
    ListPrint(p);
    printf("\n删除2后");
//    ElemType a;
    ListDelete(p, 2);
    ListPrint(p);
    int a,index;
    index=1;
    if ((a=GetElem(p, index))) {
        printf("第%d位的元素是:%d\n",index,a);
    }
    printf("SqList的大小为:%d,等于%d个int\n",(int)sizeof(SqList),(int)((int)(sizeof(SqList))/sizeof(int)));


    return 0;
}
