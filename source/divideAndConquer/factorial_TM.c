/*		name : Tae Min
*		date : 23-07-24
*/
#include <stdio.h>

double factorial(int fac, double *result); // ���丮���� ����ؼ� ����� ��ȯ�ϴ� �Լ�
void run(); // �Է� �� ���丮�� �Լ��� ȣ���ϴ� ���� �Լ�

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

double factorial(int fac, double *result) { // �Ű� ������ fac (factorial) ���ڿ� ����� �ּҸ� �޴´�.
	if (fac == 0) // fac�� 0�̸� �׳� �����Ѵ�.
		return;
	else { // fac�� 0�� �ƴϸ� factorial�Լ��� fac - 1�� ������.
		factorial(fac - 1,result);
		*result *= fac; // ���丮�� ����� �����Ѵ�.
	}
	return *result; // ������ ����� ��ȯ�Ѵ�.
}