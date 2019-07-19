# !/bin/bash

# Given a text file file.txt, transpose its content.

# You may assume that each row has the same number of columns and each field is separated by the ' ' character.

# Example:

# If file.txt has the following content:

# name age
# alice 21
# ryan 30
# Output the following:

# name alice ryan
# age 21 30

# file='file3.txt'
# cols=`head -n 1 $file | tr ' ' '\n' | wc -l`
# echo $cols
# cols=$((cols + 1))
# echo $cols
# for i in $(seq $cols); do
#     echo $i
#     cat $file | cut -d " " -f $i 
# done


# file='file3.txt'
# cat $file | awk '
# BEGIN {y=0;}
# {
#     split($0,a," ");
#     y++
#     for (x=1;x<=NF;x++) { table[y, x] = a[x] }
# }
# END {
#     cols = NF
#     rows = NR
#     print "table"
#     for (y=1;y<=rows;y++) {
#         for (x=1;x<=cols;x++) {
#             printf("%s", table[y, x]);
#             if (x<cols) printf(" ")
#         }
#         #if (y<rows) 
#         printf("\n");
#     }

#     print "transposed"
#     for (x=1;x<=cols;x++) {
#         for (y=1;y<=rows;y++) {
#             printf("%s", table[y, x]);
#             if (y<cols) printf(" ")
#         }
#         if (x<rows) 
#         printf("\n");
#     }
# }'


# file='file3.txt'
# cat $file | awk '
# BEGIN {y=0;}
# {
#     split($0,a," ");
#     y++
#     for (x=1;x<=NF;x++) { table[y, x] = a[x] }
# }
# END {
#     cols = NF
#     rows = NR
#     # print "table"
#     # for (y=1;y<=rows;y++) {
#     #     for (x=1;x<=cols;x++) {
#     #         printf("%s", table[y, x]);
#     #         if (x<cols) printf(" ")
#     #     }
#     #     #if (y<rows) 
#     #     printf("\n");
#     # }

#     # print "transposed"
#     for (x=1;x<=cols;x++) {
#         for (y=1;y<=rows;y++) {
#             printf("%s", table[y, x]);
#             if (y<cols) printf(" ")
#         }
#         #if (x<rows) 
#         printf("\n");
#     }
# }'


# This finally worked
# file='file3.txt'
# cat $file | awk '
# BEGIN {y=0;}
# {
#     split($0,a," ");
#     y++
#     for (x=1;x<=NF;x++) { table[y, x] = a[x] }
# }
# END {
#     cols = NF
#     rows = NR
#     # print "transposed"
#     for (x=1;x<=cols;x++) {
#         for (y=1;y<=rows;y++) {
#             printf("%s", table[y, x]);
#             if (y<rows) printf(" ")
#         }
#         #if (x<cols) 
#         printf("\n");
#     }
# }'


# This finally worked, with some tweeks
file='file3.txt'
cat $file | awk '
{
    for (x=1;x<=NF;x++) { table[NR, x] = $x }
}
END {
    #cols = NF
    #rows = NR
    print "transposed"
    for (x=1;x<=NF;x++) {
        for (y=1;y<=NR;y++) {
            printf("%s", table[y, x]);
            if (y<NR) printf(" ")
        }
        #if (x<NF) 
        printf("\n");
    }
}'
