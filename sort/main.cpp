#include "SortTestHelper.h"
#include "insertion.cpp"
#include "merge.cpp"
#include "mergeBottomUp.cpp"
#include "selection.cpp"
#include "quick.cpp"

using namespace SortTestHelper;

int main() {
  int n = 10000;
  int * arr1 = generateRandomArray( n, 0, n );
  int * arr2 = copyIntArray( arr1, n );
  testSort( "Merge Sort", mergeSort, arr1, n );
  testSort( "Merge Sort Bottom Up", mergeSortBU, arr2, n );
  // testSort( "Quick Sort", quickSort, arr1, n );

  delete [] arr1;
  delete [] arr2;

  return 0;
}
