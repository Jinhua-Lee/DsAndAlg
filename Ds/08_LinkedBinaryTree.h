#pragma once
#include <stdio.h>
#include <stdlib.h>

// 定义返回状态及返回码
#define Status int
#define OK 1
#define ERROR 0
// 定义存储的元素类型
#define ElementType int

// 二叉树结点结构定义
typedef struct BinaryTreeNode
{
	// 数据域
	ElementType data;
	// 指向左孩子的指针
	BinaryTreeNode* left;
	// 指向右孩子的指针
	BinaryTreeNode* right;
	// 指向父节点的指针
	BinaryTreeNode* parent;
}BTNode, *BinaryTree;

// 测试二叉树的方法
void testBinaryTree();

/*=====================================*/
/*一个指向根节点的指针，可以确定一个二叉树*/
/*=====================================*/

// 01_二叉树——初始化，拿到一个指向根节点的指针，即确定一个二叉树
Status initBiTree_L(BinaryTree& biTree);

// 02_二叉树——销毁
Status destroyBiTree_L(BinaryTree& biTree);

// 03_二叉树——判空
Status emptyBiTree_L(BinaryTree biTree);

// 04_二叉树——深度
int treeDepth_L(BinaryTree biTree);

// 返回两个数较大的一个
int max(int a, int b);

// 05_二叉树——是否是叶子结点
Status leafBiNode_L(BinaryTree biTree);

// 06_二叉树——是否根节点
Status rootBiNode_L(BinaryTree biTree);

// 07_二叉树——求父节点
Status parentBiNode_L(BinaryTree current, BinaryTree& parent);

// 访问二叉树结点的方法
void visit(BinaryTree biTree);

// 08_二叉树——先序遍历
void preOrderTraverse(BinaryTree biTree);

// 09_二叉树——中序遍历
void inOrderTraverse(BinaryTree biTree);

// 10_二叉树——后序遍历
void postOrderTraverse(BinaryTree biTree);