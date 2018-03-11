if [ $# = 0 ]
then
	echo "You must provide proper arguments."
	exit 0
fi

temp=`ls ~ | grep "evenfile"`
if [ $? = 0 ]
then
	rm ~/evenfile
fi

temp=`ls ~ | grep "oddfile"`
if [ $? = 0 ]
then
	rm ~/oddfile
fi

IFS=$'\n'
content=(`cat ~/$1`)
count=1
touch ~/evenfile ~/oddfile

for i in ${content[*]}
do
	if [ `expr $count % 2` = 0 ]
	then
		echo "$i" 1>>~/evenfile
	else
		echo "$i" 1>>~/oddfile
	fi
	count=`expr $count + 1`
done
