#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100 

//���Ľṹ 
typedef struct TreeNode {
	int data;//������
	struct TreeNode* lchild;//ָ�����ӽڵ�
	struct TreeNode* rchild;//ָ���Һ��ӽڵ� 
} BiNode, *BiTree;

//���нṹ�� 
typedef struct queue {
	struct TreeNode* numQueue[MaxSize];
	int front;
	int rear; 
} Queue; 

Queue queue;//����ȫ�ֱ��� 

//��ʼ������
void initQueue() {
	queue.front = 0;
	queue.rear = 0;
} 

//���
void Push(BiTree root) {
	queue.numQueue[++queue.rear] = root;
} 

//����
BiTree Pop() {
	return queue.numQueue[++queue.front];
}

//�ж϶����Ƿ�Ϊ��
int empty() {
	return queue.rear == queue.front;
} 


//���������
BiTree CreateTree() {
	int data;
	scanf("%d", &data);//���ڵ�����
	BiTree root;

	if (data <= 0) {
		return NULL;
	} else {
		root = (BiTree)malloc(sizeof(BiNode));
		root->data = data;
		//printf("������%d����������", root->data);
		root->lchild = CreateTree();
		//printf("������%d����������", root->data);
		root->rchild = CreateTree();
	}
	return root;
}


//�������������:�ݹ�ʵ�� 
void PreOrderTraverse(BiTree root) {
	if (root) {
		printf("%d ", root->data);
		PreOrderTraverse(root->lchild);
		PreOrderTraverse(root->rchild);
	}	
}

//�������������:�ǵݹ�ʵ�� 
void PreOrderTraverseNonRec(BiTree root) {
	BiTree stack[MaxSize];
	BiTree p;
	int top = -1;
	if (root != NULL) {
		//���ڵ���ջ
		top++;
		stack[top] = root;
		//ջ����ʱѭ��
		while (top > -1) {
			//��ջ�����ʸýڵ�
			p = stack[top];
			top--;
			printf("%d ", p->data);
			//�Һ�����ջ
			if (p->rchild != NULL) {
				top++;
				stack[top] = p->rchild;
			}
			//������ջ
			if (p->lchild != NULL) {
				top++;
				stack[top] = p->lchild;
			} 
		} 
	} 
}

//�������������:�ݹ�ʵ�� 
void InOrderTraverse(BiTree root) {
	if (root) {
		InOrderTraverse(root->lchild);
		printf("%d ", root->data);
		InOrderTraverse(root->rchild);
	}
} 

//�������������:�ǵݹ�ʵ�� 
void InOrderTraverseNonRec(BiTree root) {
	BiTree stack[MaxSize];
	BiTree p;
	int top = -1;
	if (root != NULL) {
		p = root;
		while (top > -1 || p != NULL) {
			//ɨ��p��������ڵ㲢��ջ
			while (p != NULL) {
				top++;
				stack[top] = p;
				p = p->lchild;
			} 
			if (top > -1) {
				//��ջ�����ʽڵ�
				p = stack[top];
				top--;
				printf("%d ", p->data);
				//ɨ���Һ���
				p = p->rchild; 
			}
		}
	} 
}

//�������������:�ݹ�ʵ�� 
void PostOrderTraverse(BiTree root) {
	if (root) {
		PostOrderTraverse(root->lchild);
		PostOrderTraverse(root->rchild);
		printf("%d ", root->data);
	}
} 

//�������������:�ǵݹ�ʵ�� 
void PostOrderTraverseNonRec(BiTree root) {
	BiTree stack[MaxSize];
	BiTree p;
	int top = -1;
	int sign; 
	if (root != NULL) {
		do {
			//root�ڵ���ջ
			while (root != NULL) {
				top++;
				stack[top] = root;
				root = root->lchild;
			} 
			//pָ��ջ��ǰһ���ѷ��ʽڵ�
			p = NULL;
			//��rootΪ�ѷ���
			sign = 1;
			while (top != -1 && sign) {
				//ȡ��ջ���ڵ�
		 		root = stack[top];
		 		//�Һ��Ӳ����ڻ��Һ����ѷ��������root
		 		if (root->rchild == p) {
		 			printf("%d ", root->data);
		 			top--;
		 			//pָ�򱻷��ʵĽڵ�
					 p = root; 
				 } else {
				 	//rootָ���Һ��ӽڵ�
					root = root->rchild;
					//��δ���ʱ��
					sign = 0; 
				 }
			}
		} while (top != -1);
	} 
}

//��α���:�ǵݹ�ʵ�� 
void LevelOrderTraverseNonRec(BiTree root) {
	BiTree p;
	Push(root);
	while (!empty()) {//empty()�ж϶����Ƿ�Ϊ��
		p = Pop();//����
		printf("%d ", p->data);//������׽�� 
		if (p->lchild) {//��Pop���Ľ������ӽ�������� 
			Push(p->lchild);
		}
		if (p->rchild) {//��Pop���Ľ������ӽ��������
			Push(p->rchild);
		}
	}
} 

//��������������
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

//�������߶�
int BiTreeHeight(BiTree root) {
	if (root) {
		int leftHeight = BiTreeHeight(root->lchild);
	    int rightHeight = BiTreeHeight(root->rchild); 
	    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1); 
	}
	return 0;
}

//Ҷ�ӽڵ�
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

//���k��ڵ���� 
int LevelNodeNum(BiTree root, int k) {
	if (root == NULL || k < 1) {
		return 0;
	}
	if (k == 1) {
		return 1;
	}
	return LevelNodeNum(root->lchild, k - 1) + LevelNodeNum(root->rchild, k - 1);
}  

//��������ܽڵ����
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

//����Ԫ��Ϊ x �Ľڵ�
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

//����
int main() {
	//�������ݣ�5 3 2 0 0 0 8 6 0 0 9 0 0 
	//BiTree root;
	//CreateTree(&root);
	BiTree root = NULL; 
	root = CreateTree();//������ 
	printf("����ǵݹ������");
    PreOrderTraverseNonRec(root);
    printf("\n����ǵݹ������");
    InOrderTraverseNonRec(root);
    printf("\n����ǵݹ������");
    PostOrderTraverseNonRec(root);
	printf("\n����ݹ������");
	PreOrderTraverse(root);//����������
	printf("\n����ݹ������");
	InOrderTraverse(root);//���������� 
	printf("\n����ݹ������");
	PostOrderTraverse(root);//���������� 
	printf("\n��ηǵݹ������");
	LevelOrderTraverseNonRec(root);//��α������ 
	printf("\n�����������Ϊ��%d",maxDepth(root));
	printf("\n�������ĸ߶�Ϊ��%d",BiTreeHeight(root));
	printf("\nҶ�ӽڵ�Ϊ��%d",LeafNodeNum(root));
	printf("\n�ܽڵ�Ϊ��%d", CountNode(root));
	printf("\n��3��ڵ����Ϊ��%d",LevelNodeNum(root, 3));
	BiTree q;
	q = SearchNode(root, 9);
	if (q) {
		printf("\n���ҵ��� ��%d", q->data);
	} else {
		printf("\nû�в��ҵ� 9 ");
	}
	
	return 0;
}

