#include <algorithm>
#include <cassert>

using namespace std;

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

  public:
    MaxHeap( int capacity ) {
      data = new Item[ capacity + 1 ];
      this->capacity = capacity;
      length = 0;
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
};
