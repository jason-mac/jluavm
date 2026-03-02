-- comment
-- [[
-- multi line comment
-- ]]
--
local Vector = function(dimension)
	local vector = {
		dimension = dimension,
	}
	return vector
end

local _ = Vector(3)

local counter = function(start)
	return function()
		local to_return = start
		start = start + 1
		return to_return
	end
end

function My_func(a, b)
	return a + b
end

local t = {
	[My_func] = 69,
}

print(t[My_func])

local my_count = counter(4)

print(my_count())
print(my_count())
print(my_count())

Person = {
	name = "john",
	age = 5,
}
