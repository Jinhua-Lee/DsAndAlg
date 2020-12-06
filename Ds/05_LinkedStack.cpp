#include "05_LinkedStack.h"

/* 测试单链栈的方法*/
void testLinkedStack()
{
    // 定义单链栈
    LS Ls;

    // 初始化
    printf("LinkedStack init...\n");
    initStack_LS(Ls);

    // 入栈
    LinkedStackElementType top;
    printf("LinkedStack push...\n");

    push_LS(Ls, 5);
    getTop_LS(Ls, top);
    printf("Top elem -> %d\n", top);

	push_LS(Ls, 6);
	getTop_LS(Ls, top);
	printf("Top elem -> %d\n", top);

	push_LS(Ls, 7);
	getTop_LS(Ls, top);
	printf("Top elem -> %d\n", top);

    // 出栈
    LinkedStackElementType poped;
    while (pop_LS(Ls, poped))
	{
		printf("Pop:\ttop = %d\n", poped);
	}
}

/* 01_单链栈——初始化*/
Status initStack_LS(LS& Ls)
{
    Ls = NULL;
    return OK;
}

/* 02_单链栈——取栈顶*/
Status getTop_LS(LS& Ls, LinkedStackElementType& elem)
{
    if (stackEmpty_LS(Ls))
    {
        return ERROR;
    }
    elem = Ls->data;
    return OK;
}

/* 03_单链栈——入栈*/
Status push_LS(LS& Ls, LinkedStackElementType elem)
{
    // 类似于单链表的头插法
    // 指针p用于新创建结点
    LS p = (LS)malloc(sizeof(S_Node));
    // 指针q用来保存
    LS q = Ls;
    // 创建结点失败，返回
    if (!p)
    {
        return ERROR;
    }
    p->data = elem;
    // 进行头插
    p->next = q;
    Ls = p;
    return OK;
}

/* 04_单链栈——出栈*/
Status pop_LS(LS& Ls, LinkedStackElementType& elem)
{
    // 栈为空，返回错误
    if (stackEmpty_LS(Ls))
    {
        return ERROR;
    }
    LS p = Ls;
    // 赋值
    elem = p->data;
    // 指针后移
    Ls = Ls->next;
    // 销毁出栈结点
    delete p;
    return OK;
}

/* 05_单链栈——栈长度*/
int stackLength_LS(LS Ls)
{
    int length = 0;
    // 直接用s做迭代，所以不能取引用类型
    while (Ls)
    {
        length++;
        Ls = Ls->next;
    }
	return length;
}

/* 06_单链栈——判空*/
Status stackEmpty_LS(LS Ls)
{
    // 为空返回非0，否则返回0
    return Ls == NULL ? OK : ERROR;
}

/* 07_单链栈——清空*/
Status clearStack_LS(LS& Ls)
{
    // 指针p，保存栈顶元素
    LS p;
    while (Ls)
    {
        // 保存栈顶元素
        p = Ls;
        // 栈顶指针后移
        Ls = Ls->next;
        // 销毁栈顶元素
        delete p;
    }
    delete Ls;
    return OK;
}
