#include "../tools/UFTestHelper.h"

int main( void ) {
  int n = 10000000;
  // UFTestHelper::testQuickFind( n );
  // UFTestHelper::testQuickUnion( n );
  UFTestHelper::testQuickUnionOPTSize( n );
  UFTestHelper::testQuickUnionOPTRank( n );
  UFTestHelper::testQuickUnionOPTPath( n );

  return 0;
}
