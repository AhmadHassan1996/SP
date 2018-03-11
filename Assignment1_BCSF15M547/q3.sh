is_lower()
{
	echo "$1" | tr "[:upper:]" "[:lower:]"
}
is_root()
{
	user=`whoami`

	if [ $user = "root" ]
	then
		echo "is_root: true"
	else
		echo "is_root: false"
	fi
}
is_user_exists()
{
	flag=false
	IFS=$'\n'
	content=(`cat /etc/passwd`)
	IFS=$':'
	content=(${content[*]})

	for i in ${content[*]}
	do
		if [ "$1" = "$i" ]
		then
			echo "is_user_exists: true"
			flag=true
		fi
	done

	if [ $flag = false ]
	then
		echo "is_user_exists: false"
	fi
}

if [ $# = 1 ]
then
	is_lower $1
	is_root
	is_user_exists $1
else
	is_root
fi
