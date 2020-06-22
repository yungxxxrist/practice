/**
 * @file database.c
 * @author Derzhin K.V., gr.515à
 * @date 21.06.2020
 * @brief Practice
 *
 */

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include"river.h"
#pragma warning(disable:4996)

int main() {
	int k;
	FILE* fp=0;
	struct rivers* mydata = 0;
	printf("COMMANDS:\n0-to view data\n1-to print the total length of rivers "
		"with a depth of less than 50 meters\n2-to exit\n");
	for (;;) {
		printf("\nEnter command:");
		scanf("%i", &k);
		switch (k) {
		case 0:
			fp = fopen("rivers.txt", "r");//open file
			if (!fp) {
				printf("File opening error"); break;
			};//open file error
			mydata = memory_allocation();
			if (mydata == NULL) {
				printf("Memory allocation error\n"); break;//memory allocation error
			}
			mydata = alldataload(fp, mydata);//load data to array
			if (mydata == NULL) {
				printf("Uncorrect data in database\n"); break;//uncorrect data in file
			}
			alldataview(mydata); //view data
			fclose(fp); //close file
			break;	
		case 1:
			fp = fopen("rivers.txt", "r");//open file
			if (!fp) {
				printf("File opening error"); break;
			};//open file error
			mydata = memory_allocation();
			if (mydata == NULL) {
				printf("Memory allocation error\n"); break;//memory allocation error
			}
			mydata = alldataload(fp, mydata);//load data to array
			if (mydata == NULL) {
				printf("Uncorrect data in database\n"); break;//uncorrect data in file
			}
			printf("Total lenght:%i km", searchdata(mydata)); //lenght of rivers
			fclose(fp); //close file
			break; 
		case 2:
			exit(EXIT_SUCCESS);	//for exit from prog
		default:
			printf("Unknown command, try another\n"); break; //if command undefined
		}
	}
	_getch();
	return 0;
}
