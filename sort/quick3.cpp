#include <algorithm>
#include <ctime>
#include "sort.h"

// 三路快排实现
template<typename T>
void __quickSort3( T arr[], int left, int right ) {
  if ( right - left <= 15 ) {
    insertionSort( arr, left, right);
    return;
  } 

  // partition
  swap( arr[left], arr[ rand() % ( right - left + 1 ) + left ] );
  T pivot = arr[ left ];
  // arr[l + 1 .. lt] < pivot
  int less = left;
  // arr[l + 1 ... r] > pivot
  int greater = right + 1;
  int i = left + 1;

  while ( i < greater ) {
    if ( arr[ i ] < pivot ) {
      swap ( arr[i], arr[ less + 1 ] );
      less++;
      i++;
    } else if ( arr[ i ] > pivot ) {
      swap( arr[ i ], arr[ greater - 1 ] );
      greater--;
    } else {
      i++;
    }
  }

  swap( arr[ left ], arr[ less ] );
  __quickSort3( arr, left, less - 1 );
  __quickSort3( arr, greater, right );
}

template<typename T>
void quickSort3( T arr[], int n ) {
  // set random seek
  srand( time ( NULL ) );
  __quickSort3( arr, 0, n - 1 );
}