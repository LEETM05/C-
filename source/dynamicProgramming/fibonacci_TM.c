/*		date : 2023-08-01
*		name : Tae Min
*		program : fibonacci
*/


#include <stdio.h>
#define MAX_SIZE 101
long long int memo[MAX_SIZE] = { 0, };

long long int fibo_top_down(int num);
long long int fibo_bottom_up(int num);

void main() {
	int num;
	printf("input fibonacci's index : ");
	scanf_s("%d", &num);
	printf("%lld\t%lld\n", fibo_top_down(num), fibo_bottom_up(num));
}

long long int fibo_top_down(int num) {
	if (num <= 1)
		return num;
	if (memo[num] != 0)
		return memo[num];
	else
		memo[num] = fibo_top_down(num - 1) + fibo_top_down(num - 2);
	return memo[num];
}

long long int fibo_bottom_up(int num) {
	memo[0] = 0;
	memo[1] = 1;
	for (int i = 2; i <= num; i++)
		memo[i] = memo[i - 1] + memo[i - 2];
	return memo[num];
}