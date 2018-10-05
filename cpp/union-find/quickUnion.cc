#ifndef QUICK_UNION_H__
#define QUICK_UNION_H__

#include <cassert>

namespace QU {
  class QuickUnion {
  private:
    int length;
    int * parent;

  public:
    QuickUnion( int length ) {
      parent = new int[length];
      this->length = length;

      for ( int i = 0; i < length; i++ )
        parent[i] = i;
    }

    ~QuickUnion() {
      delete [] parent;
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

      parent[ pRoot ] = qRoot;
    }
  };
}

#endif // QUICK_UNION_H__
