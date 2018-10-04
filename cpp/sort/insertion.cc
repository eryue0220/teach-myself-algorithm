#include <iostream>
#include <algorithm>
#include "sort.h"

using namespace std;

template<typename T>
void insertionSort( T arr[], int n ) {
  // 这里从 1 开始是因为在当前数组中，假设其只有一个元素，那么其已经是 sorted 的，
  // 因而不需要处理，仅从第二元素开始。
  for ( int i = 1; i < n; i++ ) {
    T element = arr[ i ];
    int j = i; // 用于保存 element 应插入的位置
    for ( ; j > 0 && arr[ j - 1 ] > element; j -- )
      arr[ j ] = arr[ j - 1 ];

    arr[j] = element;
  }
}

template<typename T>
void insertionSort( T arr[], int left, int right ) {
  for ( int i = left + 1; i <= right; i++ ) {
    T element = arr[ i ];
    int j = i;

    for ( ; j > left && arr[ j - 1 ] > element; j-- )
      arr[ j ] = arr[ j - 1 ];

    arr[j] = element;
  }
}
