IFS=$'\n'

if [ $# = 0 -o $# -gt 1 ]
then
	echo "You must provide proper arguments."
else
	arr=(`ls -l ~`)

	for i in ${arr[*]}
	do
		IFS=$' '
		array=($i)

		if [ -f ~/${array[8]} ]
		then
			if [ "${array[2]}" = "$1" ]
			then
				echo "${array[8]} | ${array[2]}"
			fi
		fi
		IFS=$'\n'
	done
fi

