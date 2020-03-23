#!/bin/bash

for i in `ls -1 | grep .obj`
do
	echo $i | sed 's/\(.*\.\)obj/\1mapconf/' > name
	sh make_conf.sh $i $(cat name)
done
