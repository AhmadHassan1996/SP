def fix_me(string,ch):
	if len(string)<2:
		return string
	index=string.find(ch)

	if index==-1:
		return string

	temp=string[index+1:]
	temp=temp.replace(str(ch), "*")
	return string[:index+1]+temp

string=raw_input("Enter a string : ")
ch=raw_input("Enter a character : ")
if len(ch)!=1:
	print "Wrong input"
	exit()
print "String : ", fix_me(string, ch)

