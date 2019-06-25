!/bin/sh

while test 1 -eq 1; do
echo "MENU \n1) Add \n2) Subtract \n3) Divide \n4) Multiply \n5) Exit" 
echo "\nEnter your choice - \c"
read choice

case "$choice" in
1) echo "ADD";;
2) echo "SUB";;
3) echo "MUL";;
4) echo "DIV";;
5) exit;;
*) echo "Invalid option";;
esac

done

