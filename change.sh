SAVEIFS=$IFS
IFS=$(echo -en "\n\b")
for l in `ls *.cpp`; do
    expand -t 4 $l > tmp
    mv tmp $l
done
IFS=$SAVEIFS
