#!bin/sh
# Author: NULL_703
# Created time: 2021.10.10 18:12
# Last change time: 2021.12.22 19:43

echo "Please input Mode(1:build 2:clean):"
read opt
if [ "$opt" == "1" ]; then
    make
elif [ "$opt" == "2" ]; then
    make clean
else
    echo "Error: No this option!"
fi