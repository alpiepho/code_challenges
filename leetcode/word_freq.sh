# !/bin/bash

# Write a bash script to calculate the frequency of each word in a text file words.txt.

# For simplicity sake, you may assume:

# words.txt contains only lowercase characters and space ' ' characters.
# Each word must consist of lowercase characters only.
# Words are separated by one or more whitespace characters.
# Example:

# Assume that words.txt has the following content:

# the day is sunny the the
# the sunny is is
# Your script should output the following, sorted by descending frequency:

# the 4
# is 3
# sunny 2
# day 1
# Note:

# Don't worry about handling ties, it is guaranteed that each word's frequency count is unique.
# Could you write it in one-line using Unix pipes?



# cat the file into next step
# replace \n
# replace all ' ' to make column
# (cheating) use awk to tally
# use sort to sort by freq
# technically, can be on 1 line

cat words.txt | tr '\n' ' ' | tr ' ' '\n' | awk '
    BEGIN {delete words} 
    { if($1!="") words[$1]++; }
    END { for (word in words) print word, words[word] }
    ' | sort -k 2 -n -r | tr '\n' ';' | sed 's/.$//' | tr ';' '\n'
