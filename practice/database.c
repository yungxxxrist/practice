#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int main() {
	int k;
	struct rivers* mydata = 0;
	printf("COMMANDS:\n0-to view data\n1-to print the total length of rivers "
		"with a depth of less than 50 meters\n2-to exit\n");
	for (;;) {
		printf("\nEnter command:");
		scanf("%i", &k);
		switch (k) {
		case 0:
			mydata = alldataload(); //load data to array
			alldataview(mydata); break;	//view data
		case 1:
			mydata = alldataload();	//load data to array
			printf("Total lenght:%i km", searchdata(mydata)); break; //lenght of rivers
		case 2:
			exit(EXIT_SUCCESS);	//for exit from prog
		default:
			printf("Unknown command, try another\n"); break; //if command undefined
		}
	}
	_getch();
	return 0;
}
