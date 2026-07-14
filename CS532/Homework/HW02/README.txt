Description:

silvia_HW02.c recursively searched through file hierarchies, listing each directory and the files it contains.
Users can also utilize five command line options:
[-S]: Lists files in a heirarchy and prints the size, permission, and last access time.
[-s]: Lists all files in a heirarchy that are less than or equal to the specified value.
[-f]: Lists files with the substring in the string pattern option at the specified depth relative to the starting directory.
[-t f]: Lists only regualar files.
[-t d]: Lists only directories

It has a corresponding Makefile that compiles code into an executable called silvia_HW02.

Compilation and Execution:

    To compile:
    make

    To execute:

    Required-> ./silvia_HW02 <directory path>
    Optional Commands-> ./silvia_HW02 <directory path> -S -s bytes -f substring depth -t f|d

    Other Directory Paths:

            For current directory: 
                ./readdir .

            For directories within the current directory:
                ./readdir <directory_name>

            For parent directory:
                ./readdir ..
                
            For different directory in parent directory:
                ./readdir ../<directory_name>