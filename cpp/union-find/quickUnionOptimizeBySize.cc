#ifndef QUICK_UNION_OPTIMIZE_SIZE_H__
#define QUICK_UNION_OPTIMIZE_SIZE_H__

#include <cassert>

namespace QUOPTSIZE {
  class QuickUnionBySize {
  private:
    int length;
    int * parent;
    // size[i] 表示以 i 为根的集合中元素的个数
    int * size;

  public:
    QuickUnionBySize( int length ) {
      parent = new int[length];
      size = new int[length];
      this->length = length;

      for ( int i = 0; i < length; i++ ) {
        parent[i] = i;
        size[i] = 1;
      }
    }

    ~QuickUnionBySize() {
      delete [] parent;
      delete [] size;
    }

    int find( int p ) {
      assert( p >= 0 && p <= length );

      while ( p != parent[p] ) p = parent[p];
      
      return p;
    }

    bool isConnected( int p, int q ) {
      return find( p ) == find( q );
    }

    void unionElement( int p, int q ) {
      int pRoot = find( p );
      int qRoot = find( q );

      if ( pRoot == qRoot ) return;

      if ( size[ pRoot ] < size[ qRoot ] ) {
        parent[ pRoot ] = qRoot;
        size[ qRoot ] += size[ pRoot ];
      } else {
        parent[ qRoot ] = pRoot;
        size[ pRoot ] += size[ qRoot ];
      }
    }
  };
}

#endif // QUICK_UNION_OPTIMIZE_SIZE_H__
