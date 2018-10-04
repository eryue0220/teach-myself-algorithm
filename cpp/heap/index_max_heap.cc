#include <algorithm>
#include <cassert>

template<typename Item>
class IndexMaxHeap {
private:
  Item * data;
  int * indexes;
  int * reverse;
  int length;
  int capacity;

  void shiftUp( int position ) {
    while (
      position > 1 &&
      data[ indexes[ position / 2 ] ] < data[ indexes[ position ] ]
    ) {
      swap( indexes[ position / 2 ], indexes[  position ] );
      reverse[ indexes[ position / 2 ] ] = position / 2;
      reverse[ indexes[ position ] ] = position;
      position /= 2;
    }
  }

  void shiftDown( int position ) {
    while ( 2 * position <= length ) {
      int j = 2 * position;
      if ( j+ 1 <= length && data[ indexes[ j + 1] > data[ indexes [ j ] ] ] ) {
        j += 1;
      }
      if ( data[ indexes[ position ] ] >= data[ indexes[ j ] ] ) break;

      swap( indexes[ position ], indexes[ j ] );
      reverse[ indexes[ position ] ] = k;
      reverse[ indexes[ j ] ] = j;
      position = j;
    }
  }

public:
  IndexMaxHeap( int capacity ) {
      data = new Item[ capacity + 1 ];
      indexes = new int[ capacity + 1 ];
      reverse = new int[ capacity + 1 ];

      for ( int i = 0; i <= capacity; i++ )
        reverse[i] = 0;

      this->capacity = capacity;
      length = 0;
    }

  ~IndexMaxHeap() {
    delete [] data;
    delete [] indexes;
    delete [] reverse;
  }

  int size() {
    return length;
  }

  bool isEmpty() {
    return length == 0;
  }

  void insert( int i, Item item ) {
    assert( count + 1 <= length );
    assert( i + 1 >= 1 && i + 1 <= capacity );

    i += 1;
    data[ i ] = item;
    indexes[ length + 1 ] = i;
    reverse[ i ] = length + 1;
  
    length ++;
    shiftUp( length )
  }

  Item extractMax() {
    assert( count > 0 );

    Item ret = data[ indexes[ 1 ] ];
    swap( indexes[ 1 ], indexes[ length ] );
    reverse[ indexes[ 1 ] ] = 1;
    reverse[ indexes[ count ] ] = 0;

    count --;
    shiftDown( 1 );

    return ret;
  }

  int extractMaxIndex() {
    assert( count > 0 );

    int ret = indexes[ 1 ] - 1;

    swap( indexes[1], indexes[length] );
    reverse[ indexes[ 1 ] ] = 1;
    reverse[ indexes[ count ] ] = 0;
    count --;
    shiftDown( 1 );

    return ret;
  }

  bool contain( int i ) {
    assert( i + 1 >= 1 && i + 1 <= capacity );
    return reverse[ i + 1 ] != 0; 
  }

  Item getItem( int position ) {
    assert( contain( position ) );
    return data[ position + 1 ];
  }

  void change( int i, Item newItem ) {
    assert( contain( i ) );

    i + =1;
    data[ i ] = newItem;

    // for ( int j = 1;  j <= length; j++ ) {
    //   if ( indexes[ j ] == i ) {
    //     shiftUp( j );
    //     shiftDown( j );
    //     return;
    //   }
    // }

    int j = reverse[ i ];
    shiftUp( j );
    shiftDown( j );
  }
}
