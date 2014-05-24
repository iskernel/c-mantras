#ifndef CM_SEARCHING_H_
#define CM_SEARCHING_H_

#define number int
#define uint   unsigned int

/*
Linear Search and Flag Search
Precondition:
 key is the element who is searched
 array[] is the array where the key is searched
 arraySize is the size of the array
Postcondition:
 Returns the position of the key, if the key is in the array
 Returns arraySize if the element does not exists in the array
*/
uint LinearSearch(number key, number array[], number arraySize);
uint SentinelLinearSearch(number key, number array[], number arraySize);

/*
Binary search, Performant binary search
Precondition:
 key is the element who is searched
 array[] is the array where the key is searched.
 array[] is SORTED
 arraySize is the size of the array
Postcondition:
 Returns the position of the key, if the key is in the array
 Returns arraySize if the element does not exists in the array
*/
uint BinarySearch(number key, number array[], number arraySize);
uint ImprovedBinarySearch(number key, number array[], number arraySize);
uint InterpolationSearch(number key, number array[], number arraySize);

#endif
