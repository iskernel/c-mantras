#ifndef CM_SEARCHING_H_
#define CM_SEARCHING_H_

#include <stdbool.h>
//
//#define number int
//#define uint   unsigned int
//
enum cm_search_algorithm
{
	cm_search_algorithm_linear = 0,
	cm_search_algorithm_sentinel_linear,
	cm_search_algorithm_binary,
	cm_search_algorithm_improved_binary,
	cm_search_algorithm_interpolation
};
//
//struct cm_search_interface
//{
//	void* (*element_at)(void* container, cm_size index);
//	cm_size (*compare)(void* element_1, void* element_2);
//	bool (*reached_end)(void* container, cm_size index);
//};
//
//
///*
//Linear Search and Flag Search
//Precondition:
// key is the element who is searched
// array[] is the array where the key is searched
// arraySize is the size of the array
//Postcondition:
// Returns the position of the key, if the key is in the array
// Returns arraySize if the element does not exists in the array
//*/
//size_t cm_search_linear(number key, number array[], number arraySize);
//size_t cm_search_sentinel_linear(number key, number array[], number arraySize);
//
///*
//Binary search, Performant binary search
//Precondition:
// key is the element who is searched
// array[] is the array where the key is searched.
// array[] is SORTED
// arraySize is the size of the array
//Postcondition:
// Returns the position of the key, if the key is in the array
// Returns arraySize if the element does not exists in the array
//*/
//size_t cm_search_binary(number key, number array[], number arraySize);
//size_t cm_search_improved_binary(number key, number array[], number arraySize);
//size_t cm_search_interpolation(number key, number array[], number arraySize);
//
#endif
