#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NAVI.h"

typedef struct {
	char str_tmp[1024];
} D;

D arr[MAX_CITY];

void main() {
	FILE* pFile = NULL;
	int i = 0;
	char* token;
	initailize(data);
	pFile = fopen("test.csv", "r");

	if (pFile != NULL) {
		while (!feof(pFile)) {

			if (i > MAX_CITY) break; // i�� R�� �ѱ�� ���� ������
			fgets(arr[i].str_tmp, 1024, pFile); // ������ �� �� �ҷ��ͼ� str_tmp�� �����Ѵ�.

			//remove_spaces(arr[i].str_tmp);

			token = strtok(arr[i].str_tmp, ","); // str_tmp�� ','�� ���е� �����͵��� �и��Ѵ�.

			separate_feild(&arr[i].str_tmp, token, &data[i]);
			i++;
		}

	}
	else printf("fail\n");
	print(data);
	//printMap(data);
}

