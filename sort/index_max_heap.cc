#include <algorithm>
#include <cassert>

template<typename Item>
class IndexMaxHeap {
private:
  Item * data;
  int * indexes;
  int length;
  int capacity;

  void shiftUp( int position ) {
    while (
      position > 1 &&
      data[ indexes[ position / 2 ] ] < data[ indexes[ position ] ]
    ) {
      swap( indexes[ position / 2 ], indexes[  position ] );
      position /= 2;
    }
  }

  void shiftDown( int position ) {

  }

public:
  void insert( int i, Item item ) {
    assert( count + 1 <= length );
    assert( i + 1 >= 1 && i + 1 <= capacity );

    i += 1;
    data[ i ] = item;
    indexes[ length + 1 ] = i;
    length ++;
    shiftUp( length )
  }

  Item extractMax() {
    assert( count > 0 );
  }
}