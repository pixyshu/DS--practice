#include <cstdio>
#include <iostream>
using namespace std;

// 链式节点的定义
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;       // 使用LNode 强调这是一个结点   使用LinkList 强调这是一个单链表

// 初始化一个单链表（不带头结点）
bool InitList(LinkList L){
    L = (LNode*)malloc(sizeof(LNode));
    if (L == NULL)
        return false;
    L->next = NULL;
    return true;
}

// 头插法创建单链表
LinkList CreateListByHeadInsert(LinkList &L){
    LNode *s; int x;
    L = (LNode*)malloc(sizeof(LNode));
    L -> next = NULL;
    scanf("%d", &x);

    while (x != 999){
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d",&x); 
    }
    
    return L;
}

// 尾插法创建单链表
LinkList CreateListByTailInsert(LinkList &L){
    LNode *r, *s; int x;
    L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;
    r = L;
    scanf("%d",&x);

    while (x != 999){
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = r->next;
        r->next = s;
        r = s;
        scanf("%d",&x);
    }

    return L;
}

// 链表的元素的个数
int length(LinkList L){
    LNode *p = L->next;
    int j = 0;
    if(p == NULL) return 0;
    while (p != NULL){
        p = p->next;
        j++;
    }
    return j;
}

// 按序插入元素
bool listInsert(LinkList &L, int i, int e){
    LNode *p = L;
    int len = length(L);
    int j = 0;

    if(i < 1 || i > len) return false;
    LNode *s = (LNode*)malloc(sizeof(LNode));
    s->data = e;

    while (j < i){
        p = p->next;
        j++;
    }

    s->next = p->next;
    p->next = s;
    return true;
}

// 按序删除结点
bool listDelet(LinkList &L, int i){
    LNode *pre =L, *p = L;
    int len = length(L) ,j = 0;
    if(i < 1 || i > len) return false;
    while (j < i && p != NULL){
        pre = p;
        p = p->next;
        j++;
    }
    pre->next = p->next;
    free(p);
    return true;
}


// 按序号查找
LNode* getElement(LinkList L, int i){
    int j = 1;
    LNode* p = L->next;

    if(i == 0) return L;
    if(i < 1) return NULL;

    while(p != NULL && j < i){
        p = p->next;
        j++;
    } 

    return p;
}

// 按值查找
LNode* getElementByValue(LinkList L, int e){
    LNode *p = L->next;

    while (p != NULL){
        if(p->data == e)
            return p;
        p = p->next;
    } 

    if(p == NULL) return NULL;
    else return p;
}

// 打印链表元素
void show(LinkList L){
    LNode *p = L->next;
    while (p  != NULL)
    {
        printf("elem : %d \n",p->data);
        p = p->next;
    } 
}


int main(){
    LinkList L;
    CreateListByHeadInsert(L);
    show(L);

    if(listInsert(L,1,99))
        printf("插入元素成功\n");
    
    show(L);
    printf("插入元素后，链表长度为：%d\n", length(L));

    // 按元素序号删除单链表元素
    if(listDelet(L,2))
        printf("删除元素成功\n");
    show(L);

    return 0;
}
