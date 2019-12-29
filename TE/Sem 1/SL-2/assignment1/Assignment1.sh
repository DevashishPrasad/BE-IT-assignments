#!/bin/sh

# Run the while loop infinitly

echo "WELCOME TO THE ADDRESS BOOK\n\n"

while(true) do
	# Print the Menu
	echo "\n=================================="
	echo "|            MENU                |"
	echo "=================================="
	echo "| 1) Create Address Book         |"
	echo "| 2) View Address Book           |"
	echo "| 3) Insert a Record             |"
	echo "| 4) Delete a Record             |"
	echo "| 5) Modify a Record             |"
	echo "| 6) Search a Record             |"
	echo "| 7) Exit                        |" 
	echo "=================================="
	echo "\nEnter your choice - \c"
	read choice

	# Switch case
	case "$choice" in
	1) 
		echo "\n Creating the address book"

		# Read the filename
		echo "\n Enter name of the new file or existing file - \c"
		read filename

		# Check that filename is not empty
		len=$(echo -n $filename | wc -m)
		if test $len -gt 0; then
			touch $filename
			echo "\n File with name $filename was created successfully"
		else
			echo "\n Filename cannot be empty"
		fi
	;;

	2) 
		echo "\nThe Address book is shown below"
		echo "\nNAME\tADDRESS\tPHONE NO" 
		# Show the sorted output
		cat $filename |	sort 
	;;

	3) 
		echo "\n Inserting a new Record"

		# Take input for new record
		echo "\n Enter the Name - \c"
		# Validation for name
		while true
		do 
			read name
			len=$(echo -n $name | wc -m)
			if test $len -gt 0; then
				break
			else
				echo "\n Name cannot be empty, Please enter the name again - \c"
			fi
		done

		echo "\n Enter the Address - \c"
		# Validation for address
		while true
		do 
			read address
			len=$(echo -n $address | wc -m)
			if test $len -gt 0; then
				break
			else
				echo "\n Address cannot be empty, Please enter the address again - \c"
			fi
		done

		echo "\n Enter the Phone Number - \c"
		# Validation for phone number
		while true
		do 
			read phone
			len=$(echo -n $phone | wc -m)
			if test $len -eq 10; then
				break
			else
				echo "\n Phone should have 10 digits, Please enter the Phone again - \c"
			fi
		done

		# Write into file
		echo "$name\t$address\t$phone" >> $filename
		echo "\n Record inserted successfully"
	;;

	4) 
		echo "\n Deleting a Record"

		# Take the phone number to be deleted
		echo "\n Enter the Phone Number - \c"
		# Validation for phone number
		while true
		do 
			read sphone
			len=$(echo -n $sphone | wc -m)
			if test $len -eq 10; then
				break
			else
				echo "\n Phone should have 10 digits, Please enter the Phone again - \c"
			fi
		done
		grep -v -i "$sphone" $filename > temp
		mv temp $filename
		echo "\n Record deleted successfully"
	;;

	5) 
		echo "\n Modify a Record"

		# Take the phone number to be modified		
		echo "\n Enter the phone number of the record to be modified- \c"
		# Validation for phone number
		while true
		do 
			read mphone
			len=$(echo -n $mphone | wc -m)
			if test $len -eq 10; then
				break
			else
				echo "\n Phone should have 10 digits, Please enter the Phone again - \c"
			fi
		done

		# Fetch the whole record from  the file
		trecord=$(grep -w -i "$mphone" $filename)
		echo $trecord

		cnt=0
		for i in $trecord 
		do 
			cnt=`expr $cnt + 1`
			if test $cnt -eq 1; 
			then
				tname=$i
			elif test $cnt -eq 2; 
			then
				taddress=$i
			elif test $cnt -eq 3; 
			then
				tphone=$i
			fi 
		done

		# Take input for modified record
		echo "\n What would you like to modify"
		echo "\n 1. Name \n 2. Address \n 3. Phone Number - \c"
		read c
		# Switch case
		case "$c" in
		1) 
			echo "\n Enter the new Name - \c"
			# Validation for name
			while true
			do 
				read tname
				len=$(echo -n $tname | wc -m)
				if test $len -gt 0; then
					break
				else
					echo "\n Name cannot be empty, Please enter the name again - \c"
				fi
			done
		;;
		2)
			echo "\n Enter the new Address - \c"
			# Validation for address
			while true
			do 
				read taddress
				len=$(echo -n $taddress | wc -m)
				if test $len -gt 0; then
					break
				else
					echo "\n Address cannot be empty, Please enter the address again - \c"
				fi
			done
		;;
		3)
			echo "\n Enter the new Phone Number - \c"
			# Validation for phone number
			while true
			do 
				read tphone
				len=$(echo -n $tphone | wc -m)
				if test $len -eq 10; then
					break
				else
					echo "\n Phone should have 10 digits, Please enter the Phone again - \c"
				fi
			done
		;;
		esac
		# Replace the record in place
		sed "s/$trecord/$tname\t$taddress\t$tphone/g" $filename > temp
		mv temp $filename
		echo "\n Record Modified successfully"
	;;
	6) 
		echo "\n Search a Record"

		# Take the phone number to be searched
		echo "\n Enter the phone number of the record to be searched- \c"
		# Validation for phone number
		while true
		do
			read sphone
			len=$(echo -n $sphone | wc -m)
			if test $len -eq 10; then
				break
			else
				echo "\n Phone should have 10 digits, Please enter the Phone again - \c"
			fi
		done
		trecord=$(grep -w -i "$sphone" $filename)
		len=$(echo -n $trecord | wc -m)
		if test $len -eq 0; then
			echo "\n No record found"
		else
			echo "\nNAME\tADDRESS\tPHONE NO"
			echo $trecord	
		fi
	;;
	7) exit
	;;
	*) echo "\n Invalid option"
	;;
	esac
done
