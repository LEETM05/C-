//#include <stdio.h>
//
//double power(int coef, int expo, double* result); // �ŵ������� ����ϴ� �Լ�
//void run(); // �Է� �� ������ ���� �Լ�
//
//void main() {
//	run();
//}
//
//void run() {
//	int coef, expo;
//	double result = 1.0; // 0���� �ʱ�ȭ�ϸ� ��������� 0�� �Ǳ⶧���� 1�� �ʱ�ȭ�Ѵ�.
//	printf("input coef and expo : ");
//	scanf_s("%d %d", &coef, &expo); // ������ ����� �Է��Ѵ�.
//	printf("%d to the power of %d is %.f\n", coef, expo, power(coef, expo, &result));
//}
//
//double power(int coef, int expo, double* result) { // �޸𸮸� �����ϱ� ���� result�� �����ͷ� �����Ѵ�.
//	if (expo == 0)
//		return;
//	else
//		power(coef, expo - 1, result);
//	*result *= coef; // expo�� 0�� �Ǳ������� result�� ����� �����ش�.
//	return *result;
//}