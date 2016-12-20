# textcmp 
Search two plain text files for differences and similarities in word usage

## Examples
textcmp searches through two text files and outputs words that are found in both or found only in the second file based on the options given.
    $ textcmp -uc test.txt test2.txt
    
    Common words in both files
   	green
    	blue
    	red
    	orange
    
    Unique words in test2.txt
    	yellow
    	grey

## Compiling and installing
To compile and install on Unix-like operating systems (e.g OSX or Linux) simply run the following command as root:
    g++ -std=c++11 -o /usr/bin/textcmp main.cpp
