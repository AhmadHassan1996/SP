if [ $# = 0 ]
then
	echo "You must provide proper arguments."
	exit 0
fi

IFS=$'\n'
content=(`cat ~/$1`)
rm ~/$1
touch ~/$1
count=0
temp=`expr $count - 1`
flag=false

for i in ${content[*]}
do
	for j in `seq 0 $temp`
	do
		if [ $i = ${content[j]} ]
		then
			flag=true
			break
		fi
	done
	
	if [ $flag = false ]
	then
		echo "$i" 1>>~/$1
	fi

	temp=$count
	count=`expr $count + 1`
	flag=false
done
