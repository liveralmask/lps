def time_usec( time )
  time.to_i * 1000000 + time.usec
end

sec = ARGV[ 0 ].to_i
sec = 1 if sec <= 0
usec = sec * 1000000

count = 0
start_usec = time_usec( Time.new )
while true
  count += 1
  end_usec = time_usec( Time.new )
  update_usec = end_usec - start_usec
  if usec <= update_usec
    puts "count=#{count} update_usec=#{update_usec}"
    break
  end
end
