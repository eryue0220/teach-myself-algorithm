#include <algorithm>
#include <cassert>

template<typename Item>
class MaxHeap {
  private:
    Item * data;
    int length;
    int capacity;

    void shiftUp( int position ) {
      while ( position > 1 && data[ position /  2] < data[ position ] ) {
        swap( data[ position / 2 ], data[ position ]);
        position /= 2;
      }
    }

    void shiftDown( int position ) {
      while ( 2 * position <= length ) {
        int j = 2 * position;
        if ( j + 1 <= length && data[ j + 1 ] > data[ j ]) j += 1;
        if ( data[ position ] >= data[ j ] ) break;

        swap( data[ position ], data[ j ] );
        position = j;
      }
    }

  public:
    // 将 N 个元素逐个插入到一个空堆的过程，运行时间是 O(nlogn)
    MaxHeap( int capacity ) {
      data = new Item[ capacity + 1 ];
      this->capacity = capacity;
      length = 0;
    }

    // heapify 的过程的运行时间是 O(n)
    MaxHeap( Item arr[], int n ) {
      data = new Item[ n + 1 ];
      capacity = length = n;

      for ( int i = 0; i < n; i++ )
        data[ i + 1 ] = arr[i];

      for ( int i = length / 2; i >= 1; i-- )
        shiftDown(1);
    }

    ~MaxHeap() {
      delete [] data;
    }

    int size() {
      return length;
    }

    bool isEmpty() {
      return length == 0;
    }

    void insert( Item item ) {
      assert( length + 1 <= capacity );
      data[ length += 1 ] = item;
      shiftUp( length );
    }

    Item extractMax() {
      assert( length  > 0 );
      Item ret = data[1];
      swap( data[ 1 ], data[ length ] );
      length--;
      shiftDown(1);

      return ret;
    }
};
