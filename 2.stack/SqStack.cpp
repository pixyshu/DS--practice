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
    push(s,123);
    push(s,456);
    push(s,789);
    
    printf("这里作为顺序栈的实现\n");
    return 0;
}