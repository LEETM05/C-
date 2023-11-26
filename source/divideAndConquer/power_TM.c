//#include <stdio.h>
//
//double power(int coef, int expo, double* result); // 거듭제곱을 계산하는 함수
//void run(); // 입력 및 실행을 위한 함수
//
//void main() {
//	run();
//}
//
//void run() {
//	int coef, expo;
//	double result = 1.0; // 0으로 초기화하면 최종결과도 0이 되기때문에 1로 초기화한다.
//	printf("input coef and expo : ");
//	scanf_s("%d %d", &coef, &expo); // 지수와 계수를 입력한다.
//	printf("%d to the power of %d is %.f\n", coef, expo, power(coef, expo, &result));
//}
//
//double power(int coef, int expo, double* result) { // 메모리를 절약하기 위해 result를 포인터로 선언한다.
//	if (expo == 0)
//		return;
//	else
//		power(coef, expo - 1, result);
//	*result *= coef; // expo가 0이 되기전까지 result에 계수를 곱해준다.
//	return *result;
//}