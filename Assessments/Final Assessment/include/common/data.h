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
 * @file data.h
 * @brief Abstraction of data operations
 *
 * This header file provides an abstraction of data operations
 *
 * @author Sameh Elwakeel
 * @date 13th September 2022
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

/**
 * @brief Convert integer to ASCII
 *
 * Given the data, pointer and base, the integer (data) is converted to ASCII
 * accordingly with its base.
 *
 * @param data the integer which will be converted
 * @param ptr pointer to help store and convert data to ascii
 * @param base the base number of the given data
 *
 * @return The length of converted data.
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Convert ASCII to Integer
 *
 * Given the pointer, digit and base, the ASCII is converted to an Integer
 * accordingly with its base.
 * 
 * 
 * @param ptr pointer to help store and convert data to ascii
 * @param digit The Ascii to be converted
 * @param base the base number of the given data
 *
 * @return The integer converted.
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)

#endif /* __DATA_H__ */
