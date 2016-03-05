package main

import (
  "fmt"
  "time"
  "os"
  "strconv"
)

func time_usec( time time.Time )( uint64 ){
  return uint64( time.UnixNano() / 1000 )
}

func main(){
  argc := len( os.Args )
  sec := 1
  if 2 <= argc {
    sec, _ = strconv.Atoi( os.Args[ 1 ] )
  }
  usec := uint64( sec * 1000000 )
  
  count := uint64( 0 )
  start_usec := time_usec( time.Now() )
  for {
    count += 1
    end_usec := time_usec( time.Now() )
    update_usec := end_usec - start_usec
    if usec <= update_usec {
      fmt.Printf( "count=%d update_usec=%d\n", count, update_usec )
      break
    }
  }
}
