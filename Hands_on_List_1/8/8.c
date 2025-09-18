/*
==========================================================================
Name : 8.c
Author : Prateek Kumar Yadav
Description : WWrite a program to open a file in read only mode, read line by line and display each line as it is read. Close the file when end of file is reached.
Date: 3rd Sep, 2025.
==========================================================================
*/

#include <stdio.h>

int main() {
    FILE *fileptr = fopen("dummy_file.txt", "r");
    if (fileptr == NULL) {
        perror("fopen");
        return 1;
    }
    char buffer[512];
    // fgets to read each line
    while (fgets(buffer, sizeof(buffer), fileptr) != NULL) {
        printf("%s", buffer);
    }
    fclose(fileptr);
    return 0;
}

/*
==========================================================================
Output : 
		    prateek@Prateek-Kumar 8 % gcc 8.c
            prateek@Prateek-Kumar 8 % ./a.out
            hey there
            it's a dummy txt file
            thank you%  
==========================================================================
*/
