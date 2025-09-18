# /*
# ==========================================================================
# Name : 7.sh
# Author : Prateek Kumar Yadav
# Description : Write a program to copy file1 into file2 ($cp file1 file2).
# Date: 3rd Sep, 2025.
# ==========================================================================
# */

# write into file_1.txt
echo "content of file_1" > file_1.txt

# write into file_2.txt
echo "content of file_2" > file_2.txt

# copy content of file_1 into file_2
cp file_1.txt file_2.txt

# view content of file_2 after copy
cat file_2.txt

# /*
# ==========================================================================
# Output : 
#           prateek@Prateek-Kumar 7 % cat file_1.txt
#           content of file_1
#           prateek@Prateek-Kumar 7 % cat file_2.txt
#           prateek@Prateek-Kumar 7 % chmod +x 7.sh 
#           prateek@Prateek-Kumar 7 % ./7.sh        
#           content of file_1
#           prateek@Prateek-Kumar 7 % cat file_1.txt
#           content of file_1
#           prateek@Prateek-Kumar 7 % cat file_2.txt
#           content of file_1
# ==========================================================================
# */