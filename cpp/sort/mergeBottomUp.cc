#include <algorithm>
#include "sort.h"

using namespace std;

template<typename T>
void __mergeBU( T arr[], int left, int mid, int right ) {
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

template <typename T>
void mergeSortBU( T arr[], int n ) {
  for ( int sz = 1; sz <= n; sz += sz )
    for ( int i = 0; i + sz < n; i += sz + sz )
      __mergeBU( arr, i, i + sz - 1, min( i + sz + sz - 1, n - 1 ) );
}
