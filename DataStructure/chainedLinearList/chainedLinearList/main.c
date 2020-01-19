//
//  main.c
//  chainedLinearList
//
//  Created by 杨磊 on 2019/12/20.
//  Copyright © 2019 Yang To. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1

#define ERROR 0

#define TRUE 1

#define FALSE 0

#define MAXSIZE 1000


typedef int  Status; //Status 函数的类型，其值是函数结果状态代码
typedef int  ElemType; //ElemType 类型根据情况而定

typedef struct{
    ElemType data;
    int cur;  //游标(Cursor),为0时表示无指向
}Component,StaticLinkList[MAXSIZE];


/*
 初始条件，静态链表L已经存在，操作结果返回L中数据元素的个数
 */
int ListLength(StaticLinkList L){
    int j=0;
    int i=L[MAXSIZE-1].cur;
    while (i) {
        i=L[i].cur;
        j++;
    }
    return j;
}

/*
 将一维数组space中个分量链成一条。                     3  备用链表
 space[0].cur 为头指针，"0“表示空指针
 */
Status InitList(StaticLinkList space){
    int i;
    for (i=0; i<MAXSIZE-1; i++) {
        space[i].cur=i+1;
    }
    space[MAXSIZE-1].cur=0; //目前静态链表为空，最后一个元素的cur为0
    return OK;
}

/*
 若备用空间链表非空，则返回分配的结点下标，否则返回05
 */
int Malloc_SLL(StaticLinkList space){
    int i=space[0].cur;  //当前数组的第一个元素的cur存的值
    if (space[0].cur) {     //返回第一个备用空闲的下标
        space[0].cur=space[i].cur; //由于要拿出一个分量来使用了，所以我们把它的下一个分量拿来做备用
    }
    return i;
}

/*
 在L中的第i个元素之前插入新的数据元素e
 */

Status ListInsertOf(StaticLinkList L,int i,ElemType e){
    int j,k,l;
    k=MAXSIZE-1;  //k是第一个元素的下标
    if (i<1||i>ListLength(L)+1) {
        return ERROR;
    }
    j=Malloc_SLL(L);
    if (j) {
        L[j].data=e;
        for (l=1; l<=i-1; l++) {
            k=L[k].cur;
        }
        L[j].cur=L[k].cur;
        L[k].cur=j;
        return OK;
    }
    return ERROR;
}



typedef struct Node{
    ElemType data;
    struct Node *next;
}Node;

typedef struct Node *LinkList;

void ListPrint(LinkList head){
    LinkList p=head->next;
    while (p!=NULL) {
        printf("->%d",p->data);
        p=p->next;
    }
    printf("\n");
}

void CreateListHead(LinkList *L,int n){
    LinkList p;
    srand((unsigned int)time(0)); //srand(unsigned int) time(long) 需要强制类型转换 初始化随机种子
    *L=(LinkList)malloc(sizeof(Node));
    (*L)->next=NULL; //建立一个带头节点的单链表
    for (int i=0; i<n; i++) {
        p=(LinkList)malloc(sizeof(Node)); //生产新结点
        p->data=rand()%100+1; //随机生成1～100的数字
        p->next=(*L)->next;
        (*L)->next=p; //插入到表头
    }
}

void CreateListTail(LinkList *L,int n){
    LinkList p,r;
    srand((unsigned int)time(0)); //srand(unsigned int) time(long) 需要强制类型转换 初始化随机种子
    *L=(LinkList)malloc(sizeof(Node)); //为整个线性表
    r=*L; //r为指向为尾部的结点
    for (int i=0; i<n; i++) {
        p=(Node *)malloc(sizeof(Node)); //生成新结点
        p->data=rand()%100+1; //生产1～100随机数
        r->next=p;      //将表尾终端结点的指针指向新结点
        r=p;    //将当前的新结点定义为表尾终端结点
    }
    r->next=NULL;
}

Status GetElem(LinkList L,int i,ElemType *e){
    /*
     功能: 用e返回L的第i个元素
     思想：工作指针后移
     */
    int j;
    LinkList p; //声明一结点p
    p=L->next;  //p指向L的第一个结点
    j=1; //计数器
    while (p&&j<i) { //p不为空或者j不等于i时，继续循环
        p=p->next; //让p指向下一个结点
        ++j;
    }
    if (!p||j>1) {
        return ERROR; //第i个元素不存在
    }
    *e=p->data; //获取第i个元素的数据
    return OK;
}

Status ListInsert(LinkList *L,int i,ElemType e){
    int j;
    LinkList p,s;
    p=*L;
    j=1;
    while (p&&j<i) { //寻找第i个结点
        p=p->next;
        ++j;
    }
    if (!p||j>i) {
        return ERROR; //第i个元素不存在
    }
    s=(LinkList)malloc(sizeof(Node)); //生成新结点
    s->data=e;
    s->next=p->next; //将p的后继节点赋值给s的后继
    p->next=s; //将s赋值给p的后继
    return OK;
}

Status ListDelete(LinkList *L,int i,ElemType *e){
    int j;
    LinkList p,q;
    p=*L;
    j=1;
    while (p->next && j<i) { //寻找第i个元素
        p=p->next;
        ++j;
    }
    if (!(p->next)||j>i) {
        return ERROR; //第i个元素不存在
    }
    q=p->next;
    p->next=q->next; //将q的后继赋值给p的后继
    *e = q->data;         //将q结点中的数据给e*
    free(q);        //s释放内存
    return OK;
}
//创建链表
int create_List(Node **p) {
    int data = 0;
    int ret = 0;
    Node *pHead = NULL; //头结点指针
    Node *node = NULL;
    Node *tmp = NULL;
    pHead = (Node *)malloc(sizeof(Node));//创建一个头结点
    if(pHead == NULL) {
        ret = -1;
    }
    tmp = pHead;
    printf("请输入一个整数数据n");//等待用户输入整数数据，输入-1结束
    scanf("%d", &data);
    while(data != -1) {
        node = (Node *)malloc(sizeof(Node));//创建新节点
        if(node == NULL) {
            ret = -1;
            printf("List_Create erron");
        }
        node->data = data;//为新节点赋值
        tmp->next = node;//将当前节点添加至当前链表末尾
        tmp = node;//将当前指向的节点指针指向新节点
        printf("请输入一个整数数据n");
        scanf("%d", &data);
    }
    node->next = NULL;
    *p = pHead;
    return ret;
}

Node* headcreat(int n)
{
    Node* head = (Node*)malloc(sizeof(Node));

    head->data = n;

    head->next = NULL;

    for (int i = 0; i < n; i++) {

        Node* p = (Node*)malloc(sizeof(Node));

        printf("请输入第%d个数据:",(i + 1));

        scanf("%d", &p->data);

        p->next = head->next;

        head->next = p;

    }

    return head;
}

void traverse_List(Node* pHead) {
    Node* pCur;//创建用于遍历链表的指针
    if(pHead == NULL || pHead->next == NULL) {
        printf("LinkList is NULLn");//表为空
    }

    pCur = pHead;//将pCurrent指向头节点
    while(pCur->next) { //当前节点不为最后的节点
        printf("%d ", pCur->next->data);//输出数据值
        pCur = pCur->next;//将当前节点指针后移，指向下一个节点
    }

}

//查找数据为value的节点
Node* find_List(Node *pHead, int value){
    Node *pTmp; //遍历链表指针
    if(pHead == NULL || pHead->next == NULL) {
        printf("Node is NULLn");
        return NULL;
    }

    pTmp = pHead;
    while(pTmp->next) {//遍历链表
        printf("%d ", pTmp->next->data);
        if(pTmp->next->data == value){//判断值是否相等
            pTmp = pTmp->next;//查找到目标节点
            return pTmp; //返回目标节点
        }
        pTmp = pTmp->next;//继续向下查找
    }
    return NULL;//查找失败
}

void* delete_List(Node * pHead, int data){
    //void 是说明无返回值
    //    void * 才可以返回NULL!
    if(pHead == NULL || pHead->next == NULL) {
        printf("Node is NULLn");
        return NULL;
    }

    while(1){
        int flag=-1;
        Node* pCur;//指向当前节点的指针
        Node* pPre;//指向当前节点的上一个节点指针
        pCur = pHead->next;
        pPre= pHead;
        while(pCur){
            if(pCur->data==data){//元素比较
                //将当前节点的前驱节点的next指向当前节点的后继节点
                pPre->next = pCur->next;
                flag = 1;
                break;
            }

            //继续向后查找
            pCur = pCur->next;
            pPre = pPre->next;

        }

        if(flag==1){
            free(pCur);//释放当前节点占据空间
            printf("节点删除成功n");
        }else{
            printf("此链表找不到这个值n");
        }

    }

}

//单链表逆序
void reverseLinkList(Node* pHead) {
    Node* pPre = NULL;//指向当前节点的上一个节点
    Node* pCur = NULL;//指向当前节点的指针
    Node* pTmp = NULL;
    if(pHead == NULL || pHead->next == NULL || pHead->next->next == NULL) {
        return;
    }

    pPre = pHead->next;
    pCur = pHead->next->next;

    while(pCur) {//遍历整个链表
        //交换顺序，实现逆序
        pTmp = pCur->next;
        pCur->next = pPre;
        pPre = pCur;
        pCur = pTmp;
    }

    pHead->next->next = NULL;
    pHead->next = pPre;

}

/*
 初始条件：顺序线性表L已存在，操作结果：将L重置为空表
 */
Status ClearList(LinkList *L){
    LinkList p,q;
    p=(*L)->next;  //*p 指向第一个结点
    while (p) {         //没到表尾
        q=p->next;
        free(p);
        p=q;
    }
    (*L)->next=NULL;  //头结点指针域为空
    return  OK;
}

int main(int argc, const char * argv[]) {
   
    return 0;
}
