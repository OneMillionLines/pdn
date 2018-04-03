echo "enter the no"
read num
i=2
f=0
r=$((num/2))
while [ $i -le $r ]
do
	rem=$((num%i))
		if [ $rem -eq 0 ]
		then
			f=1
		fi
	i=$((i+1))
	done
if [ $f -eq 1 ]
then 	
	echo "not prime"
else
	echo "prime"
fi
