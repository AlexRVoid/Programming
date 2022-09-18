print 'a='
a = gets.chomp.to_i
print 'b='
b = gets.chomp.to_i
print 'c='
c = gets.chomp.to_i
puts 'v=', a * b * c, 's=',  2 * (a * b + b * c + a * c)