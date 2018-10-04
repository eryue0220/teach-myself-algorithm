#include <algorithm>
#include <ctime>
#include "sort.h"

// 双路快排实现
template<typename T>
int __partition2( T arr[], int left, int right ) {
  swap ( arr[ left ], arr[ rand() % ( right - left + 1 ) + left ] );

  T pivot = arr[ left ];
  int i = left + 1;
  int j = right;

  while ( true ) {
    while ( i <= right && arr[ i ] < pivot ) i++;
    while ( j >= left + 1 && arr[ j ] > pivot ) j--;
    if ( i > j ) break;
    swap( arr[ i++ ], arr[ j-- ] );
  }

  swap ( arr[ left ], arr[ j ] );

  return j;
}

template<typename T>
void __quickSort2( T arr[], int left, int right ) {
  if ( right - left <= 15 ) {
    insertionSort( arr, left, right);
    return;
  } 

  int pivot = __partition2( arr, left, right );
  __quickSort2( arr, left, pivot - 1 );
  __quickSort2( arr, pivot + 1, right );
}

template<typename T>
void quickSort2( T arr[], int n ) {
  // set random seek
  srand( time ( NULL ) );
  __quickSort2( arr, 0, n - 1 );
}
