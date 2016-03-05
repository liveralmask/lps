using System;

class Lps {
  static DateTime m_unix_epoch_base_time = new DateTime( 1970, 1, 1 );
  
  public static UInt64 TimeUSec( DateTime utc_time ){
    return (UInt64)( ( utc_time - m_unix_epoch_base_time ).TotalSeconds * 1000000 );
  }
  
  public static void Main( string[] args ){
    Int32 sec = 1;
    if ( 0 < args.Length ){
      sec = Convert.ToInt32( args[ 0 ] );
    }
    if ( sec <= 0 ){
      sec = 1;
    }
    
    UInt64 usec = (UInt64)sec * 1000000;
    UInt64 count = 0;
    UInt64 start_usec = TimeUSec( DateTime.UtcNow );
    while ( true ){
      count += 1;
      UInt64 end_usec = TimeUSec( DateTime.UtcNow );
      UInt64 update_usec = end_usec - start_usec;
      if ( usec <= update_usec ){
        Console.WriteLine( String.Format( "count={0} update_usec={1}", count, update_usec ) );
        break;
      }
    }
  }
}
