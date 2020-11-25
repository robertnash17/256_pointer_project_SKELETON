//============================================================================
// Name        : 256_pointer_project.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>      // std::ifstream
#include "../includes/constants.h"
#include "../includes/memorymanager.h"
#include "../includes/utilities.h"
#include "../includes/test.h"
#include "../includes/transform1.h"

using namespace std;


int main( int argc, char *argv[] )  {

	//TODO read commandline params
	string progname = argv[0];
	string infile = argv[1];
	int total_memory = stoi(argv[2]);
	string results_file = argv[3];

	//expect progname, infile, total_memory, results_file   //program and 3 arguments, argc=4
	if( argc != EXPECTED_NUMBER_ARGUMENTS ) {
	   cout<< WRONG_NUMB_ARGS <<endl;
	   return FAIL_WRONG_NUMBER_ARGS;
	}


	//cout<<test_system(argv,total_memory)<<endl;
	//cout<<"params passed are: "<<infile << " " <<total_memory<< " " << results_file<<endl;

	//TODO get the total memory passed in for use, stoi may come in handy
	//but its delicate because it expects the string to hold only numbers


	//test the memorymanager
	run_all_tests(argv,total_memory);
	return SUCCESS;
}
