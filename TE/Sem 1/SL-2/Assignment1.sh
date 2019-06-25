#!/bin/sh

while test 1 -eq 1; do
echo "\n=================================="
echo "             MENU "
echo "=================================="
echo " 1) Create Address Book \n 2) View Address Book \n 3) Insert a Record \n 4) Delete a Record \n 5) Modify a Record \n 6) Exit" 
echo "=================================="
echo "\nEnter your choice - \c"
read choice

case "$choice" in
1) 
	echo "\n Creating the address book"
	echo "\n Enter name of the new file or existing file - \c"
	read filename
	touch $filename
	echo "\n File with name $filename was created successfully"
;;
2) 
	echo "\nThe Address book is shown below"
	echo "\nName\tAddress\tPhone Number" 
	cat $filename	
;;
3) 
	echo "\nInserting a new Record"
	echo "\n Enter the Name - \c"
	read name
	echo "\n Enter the Address - \c"
	read address
	echo "\n Enter the Phone Number - \c"
	read phone
	echo "$name\t$address\t$phone" >> $filename
	echo "\n Record inserted successfully"
;;
4) 
	echo "\n Deleting a Record"
	echo "\n Enter the Phone Number - \c"
	read sphone
	grep -v -i "$sphone" $filename > temp
	mv temp $filename
;;
5) 
	echo "\nModify a Record"
	echo "\n Enter the phone number "
;;
6) exit
;;
*) echo "\nInvalid option"
;;
esac

done

