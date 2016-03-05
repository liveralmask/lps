task :default => [ :build ]

desc "Build"
task :build do |t, args|
  sh "gcc -Wall lps.c -o lps_c"
  sh "go build -o lps_go lps.go"
  sh "mcs -out:lps_cs lps.cs"
  sh "scalac -d obj lps.scala"
end

desc "Clean"
task :clean do |t, args|
  sh "rm -f lps_c lps_go lps_cs obj/lps*"
end

desc "Version"
task :version do |t, args|
  sh "gcc -dumpversion"
  sh "go version"
  sh "scala -version"
  sh "node -v"
  sh "mono -V|grep version"
  sh "php -v|grep built"
  sh "ruby -v"
end

desc "Run"
task :run do |t, args|
  sh "npm install date-utils" if ! Dir.exist?( "node_modules/date-utils" )
  
  sh "./lps_go"
  sh "./lps_c"
  sh "scala lps.scala"
  sh "node lps.js"
  sh "mono lps_cs"
  sh "php lps.php"
  sh "ruby lps.rb"
end
