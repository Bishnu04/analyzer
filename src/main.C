//////////////////////////////////////////////////////////////////////////
//
//  The Hall A analyzer interactive interface
//
//////////////////////////////////////////////////////////////////////////

#include "THaInterface.h"
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char **argv)
{
  // Create a ROOT-style interactive interface

  // Handle convenience command line options
  bool print_version = false, no_logo = false;
  for( int i=1; i<argc; ++i ) {
    if( !strcmp(argv[i],"-l") )
      no_logo = true;
    else if( !strcmp(argv[1],"-v") || !strcmp(argv[1],"--version") ) {
      print_version = true;
      break;
    }
  }

  if( print_version ) {
    cout << THaInterface::GetVersionString() << endl;
    return 0;
  }

  TApplication *theApp =
    new THaInterface( "The Hall A analyzer", &argc, argv, 0, 0, no_logo );
  theApp->Run(kFALSE);

  cout << endl;
  delete theApp;

  return 0;
}
