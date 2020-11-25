/*
 * memorymanager.cpp
 *
 *  Created on: Oct 31, 2020
 *      Author: keith
 */

//TODO organize includes
#include <iostream>
#include "../includes/memorymanager.h"
#include "../includes/utilities.h"
#include "../includes/constants.h"
using namespace std;

/**
 * this will hold the list of structs
 */
data *list_data=0;

int num_struct = 1;



/**
 * create a linked list of  structs.
 * NOTE: be sure you do not leak memory if you call this function twice!
 *       IOW deallocate any existing list before reallocating
 *
 * \param total_memory: the maximum memory to use
 * \return if a positive number, then its the number of structs created
 *         if 0, then there is not enough memory to allocate a struct
 * 		   if MEM_ALREADY_ALLOCATED  if memory has already been allocated by this function.
 * 		   						     You can tell if memory has already been allocated
 * 		   						     by whether list_data points to null or not.
 */
int create_list(int total_memory){
	if (list_data!=NULL){
		return MEM_ALREADY_ALLOCATED;
	}else if (how_many_structs_can_fit_in_memory(total_memory)==0){
		return 0;
	}

	list_data = new data;
	data *piter=list_data;
	//add more data structs to the list
	for(int i=1;i<how_many_structs_can_fit_in_memory(total_memory);i++){
		//add another struct to the list
		(*piter).p_next = new data;
		piter=(*piter).p_next;
		num_struct++;
	}
	return num_struct;
}

/**
 * deallocate the list of structs, easiest way is to start at the beginning
 * and delete as you go, don't forget to set list_data to null when done
 *
 * \return SUCCESS if memory deallocated
 *         NO_STRUCTS_TO_DEALLOCATE if no memory allocated
 */
int destroy_list(){
	if(!list_data){
		return NO_STRUCTS_TO_DEALLOCATE;
	}
	data *pstart = new data;
	pstart = list_data;

	//as long as pstart is not null
	while(pstart){
		//get a pointer to next data struct in list
		list_data = (*list_data).p_next;

		//delete current data struct
		delete pstart;

		//set pstart  equal to next struct to delete
		pstart=list_data;
	}
	num_struct=0;
	return SUCCESS;
}

/**
 * How many structs are available in list_data
 *
 * \return number structs available
  */
int numb_available_structs(){
	int cnt = 0;
	data *point = list_data;
	while (point != NULL){
		cnt++;
		point = point -> p_next;
	}

	return cnt;
}

/**
 *returns the list for client use
 *
 * \return 	pointer to list
 * 			0 if the list his empty
 *
 */
data*  get_list(){
	return list_data;
}
