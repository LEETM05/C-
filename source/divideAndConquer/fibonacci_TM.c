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
//    listpointer llink; // 이중 연결 리스트를 사용하기 위한 Llink
//    double data;
//    listpointer rlink; // 다음 노드를 가리킬 Rlink
//} Listnode;
//
//listpointer front, rear; // 피보나치 수열을 큐 처럼 적용
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
//void fibonacci(int num, int i) { // 피보나치 수열을 재귀호출하는 함수
//    if(i <= num) {
//        if (i == 0) { // i 가 0일 때는 add에 0,0을 넣어준다.
//            add(0, 0); 
//            fibonacci(num, i + 1);
//        }
//        else if (i == 1) { // i가 1일 때는 add에 0,1을 넣어준다.
//            add(0, 1);
//            fibonacci(num, i + 1); 
//        }
//        else { // 모든 조건이 아닐 때는 rear의 이전 data와 현재 rear의 data를 더해준다.
//            add(rear->llink->data, rear->data);
//            fibonacci(num, i + 1);
//        }
//    }
//}
//
//void add(int num1, int num2) { // 매개변수로 받은 정수들을 더하면서 큐처럼 이어준다. 
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