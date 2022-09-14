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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Sameh Elwakeel
 * @date 13th September 2022
 *
 */
#include "../include/common/memory.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

/***********************************************************
 Function Definitions
***********************************************************/

/*

  Basic Pre-made functions

*/

void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

/*

  Final Assessment Functions

*/

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length) {

  uint8_t ** srcAddress = &src;
  uint8_t ** dstAddress = &dst;

  if(srcAddress == dstAddress)
    return src;

  uint8_t * srcData;
  srcData = (uint8_t *)malloc(length*sizeof(uint8_t)) != NULL ? (uint8_t *)malloc(length*sizeof(uint8_t)) : NULL;
  
  if(srcData == NULL) {
    perror("Not enough memory available.");
    abort();
  }

  *srcData = *src;
  free(src);
  my_memcopy(srcData, dst, length);
  free(srcData);

  return dst;

}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length) {
  /* 
    We can also attempt to check the size of allocated memory for the destenation.
    If it is less than the given length, then we can use "realloc()" to change its
    size to length size.
  */
  uint8_t *dest = dst;
  uint8_t *source = src;
  size_t len = length;

  uint8_t i = 0;
  while(i < len) {
    *(dest + i) = *(source + i); 
    i++;
  }

  return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value) {
  
  uint8_t *source = src;
  size_t len = length;
  uint8_t val = value;

  uint8_t i = 0;
  while(i < len) {
    *source = val; 
    i++;
  }

  return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length) {
  
  uint8_t *source = src;
  size_t len = length;
  uint8_t val = 0;

  my_memset(source, len, val);

  return src;
}

uint8_t * my_reverse(uint8_t * src, size_t length) {

  uint8_t temp;
  uint8_t startStack;
  uint8_t endStack;
  for(int i = 0; i < (length/2); i++) {
    startStack = *(src+i);
    endStack = *((src + length) - i);
    temp = startStack;
    startStack = endStack;
    endStack = temp;
  }

  return src;
}

int32_t * reserve_words(size_t length) {

  if((int32_t *)malloc(length * sizeof(length)) != NULL) {
    return (int32_t *)malloc(length * sizeof(length));
  } else {
    perror("Not enough memory available.");
    return (int32_t *)malloc(length * sizeof(length));
  }

}

void free_words(int32_t * src) {
  free((void *)src);
}