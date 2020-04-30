#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100 

//树的结构 
typedef struct TreeNode {
	int data;//数据域
	struct TreeNode* lchild;//指向左孩子节点
	struct TreeNode* rchild;//指向右孩子节点 
} BiNode, *BiTree;

//队列结构体 
typedef struct queue {
	struct TreeNode* numQueue[MaxSize];
	int front;
	int rear; 
} Queue; 

Queue queue;//声明全局变量 

//初始化队列
void initQueue() {
	queue.front = 0;
	queue.rear = 0;
} 

//入队
void Push(BiTree root) {
	queue.numQueue[++queue.rear] = root;
} 

//出队
BiTree Pop() {
	return queue.numQueue[++queue.front];
}

//判断队列是否为空
int empty() {
	return queue.rear == queue.front;
} 


//构造二叉树
BiTree CreateTree() {
	int data;
	scanf("%d", &data);//根节点数据
	BiTree root;

	if (data <= 0) {
		return NULL;
	} else {
		root = (BiTree)malloc(sizeof(BiNode));
		root->data = data;
		//printf("请输入%d的左子树：", root->data);
		root->lchild = CreateTree();
		//printf("请输入%d的右子树：", root->data);
		root->rchild = CreateTree();
	}
	return root;
}


//先序遍历二叉树:递归实现 
void PreOrderTraverse(BiTree root) {
	if (root) {
		printf("%d ", root->data);
		PreOrderTraverse(root->lchild);
		PreOrderTraverse(root->rchild);
	}	
}

//先序遍历二叉树:非递归实现 
void PreOrderTraverseNonRec(BiTree root) {
	BiTree stack[MaxSize];
	BiTree p;
	int top = -1;
	if (root != NULL) {
		//根节点入栈
		top++;
		stack[top] = root;
		//栈不空时循环
		while (top > -1) {
			//出栈并访问该节点
			p = stack[top];
			top--;
			printf("%d ", p->data);
			//右孩子入栈
			if (p->rchild != NULL) {
				top++;
				stack[top] = p->rchild;
			}
			//左孩子入栈
			if (p->lchild != NULL) {
				top++;
				stack[top] = p->lchild;
			} 
		} 
	} 
}

//中序遍历二叉树:递归实现 
void InOrderTraverse(BiTree root) {
	if (root) {
		InOrderTraverse(root->lchild);
		printf("%d ", root->data);
		InOrderTraverse(root->rchild);
	}
} 

//中序遍历二叉树:非递归实现 
void InOrderTraverseNonRec(BiTree root) {
	BiTree stack[MaxSize];
	BiTree p;
	int top = -1;
	if (root != NULL) {
		p = root;
		while (top > -1 || p != NULL) {
			//扫描p的所有左节点并入栈
			while (p != NULL) {
				top++;
				stack[top] = p;
				p = p->lchild;
			} 
			if (top > -1) {
				//出栈并访问节点
				p = stack[top];
				top--;
				printf("%d ", p->data);
				//扫描右孩子
				p = p->rchild; 
			}
		}
	} 
}

//后序遍历二叉树:递归实现 
void PostOrderTraverse(BiTree root) {
	if (root) {
		PostOrderTraverse(root->lchild);
		PostOrderTraverse(root->rchild);
		printf("%d ", root->data);
	}
} 

//后序遍历二叉树:非递归实现 
void PostOrderTraverseNonRec(BiTree root) {
	BiTree stack[MaxSize];
	BiTree p;
	int top = -1;
	int sign; 
	if (root != NULL) {
		do {
			//root节点入栈
			while (root != NULL) {
				top++;
				stack[top] = root;
				root = root->lchild;
			} 
			//p指向栈顶前一个已访问节点
			p = NULL;
			//置root为已访问
			sign = 1;
			while (top != -1 && sign) {
				//取出栈顶节点
		 		root = stack[top];
		 		//右孩子不存在或右孩子已访问则访问root
		 		if (root->rchild == p) {
		 			printf("%d ", root->data);
		 			top--;
		 			//p指向被访问的节点
					 p = root; 
				 } else {
				 	//root指向右孩子节点
					root = root->rchild;
					//置未访问标记
					sign = 0; 
				 }
			}
		} while (top != -1);
	} 
}

//层次遍历:非递归实现 
void LevelOrderTraverseNonRec(BiTree root) {
	BiTree p;
	Push(root);
	while (!empty()) {//empty()判断队列是否为空
		p = Pop();//出队
		printf("%d ", p->data);//输出队首结点 
		if (p->lchild) {//把Pop掉的结点的左子结点加入队列 
			Push(p->lchild);
		}
		if (p->rchild) {//把Pop掉的结点的右子结点加入队列
			Push(p->rchild);
		}
	}
} 

//二叉树的最大深度
int maxDepth(BiTree root) {
	if (root) {
		int maxLeft = maxDepth(root->lchild);
		int maxRight = maxDepth(root->rchild);
		if (maxLeft > maxRight) {
			return maxLeft + 1; 
		} else {
			return maxRight + 1;
		}
	}
	return 0;
} 

//二叉树高度
int BiTreeHeight(BiTree root) {
	if (root) {
		int leftHeight = BiTreeHeight(root->lchild);
	    int rightHeight = BiTreeHeight(root->rchild); 
	    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1); 
	}
	return 0;
}

//叶子节点
int LeafNodeNum(BiTree root) {
	if (root == NULL) {
		return 0;
	}
	if (root->lchild == NULL && root->rchild == NULL) {
		return 1;
	} else {
		return LeafNodeNum(root->lchild) + LeafNodeNum(root->rchild);
	}
} 

//求第k层节点个数 
int LevelNodeNum(BiTree root, int k) {
	if (root == NULL || k < 1) {
		return 0;
	}
	if (k == 1) {
		return 1;
	}
	return LevelNodeNum(root->lchild, k - 1) + LevelNodeNum(root->rchild, k - 1);
}  

//求二叉树总节点个数
int CountNode(BiTree root) {
	if (root) {
		if ((root->lchild == NULL) && (root->rchild == NULL)) {
			return 1;
		} else {
			return CountNode(root->lchild) + CountNode(root->rchild) + 1;
		}
	}
	return 0;
} 

//查找元素为 x 的节点
BiTree SearchNode(BiTree root, int x) {
	if (root) {
		if (root->data == x) {
			return root;
		} else {
			BiTree p;
			p = SearchNode(root->lchild, x);
			if (!p) {
				p = SearchNode(root->rchild, x);
			}
			return p;
		}
	}
	return NULL;
} 

//测试
int main() {
	//测试数据：5 3 2 0 0 0 8 6 0 0 9 0 0 
	//BiTree root;
	//CreateTree(&root);
	BiTree root = NULL; 
	root = CreateTree();//创建树 
	printf("先序非递归遍历：");
    PreOrderTraverseNonRec(root);
    printf("\n中序非递归遍历：");
    InOrderTraverseNonRec(root);
    printf("\n后序非递归遍历：");
    PostOrderTraverseNonRec(root);
	printf("\n先序递归遍历：");
	PreOrderTraverse(root);//先序遍历输出
	printf("\n中序递归遍历：");
	InOrderTraverse(root);//中序遍历输出 
	printf("\n后序递归遍历：");
	PostOrderTraverse(root);//中序遍历输出 
	printf("\n层次非递归遍历：");
	LevelOrderTraverseNonRec(root);//层次遍历输出 
	printf("\n二叉树的深度为：%d",maxDepth(root));
	printf("\n二叉树的高度为：%d",BiTreeHeight(root));
	printf("\n叶子节点为：%d",LeafNodeNum(root));
	printf("\n总节点为：%d", CountNode(root));
	printf("\n第3层节点个数为：%d",LevelNodeNum(root, 3));
	BiTree q;
	q = SearchNode(root, 9);
	if (q) {
		printf("\n查找到了 ：%d", q->data);
	} else {
		printf("\n没有查找到 9 ");
	}
	
	return 0;
}

