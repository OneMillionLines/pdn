echo "enter number"
read a
x=$((a%2))
if [ $x -eq 0 ]
then 
echo "even"
else
echo "odd"
fi
