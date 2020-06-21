#ifndef RIVER_H
#define RIVER_H
#define STR_LENGTH 11	//max lenght of river name
#define N 12	//max number of recordings in database

struct rivers {
	char name[STR_LENGTH];	//river name
	int lenght;	//river lenght
	int depth;	//river depth
};

/**
  *	Filling out information from file
  *	@param 
  *	@return struct rivers* database - array with info from database
  */
struct rivers* alldataload();

/**
  *	Search by condition (total length of rivers with a depth of less than 50 meters)
  *	@param struct rivers* - array with info from database
  *	@return int - total lenght
  */
int searchdata(struct rivers* database);

/**
  *	Search by condition (total length of rivers with a depth of less than 50 meters)
  *	@param struct rivers* - array with info from database
  *	@return 
  */
void alldataview(struct rivers* database);
#endif // !RIVER_H
