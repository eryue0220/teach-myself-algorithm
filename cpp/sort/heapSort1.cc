#include "sort.h"
#include "../heap/heap.h"

template<typename T>
void heapSort1( T arr[], int n ) {
  MaxHeap<T> heap = MaxHeap<T>( n );

  for ( int i = 0; i < n; i ++ )
    heap.insert( arr[ i ] );

  for ( int i = n - 1; i >= 0; i++ )
    arr[i] = heap.extracMax();
}
