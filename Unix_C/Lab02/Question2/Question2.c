//
//  Question2
//
//  Created by Aidan Law on 11/08/2015.
//
//

// 2. Shell Commands
// Construct bash commands to do the following

//  a) List all files in the current directory whose name contains RALPH
        ls *RALPH*

//  b) List all files in the "codes" directory whose name consists of two digits, then a dash, then any three characters
        ls codes/[0-9][0-9]-???

//  c) List all files that end with a vowel in all subdirectories that DON'T end with a vowel
        ls *[^aeiou] / *[aeiou]

//  d) Create an alias for listing all .c files
        alias lsc = 'ls *.c'

//  e) Create an alias to turn the -Wall -ansi -pedantic switches on by default
        alias gcc = 'gcc -Wall -ansi -pedantic'
