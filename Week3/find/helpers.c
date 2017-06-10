/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include <stdio.h>
#include "helpers.h"
int indexArray[65536];
/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // return false if nonpositive n
    if(n<0){
      return false;
    }

    int mid = n/2;
    int right = n-1;
    int left = 0;
    // use binary search algorithm O(log n)
    while(left <= right){
      if(values[mid] < value){
        left = mid + 1;
      }
      else if(values[mid] == value){
        return true;
      }
      else{
        right = mid - 1;
      }
      mid = (left+right)/2;
    }
    // TODO: if not found, returns false
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement a sorting algorithm

    int index;
    printf("IndexArray initialized\n");


    //create an array who's indexes map to the values in values array
    for(int i = 0; i < n; i++){
      index = values[i];
      indexArray[index]++;
    }

    printf("IndexArray completed\n");
    index = 0;
    //create the sorted array from the indexArray
    for(int i = 0; i < 65536; i++){
      if (indexArray[i] == 0){
        continue;
      }
      for(int j = indexArray[i]; j > 0; j--){
        values[index] = i;
        index++;
      }
    }
    return;
}
