/*
 * constants.h
 *
 *  Created on: Oct 31, 2020
 *      Author: keith
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_
#include <string>

const std::string OUT="./out.txt";
const std::string OUT_CORRECT="./out_correct.txt";
const int FAIL_WRONG_NUMBER_ARGS = -5;
const int EXPECTED_NUMBER_ARGUMENTS =4;
const int MEM_ALREADY_ALLOCATED = -1;
const int NO_MEM_ALLOCATED = -2;
const int LIST_IS_EMPTY = -3;
const int TRIED_TO_ADD_MORE_THAN_ORIGINALLY_AVAILABLE =-4;
const int COULD_NOT_OPEN_FILE=-5;

const int NO_STRUCTS_TO_DEALLOCATE = 1;
const int SUCCESS = 0;

const std::string WRONG_NUMB_ARGS = "This program expects 3 arguments; infile, the total amount of memory it can use, outfile";

struct data{
	char data;
	struct data *p_next=0;
};

#endif /* CONSTANTS_H_ */
