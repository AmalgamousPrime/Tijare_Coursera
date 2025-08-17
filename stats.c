
/******************************************************************************
 * Copyright (C) 2020 by Coursera
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Coursera and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/

/**
 * @file stats.c
 * @brief Functions for statistical analysis
 *
 * This file contains the definitions of functions declared in stats.h.
 * They perform statistical analysis on an array of unsigned char data.
 *
 * @author Hemang Tijare
 * @date 17 Aug 2025
 *
 */

#include <stdio.h>
#include "stats.h"

/* Print statistics: min, max, mean, median */
void print_statistics(unsigned char* array, unsigned int length) {
  printf("Minimum: %d\n", find_minimum(array, length));
  printf("Maximum: %d\n", find_maximum(array, length));
  printf("Mean: %d\n", find_mean(array, length));
  printf("Median: %d\n", find_median(array, length));
}

/* Print array elements */
void print_array(unsigned char* array, unsigned int length) {
  for (unsigned int i = 0; i < length; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

/* Return median of array */
unsigned char find_median(unsigned char* array, unsigned int length) {
  // Make a copy to avoid changing original
  unsigned char temp[length];
  for (unsigned int i = 0; i < length; i++) {
    temp[i] = array[i];
  }

  // Sort copy (largest to smallest)
  sort_array(temp, length);

  if (length % 2 == 0) {
    // even: average of two middle
    return (temp[length/2 - 1] + temp[length/2]) / 2;
  } else {
    // odd: middle element
    return temp[length/2];
  }
}

/* Return mean of array */
unsigned char find_mean(unsigned char* array, unsigned int length) {
  unsigned int sum = 0;
  for (unsigned int i = 0; i < length; i++) {
    sum += array[i];
  }
  return (unsigned char)(sum / length);  // integer division (round down)
}

/* Return max of array */
unsigned char find_maximum(unsigned char* array, unsigned int length) {
  unsigned char max = array[0];
  for (unsigned int i = 1; i < length; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max;
}

/* Return min of array */
unsigned char find_minimum(unsigned char* array, unsigned int length) {
  unsigned char min = array[0];
  for (unsigned int i = 1; i < length; i++) {
    if (array[i] < min) {
      min = array[i];
    }
  }
  return min;
}

/* Sort array (largest to smallest) */
void sort_array(unsigned char* array, unsigned int length) {
  for (unsigned int i = 0; i < length-1; i++) {
    for (unsigned int j = i+1; j < length; j++) {
      if (array[i] < array[j]) {
        // swap
        unsigned char temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
}

/* main() placeholder */
int main() {
  unsigned char test[] = {34, 201, 190, 154, 8, 194, 2, 6,
                          114, 88, 45, 76, 123, 87, 25, 23,
                          200, 122, 150, 90, 92, 87, 177, 244,
                          201, 6, 12, 60, 8, 2, 5, 67};
  unsigned int length = 32;

  printf("Original array:\n");
  print_array(test, length);

  printf("\nStatistics:\n");
  print_statistics(test, length);

  printf("\nSorted array (largest → smallest):\n");
  sort_array(test, length);
  print_array(test, length);

  return 0;
}

