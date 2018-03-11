showTable()
{
	var1=$1
	var2=$2
	var3=$3
	var4=$4

	if [ $var4 -eq 6 ]
	then
		while [ $var2 -ge $var3 ]
		do
			echo "$var1"x"$var2=`expr $var1 \* $var2`"
			var2=`expr $var2 - 1`
		done
	else
		while [ $var2 -le $var3 ]
		do
			echo "$var1"x"$var2=`expr $var1 \* $var2`"
			var2=`expr $var2 + 1`
		done
	fi


}
if [ $# = 0 -o $# -gt 6 ]
then
	echo "You must provide proper arguments."
elif [ $# = 1 ]
then
	showTable $1 1 10 $#
elif [ $# = 3 ]
then
	if [ $2 = "-s" ]
	then
		showTable $1 $3 10 $#
	elif [ $2 = "-e" ]
	then	
		showTable $1 1 $3 $#
	fi
elif [ $# = 5 ]
then
	if [ $5 -lt $3 ]
	then
		echo "You must provide proper arguments."
	else
		showTable $1 $3 $5 $#
	fi
elif [ $# = 6 ]
then
	if [ $5 -lt $3 ]
	then
		echo "You must provide proper arguments."
	else
		showTable $1 $5 $3 $#
	fi
fi
