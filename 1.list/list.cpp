#include <iostream>
#include <cstdio>
using namespace std;

const int MaxSize = 10;
const int InitSize = 10;

// 定义一个静态整型顺序表：包含了数据阈和元素长度
typedef struct {
    int data[MaxSize];
    int length;
}SqList;

// 定义一个动态整型顺序表
typedef struct {
    int *data;
    int length;
    int maxSize;
}SeqList;

// 初始化链表
void initSqList(SqList &L){
    for(int i = 0; i < MaxSize; i++)
        L.data[i] = 0;
    L.length = 0;
}

// 初始化一个动态顺序表
void initSeqList(SeqList &L){
    L.data = (int*)malloc(sizeof(int) * InitSize);
    L.maxSize = InitSize;
    L.length = 0;
}

// 增加动态数组长度
void increaseSize(SeqList &L, int len){
    int *p = L.data;
    L.data = (int*)malloc(sizeof(int) * (L.maxSize + len));
    for (int i = 0; i < L.length; i++){
        L.data[i] = p[i];
    }
    L.maxSize += len;
    free(p);
}

// 插入操作: 在第k个位置插入元素e
bool listInsert(SqList &L, int k, int e){
    if(k < 1 || k > L.length+1) return false;
    if(k >= MaxSize) return false;
    for(int i = L.length; i >= k; i--)
        L.data[i] = L.data[i-1];
    L.data[k-1] = e;
    L.length ++;
    return true;
}

// 删除操作
bool listDelete(SqList &L, int i, int &e){
    if(i < 1 || i > L.length) return false;
    for(int j = i; j < L.length; j++)
        L.data[j-1] = L.data[j]; 
    L.length --;
    return true;
}

// 查找操作
bool find(SqList &L, int i, int &e){
    if(i < 1 || i > L.length) return false;
    e = L.data[i-1];
    return true;
}

int main(){
    SqList l;
    initSqList(l);
    bool isInsert = listInsert(l,1,999);
    printf("%d\n",l.data[0]);
    listInsert(l,2,67);
    listInsert(l,3,123);
    listInsert(l,4,90);
    printf("length : %d\n",l.length);
    int e = -1;
    listDelete(l, 2, e);
    printf("length : %d\n",l.length);
    printf("delete E : %d\n",e);
    find(l,2,e);
    printf("find E : %d\n",e);
    return 0;
}