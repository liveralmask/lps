<?php
function time_usec( $time ){
  return $time * 1000000;
}

$sec = isset( $argv[ 1 ] ) ? intval( $argv[ 1 ] ) : 1;
if ( $sec <= 0 ){
  $sec = 1;
}
$usec = $sec * 1000000;

$count = 0;
$start_usec = time_usec( microtime( true ) );
while ( true ){
  $count += 1;
  $end_usec = time_usec( microtime( true ) );
  $update_usec = $end_usec - $start_usec;
  if ( $usec <= $update_usec ){
    printf( "count=%u update_usec=%u\n", $count, $update_usec );
    break;
  }
}
