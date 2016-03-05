#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <sys/time.h>

uint64_t time_usec( struct timeval* time ){
  return time->tv_sec * 1000000 + time->tv_usec;
}

int main( int argc, char* argv[] ){
  int sec = 1;
  if ( 1 < argc ){
    sec = atoi( argv[ 1 ] );
    if ( sec <= 0 ){
      sec = 1;
    }
  }
  
  uint64_t usec = sec * 1000000;
  uint64_t count = 0;
  struct timeval start_tv;
  gettimeofday( &start_tv, NULL );
  uint64_t start_usec = time_usec( &start_tv );
  while ( true ){
    count += 1;
    struct timeval end_tv;
    gettimeofday( &end_tv, NULL );
    uint64_t end_usec = time_usec( &end_tv );
    uint64_t update_usec = end_usec - start_usec;
    if ( usec <= update_usec ){
      printf( "count=%"PRIu64" update_usec=%"PRIu64"\n", count, update_usec );
      break;
    }
  }
  return 0;
}
