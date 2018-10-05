#ifndef QUICK_UNION_OPTIMIZE_RANK_H__
#define QUICK_UNION_OPTIMIZE_RANK_H__

#include <cassert>

namespace QUOPTRANK {
  class QuickUnionByRank {
  private:
    int length;
    int * parent;
    // rank[i] 表示以 i 为根的集合所表示的树的层数
    int * rank;

  public:
    QuickUnionByRank( int length ) {
      parent = new int[length];
      rank = new int[length];
      this->length = length;

      for ( int i = 0; i < length; i++ ) {
        parent[i] = i;
        rank[i] = 1;
      }
    }

    ~QuickUnionByRank() {
      delete [] parent;
      delete [] rank;
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

#endif // QUICK_UNION_OPTIMIZE_RANK_H__
