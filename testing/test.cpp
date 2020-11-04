/*
 * test.cpp
 *
 *  Created on: Nov 1, 2020
 *      Author: keith
 */

#include <iostream>
#include <fstream>
#include <string>
#include "../includes/constants.h"
#include "../includes/utilities.h"
#include "../includes/memorymanager.h"
#include "../includes/transform1.h"
#include "../includes/test.h"

using namespace std;
const int ONE_POINT=1;
const int TWO_POINT=2;
const int THREE_POINT=3;
const int FIVE_POINT=5;
//tracks how many points you will get out of 100
//yeah, yeah its a global
int total_points =1;

//this is a template class, its mostly here as a helper for me
//the T and U are generic params, I can substitute any type for them
//they must be comparable with ==, templates are extremely hard to get right BTW
template<typename T, typename U>
bool EXPECT_EQ(T expectedVal, U actualVal,string testnumb = "", int pts=TWO_POINT){
	bool bout = (expectedVal == actualVal);
	if (bout){
		total_points+=pts;
		cout<<"SUCCESS Test="+testnumb<<" points:"<<total_points;
	}
	else{
		cout<<"FAIL    Test="<<testnumb<<" expected="<<expectedVal<<", actual="<<actualVal;
	}
	cout<<endl;
	return bout;
}

//runs a diff command, I'm using (GNU diffutils) 3.3
//this code cadged from stack overflow
bool diff_files(string testoutput,string correctfile, string testnumb = "" ){

	const int SMALL_BUFFER = 512;
	if (testoutput.length()== 0 || correctfile.length()==0)
		return false;

	//build shell command
	string command ="diff "+  testoutput + " " + correctfile;

	FILE *in;
	char buff[SMALL_BUFFER];

	if(!(in = popen(command.c_str(), "r")))
		return false;

	if (fgets(buff, sizeof(buff), in)==NULL)
		return true;
	else
		cout << buff;

	pclose(in);
	return false;
}

//gets rid of the legacy .out files
void remove_file_debris(){
	popen("rm ./out.txt", "r");
}
//returns: true file is there, false if not
bool does_file_exist(const std::string &file_name){
	std::ifstream fle(file_name);
	return fle.good();
}
int test_system(char *argv[], int total_memory){

	//open input file
	ifstream myInputfile;
	myInputfile.open(argv[1]);	//could open with  flags myfile.open(MYFILE, ios::in)													//note the .c_str() call on MYFILE
	if (!myInputfile.is_open())
		return COULD_NOT_OPEN_FILE;

	//open output file
	ofstream myOutputfile;
	myOutputfile.open(argv[3]);
	if (!myOutputfile.is_open())
		return COULD_NOT_OPEN_FILE;

	//create the list
	create_list(total_memory);


	data* p=get_list();	//always points to the head of the list
	data *ptmp=p;		//used to traverse the list

	//read 1 char at a time and place in the list
	//until it is full, then restart at the beginning
	char c;
	while (myInputfile.get(c)){
		transform(&c);
		ptmp->data=c;
		myOutputfile<<ptmp->data;
		if(ptmp->p_next)
			ptmp=ptmp->p_next;//go to next
		else
			ptmp=p;	//start over
	}

	//cleanup
	myInputfile.close();
	myOutputfile.close();
	destroy_list();

	//worth 10 (correct output)
	if (does_file_exist(OUT))
		EXPECT_EQ(true,diff_files(OUT, OUT_CORRECT),"30",40);
	else
		cout<<"ERROR 30 "<<OUT<< " does not exist"<<endl;

	return SUCCESS;
}

void test_how_many_structs_can_fit_in_memory(){
	EXPECT_EQ(0,how_many_structs_can_fit_in_memory(0 ) ," 1");
	EXPECT_EQ(0,how_many_structs_can_fit_in_memory(15) ," 2");
	EXPECT_EQ(1,how_many_structs_can_fit_in_memory(16) ," 3");
	EXPECT_EQ(1,how_many_structs_can_fit_in_memory(17) ," 4");
	EXPECT_EQ(1,how_many_structs_can_fit_in_memory(31) ," 5");
	EXPECT_EQ(2,how_many_structs_can_fit_in_memory(32) ," 6");
	EXPECT_EQ(2,how_many_structs_can_fit_in_memory(33) ," 7");
}
void test_create_and_destroy(int total_memory){
	//try to create without enough memory
	EXPECT_EQ(0,create_list(0),"11",FIVE_POINT);

	//now with enough
	EXPECT_EQ(total_memory/sizeof(data),create_list(total_memory),"12",FIVE_POINT);

	//try to create again without destroying structs
	EXPECT_EQ(MEM_ALREADY_ALLOCATED,create_list(total_memory),"13",FIVE_POINT);

	//try to deallocate structs
	EXPECT_EQ(SUCCESS,destroy_list(),"14",FIVE_POINT);

	//try to deallocate structs again
	EXPECT_EQ(NO_STRUCTS_TO_DEALLOCATE,destroy_list(),"15",FIVE_POINT);
}

void test_numb_available_structs(int total_memory){
	create_list(0);
	EXPECT_EQ(0,numb_available_structs(),"21",FIVE_POINT);

	create_list(15);
	EXPECT_EQ(0,numb_available_structs(),"22",FIVE_POINT);
	destroy_list();

	create_list(16);
	EXPECT_EQ(1,numb_available_structs(),"23",FIVE_POINT);
	destroy_list();

	create_list(total_memory);
	EXPECT_EQ(total_memory/sizeof(data),numb_available_structs(),"24",FIVE_POINT);
	destroy_list();
}

//runs all tests, returns the score
void run_all_tests(char *argv[], int total_memory){
	//get rid of old out.txt
//	remove_file_debris();  //this is async call, do not use it with this program

	test_how_many_structs_can_fit_in_memory();
	test_create_and_destroy(total_memory);
	test_numb_available_structs(total_memory);
	test_system(argv,total_memory);
}
