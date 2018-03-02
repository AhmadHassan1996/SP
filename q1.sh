if [ $# = 0 ]
then
	echo "First number : "
	read var1
	echo "Second number : "
	read var2
else
	var1=$1
	var2=$2
fi

echo "Addition : "
echo `expr $var1 + $var2`
echo "Subtraction : "
echo `expr $var1 - $var2`
echo "Multiplication : "
echo `expr $var1 \* $var2`

if [ $var2 -eq 0 ]
then
	echo "Division with 0 is not possible."
else
	echo "Division : "
	echo `expr $var1 / $var2`
	echo "Mod : "
	echo `expr $var1 % $var2`
fi
