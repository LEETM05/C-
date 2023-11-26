/*		name : Tae Min
*		date : 23-07-24
*/
#include <stdio.h>

double factorial(int fac, double *result); // 팩토리얼을 계산해서 결과를 반환하는 함수
void run(); // 입력 및 팩토리얼 함수를 호출하는 실행 함수

void main() {
	run();
}

void run() {
	int Fac_num;
	double result = 1;
	printf("input factorial number : ");
	scanf_s("%d", &Fac_num);
	printf("%d factorial is %.f\n", Fac_num, factorial(Fac_num, &result));
}

double factorial(int fac, double *result) { // 매개 변수로 fac (factorial) 숫자와 결과의 주소를 받는다.
	if (fac == 0) // fac이 0이면 그냥 리턴한다.
		return;
	else { // fac이 0이 아니면 factorial함수에 fac - 1을 보낸다.
		factorial(fac - 1,result);
		*result *= fac; // 팩토리얼 결과를 누적한다.
	}
	return *result; // 누적한 결과를 반환한다.
}