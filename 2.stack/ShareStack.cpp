#include <cstdio>
using namespace  std;

const int MaxSize = 10;

// 定义共享栈结构体
typedef struct {
    int data[MaxSize];
    int top[2];
}ShareStack;

// 初始化共享栈
void InitShareStack(ShareStack &s){
    s.top[0] = -1;
    s.top[1] = MaxSize;
}

// 校验栈标志函数
bool isAvailabe(int flag){
    if(flag != 0 || flag != 1) return false;
    return true;
}

// 判空
bool isEmpty(ShareStack &s, int flag){
    if(isAvailabe(flag)) return false;      // 操作栈指针非法校验
    if(flag == 1){
        if(s.top[flag] == MaxSize ) return true;
        else return false;
    }else{
        if(s.top[0] == -1) return true;
        else return false;
    }
}

// 判空函数
bool isEmpty(ShareStack &s, int flagA, int flagB){
    if(isAvailabe(flagA) && isAvailabe(flagB)) return false;
    if(s.top[flagA] == -1 && s.top[flagB] == MaxSize) return true; 
    else return false;
}

// 入栈
bool push(ShareStack &s, int flag, int e){
    if(isAvailabe(flag)) return false;      // 操作栈指针非法
    if(s.top[0] == s.top[1] - 1) return false;      // 判断栈满
    if(flag == 1) s.data[--s.top[1]] = e;          // 如果为右边栈，则栈指针需要减1，再赋值，反之
    else s.data[++s.top[0]] = e;
    return true;
}

// 出栈
bool pop(ShareStack &s, int flag, int &e){
    if(isAvailabe(flag)) return false;      // 操作栈指针非法校验
    if(isEmpty(s,flag)) return false;     // 栈为空
    if(flag == 1) e = s.data[s.top[1]++];
    else e = s.data[s.top[0]--];
    return true;
}

// 获取栈顶元素
bool getTopElement(ShareStack &s, int flag, int &e){
    if(isAvailabe(flag)) return false;
    if(isEmpty(s,flag)) return false;
    e = s.data[s.top[flag]];
    return true;
}

int main(){
    ShareStack ss;
    InitShareStack(ss);
    if(isEmpty(ss,0,1)) printf("刚刚初始化，共享栈还是空\n"); 
    push(ss,0,123);
    push(ss,1,789);
    push(ss,0,345);
    push(ss,1,567);
  
    int x = 0;
    getTopElement(ss,1,x);
    printf("右边栈顶元素是：%d\n",x);

    pop(ss,0,x);
    printf("左边栈出栈元素为：%d\n",x);
    return 0;
}
