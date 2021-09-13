#include <cstdio>
using namespace std;

const int MAXSIZE = 10;

// 顺序栈定义
typedef struct {
    int data[MAXSIZE];
    int top;
}SqStack;

// 初始化栈
void InitStack(SqStack &s){
    s.top = -1;     // -1 表示栈为空
}

// 判空
bool isEmpty(SqStack s){
    if(s.top == -1) return true;
    else return false;
}

// 进栈
bool push(SqStack &s, int e){
    if(s.top == MAXSIZE -1) return false;
    s.data[++s.top] = e;
    return true;
}

// 出栈
bool pop(SqStack &s, int &e){
    if(s.top == -1) return false;
    e = s.data[s.top--];
    return true;
}

// 读栈顶元素
bool getTopElement(SqStack &s, int &e){
    if(s.top == -1) return false;
    e = s.data[s.top];
    return true;
}

int main(){
    SqStack s;
    InitStack(s);
    if(isEmpty(s)) 
        printf("初始化栈，栈元素为空\n");
    
    push(s,123);
    push(s,456);
    push(s,789);
    
    if(isEmpty(s) != true)
        printf("栈元素不为空，可以开始其他操作\n");

    int e;
    pop(s,e);

    printf("此时的栈顶元素为：%d,将其出栈\n",e);
    printf("栈内元素个个数为：%d\n",s.top+1);

    printf("这里作为顺序栈的实现\n");
    return 0;
}