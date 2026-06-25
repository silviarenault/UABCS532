Description:

fileCat.c takes two files and concatenates the contents of the second file to the first. The first file then has content from both files and the second remains the same.
Program checks that two files names were given as parameters and that the files are accessible and checks that the same file is not put in for both arguments.

Compilation and Execution:

To compile, type:
gcc -o fileCat fileCat.c

To execute:
./fileCat <destination_file> <source_file>