#include <iostream>
#include <ctime>
#include "heap.cpp"

using namespace std;

int main() {
  MaxHeap<int> heap = MaxHeap<int>(100);
  cout << heap.size() << endl;

  srand( time ( NULL ) );

  for ( int i = 0; i < 15; i++ )
    heap.insert( rand() % 100 );

  return 0;
}
