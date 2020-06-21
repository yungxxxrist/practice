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
#include "river.h"	//module connection
#pragma warning(disable:4996)

extern struct rivers* alldataload() {
	struct rivers* database = malloc(N * sizeof(struct rivers)); //memory for data from file
	FILE* fp;
	int i = 0;
	fp = fopen("rivers.txt", "r"); //open file
	while (fscanf(fp, "%s%i%i", database[i].name, &(database[i].lenght), &(database[i].depth)) != EOF) { //load data until the file ends
		i++;
	}
	fclose(fp); //close file
	return database;
}

extern void alldataview(struct rivers* database) {
	printf("DATABASE:\n|River name| lenght  |depth|\n");
	for (int i = 0; i < N; i++) {
		printf("|%-10s| %-5ikm | %-2im |\n", database[i].name, database[i].lenght, database[i].depth); //print data from array
	}
}

extern int searchdata(struct rivers* database) {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (database[i].depth < 50) {	//for rivers with a depth of less than 50 meters add each lenght
			sum += database[i].lenght;
		}
	}
	return sum;
}