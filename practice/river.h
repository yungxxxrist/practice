/**
 * @file river.h
 * @author Derzhin K.V., gr.515à
 * @date 21.06.2020
 * @brief Practice
 *
 */
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
  *	Creates memory block
  *	@param
  *	@return struct rivers* memoryblock - block of reserved memory
  */
struct rivers* memory_allocation();

/**
  *	Filling out information from file
  *	@param FILE* fp - file with info, struct rivers* database - memory block
  *	@return struct rivers* database - array with info from database
  */
struct rivers* alldataload(FILE* fp, struct rivers* database);

/**
  *	Search by condition (total length of rivers with a depth of less than 50 meters)
  *	@param struct rivers* - array with info from database
  *	@return int - total lenght
  */
int searchdata(struct rivers* database);

/**
  *	Database information output
  *	@param struct rivers* - array with info from database
  *	@return 
  */
void alldataview(struct rivers* database);
#endif // !RIVER_H
