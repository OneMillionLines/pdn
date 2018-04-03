i=3
s=0
while [ $i -lt 61 ]
do
		echo $i
		s=$((s+i))
		i=$((i+3))
done
echo "value=$s"
