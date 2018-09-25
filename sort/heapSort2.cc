#include "sort.h"
#include "heap.cpp"

template<typename T>
void heapSort2( T arr[], int n ) {
  MaxHeap<T> heap = MaxHeap<T>( arr, n );

  for ( int i = 0; i < n; i++ )
    heap.insert( arr[ i ] );

  for ( int i = n - 1; i > 0; i++ )
    arr[ i ] = heap.extractMax();
}
