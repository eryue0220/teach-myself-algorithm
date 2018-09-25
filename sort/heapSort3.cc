#include <algorithm>
#include "sort.h"

template<typename T>
void __shiftDown( T arr[], int n, int position ) {
  while ( 2 * position + 1 < n ) {
    int j = 2 * position + 1;
    if ( j + 1 < n && arr[ j + 1 ] > arr[ j ] ) j += 1;
    if ( arr[ position ] >= arr[ j ] ) break;
    swap( arr[position], arr[j] );
    position = j;
  }
}

template<typename T>
void heapSort3( T arr[], int n ) {
  for ( int i = ( n - 1 ) / 2; i >= 0; i-- )
    __shiftDown( arr, n, i );

  for ( int i = n - 1; i > 0; i-- ) {
    swap ( arr[0], arr[i] );
    __shiftDown( arr, i, 0 );
  }
}
