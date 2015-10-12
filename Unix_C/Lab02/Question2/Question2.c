//
//  Question2
//
//  Created by Aidan Law on 11/08/2015.
//
//

// 2. Shell Commands
// Construct bash commands to do the following

//  a) List all files in the current directory whose name contains RALPH
        ls *RALPH*.*
    /*  
     make a list of: <anything> <RALPH> <anything> . <anything>
    */

//  b) List all files in the "codes" directory whose name consists of two digits, then a dash, then any three characters
        ls codes/[0-9][0-9]-???
    /*  
     within the directory: codes
     make a list of: <any single digit number> <any single digit number> <dash> <character> <character> <character>
    */

//  c) List all files that end with a vowel in all subdirectories that DON'T end with a vowel
        ls *[^aeiou] / *[aeiou]
    /*
     within a directory that has the following: <anything> <not any vowel>
     make a list of: <anything> <only vowels>
    */

//  d) Create an alias for listing all .c files
        alias lsc = 'ls *.c'
    /*
     invoke "ls *.c" when lsc is typed within the terminal
    */

//  e) Create an alias to turn the -Wall -ansi -pedantic switches on by default
        alias gcc = 'gcc -Wall -ansi -pedantic'
    /*
     invoke a C89 compatible compiler with all warnings (-Wall)
    */