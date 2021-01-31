#pragma once
#include <stdio.h>
#include <stdlib.h>

// 定义返回状态及返回码
#define Status int
#define OK 1
#define ERROR 0
// 定义存储的元素类型
#define BrTreeNodeElementType int

// 红黑树结点结构定义
typedef struct BrTreeNode
{
	// 数据域
	BrTreeNodeElementType data;
	// 左孩子的指针
	BrTreeNode* left;
	// 右孩子的指针
	BrTreeNode* right;
	// 父指针
	BrTreeNode* parent;
	// 红黑状态标记，默认为红色
	bool black = false;
}BrNode, * BrTree;

/*替代所有NULL的结点*/
extern BrTreeNode nil;

/*根结点指针*/
extern BrTree root;

/**********/
/*测试方法*/
/*********/

// 测试红黑树的方法
void testBrTree();

/**********/
/*保持平衡的基本操作*/
/*********/

// 01_红黑树_变色（黑->红，红->黑）
void changeColor_BrT(BrTree& brTree);

// 02_红黑树_左旋（对某个结点及其右孩子的操作）
void leftRotate_BrT(BrTree& root, BrTree x);

// 03_红黑树_右旋（对某个结点及其左孩子的操作）
void rightRotate_BrT(BrTree& root, BrTree y);

/**********/
/*存取操作*/
/*********/

// 根据颜色和数据，构建结点
Status buildBrNode_BrT(BrTree& brT, bool black, BrTreeNodeElementType data);

// 红黑树基础二叉搜索插入(注意parent指针)
void brSearchAddElem(BrTree& brT, BrTree& toAdd);

// 04_红黑树_插入元素（插入完成，根据情况执行保持平衡的基本操作）
Status insertElem_BrT(BrTree& root, BrTreeNodeElementType data);

// 10_红黑树_插入自平衡处理
void insertFixUp_BrT(BrTree& root, BrTree cur);

// 05_红黑树_删除元素（删除完成，根据情况执行保持平衡的基本操作）
Status deleteElem_BrT(BrTree& root, BrTreeNodeElementType key);

// 10_红黑树_找到等值的结点
BrTree findKey_BrT(BrTree brTree, BrTreeNodeElementType key);

// 13_红黑树_中序前驱
BrTree inOrderPre_BrT(BrTree root, BrTree cur);

// 11_红黑树_中序后继
BrTree inOrderPost_BrT(BrTree root, BrTree cur);

// 12_红黑树_确定与父结点的关系
int relateParent_BrT(BrTree brTree);

// 移植，将一个结点的与父亲的关系移植给另一个结点
void transparent(BrTree& root, BrTree& src, BrTree& target);

// 14_红黑树_删除自平衡
void deleteFixUp_BrT(BrTree& root, BrTree cur);

/****************************/
/*遍历操作（用于检查树的结构）*/
/***************************/

// 06_红黑树_先序遍历
void preOrderTraverse_BrT(BrTree brTree);

// 07_红黑树_中序遍历
void inOrderTraverse_BrT(BrTree brTree);

// 08_红黑树_后序遍历
void postOrderTraverse_BrT(BrTree brTree);

// 09_红黑树_访问方法
void visitBrNode_BrT(BrTree brTree);