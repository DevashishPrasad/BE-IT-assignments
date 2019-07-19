
#!/bin/sh
echo "Welcome to the grading system"
echo "Enter your marks - \c"
read marks

# Validate the input
if test $marks -gt 100; then
        echo "Invalid input! Marks should be between 0-100"
        exit 1
fi

# Start with the Grading
if test $marks -lt 40; then
        echo "Fail"
elif test $marks -lt 60; then
        echo "Pass"
elif test $marks -lt 75; then
        echo "first class"
else
        echo "Distinction"
fi
# End of script


