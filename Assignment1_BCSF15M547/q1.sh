files=(`ls ~`)
temp=0

for i in ${files[*]}
do
	if [ -f ~/$i ]
	then
		temp=`expr ${#i} - 1`

		while [ $temp -ge 0 ]
		do
			k=${i:$temp:1}

			if [ $k = '.' ]
			then
				break
			fi

			str="$str$k"
			temp=`expr $temp - 1`
		done

		str=`echo "$str" | rev`
		str=`echo "$str" | tr "[:lower:]" "[:upper:]"`
		mkdir ~/$str
		mv ~/$i ~/$str/$i
		str=""
	fi
done
