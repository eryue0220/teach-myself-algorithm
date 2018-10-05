#ifndef QUICK_UNION_OPTIMIZE_PATH_H__
#define QUICK_UNION_OPTIMIZE_PATH_H__

#include <cassert>

namespace QUOPTPATH {
  class QuickUnionByPath {
  private:
    int length;
    int * parent;
    // rank[i] 表示以 i 为根的集合所表示的树的层数
    int * rank;

  public:
    QuickUnionByPath( int length ) {
      parent = new int[length];
      rank = new int[length];
      this->length = length;

      for ( int i = 0; i < length; i++ ) {
        parent[i] = i;
        rank[i] = 1;
      }
    }

    ~QuickUnionByPath() {
      delete [] parent;
      delete [] rank;
    }

    int find( int p ) {
      assert( p >= 0 && p <= length );

      // if ( p != parent[ p ] ) parent[ p ] = find( parent[ p ] );
      // return parent[p];
      while ( p != parent[p] ) {
        parent[p] = parent[parent[p]];
        p = parent[p];
      }
      
      return p;
    }

    bool isConnected( int p, int q ) {
      return find( p ) == find( q );
    }

    void unionElement( int p, int q ) {
      int pRoot = find( p );
      int qRoot = find( q );

      if ( pRoot == qRoot ) return;

      if ( rank[ pRoot ] < rank[ qRoot ] ) {
        parent[ pRoot ] = qRoot;
      } else if ( rank[ qRoot ] < rank[ pRoot ] ){
        parent[ qRoot ] = pRoot;
      } else {
        parent[ pRoot ] = qRoot;
        rank[ qRoot ] += 1;
      }
    }
  };
}

#endif // QUICK_UNION_OPTIMIZE_PATH_H__
