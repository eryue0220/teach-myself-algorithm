#include "search.h"

/**
 * @description 若查找到 target 则返回 target 在 arr 数组中的位置，否则返回 -1;
 * @return int
 */
template<typename T>
int binarySearch( T arr[], int n, T target ) {
  // 表示在 arr[left...right] 间查找 target
  int left = 0;
  int right = n - 1;

  while ( left <= right ) {
    int mid = left + ( right - left ) / 2;
    if ( arr[mid] == target ) return mid;
    if ( target < arr[mid] ) right = mid - 1;
    else if ( arr[mid] < target ) left = mid + 1;
  }

  return -1;
}
