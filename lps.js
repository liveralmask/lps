require ( "date-utils" );

function time_usec( time ){
  return time * 1000;
}

var sec = 1;
if ( 3 <= process.argv.length ){
  sec = parseInt( process.argv[ 2 ] );
}
var usec = sec * 1000000;

var count = 0;
var start_usec = time_usec( Date.now() );
while ( true ){
  count += 1;
  var end_usec = time_usec( Date.now() );
  var update_usec = end_usec - start_usec;
  if ( usec <= update_usec ){
    console.log( "count="+ count +" update_usec="+ update_usec );
    break;
  }
}
