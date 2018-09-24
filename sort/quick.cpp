#include <algorithm>
#include "sort.h"

template<typename T>
int __partition( T [], int, int );

template<typename T>
void __quickSort( T [], int, int );

// 其返回值满足以下规则：
// arr[l..p - 1] <= arr[p] 和 arr[p + 1..r] >= arr[p]
template<typename T>
int __partition( T arr[], int left, int right ) {
  T pivot = arr[left];
  int j = left;

  for ( int i = left + 1; i <= right; i++ )
    if ( arr[ i ] < pivot)
      swap( arr[ ++j ], arr[ i ] );

  swap( arr[ left ], arr[ j ] );

  return j;
}

template<typename T>
void __quickSort( T arr[], int left, int right ) {
  if ( left >= right ) return;

  int pivot = __partition( arr, left, right );
  __quickSort( arr, left, pivot );
  __quickSort( arr, pivot + 1, right );
}

template<typename T>
void quickSort( T arr[], int n ) {
  __quickSort( arr, 0, n - 1 );
}
