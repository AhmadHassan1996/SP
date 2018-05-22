def both_ends(string):
	if len(string)<2:
		return ""
	return string[:2]+string[-2:]

string=raw_input("Enter a string : ")
print "String : ", both_ends(string)

