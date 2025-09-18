# /*
# ==========================================================================
# Name : 10_b.c
# Author : Prateek Kumar Yadav
# Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes.     
#     b. open the file with od and check the empty spaces in between the data
# Date: 3rd Sep, 2025.
# ==========================================================================
# */

# This will display the file contents as characters. The empty spaces (created by lseek) will appear as \\0 (null bytes).
od -c dummy10.txt
# ===========
# Output : 
# prateek@Prateek-Kumar 10 % od -c dummy10.txt
# 0000000    H   E   Y   P   R   A   T   E   E   K  \0  \0  \0  \0  \0  \0
# 0000020   \0  \0  \0  \0   I   M   A   C   I   N   T   O   S   H        
# 0000036
# ===========

# This will show the file contents byte by byte in hex, where 00 represents a null byte (empty space).
od -tx1 dummy10.txt
# ===========
# Output : 
# prateek@Prateek-Kumar 10 % od -tx1 dummy10.txt
# 0000000    48  45  59  50  52  41  54  45  45  4b  00  00  00  00  00  00
# 0000020    00  00  00  00  49  4d  41  43  49  4e  54  4f  53  48        
# 0000036
# ===========