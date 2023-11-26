//#include <stdio.h>
//#include <stdlib.h>
//#define MALLOC(p,s)\
//    if (!((p) = malloc(s))) {\
//    	fprintf(stderr, "Insufficient memory.");\
//        exit(1);\
//    }
//
//typedef struct Listnode* listpointer;
//typedef struct Listnode {
//    listpointer llink; // ���� ���� ����Ʈ�� ����ϱ� ���� Llink
//    double data;
//    listpointer rlink; // ���� ��带 ����ų Rlink
//} Listnode;
//
//listpointer front, rear; // �Ǻ���ġ ������ ť ó�� ����
//
//void add(int num1, int num2);
//void fibonacci(int num, int i);
//void input();
//void printFibo();
//
//void main() {
//    front = NULL;
//    rear = front;
//    input();
//    printFibo();
//    free(front);
//    free(rear);
//}
//
//void input() {
//    int index;
//    printf("input last fibonacci's index : ");
//    scanf_s("%d", &index);
//    fibonacci(index, 0);
//}
//
//void fibonacci(int num, int i) { // �Ǻ���ġ ������ ���ȣ���ϴ� �Լ�
//    if(i <= num) {
//        if (i == 0) { // i �� 0�� ���� add�� 0,0�� �־��ش�.
//            add(0, 0); 
//            fibonacci(num, i + 1);
//        }
//        else if (i == 1) { // i�� 1�� ���� add�� 0,1�� �־��ش�.
//            add(0, 1);
//            fibonacci(num, i + 1); 
//        }
//        else { // ��� ������ �ƴ� ���� rear�� ���� data�� ���� rear�� data�� �����ش�.
//            add(rear->llink->data, rear->data);
//            fibonacci(num, i + 1);
//        }
//    }
//}
//
//void add(int num1, int num2) { // �Ű������� ���� �������� ���ϸ鼭 ťó�� �̾��ش�. 
//    listpointer temp;
//    MALLOC(temp, sizeof(*temp));
//    temp->rlink = NULL;
//    temp->data = num1 + num2;
//    if (front) {
//        temp->llink = rear;
//        rear->rlink = temp;
//    }
//    else {
//        front = temp;
//    }
//    rear = temp;
//}
//
//void printFibo() {
//    rear = front;
//    while (rear) {
//        printf("%.f ", rear->data);
//        rear = rear->rlink;
//    }
//    printf("\n");
//}