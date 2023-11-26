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

			if (i > MAX_CITY) break; // i가 R을 넘기는 것을 방지함
			fgets(arr[i].str_tmp, 1024, pFile); // 파일을 한 줄 불러와서 str_tmp에 저장한다.

			//remove_spaces(arr[i].str_tmp);

			token = strtok(arr[i].str_tmp, ","); // str_tmp에 ','로 구분된 데이터들을 분리한다.

			separate_feild(&arr[i].str_tmp, token, &data[i]);
			i++;
		}

	}
	else printf("fail\n");
	print(data);
	//printMap(data);
}

