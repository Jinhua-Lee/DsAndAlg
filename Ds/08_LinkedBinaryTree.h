#pragma once
#include <stdio.h>
#include <stdlib.h>

// 定义返回状态及返回码
#define Status int
#define OK 1
#define ERROR 0
// 定义存储的元素类型
#define BiTreeNodeElementType int

// 二叉树结点结构定义
typedef struct BinaryTreeNode
{
	// 数据域
	BiTreeNodeElementType data;
	// 指向左孩子的指针
	BinaryTreeNode* left;
	// 指向右孩子的指针
	BinaryTreeNode* right;
	// 指向父结点的指针
	BinaryTreeNode* parent;
}BTNode, *BinaryTree;

// 测试二叉树的方法
void testBinaryTree();

/*=====================================*/
/*一个指向根结点的指针，可以确定一个二叉树*/
/*=====================================*/

// 01_二叉树——初始化，拿到一个指向根结点的指针，即确定一个二叉树
Status initBiTree_T(BinaryTree& biTree);

// 02_二叉树——销毁
Status destroyBiTree_T(BinaryTree& biTree);

// 03_二叉树——判空
Status emptyBiTree_T(BinaryTree biTree);

// 04_二叉树——深度
int treeDepth_T(BinaryTree biTree);

// 返回两个数较大的一个
int max(int a, int b);

// 05_二叉树——是否是叶子结点
Status leafBiNode_T(BinaryTree biTree);

// 06_二叉树——是否根结点
Status rootBiNode_T(BinaryTree biTree);

// 07_二叉树——求父结点
Status parentBiNode_T(BinaryTree current, BinaryTree& parent);

// 访问二叉树结点的方法
void visit(BinaryTree biTree);

// 08_二叉树——先序遍历_递归
void preOrderTraverse_Recur(BinaryTree biTree);

// 09_二叉树——中序遍历_递归
void inOrderTraverse_Recur(BinaryTree biTree);

// 10_二叉树——后序遍历_递归
void postOrderTraverse_Recur(BinaryTree biTree);

// 11_二叉树——通过先序遍历方法创建
void createByPreOrderTraverse_T(BinaryTree& biTree);

// 12_二叉树——先序遍历_非递归
void preOrderTraverse_NonRecur(BinaryTree biTree);

// 13_二叉树——中序遍历_非递归
void inOrderTraverse_NonRecur(BinaryTree biTree);

// 14_二叉树——后序遍历_非递归
void postOrderTraverse_NonRecur(BinaryTree biTree);

// 15_二叉树——层次遍历
void breadthTraverse(BinaryTree biTree);