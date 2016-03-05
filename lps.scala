import scala.util.control.Breaks.{ breakable, break }

object lps {
  def time_usec( time: Long ): Long = {
    time * 1000
  }
  
  def main( args: Array[ String ] ){
    var argc = args.size
    var sec = 1
    if ( 1 <= argc ){
      sec = Integer.parseInt( args( 0 ) )
    }
    var usec = sec * 1000000
    
    var count = 0
    var start_usec = time_usec( System.currentTimeMillis() )
    breakable {
      while ( true ){
        count += 1
        var end_usec = time_usec( System.currentTimeMillis() )
        var update_usec = end_usec - start_usec
        if ( usec <= update_usec ){
          printf( "count=%d update_usec=%d\n", count, update_usec )
          break
        }
      }
    }
  }
}
