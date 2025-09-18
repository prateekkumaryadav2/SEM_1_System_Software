# /*
# ==========================================================================
# Name : 9.sh
# Author : Prateek Kumar Yadav
# Description : Write a program to print the following information about a given file.    
#     a. inode    
#     b. number of hard links    
#     c. uid    
#     d. gid    
#     e. size    
#     f. block size    
#     g. number of blocks    
#     h. time of last access    
#     i. time of last modification    
#     j. time of last change 
# Date: 3rd Sep, 2025.
# ==========================================================================
# */

# (a)
# --> INODE
# display the inode number followed by the file name
s -i dummy.txt
# ===========
# Output : 
# prateek@Prateek-Kumar 9 % ls -i dummy.txt
# 6087365 dummy.txt
# ===========

# prints only the inode number
stat -f '%i' dummy.txt
# ===========
# Output : 
# prateek@Prateek-Kumar 9 % stat -f '%i' dummy.txt
# 6087365
# ===========

# (b)
# --> no of hardlinks
ls -l dummy.txt
# Column meanings:
#   1. File permissions
#   2. Number of hard links
#   3. Owner
#   4. Group
#   5. File size (bytes)
#   6. Modification date/time
#   7. File name

# ===========
# Output : 
# prateek@Prateek-Kumar 9 % ls -l dummy.txt
# -rw-r--r--@ 1 prateek  staff  63 Aug 15 14:42 dummy.txt
# --> creating new hardlink
# prateek@Prateek-Kumar 9 % ln dummy.txt hardlink_to_dummy
# prateek@Prateek-Kumar 9 % ls -l dummy.txt               
# -rw-r--r--@ 2 prateek  staff  63 Aug 15 14:42 dummy.txt
# ===========

# (c)
# --> uid (user id of the owner of the given file)
stat -f '%u' dummy.txt
# ===========
# Output : 
# prateek@Prateek-Kumar 9 % stat -f '%u' dummy.txt
# 501
# ===========

# (d)
# --> gid
stat -f '%g' dummy.txt
# ===========
# Output : 
# prateek@Prateek-Kumar 9 % stat -f '%g' dummy.txt
# 20
# ===========
# on 3rd(user id) and 4th(group id) column
# as their actual name
ls -l dummy.txt
# as numeric
ls -n dummy.txt

# (e)
# --> size
# size in Bytes
stat -f '%z' dummy.txt
# on 5th column in Bytes
ls -l dummy.txt
# ===========
# Output : 
# prateek@Prateek-Kumar 9 % ls -l dummy.txt      
# -rw-r--r--@ 2 prateek  staff  63 Aug 15 14:42 dummy.txt
# ===========

# in human readable way
ls -lh dummy.txt
# ===========
# Output : 
# prateek@Prateek-Kumar 9 % ls -lh dummy.txt      
# -rw-r--r--@ 2 prateek  staff    63B Aug 15 14:42 dummy.txt
# ===========

# (f)
# --> block size
# block size of system where file is stored
stat -f '%k' dummy.txt
# ===========
# Output : 
# prateek@Prateek-Kumar 9 % stat -f '%k' dummy.txt    
# 4096
# ===========

# (g)
# --> no of blocks
# no if blocks allocated to the file
stat -b '%k' dummy.txt
# ===========
# Output : 
# prateek@Prateek-Kumar 9 % stat -f '%b' dummy.txt
# 8
# ===========

# (h)
# --> time of last access

# unix time-stamp
stat -f '%a' dummy.txt
# ===========
# Output : 
# prateek@Prateek-Kumar 9 % stat -f '%a' dummy.txt
# 1755250965
# ===========

# human readable
stat -f '%Sa' dummy.txt
# ===========
# Output : 
# prateek@Prateek-Kumar 9 % stat -f '%Sa' dummy.txt
# Aug 15 15:12:45 2025
# ===========

# (i)
# --> time of last modification
stat -f '%Sm' dummy.txt
# ===========
# Output : 
# prateek@Prateek-Kumar 9 % stat -f '%Sm' dummy.txt
# Aug 15 14:42:42 2025
# ===========

# (j)
# --> time of last change
stat -f '%Sc' dummy.txt
# ===========
# Output : 
# prateek@Prateek-Kumar 9 % stat -f '%Sc' dummy.txt
# Aug 15 14:58:59 2025
# ===========

stat -x dummy.txt
# shows all timestamps in a readable format
# ===========
# Output : 
# prateek@Prateek-Kumar 9 % stat -x dummy.txt
#   File: "dummy.txt"
#   Size: 63           FileType: Regular File
#   Mode: (0644/-rw-r--r--)         Uid: (  501/ prateek)  Gid: (   20/   staff)
# Device: 1,17   Inode: 6087365    Links: 2
# Access: Fri Aug 15 15:12:45 2025
# Modify: Fri Aug 15 14:42:42 2025
# Change: Fri Aug 15 14:58:59 2025
#  Birth: Fri Aug 15 14:42:13 2025
# ===========