def fix_start(string):
	if len(string)<2:
		return string
	
	temp=string[1:]
	temp=temp.replace(str(string[0]), "*")
	return str(string[0])+temp

string=raw_input("Enter a string : ")
print "String : ", fix_start(string)

