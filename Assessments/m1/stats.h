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
 * @file stats.h
 * @brief the header file of stats.c
 *
 * This header file contains all the function declarations along with a breif description
 * describing the function in detail such as the parameters and the information returned
 * from the function 
 *
 * @author Sameh Elwakeel
 * @date 7th September 2022
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * 
 * Function: print_statistics
 * 
 * @brief This function displays the overall statistics of the given array
 *
 * Given the array, the function executes multiple other functions including the
 * mean, median, maximum and minimum to generate a list of statistics.
 * 
 * @param unsigned char *arr      A pointer to the given array for the function to loop over
 * @param unsigned int length     A macro storing the size of the array (40)
 *
 */
/**
 * 
 * Function: print_array
 * 
 * @brief This function displays the given array
 *
 * Given the array, the function loops on its size and
 * displays the contents of the array.
 *
 * @param unsigned char *arr      A pointer to the given array for the function to loop over
 * @param unsigned int length     A macro storing the size of the array (40)
 *
 */
/**
 * 
 * Function: find_median
 * 
 * @brief This function grabs the median by sorting the array and grabbing the center number
 *
 * @param unsigned char *arr      A pointer to the given array for the function to loop over
 * @param unsigned int length     A macro storing the size of the array (40)
 *
 */
 /**
 * 
 * Function: find_mean
 * 
 * @brief This function grabs the mean by incrementing the numbers and diving by its size
 *
 * @param unsigned char *arr      A pointer to the given array for the function to loop over
 * @param unsigned int length     A macro storing the size of the array (40)
 *
 */
 /**
 * 
 * Function: find_maximum
 * 
 * @brief This function grabs the maximum number in the array by sorting through the array using a for loop
 *
 * @param unsigned char *arr      A pointer to the given array for the function to loop over
 * @param unsigned int length     A macro storing the size of the array (40)
 *
 */
 /**
 * 
 * Function: find_minimum
 * 
 * @brief This function grabs the minimum number in the array by sorting through the array using a for loop
 *
 * @param unsigned char *arr      A pointer to the given array for the function to loop over
 * @param unsigned int length     A macro storing the size of the array (40)
 *
 */
 /**
 * 
 * Function: sort_array
 * 
 * @brief This function sorts the array by looping on all elements and comparing each element with each other to sort in acending order
 *
 * @param unsigned char *arr      A pointer to the given array for the function to loop over
 * @param unsigned int length     A macro storing the size of the array (40)
 *
 */

/* Add Your Declarations and Function Comments here */ 
void print_statistics();
void print_array(unsigned char *arr, unsigned int length);
int find_median(unsigned char *arr, unsigned int length);
float find_mean(unsigned char *arr, unsigned int length);
int find_maximum(unsigned char *arr, unsigned int length);
int find_minimum(unsigned char *arr, unsigned int length);
void sort_array(unsigned char *arr, unsigned int length);

#endif /* __STATS_H__ */
