#include "08_LinkedBinaryTree.h"

/* 测试二叉树的方法*/
void testBinaryTree()
{

}

/* 01_二叉树——初始化*/
Status initBiTree_L(BinaryTree& biTree)
{
    biTree = NULL;
    return OK;
}

/* 02_二叉树——销毁*/
Status destroyBiTree_L(BinaryTree& biTree)
{
    // 如果结点不为空
    if (biTree)
    {
        biTree->parent = NULL;
        // 先删除左右子树
        if (destroyBiTree_L(biTree->left) && destroyBiTree_L(biTree->right))
        {
            return OK;
        }
        // 再删除该结点
        delete biTree;
    }
	return OK;
}

/* 03_二叉树——判空*/
Status emptyBiTree_L(BinaryTree biTree)
{
    return biTree == NULL ? OK : ERROR;
}

/* 04_二叉树——深度*/
int treeDepth_L(BinaryTree biTree)
{
    // 该结点为空，则该层深度为0
    if (!biTree)
    {
        return 0;
    }
    // 否则，该层深度有1，要向上累加
    else
    {
        int leftDepth = treeDepth_L(biTree->left);
        int rightDepth = treeDepth_L(biTree->right);
        // 左右子树的深度，加上本层的深度1，即是该结点的深度
        return 1 + max(leftDepth, rightDepth);
    }
}

/*返回两个数较大的一个*/
int max(int a, int b)
{
    return a > b ? a : b;
}

/* 05_二叉树——是否是叶子结点*/
Status leafBiNode_L(BinaryTree biTree)
{
    // 左右孩子都不存在，即为叶子结点
    return (biTree->left == NULL && biTree->right == NULL) ? OK : ERROR;
}

/* 06_二叉树——是否根节点*/
Status rootBiNode_L(BinaryTree biTree)
{
    return biTree->parent == NULL ? OK : ERROR;
}

/* 06_二叉树——求父节点*/
Status parentBiNode_L(BinaryTree current, BinaryTree& parent)
{
    // 如果当前结点为空，或当前结点为根节点
    if (emptyBiTree_L(current) || rootBiNode_L(current))
    {
        parent = NULL;
        return ERROR;
    }
    parent = current->parent;
    return OK;
}
