
# Code
# Testcase
# Test Result
# Test Result
# 195. Tenth Line
# Solved
# Easy
# Topics
# premium lock icon
# Companies
# Given a text file file.txt, print just the 10th line of the file.

# Example:

# Assume that file.txt has the following content:

# Line 1
# Line 2
# Line 3
# Line 4
# Line 5
# Line 6
# Line 7
# Line 8
# Line 9
# Line 10
# Your script should output the tenth line, which is:

# Line 10
# Note:
# 1. If the file contains less than 10 lines, what should you output?
# 2. There's at least three different solutions. Try to explore all possibilities.

--------------------------------------------------------------------------------------------------------------
solution : there is multiple method to retrive nth line from a file 
1.  using sed 
code:

sed -n "np" file.txt

-> sed -n "10p" file.txt


2. using awk 
awk 'NR==5' file.txt

-> awk 'NR==10' file.txt

3. using head and tail 

head -n ${N} file.txt | tail -n 1




BUT OUR Sumitted solution : 
    sed -n "10p" file.txt

    