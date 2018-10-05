#ifndef QUICK_FIND_H__
#define QUICK_FIND_H__

#include <cassert>

using namespace std;

namespace QF {
  class QuickFind {

  private:
    int * id;
    int length;

  public:
    QuickFind( int n ) {
      length = n;
      id = new int[n];

      for ( int i = 0; i < n; ++i )
        id[i] = i;
    }

    ~QuickFind() {
      delete [] id;
    }

    int find( int position ) {
      assert( position >= 0 && position <= length );
      return id[ position ];
    }

    bool isConnected( int p, int q ) {
      return find( p ) == find( q );
    }

    void unionElement( int p, int q ) {
      int pId = find( p );
      int qId = find( q );

      if ( qId == pId ) return;

      for ( int i = 0; i < length; i++ )
        if ( id[ i ] == pId )
          id[ i ] = qId; 
    }
  };
}

#endif // QUICK_FIND_H__
