#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 20

/*�����������ʣ�
 * 1.�ṹ�ԣ��ѱ�����һ����ȫ������
 * 2.�����ԣ��ѵĸ��ڵ�Ҫô�������ӽڵ㣬ҪôС���ӽڵ㣬ǰ�߽д󶥶ѣ����߽�С���ѣ�
 * �ɴˣ��ѿ�����һ����������ʾ�������������ʣ�
 * 1.��������iλ�õ�Ԫ�أ��������ӽڵ���2iλ�ã����ӽڵ���2i+1λ�ã�
 * 2.���ĸ��ڵ㣨�����У���i/2λ��*/

//����һ��С����,size�������ʵ��Ԫ�صĸ���
typedef struct MinHeap {
    int size;
    int data[MAX_SIZE];
} heap;

//��ʼ��������0λ��Ҫ����
void init(heap* h ) {
    h->size = 0;
}

//����Ԫ��x 
int insert(heap* h, int x) {
	int flag = 1;
    if (h->size == MAX_SIZE) {
        printf("heap is full!");
        flag = 0;
    }
    int i;
    h->size++;
    for (i = h->size; i >= 1; i /= 2) {
        if(x < h->data[i / 2]) {
            h->data[i] = h->data[i/2];
        } else {
            break;
        }
    }
    h->data[i] = x;
    return flag;
}

/*ɾ����СԪ�أ���С���Ѽ���ζ��ɾ�����ڵ�
 * 1.���Ƚ���Ԫ�ر��棬�ȴ����return��
 * 2.�����һ��Ԫ�ظ�ֵ����Ԫ�أ��������ֵ������������������֤�˶ѵĽṹ�ԣ�
 * 3.�Ӹ��ڵ㿪ʼ�������Ƚϸ��ڵ�������ӽڵ�Ĵ�С�����������ֵ���ڽ�С���ӽڵ㣬��С�ڵ��ֵ�������ڵ�
 * 4.ֱ��������ֵС���α�������ӽڵ㣬��ʱ��������ֵ�����α�����λ��*/
int deleteMin(heap* h) {
    int child;
    int result = h->data[1];
    h->data[1] = h->data[h->size];
    h->size--;
    int i = 1;
    int temp = h->data[1];
    for (i = 1; 2 * i <= h->size; i = child) {
        child = 2 * i;
        if (child != h->size && h->data[child] > h->data[child+1]) {
			//������ӽڵ�����Ԫ����>���ӽڵ�,�����ӽڵ���С
            child++;
        }
        if (temp > h->data[child]) {
			//���temp���ڵ�ǰԪ�ص���С�ӽڵ㣬����С�ӽڵ㸳ֵ�����ڵ㣬��������
            h->data[i] = h->data[child];
        } else {
            break;
        }
    }
    h->data[i] = temp;//��������ֵ������ǰ�α�
    return result;
}

//������
void heap_sort(int a[], int n) {
    int i;
    heap* h = (heap*)malloc(sizeof(heap));//����ָ�����ռ�
    init(h);//��ʼ����
    for (i = 0; i < n; i++) {//�������Ԫ�����β����
        insert(h, a[i]);
    }
    for (i = 0; i < n; i++) {
        a[i] = deleteMin(h);
    }
}
//��������
void traverse_array(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
}

//���������� 
int main() {
    int a[] = {10,7,2,5,1};
    int n = sizeof(a) / sizeof(int);
    traverse_array(a, n);
    heap_sort(a, n);
    traverse_array(a, n);
}
