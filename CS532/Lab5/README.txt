Description:

readdir.c recursively traverses through file hierarchies, listing each directory and the files it contains.

Compilation and Execution:

    To compile:
    gcc -Wall -o readdir readdir.c

    To execute:

    Through directory path:
        ./readdir <directory_path>

    For current directory: 
        ./readdir .

    For directories within the current directory:
        ./readdir <directory_name>

    For parent directory:
        ./readdir ..
        
    For different directory in parent directory:
        ./readdir ../<directory_name>