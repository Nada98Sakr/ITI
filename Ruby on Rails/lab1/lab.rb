#__________________________________________________________________
#___________________________ Question 1 ___________________________
def create_copies(string, n)
    n.times do |i|
        puts string * (i + 1)
    end
end

string = "a"
n = 6
create_copies(string, n)

#__________________________________________________________________
#___________________________ Question 2 ___________________________
def starts_with_if?(string)
    string.start_with?("if")
end

string = "if condition"
result = starts_with_if?(string)
puts result

#__________________________________________________________________
#___________________________ Question 3 ___________________________
def exchange_first_last(string)
    if string.length >= 2
        string[0], string[-1] = string[-1], string[0]
    end
    string
end
string1 = "Python"
result1 = exchange_first_last(string1)
puts result1

#__________________________________________________________________
#___________________________ Question 4 ___________________________
def add_last_character(string)
    if string.length >= 1
        last_character = string[-1]
        new_string = last_character + string + last_character
        new_string
    end
end
string1 = "abc"
result1 = add_last_character(string1)
puts result1

#__________________________________________________________________
#___________________________ Question 4 ___________________________
def leap _year?(year)
    (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0)
end

year = 2012
if leap_year?(year)
    puts "#{year} is a leap year"
else
    puts "#{year} is not a leap year"
end
#__________________________________________________________________
#___________________________ Question 5 ___________________________
def rota te_left(arr)
    rotated_arr = arr[1..-1] + [arr[0]]
end
arrays = [[1, 2, 5], [1, 2, 3], [1, 2, 4]]

arrays.each do |arr|
result = rotate_left(arr)
puts result.inspect
end

#__________________________________________________________________
#___________________________ Question 6 ___________________________
def compute_sum(array)
    result = []
    skip_next = false
    array.each_with_index do |num, index|
    if skip_next
    skip_next = false
    next
    end

    if num == 17 && index < array.length - 1
    skip_next = true
    next
    end

    result << num
end

result
end
arrays = [[3, 5, 17, 6], [3, 5, 1, 17], [3, 17, 1, 7]]

arrays.each do |array|
result = compute_sum(array)
puts result.inspect
end