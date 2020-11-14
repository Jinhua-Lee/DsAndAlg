#include"02_SingleLinkedList.h"

/* 测试单链表的方法*/
void testSingleLinkedList()
{
	int length;
	printf("请输入链表长度：\n");
	scanf_s("%d", &length);
	ElementType* datas = new ElementType[length];
	printf("请输入链表的 %d 个元素：\n", length);
	for (int i = 0; i < length; i++)
	{
		scanf_s("%d", datas + i);
	}

	// =====带头结点=====
	// 指向头节点的指针：头指针
	SL head = NULL;

	// 初始化
	int initStatus = initList_SLh(head);
	printf("initStatus: %d\n", initStatus);

	// 尾插法
	int tailInsertStatus = tailInsert_SLh(head, datas, length);
	printf("tailInsertStatus: %d\n", tailInsertStatus);

	// 长度
	int listLength = listLength_SLh(head);
	printf("带头结点，单链表长度为： %d\n", listLength);

	// 遍历
	traveseList_SLh(head);

	// =====不带头结点=====
	SL sL;

	// 初始化
	int initStatus2 = initList_SL(sL);
	printf("initStatus2: %d\n", initStatus2);

	// 尾插法
	int tailInsertStatus2 = tailInsert_SL(sL, datas, length);
	printf("tailInsertStatus2: %d\n", tailInsertStatus2);

	// 长度
	int listLength2 = listLength_SL(sL);
	printf("不带头结点，单链表长度为： %d\n", listLength2);

	// 遍历
	traverseList_SL(sL);

}

/* 01_单链表——初始化_带头结点
*/
Status initList_SLh(SL& head)
{
	// 指向头节点的指针
	head = (SL)malloc(sizeof(SL_Node));
	if (!head)
	{
		return ERROR;
	}
	head->data = NULL;
	head->next = NULL;
	return OK;
}

/* 02_单链表——初始化_无头结点*/
Status initList_SL(SL& sL)
{
	sL = NULL;
	return OK;
}

/* 03_单链表——长度_带头结点*/
int listLength_SLh(SL head)
{
	// 初始迭代长度
	int length = 0;
	// 指向头结点的变量
	SL p = head->next;
	while (p)
	{
		length++;
		p = p->next;
	}
	return length;
}

/* 04_单链表——长度_无头结点*/
int listLength_SL(SL sL)
{
	int length = 0;
	// 从头指针开始迭代
	SL p = sL;
	while (p)
	{
		length++;
		p = p->next;
	}
	return length;
}

/* 05_单链表——销毁_带头节点*/
void destroy_SLh(SL& head)
{
	// 定义p指针，指向头节点后的待删除结点
	SL_Node* p;
	// 当前存在待删除结点
	while (head->next)
	{
		// 指向待删除结点
		p = head->next;
		// 头结点连接到后继结点
		head->next = p->next;
		// 进行当前结点的删除
		p->data = NULL;
		p->next = NULL;
		free(p);
	}
}

/* 06_单链表——销毁_无头节点*/
void destroy_SL(SL& sL)
{
	// 指针p，指向当前待删除结点
	SL p;
	while (sL)
	{
		// 每次先指向待删除结点
		p = sL;
		// 头指针指向后继节点
		if (p->next)
		{
			sL = p->next;
		}
		// 进行删除操作
		p->data = NULL;
		p->next = NULL;
		free(p);
	}
}

/* 07_单链表——尾插法建立_带头节点*/
Status tailInsert_SLh(SL& head, ElementType *datas, int length)
{
	// 指针p存放上一个结点
	SL p = head;
	// 用于新建的结点
	SL q = NULL;

	for (int i = 0; i < length; i++)
	{
		// 指针p，每次循环在最后一个结点指针域，进行结点创建
		q = (SL)malloc(sizeof(SL_Node));
		if (!q)
		{
			return ERROR;
		}
		q->data = *(datas + i);
		q->next = NULL;
		// 新结点连接到上一个结点
		p->next = q;
		// 迭代
		p = q;
		q = q->next;
	}
	return OK;
}

/* 08_单链表——尾插法建立_不带头节点*/
Status tailInsert_SL(SL& sL, ElementType* datas, int length)
{
	// 指针p，用来保存上一个结点
	SL p = sL;
	// 指针q，用于创建新结点
	SL q = p;

	for (int i = 0; i < length; i++)
	{
		// 指针p，每次循环在最后一个结点指针域，进行结点创建
		q = (SL)malloc(sizeof(SL_Node));
		if (!q)
		{
			return ERROR;
		}
		q->data = *(datas + i);
		q->next = NULL;
		// 不为第一个结点时
		if (i)
		{
			// 将新节点连到p后面
			p->next = q;
			// 新节点作为上一个结点
			p = q;
			
		}
		// 为第一个结点时q新创建的地址赋值给链表标识sL，以及上一个结点标识p
		else
		{
			sL = q;
			p = q;
		}
		// 指针q，再移动到新结点创建位置
		q = q->next;
	}
	return OK;
}

/* 09_单链表——头插法建立_带头结点*/
Status headInsert_SLh(SL& head, ElementType* datas, int length)
{
	// 指针p，用作保存上一个创建的结点，使得头节点指向的新创建结点指向上一个结点。
	SL p = head->next;
	for (int i = 0; i < length; i++)
	{
		// 每次通过头结点创建新结点
		head->next = (SL)malloc(sizeof(SL_Node));
		if (!head->next)
		{
			return ERROR;
		}
		head->next->data = *(datas + i);
		// i==0，第一个结点即为链表的最后一个元素，next置空
		if (i)
		{
			head->next->next = NULL;
		}
		else
		{
			head->next->next = p;
		}
		p = head->next;
	}
	return OK;
}

/* 10_单链表——头插法建立_不带头结点*/
Status headInsert_SL(SL& sL, ElementType* datas, int length)
{
	// 同上，指针p用来保存上一个创建的结点，当新节点创建时候，next域赋值给p
	SL p = sL;
	for (int i = 0; i < length; i++)
	{
		sL = (SL)malloc(sizeof(SL_Node));
		if (!sL)
		{
			return ERROR;
		}
		sL->data = *(datas + i);
		// i==0，第一个结点即为链表的最后一个元素，next置空
		if (i)
		{
			sL->next = NULL;
		}
		else
		{
			sL->next = p;
		}
		p = sL;
	}
	return OK;
}

/* 11_单链表——遍历_带头节点*/
void traveseList_SLh(SL head)
{
	SL p = head->next;
	printf("开始遍历！\n");
	while (p)
	{
		visit(*p);
		p = p->next;
	}
	printf("遍历结束！\n");
}

/* 12_单链表——遍历_不带头结点*/
void traverseList_SL(SL sL)
{
	SL p = sL;
	printf("开始遍历！\n");
	while (p)
	{
		visit(*p);
		p = p->next;
	}
	printf("遍历结束！\n");
}
/* 13_单链表——访问方法*/
void visit(Hnode hnode)
{
	printf("data -->> %d\n", hnode.data);
}
