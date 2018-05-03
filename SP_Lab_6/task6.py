string=raw_input("Enter some words : ")
list1=[]
set1={1,2,3}
list1=string.split(' ')
set1=set(list1)
list1=list(set1)
list1.sort()
for i in list1:
	print i," ",

