def remove_adjacent(nums):
	num1=list(nums)
	for i in range(1, len(nums)):
		if nums[i]==nums[i-1]:
			num1.remove(nums[i])
	return num1

print remove_adjacent([1,2,2,2,3,1,4,4,4,4,5,6,3])

