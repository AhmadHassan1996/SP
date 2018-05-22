def match_ends(words):
	count=0
	for i in words:
		if len(i)>=2 and i[0]==i[-1]:
			count+=1
	return count

print "Count : ", match_ends(["1", "hello", "madam"])

