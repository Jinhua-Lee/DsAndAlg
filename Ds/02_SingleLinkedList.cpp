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

	// 测试带头结点
	printf("=====带头结点=====");
	testWithHead(datas, length);

	// 测试不带头结点
	printf("=====不带头结点=====");
	testWithoutHead(datas, length);

}

/* 带头结点的测试方法*/
void testWithHead(ElementType* datas, int length)
{
	// =====带头结点=====
	// 指向头节点的指针：头指针
	SL head = NULL;

	// 初始化
	int initStatus = initList_SLh(head);
	printf("初始化状态: %d\n", initStatus);

	// 尾插法
	int tailInsertStatus = tailInsert_SLh(head, datas, length);
	printf("尾插法状态: %d\n", tailInsertStatus);
	traveseList_SLh(head);

	// 头插法
	int headInsertStatus = headInsert_SLh(head, datas, length);
	printf("头插法状态: %d\n", headInsertStatus);
	traveseList_SLh(head);

	// 长度
	int listLength = listLength_SLh(head);
	printf("带头结点，单链表长度为： %d\n", listLength);

	// 删除结点
	deleteElem_SLh(head, 5);
	traveseList_SLh(head);

	// 原地逆置单链表
	invertList_SLh(head);
	traveseList_SLh(head);
}

/* 不带头结点的测试方法*/
void testWithoutHead(ElementType* datas, int length)
{
	// =====不带头结点=====
	SL sL;

	// 初始化
	int initStatus = initList_SL(sL);
	printf("初始化状态: %d\n", initStatus);

	// 尾插法
	int tailInsertStatus2 = tailInsert_SL(sL, datas, length);
	printf("尾插法状态: %d\n", tailInsertStatus2);
	traverseList_SL(sL);

	// 头插法
	int headInsertStatus2 = headInsert_SL(sL, datas, length);
	printf("头插法状态: %d\n", headInsertStatus2);
	traverseList_SL(sL);

	// 长度
	int listLength2 = listLength_SL(sL);
	printf("不带头结点，单链表长度为： %d\n", listLength2);

	// 删除结点
	deleteElem_SL(sL, 5);
	traverseList_SL(sL);

	// 原地逆置单链表
	invertList_SL(sL);
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
	SL p = head;
	// 指针q，用于创建新的结点
	SL q = NULL;

	for (int i = 0; i < length; i++)
	{
		// 每次通过头结点创建新结点
		q = (SL)malloc(sizeof(SL_Node));
		if (!q)
		{
			return ERROR;
		}
		q->data = *(datas + i);
		// 元素接到头结点后
		head->next = q;
		// 第一个结点插入
		if (!i)
		{
			// 第一个结点即为表尾结点
			q->next = NULL;
			// 指针p，保存为上一个插入的结点
			
		}
		// 非第一个结点
		else
		{
			// 结点前置为头结点
			head->next = q;
			// 结点后继为上一个结点
			q->next = p;
		}
		// 指针p保存当次插入的结点位置
		p = q;
	}
	return OK;
}

/* 10_单链表——头插法建立_不带头结点*/
Status headInsert_SL(SL& sL, ElementType* datas, int length)
{
	// 同上，指针p用来保存上一个创建的结点
	SL p = sL;
	// 指针q，用来创建新的节点
	SL q = NULL;

	for (int i = 0; i < length; i++)
	{
		q = (SL)malloc(sizeof(SL_Node));
		if (!q)
		{
			return ERROR;
		}
		q->data = *(datas + i);
		// 第一个结点
		if (!i)
		{
			// 第一个结点作为表尾结点
			q->next = NULL;
		}
		else
		{
			// 连接到上一次插入的结点
			q->next = p;
		}
		// 连接到开始
		sL = q;
		// 保存为上一个结点
		p = q;
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

/* 14_单链表——删除结点_带头结点*/
void deleteElem_SLh(SL& head, ElementType data)
{
	// 保存待删除结点的上一个结点
	SL p = head;
	// 保存待删除结点
	SL q = NULL;
	while (p->next)
	{
		// 指针p总是在上一个结点的时候判断出下一个结点的条件
		if (p->next->data == data)
		{
			q = p->next;
			// 指针q若无后继结点，不影响
			p->next = q->next;
			free(q);
			return;
		}
		// 否则继续查找
		p = p->next;
	}
}

/* 15_单链表——删除结点_不带头结点*/
void deleteElem_SL(SL& sL, ElementType data)
{
	// 指针p，保存待删除结点的前一个结点
	SL p = sL;
	// 指针q，指向p的后继结点
	SL q = p->next;
	// 如果链表没有结点，直接返回
	if (!p)
	{
		return;
	}
	// 如果第一个结点就是待删除结点
	else if (p && p->data == data)
	{
		sL = q;
		free(p);
		return;
	}
	// 两个以上结点
	while (p->next)
	{
		// 指针p总是在上一个结点的时候判断出下一个结点的条件
		if (p->next->data == data)
		{
			q = p->next;
			p->next = q->next;
			free(q);
			return;
		}
		p = p->next;
	}
}

/* 16_单链表——原地逆置_带头节点*/
/* 『单链表原地逆置』个人理解。
1. 大思路是将所有结点分为两种状态，『已完成逆置』和『待逆置』；
2. 刚开始的状态，所有结点都是待逆置状态。
3. 除了首元结点外，后续结点在执行逆置过程中都有结点处于已完成逆置状态。
4. 为了方便理解，且不将『首元结点的逆置』与『其余结点逆置』过程作为不同子过程单独处理，需在首元结点逆置过程中『虚拟出一个空结点』作为『已完成逆置状态』的结点。
5. 此次虚拟空结点作为『已完成逆置状态结点』，更方便将循环体划分出来。
6. 难点在于划分出单轮次的循环过程。
*/
void invertList_SLh(SL& head)
{
	/**
	 * 指针p保存下一个带改变指向的元素，保证断开后头结点的指针能找到
	 */
	SL p = head->next;
	// 用指针p保存了，此处一定要置空
	head->next = NULL;
	// 指针s是要改变指向的元素
	SL s = NULL;
	// 特别注意理解第一轮的过程，虚拟一个NULL结点在头结点和首元结点之间，作为【已完成逆置】的元素。
	while (p)
	{
		// 当前【待逆置的元素】完成，设置【下一个待逆置元素】为【当前待逆置】；
		s = p;
		// 指针p作为【下一个待逆置】
		p = p->next;
		// 当前待逆置元素，指向逆置完成的第一个元素（完成状态时候，最后一个元素是先完成的，所以每次执行时候，逆置完成的第一个元素即是上一次完成逆置的元素）
		s->next = head->next;
		// 当前元素逆置完成，【头结点指针指向的元素】则是【上一轮逆置完成的元素】
		head->next = s;
	}
}

/* 17_单链表——原地逆置_不带头节点*/
/* 过程同上，原理无不同，只有head->next替换为sL头指针*/
void invertList_SL(SL& sL)
{
	SL p = sL;
	sL = NULL;
	SL s = NULL;
	while (p)
	{
		s = p;
		p = p->next;
		s->next = sL;
		sL = s;
	}
}
