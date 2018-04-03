i=-100
num=100
num=$(echo "scale=2; (($i/1.0))"|bc)
i=$(echo "scale=2; ((i/1.0))"|bc)
while [ $(echo "$i<$num"|bc) -eq 1]
do
ct=$(echo "scale=2;((9/5*$i)+32)"|bc
i=$(echo "scale=2;(($i/1.0))"|bc
if [ $(echo "$ct==$i"|bc) -eq 1 ]
ten
echo $i
fi
i=$(echo "scale=2;(($i+1))" |bc)
done
