UNIX=("Debian" "Red hat" "Ubuntu" "Suse" "Fedora")

echo ${UNIX[*]}
echo ${#UNIX[*]}
echo ${#UNIX[2]}
echo ${UNIX[*]:3:2}

UNIX=(${UNIX[*]/"Ubuntu"/"SCO Unix"})
echo ${UNIX[*]}

UNIX=(${UNIX[*]} "AIX" "HP-UX")
echo ${UNIX[*]}

unset UNIX[2]
echo ${UNIX[*]}

LINUX=(${UNIX[*]})
echo ${LINUX[*]}
BASH=(${LINUX[*]} ${UNIX[*]})
echo ${BASH[*]}

unset LINUX[*]
unset UNIX[*]

