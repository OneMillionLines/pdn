echo "enter 10 nos"
i=0
t=0
while [ $i -lt 10 ]
do
	read a
	t=$((t+a))
	i=$((i+1))
done
echo "value=$t"
