#ifndef UF_TEST_HELPER_H__
#define UF_TEST_HELPER_H__

#include <ctime>
#include <iostream>
#include "../union-find/quickFind.cc"
#include "../union-find/quickUnion.cc"
#include "../union-find/quickUnionOptimizeBySize.cc"
#include "../union-find/quickUnionOptimizeByRank.cc"
#include "../union-find/quickUnionOptimizeByPath.cc"

using namespace std;

namespace UFTestHelper {
  void testQuickFind( int n ) {
    srand( time( NULL ) );
    QF::QuickFind qf = QF::QuickFind( n );
    time_t startTime = clock();

    for ( int i = 0; i < n; i++ ) {
      int a = rand() % n;
      int b = rand() % n;
      qf.unionElement( a, b );
    }

    for ( int i = 0; i < n; i++ ) {
      int a = rand() % n;
      int b = rand() % n;
      qf.isConnected( a, b );
    }

    time_t endTime = clock();
    cout << "QuickFind: " << 2 * n << " ops, " << double( endTime - startTime ) / CLOCKS_PER_SEC << "s" << endl;
  }

  void testQuickUnion( int n ) {
    srand( time( NULL ) );
    QU::QuickUnion qu = QU::QuickUnion( n );
    time_t startTime = clock();

    for ( int i = 0; i < n; i++ ) {
      int a = rand() % n;
      int b = rand() % n;
      qu.unionElement( a, b );
    }

    for ( int i = 0; i < n; i++ ) {
      int a = rand() % n;
      int b = rand() % n;
      qu.isConnected( a, b );
    }

    time_t endTime = clock();
    cout << "QuickUnion: " << 2 * n << " ops, " << double( endTime - startTime ) / CLOCKS_PER_SEC << "s" << endl;
  }

  void testQuickUnionOPTSize( int n ) {
    srand( time( NULL ) );
    QUOPTSIZE::QuickUnionBySize qu = QUOPTSIZE::QuickUnionBySize( n );
    time_t startTime = clock();

    for ( int i = 0; i < n; i++ ) {
      int a = rand() % n;
      int b = rand() % n;
      qu.unionElement( a, b );
    }

    for ( int i = 0; i < n; i++ ) {
      int a = rand() % n;
      int b = rand() % n;
      qu.isConnected( a, b );
    }

    time_t endTime = clock();
    cout << "QuickUnionBySize: " << 2 * n << " ops, " << double( endTime - startTime ) / CLOCKS_PER_SEC << "s" << endl;
  }

  void testQuickUnionOPTRank( int n ) {
    srand( time( NULL ) );
    QUOPTRANK::QuickUnionByRank qu = QUOPTRANK::QuickUnionByRank( n );
    time_t startTime = clock();

    for ( int i = 0; i < n; i++ ) {
      int a = rand() % n;
      int b = rand() % n;
      qu.unionElement( a, b );
    }

    for ( int i = 0; i < n; i++ ) {
      int a = rand() % n;
      int b = rand() % n;
      qu.isConnected( a, b );
    }

    time_t endTime = clock();
    cout << "QuickUnionByRank: " << 2 * n << " ops, " << double( endTime - startTime ) / CLOCKS_PER_SEC << "s" << endl;
  }

  void testQuickUnionOPTPath( int n ) {
    srand( time( NULL ) );
    QUOPTPATH::QuickUnionByPath qu = QUOPTPATH::QuickUnionByPath( n );
    time_t startTime = clock();

    for ( int i = 0; i < n; i++ ) {
      int a = rand() % n;
      int b = rand() % n;
      qu.unionElement( a, b );
    }

    for ( int i = 0; i < n; i++ ) {
      int a = rand() % n;
      int b = rand() % n;
      qu.isConnected( a, b );
    }

    time_t endTime = clock();
    cout << "QuickUnionByPath: " << 2 * n << " ops, " << double( endTime - startTime ) / CLOCKS_PER_SEC << "s" << endl;
  }
}

#endif // UF_TEST_HELPER_H__
