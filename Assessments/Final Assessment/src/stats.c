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
 * @file stats.c
 * @brief perform statistical analyzation of the data given the array
 *
 * This program is designed to take input of a singular array and to perform statistical analyzation:
 *      
 *      - Mean: Given the array of data and length, return the mean
 *      - Median: Given the array of data and length, return the median
 *      - Print Array: Display the contents of the given array
 *      - Maximum: Given the array of data and length, return the maximum
 *      - Minimum: Given the array of data and length, return the minimum
 *      - Sort: Given the array of data and length, sort the array from largest to smallest
 *      - Print Statistics: Display the statistics of the array (combined functionalities)
 *
 * @author Sameh Elwakeel
 * @date 7th September 2022
 *
 */


#include <stdio.h>
#include "../include/common/stats.h"
#include "../include/common/platform.h"

/* Size of the Data Set */
#define SIZE (40)

/* void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  -- Other Variable Declarations Go Here 
  unsigned int length = SIZE;
  -- Statistics and Printing Functions Go Here 
  printf("-- Displaying Array Contents --\n");
  print_array(test, length);
  printf("\n-- Displaying sorted array in ascending order --\n");
  sort_array(test, length);
  print_array(test, length);
  printf("\n-- Displaying the array statistics --\n");
  print_statistics(test, length);

} */

void print_statistics(unsigned char *arr, unsigned int length) {
  PRINTF("The Median is: %d\n", find_median(arr, length));
  PRINTF("The Mean is: %.2f\n", find_mean(arr, length));
  PRINTF("The Maximum is: %d\n", find_maximum(arr, length));
  PRINTF("The Minimum is: %d\n", find_minimum(arr, length));
}

void print_array(unsigned char *arr, unsigned int length) {
  #ifndef VERBOSE
    for(int i = 0; i < length; i++) {
      PRINTF("%d ", arr[i]);
      if(i == length - 1) {
        PRINTF("\n");
      }
    }
  #endif
}

int find_median(unsigned char *arr, unsigned int length) {
  if(length % 2 == 0) {
    int numPos1 = length / 2;
    int numPos2 = (length / 2) + 1;
    int num1 = arr[numPos1];
    int num2 = arr[numPos2];
    int avg = (num1 + num2) / 2;
    return avg;
  } else if (length % 2 != 0) {
    int pos = length + 1;
    pos += 1;
    return arr[pos];
  }
}

float find_mean(unsigned char *arr, unsigned int length) {
  float sum = 0.0;
  for(int i = 0; i < length; i++) {
    sum += arr[i];
  }
  float mean = sum/length;
  return mean;
}

int find_maximum(unsigned char *arr, unsigned int length) {
  signed int max = -999;
  for(int i = 0; i < length; i++) {
    if(arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

int find_minimum(unsigned char *arr, unsigned int length) {
  unsigned int min = 999;
  for(int i = 0; i < length; i++) {
    if(arr[i] < min) {
      min = arr[i];
    }
  }
  return min;
}

void sort_array(unsigned char *arr, unsigned int length) {
  for(int i = 0; i < length; i++) {
    for(int j = i+1; j < length; j++) {
      if(arr[i] > arr[j]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

