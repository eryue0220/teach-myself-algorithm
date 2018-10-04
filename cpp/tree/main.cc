#include <iostream>
#include <string>
#include <vector>
#include "binarySearchTree.cc"
#include "../tools/FileReader.h"

using namespace std;
using namespace FileReader;

int main( void ) {
  string filename = "communist.txt";
  vector<string> words;

  if ( readFile( filename, words ) ) {
    time_t startTime = clock();
    BST<string, int> * bst = new BST<string, int>();

    for ( vector<string>::iterator iter = words.begin(); iter != words.end(); ++iter ) {
        int * res = bst->search( *iter );
        if ( res == NULL ) bst->insert( *iter, 1 );
        else (*res)++;
    }

    if ( bst->contain( "unite" ) ) {
      cout << "'unite' : " << *(bst->search( "unite" )) << endl;
    } else {
      cout << "No word 'unite' in " << filename << endl;
    }

    time_t endTime = clock();
    cout << "BST, time " << double( endTime - startTime ) / CLOCKS_PER_SEC << endl;

    startTime = clock();
    BST<string, int> * bst2 = new BST<string, int>();
    sort( words.begin(), words.end() );

    for ( vector<string>::iterator iter = words.begin(); iter != words.end(); ++iter ) {
      int * res = bst2->search( *iter );
      if ( res == NULL ) bst2->insert( *iter, 1 );
      else (*res)++;
    }

    if ( bst2->contain( "unite" ) ) {
      cout << "'unite' : " << *(bst2->search( "unite" )) << endl;
    } else {
      cout << "No word 'unite' in " << filename << endl;
    }

    endTime = clock();
    cout << "BST2, time " << double( endTime - startTime ) / CLOCKS_PER_SEC << endl;

    delete bst;
    delete bst2;
  }

  return 0;
}
