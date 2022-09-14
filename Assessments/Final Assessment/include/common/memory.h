/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Sameh Elwakeel
 * @date 14th September 2022
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stddef.h>
#include <stdint.h>
#include <inttypes.h>

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief moves data from source to destination
 *
 * Given the two byte pointers, source and destination, along with the length
 * of bytes to move, data is moved from the source address to the destination address
 *
 * @param src pointer to source of data
 * @param dst pointer to the destination for data to be moved at
 * @param length size of the bytes to be moved
 *
 * @return destination of moved data
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief copies the data located in the source to the destination
 *
 * Given the two byte pointers, source and destination, along with the length
 * of bytes to copy, data is copied from the source address to the destination address
 *
 * @param src pointer to source of data
 * @param dst pointer to the destination for data to be copied at
 * @param length size of the bytes to be copied
 *
 * @return destination of copied data
 */
 uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief sets the given value to the source address
 *
 * Given the source, along with the length of bytes and value to set, 
 * the value is set for all memory locations of the source.
 *
 * @param src pointer to source of data
 * @param length size of the bytes to be set
 * @param value the value to be set for the source
 *
 * @return source of set data
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief zero's out the given source memory location
 *
 * Given the source, along with the length of bytes, the source is filled
 * with zeros in all its locations.
 *
 * @param src pointer to source of data
 * @param length size of the bytes to be zero'd out
 *
 * @return source of set data
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief reverses the entire stack of data 
 *
 * Given the source, along with the length of bytes, the source containing
 * its data is reversed by switching positions with the first and last data
 * located in the head and tail of the stack then incrementing to get closer
 * to the center.
 *
 * @param src pointer to source of data
 * @param length size of the bytes to be reversed
 *
 * @return source of set data
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief allocate memory depending on the number of words
 *
 * Given the length of words, memory is allocated depending on its size
 * and
 *
 * @param length size of the bytes to be copies
 *
 * @return pointer of allocated memory
 */
int32_t * reserve_words(size_t length);

/**
 * @brief frees the memory from the given source
 *
 * Given the source, the memory is cleared by freeing the source.
 *
 * @param src pointer to source of data
 *
 * @return Void.
 */
void free_words(int32_t * src);

#endif /* __MEMORY_H__ */
