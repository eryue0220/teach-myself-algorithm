#include <algorithm>
#include <ctime>
#include "sort.h"

// 其返回值满足以下规则：
// arr[l..p - 1] <= arr[p] 和 arr[p + 1..r] >= arr[p]
template<typename T>
int __partition( T arr[], int left, int right ) {
  swap ( arr[ left ], arr[ rand() % ( right - left + 1 ) + left ] );

  T pivot = arr[ left ];
  int j = left;

  for ( int i = left + 1; i <= right; i++ )
    if ( arr[ i ] < pivot)
      swap( arr[ ++j ], arr[ i ] );

  swap( arr[ left ], arr[ j ] );

  return j;
}

template<typename T>
void __quickSort( T arr[], int left, int right ) {
  if ( right - left <= 15 ) {
    insertionSort( arr, left, right);
    return;
  } 

  int pivot = __partition( arr, left, right );
  __quickSort( arr, left, pivot - 1 );
  __quickSort( arr, pivot + 1, right );
}

template<typename T>
void quickSort( T arr[], int n ) {
  // set random seek
  srand( time ( NULL ) );
  __quickSort( arr, 0, n - 1 );
}
