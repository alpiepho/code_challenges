# !/bin/bash

# Given a text file file.txt that contains list of phone numbers (one per line), write a one liner bash script to print all valid phone numbers.

# You may assume that a valid phone number must appear in one of the following two formats: (xxx) xxx-xxxx or xxx-xxx-xxxx. (x means a digit)

# You may also assume each line in the text file must not contain leading or trailing white spaces.

# Example:

# Assume that file.txt has the following content:

# 987-123-4567
# 123 456 7890
# (123) 456-7890
# Your script should output the following valid phone numbers:

# 987-123-4567
# (123) 456-7890


#grep -E '^(([(][1-9]\d{2})[)]|([1-9]\d{2}))(\s|[-])([1-9]\d{2})([-](\d{4}))$' file.txt
#egrep -e '^(([(][1-9]\d{2})[)]\s|([1-9]\d{2})[-])([1-9]\d{2})([-](\d{4}))$' file.txt

#egrep -e '^([(][1-9]\d{2}[)] |[1-9]\d{2}-)\d{3}-\d{4}$' file.txt

#egrep -e '(^[(][1-9]\d{2}[)] \d{3}-\d{4}$)|(^[1-9]\d{2}-\d{3}-\d{4}$)' file.txt

#egrep -e '^\([0-9]{3}\) [0-9]{3}-[0-9]{4}$|^[0-9]{3}-[0-9]{3}-[0-9]{4}$' file.txt

# [ ]: Matches any one of a set characters
# [ ] with hyphen: Matches any one of a range characters
# ^: The pattern following it must occur at the beginning of each line
# ^ with [ ] : The pattern must not contain any character in the set specified
# $: The pattern preceding it must occur at the end of each line
# . (dot): Matches any one character
# \ (backslash): Ignores the special meaning of the character following it
# *: zero or more occurrences of the previous character
# (dot).*: Nothing or any numbers of characters.

# LeetCode did not like my \d
egrep -e '(^[(][0-9]{3}[)] [0-9]{3}-[0-9]{4}$)|(^[0-9]{3}-[0-9]{3}-[0-9]{4}$)' file.txt
