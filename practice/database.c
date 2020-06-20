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
			mydata = alldataload();
			alldataview(mydata); break;
		case 1:
			mydata = alldataload();
			printf("Total lenght:%i km", searchdata(mydata)); break;
		case 2:
			exit(EXIT_SUCCESS);
		default:
			printf("Unknown command, try another\n"); break;
		}
	}
	_getch();
	return 0;
}
