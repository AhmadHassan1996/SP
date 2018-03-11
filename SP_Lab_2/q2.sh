pid=`pidof $1`
arr=($pid)
IFS=$'\n'

for i in ${arr[*]}
do
	content=`cat /proc/$i/status`
	array=($content)
	echo ${array[5]}
	echo ${array[0]}
	echo ${array[6]}
	echo "STATE: running"
	echo " "
done
