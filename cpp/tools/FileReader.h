#ifndef FILE_READER_H
#define FILE_READER_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace FileReader {
  int firstCharacterIndex( const string & s, int start ) {
    for ( int i = start; i < s.length(); i++ ) {
      if ( isalpha( s[ i ] ) ) return i;
    }

    return s.length();
  }

  string lowerString( const string & s ) {
    string ret = "";

    for ( int i = 0; i < s.length(); i++ ) {
      ret += tolower( s[ i ] );
    }

    return ret;
  }

  bool readFile( const string & filename, vector<string> & words ) {
    string line;
    string contents = "";
    ifstream file ( filename );

    if ( file.is_open() ) {
      while ( getline( file, line ) ) contents += ( line + "\n" );
      file.close();
    } else {
      cout << "Can't open " << filename << " !" << endl;
      return false;
    }

    int start = firstCharacterIndex( contents, 0 );

    for ( int i = start + 1; i <= contents.length(); ) {
      if ( i == contents.length() || !isalpha( contents[i] ) ) {
        words.push_back( lowerString( contents.substr( start, i - start ) ) );
        start = firstCharacterIndex( contents, i );
        i = start + 1;
      } else {
        i++;
      }
    }

    return true;
  }
}

#endif // FILE_READER_H
