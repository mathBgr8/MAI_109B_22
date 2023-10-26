#!/bin/sh
a=$(wc -c $1|cut -d " " -f1)
if (( $a * $2 < $3))
then
res=./${1%.*}repeated$2times.${1##*.}
touch $res
for(( k=0; k<$2; k++ ))
do
cat $1>>$res
done
fi
