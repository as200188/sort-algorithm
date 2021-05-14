#include "sort_alg.h"
#include <stdio.h>
#include <string>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

struct Obj
{
  string name="";
  int value = 0;
};


int cmp( Obj a, Obj b) {
  if ( a.value < b.value ) {
    return -1;
  } // if
  else if ( a.value > b.value ) {
    return 1;
  } // else if
  
  return 0;
}

int main( char args[] ) {

  default_random_engine generator( time( NULL ) );
  uniform_real_distribution<float> unif( 0.0, 1.0 );

  vector<Obj> list;

  for ( int i = 0 ; i < 20 ; i++ ) {
    float x = unif( generator );
    int num = x * 100;

    Obj temp;
    temp.value = num;
    list.push_back( temp );
  } // for

  printf( "%s\n", "unsort:" );
  for ( int i = 0 ; i < 20 ; i++ ) {
    printf( "%d\n", list[ i ].value );
  } // for

  insertion_sort is;
  int (*cmp_ptr)( Obj, Obj ); // function pointer
  cmp_ptr = cmp; // assign function to pointer
  is.sort( list, 0, 19, cmp_ptr );


  printf( "%s\n", "sorted:" );
  for ( int i = 0 ; i < 20 ; i++ ) {
    printf( "%d\n", list[ i ].value );
  } // for



  system( "pause" );
  return 0;
}