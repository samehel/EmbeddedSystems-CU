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
 * @file data.c
 * @brief Data file for final assessment
 *
 * @author Sameh Elwakeel
 * @date 13th September 2022
 *
 */

#include "../include/common/data.h"
#include "../include/common/memory.h"
#include "../include/common/platform.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {

    // Checking if the data is 0
    if(data == 0) {
        *ptr = '0';
        *(ptr + 1) = '\0';
        return 0;
    }

    // Checking if the data will be a negative number
    uint8_t isNegative = false;
    if (data < 0) {
      isNegative = true;
      data = data *- 1;
    }  

    *ptr = '\0';

    // Start converting it to ASCII
    uint8_t i = 1;
    for(; data > 0; i++) {
      uint8_t rm = data % base;
      *(ptr + i) = (rm < 10) ? ('0' + rm) : ('a' - 10 + rm);
      data /= base;
    }

    // Adding the negative symbol if the data was negative
    if(isNegative) {
      *(ptr + i += 1) = '-';
      i += 1;
    }

    i += 1;
    my_reverse(ptr, i);

    return i;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {

  uint8_t isNegative = false;

  // Checking if the data will be a negative number
  if(*ptr == '-') {
    isNegative = true;
    ptr++;
    digits--;
  }

  digits--;

  int32_t convertedinteger = 0;
  for(int i = 0; i < digits; i++) {
    convertedinteger = convertedinteger * base + *ptr - '0';
    ptr++;
  }

  // Adding the negative symbol if the data was negative
  if(isNegative) {
    convertedinteger = (convertedinteger - convertedinteger) - convertedinteger;
  }

  return convertedinteger;
}