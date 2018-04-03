n=100
i=-40
echo "finding"
f=$(echo "scale=2;((9/5) * $i) + 32" |bc)
echo "found $f"

