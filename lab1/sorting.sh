n=10
echo "enter 10  nos"
for i in $(seq 1 $n)
do
read arr[$i]
done
for j in $(seq 2 $n)
do
key=${arr[$j]}
i=$((j-1))
while [ $i -gt 0 ] && [ ${arr[$i]} -gt $key ]
do
arr[$(expr $i + 1)]=${arr[$i]}
i=$(expr $i - 1)
done
arr[$(expr $i + 1)]=$key
done
echo "after sorting"
echo ${arr[@]}
