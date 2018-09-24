#include "SortTestHelper.h"
#include "insertion.cpp"
#include "merge.cpp"
#include "mergeBottomUp.cpp"
#include "selection.cpp"
#include "quick.cpp"
#include "quick2.cpp"
#include "quick3.cpp"

using namespace SortTestHelper;

int main() {
  int n = 1000000;

  cout << "Sort Random Array:" << endl;

  int * arr1 = generateRandomArray( n, 0, n );
  int * arr2 = copyIntArray( arr1, n );
  int * arr3 = copyIntArray( arr1, n );
  int * arr4 = copyIntArray( arr1, n );
  testSort( "Merge Sort", mergeSort, arr1, n );
  testSort( "Quick Sort", quickSort, arr2, n );
  testSort( "Quick Sort 2", quickSort2, arr3, n );
  testSort( "Quick Sort 3", quickSort3, arr4, n );
  delete [] arr1;
  delete [] arr2;
  delete [] arr3;
  delete [] arr4;

  cout << endl;

  cout << "Sort Nearly Ordered Array:" << endl;

  arr1 = generateNearlyOrderedArray( n, 100 );
  arr2 = copyIntArray( arr1, n );
  arr3 = copyIntArray( arr1, n );
  arr4 = copyIntArray( arr1, n );
  testSort( "Merge Sort", mergeSort, arr1, n );
  testSort( "Quick Sort", quickSort, arr2, n );
  testSort( "Quick Sort 2", quickSort2, arr3, n );
  testSort( "Quick Sort 3", quickSort3, arr4, n );
  delete [] arr1;
  delete [] arr2;
  delete [] arr3;
  delete [] arr4;

  cout << endl;

  cout << "Sort Random Array From 0 to 10: " << endl;

  arr1 = generateRandomArray( n, 0, 10 );
  arr2 = copyIntArray( arr1, n );
  arr3 = copyIntArray( arr1, n );
  arr4 = copyIntArray( arr1, n );
  testSort( "Merge Sort", mergeSort, arr1, n );
  testSort( "Quick Sort", quickSort, arr2, n );
  testSort( "Quick Sort 2", quickSort2, arr3, n );
  testSort( "Quick Sort 3", quickSort3, arr4, n );
  delete [] arr1;
  delete [] arr2;
  delete [] arr3;
  delete [] arr4;

  cout << endl;

  return 0;
}
