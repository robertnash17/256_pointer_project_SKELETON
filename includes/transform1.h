///*
// * transform1.h
// * Sole purpose of this class is to covert lowercase chars into uppercase
// * For instance 'a' to 'A'
// *
// *  Created on: Oct 31, 2020
// *      Author: keith
// */

#ifndef TRANSFORM1_H_
#define TRANSFORM1_H_

/**
 * transforms a lowercase char to an uppercase one
 * for instance 'a' to 'A'. Has no effect on non-
 * alphabetic characters.  islower may be of use
 *
 * \param pchar char to transform
 * \return bool - 	true - transform occurred
 * 					false - either pchar is null or its not an alhabetic char
 */
bool transform(char *pchar);

#endif /* TRANSFORM1_H_ */
