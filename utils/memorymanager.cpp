/*
 * memorymanager.cpp
 *
 *  Created on: Oct 31, 2020
 *      Author: keith
 */

//TODO organize includes
#include "../includes/memorymanager.h"

/**
 * this will hold the list of structs
 */
data *list_data=0;
data *piter=0;

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
//	if(list_data){
//		piter=list_data->data *pnext;}
	if(total_memory > 0){

	}

	return 0;
}

/**
 * deallocate the list of structs, easiest way is to start at the beginning
 * and delete as you go, don't forget to set list_data to null when done
 *
 * \return SUCCESS if memory deallocated
 *         NO_STRUCTS_TO_DEALLOCATE if no memory allocated
 */
int destroy_list(){
	return 0;
}

/**
 * How many structs are available in list_data
 *
 * \return number structs available
  */
int numb_available_structs(){
	return 0;
}

/**
 *returns the list for client use
 *
 * \return 	pointer to list
 * 			0 if the list his empty
 *
 */
data*  get_list(){
	return 0;
}
