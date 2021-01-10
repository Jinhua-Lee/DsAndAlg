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
	// 左指针功能标记，为true则指向前驱
	bool ltag = false;
	// 指向右孩子的指针
	BinaryTreeNode* right;
	// 右指针功能标记，为true则指向后继
	bool rtag = false;
}BTNode, *BinaryTree;

// 测试二叉树的方法
void testBinaryTree();

// 递归遍历
void traverseRecur(BinaryTree bt);

// 非递归遍历
void traverseNonRecur(BinaryTree bt);

// 测试线索遍历方式
void threadTraverse(BinaryTree bt);

// 测试镜像
void testMirror(BinaryTree bt);

// 测试二叉查找树
void testBST();

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

// 06_二叉树——求父结点
BinaryTree parentBiNode_T(BinaryTree biTree, BinaryTree target);

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

// 16_二叉树——叶子个数
int leafCount_T(BinaryTree biTree);

// 17_二叉树——第k层结点数目
int getKLevel_T(BinaryTree biTree, int k);

// 18_二叉树——结构是否相同
bool structureCompare_T(BinaryTree bt1, BinaryTree bt2);

// 19_二叉树——求镜像
void treeMirror_T(BinaryTree biTree);

// 20_二叉树——找到关键字所在结点
BinaryTree findKey_T(BinaryTree biTree, BiTreeNodeElementType btValue);

// 21_二叉树——找最低公共祖先
BinaryTree findLCA_T(BinaryTree biTree, BinaryTree bt1, BinaryTree bt2);

// 22_二叉树——结点距离
int nodeDistance_T(BinaryTree biTree, BinaryTree bt1, BinaryTree bt2);

// 23_二叉树——结点相隔层数
int levelDist_T(BinaryTree biTree, BinaryTree bt);

// 24_二叉树——结点所有祖先
bool allAncestors_T(BinaryTree biTree, BinaryTree bt);

// 25_二叉树——前序线索化
void preThreading_T(BinaryTree& bt, BinaryTree& pre);

// 26_二叉树——中序线索化
void inThreading_T(BinaryTree& bt, BinaryTree& pre);

// 27_二叉树——后序线索化
void postThreading_T(BinaryTree& bt, BinaryTree& pre);

// 28_二叉树——前序线索遍历
void preThreadTraverse_T(BinaryTree biTree);

// 29_二叉树——中序线索遍历
void inThreadTraverse_T(BinaryTree biTree);

// 30_二叉树——是否完全二叉树
bool isCompleteBinary_T(BinaryTree biTree);

// 31_二叉树——二叉查找树加入元素
Status binSerchAddElem_T(BinaryTree& cur, BiTreeNodeElementType elem);

// 32_二叉树——构建二叉查找树
void buildBinarySearchTree(BinaryTree& bst, BiTreeNodeElementType* arr, int length);

// 33_二叉树——二叉搜索树删除指定结点
Status deleteBiSearchElem_T(BinaryTree& bst, BinaryTree& toDel);

// 34_二叉树——查找二叉树中某个结点中序后继，找不到返回NULL
BinaryTree inorderPost_T(BinaryTree bt, BinaryTree cur);