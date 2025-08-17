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
 * @brief Declarations of functions to analyse statistics 
 *
 *
 *
 * @author Hemang Tijare
 * @date 17 Aug 2025
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Print statistics: min, max, mean, median */
void print_statistics(unsigned char* array, unsigned int length);

/* Print array elements */
void print_array(unsigned char* array, unsigned int length);

/* Return median of array */
unsigned char find_median(unsigned char* array, unsigned int length);

/* Return mean of array */
unsigned char find_mean(unsigned char* array, unsigned int length);

/* Return max of array */
unsigned char find_maximum(unsigned char* array, unsigned int length);

/* Return min of array */
unsigned char find_minimum(unsigned char* array, unsigned int length);

/* Sort array (largest to smallest) */
void sort_array(unsigned char* array, unsigned int length);




#endif /* __STATS_H__ */
