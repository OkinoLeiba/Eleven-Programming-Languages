# puts "Hello World!"

def is_palindrome(s)
  i = 0
  r = s.downcase.gsub(/[[:punct:]]/, '').gsub('`', '').gsub(' ', '')
  j = r.length

  while i < j
    if r[i] != r[j] then 
      print false
    end
    i += 1
    j -= 1
  end
  print true

# return r == r.reverse
end

# is_palindrome("A man, a plan, a canal: Panama")

class Rubies
  # @param {Integer[]} nums
  # @param {Integer} k
  # @return {Float}
  def find_max_average(nums, k)
    @i = 0
    @m = nums[0]
    for @j in (k..nums.length)
      @sum = 0.0
      @sum = nums.slice(@i, k).sum
      @m = [@m, @sum].max
      print(@m / k.to_f)
      @i += 1
    end
    return @m / k.to_f
  end
end

rubies = Rubies.new
rubies.find_max_average([1,12,-5,-6,50,3], 4)