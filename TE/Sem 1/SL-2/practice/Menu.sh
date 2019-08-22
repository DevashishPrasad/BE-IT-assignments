#!/bin/sh

while test 1 -eq 1; do
echo "MENU \n1) Add \n2) Subtract \n3) Multiply \n4) Divide \n5) Exit" 
echo "\nEnter your choice - \c"
read choice

case "$choice" in
1) 
	echo "-------- ADDITION --------- "
	echo "Enter number 1 -  \c"
	read no1
	echo "Enter number 2 -  \c"
	read no2
	res=`expr $no1 + $no2`
	echo "Result of addition is - $res"
;;
2)
	echo "-------- SUBTRACTION --------- "
	echo "Enter number 1 -  \c"
	read no1
	echo "Enter number 2 -  \c"
	read no2
	res=$(($no1-$no2))
	echo "Result of SUBTRACTION is - $res" 
;;
3)
	echo "-------- MULTIPLICATION --------- "
	echo "Enter number 1 -  \c"
	read no1
	echo "Enter number 2 -  \c"
	read no2
	res=$(($no1*$no2))
	echo "Result of multiplication is - $res" 
;;
4) 
	echo "-------- DIVISION --------- "
	echo "Enter number 1 -  \c"
	read no1
	echo "Enter number 2 -  \c"
	read no2
	res=$(($no1/$no2))
	echo "Result of DIVISION is - $res"
;;
5) exit;;
*) echo "Invalid option";;
esac

done

