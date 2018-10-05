template<typename T>
int binarySearchRecurisiveCore( T arr[], int start, int end, int target ) {
  if ( start > end ) return -1;
  int mid = start + ( end - start ) / 2;
  if ( arr[mid] == target ) return mid;
  if ( target < arr[ mid ] ) return binarySearchRecurisiveCore( arr, start, mid - 1, target );
  else if ( arr[mid] < target ) return binarySearchRecurisiveCore( arr, mid + 1, end, target );
}

template<typename T>
int binarySearchRecurisive( T arr[], int n, int target ) {
  return binarySearchRecurisiveCore( arr, 0, n - 1, target );
}
