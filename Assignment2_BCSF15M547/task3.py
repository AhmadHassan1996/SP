matrix_8=[[1,2,3,4,5,6,7,8],[9,10,11,12,13,14,15,16],[17,18,19,20,21,22,23,24],
[25,26,27,28,29,30,31,32],[33,34,35,36,37,38,39,40],[41,42,43,44,45,46,47,48],
[49,50,51,52,53,54,55,56],[57,58,59,60,61,62,63,64]]

matrix_2=[]
list1=[]
temp=0
print "Enter numbers for a 2x2 matrix"

for i in range(0,2):
	for j in range(0,2):
		try:
			temp=input("Enter number at "+str(i)+","+str(j)+" : ")
			list1.append(temp)
		except (NameError, SyntaxError):
			print "Invalid input! Exiting..."
			exit(0)
	matrix_2.append(list(list1))
	list1.pop()
	list1.pop()

for i in range(0,7):
	for j in range(0,7):
		if matrix_2[0][0]==matrix_8[i][j] and matrix_2[0][1]==matrix_8[i][j+1] and matrix_2[1][0]==matrix_8[i+1][j] and matrix_2[1][1]==matrix_8[i+1][j+1]:
			print "Matrix found starting from index : ",i,",",j
			exit(0)

print "No such matrix found"

