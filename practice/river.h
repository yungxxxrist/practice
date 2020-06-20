#ifndef RIVER_H
#define RIVER_H
#define STR_LENGTH 11
#define N 12

struct rivers {
	char name[STR_LENGTH];
	int lenght;
	int depth;
};

struct rivers* alldataload();
int searchdata(struct rivers* database);
void alldataview(struct rivers* database);
#endif // !RIVER_H
