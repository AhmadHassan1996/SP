num=raw_input("Enter a number : ")
for i in num:
	if i<'0' or i>'9':
		print "Wrong input"
		exit()
d={}
for i in range(1, int(num)+1):
	d[i]=i*i
print d

