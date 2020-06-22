/**
 * @file river.c
 * @author Derzhin K.V., gr.515à
 * @date 21.06.2020
 * @brief Practice
 *
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "river.h"	
#pragma warning(disable:4996)

struct rivers* memory_allocation() {
	struct rivers* memoryblock = malloc(1000000000 * sizeof(struct rivers)); //memory for data from file
	if (!memoryblock) return NULL; //if memory allocation error
	return memoryblock;
}

struct rivers* alldataload(FILE* fp, struct rivers* database) {
	int i = 0, j = 0;
	while (j != EOF) { //load data until the file ends
		j = fscanf(fp, "%s%i%i", database[i].name, &(database[i].lenght), &(database[i].depth));
		if (((j<3)&&(j>EOF))||((strlen(database[i].name)>STR_LENGTH)&&(j!=EOF))) return NULL;//if uncorrect data
		i++;
	}
	return database;
}

void alldataview(struct rivers* database) {
	printf("DATABASE:\n|River name| lenght  |depth|\n");
	for (int i = 0; i < N; i++) {
		printf("|%-10s| %-5ikm | %-2im |\n", database[i].name, database[i].lenght, database[i].depth); //print data from array
	}
}

int searchdata(struct rivers* database) {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (database[i].depth < 50) {	//for rivers with a depth of less than 50 meters add each lenght
			sum += database[i].lenght;
		}
	}
	return sum;
}