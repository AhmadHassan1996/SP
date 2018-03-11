if [ $# = 2 ]
then
	var1=`ls -l $1`
	arr=($var1)

	echo "OWNER:"${arr[2]}
	echo "GROUP:"${arr[3]}
	echo "PERMISSIONS:"${arr[0]}
	echo "FILENAME:"$1

	if [ ${arr[2]} = $2 ]
	then
		echo "CHEATING:0"
	else
		echo "CHEATING:1"		
	fi
else
	file1=`ls -l $1`
	file2=`ls -l $3`

	arr1=($file1)
	arr2=($file2)

	echo "OWNER:"${arr1[2]}
	echo "GROUP:"${arr1[3]}
	echo "PERMISSIONS:"${arr1[0]}
	echo "FILENAME:"$1

	if [ $2 = $4 ]
	then
		echo "CHEATING:1"
	else
		diff $1 $3

		if [ $? = 0 ]
		then
			echo "CHEATING:1"
		else
			echo "CHEATING:0"
		fi
	fi
	
	echo "OWNER:"${arr2[2]}
	echo "GROUP:"${arr2[3]}
	echo "PERMISSIONS:"${arr2[0]}
	echo "FILENAME:"$3

	if [ $2 = $4 ]
	then
		echo "CHEATING:1"
	else
		diff $1 $3

		if [ $? = 0 ]
		then
			echo "CHEATING:1"
		else
			echo "CHEATING:0"
		fi
	fi

fi
