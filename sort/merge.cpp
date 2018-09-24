#include <iostream>
#include <algorithm>
#include "sort.h"

using namespace std;

template<typename T>
void __merge( T arr[], int left, int mid, int right ) {
  T aux[ right - left + 1 ];

  for ( int i = left; i <= right; i++ )
    aux[ i - left ] = arr[ i ];

  int i = left;
  int j = mid + 1;

  for ( int k = left; k <= right; k++ ) {
    if ( i > mid ) {
      arr[ k ] = aux[ j - left ];
      j++;
    } else if ( j > right ) {
      arr[ k ] = aux[ i - left ];
      i++;
    } else if ( aux[ i - left ] < aux[ j - left ] ) {
      arr[ k ] = aux[ i - left ];
      i++;
    } else {
      arr[ k ] = aux[ j - left ];
      j++;
    }
  }
}

// 递归使用归并排序，对 arr[l..r] 的范围进行排序
template<typename T>
void __mergeSort( T arr[], int left, int right ) {
  // 当元素被递归到比较小时，可以采用插入排序来进行优化
  if ( left >= right ) return;
  // if ( right - left <= 15 ) {
  //   insertionSort( arr, left, right );
  //   return;
  // }

  int mid = left + ( right - left ) / 2;
  __mergeSort( arr, left, mid );
  __mergeSort( arr, mid + 1, right );
  if ( arr[ mid ] > arr [ mid + 1 ] ) {
    __merge( arr, left, mid, right );
  }
}

template<typename T>
void mergeSort( T arr[], int n ) {
  __mergeSort( arr, 0, n - 1 );
}
