#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "river.h"
#pragma warning(disable:4996)

extern struct rivers* alldataload() {
	struct rivers* database = malloc(N * sizeof(struct rivers));
	FILE* fp;
	int i = 0;
	fp = fopen("rivers.txt", "r");
	while (fscanf(fp, "%s%i%i", database[i].name, &(database[i].lenght), &(database[i].depth)) != EOF) {
		i++;
	}
	fclose(fp);
	return database;
}

extern void alldataview(struct rivers* database) {
	printf("DATABASE:\n|River name| lenght  |depth|\n");
	for (int i = 0; i < N; i++) {
		printf("|%-10s| %-5ikm | %-2im |\n", database[i].name, database[i].lenght, database[i].depth);
	}
}

extern int searchdata(struct rivers* database) {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (database[i].depth < 50) {
			sum += database[i].lenght;
		}
	}
	return sum;
}