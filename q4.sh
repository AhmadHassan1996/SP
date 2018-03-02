var1=`cat file1`
arr=($var1)
echo ${arr[*]}
echo ${#arr[*]}
echo ${#arr[3]}

