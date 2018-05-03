string=raw_input("Enter a sentence : ")
digits=0;
alphabets=0;
for i in string:
	if i>='0' and i<='9':
		digits+=1
	if (i>='A' and i<='Z') or (i>='a' and i<='z'):
		alphabets+=1
print "Letters : ", alphabets, " | ", "Digits : ", digits

