mylist=[1,2,[3,4],"hello",'world',3.4,5,(0,1),{1},{"key1":1}]
dict1={}
list1=[]

for i in mylist:
	list1=dict1.get(type(i),[])
	list1.append(i)
	dict1[type(i)]=list1

print "Original list : ", mylist

for i, j in dict1.items():
	print i,"->", j

