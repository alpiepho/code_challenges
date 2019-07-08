## Collection of Leet Code solutions

The first few are seed/examples from aws-freertos-onsite:

- doublestack.c
- oddeven.c
- queue.c

### (Personal) binary_counter.c

Given a number N, list all the possible binary strings.  N is the number of bits.  For example:
```
Size: 3
000
001
010
011
100
101
110
111
```

### (LeetCode, Easy) Two Sum

Given an array of integers, return indices of the two numbers such that they add up to a specfic target.  Assume exactly one solution.

Given nums = [2,7,11,15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
Return [0, 1]

### (Personal) Any Sum
:warning: NOTE: this was not finished

Expand 'Two Sum' to look for any number values from nums that sum to the value 'target'.  Each num is used once.  Size of solution array can be 1 to n.

Given nums = [2,4,6,1], target = 9,
Because nums[0] + nums[2] + nums[3] = 2 + 6 + 1 = 9
Return [0, 2, 3]

### (LeetCode, Easy) Reverse Integer

After some attention to overflows, this passes LeetCode.  Not sure why memory is not better.

### (Personal, Basic) Bubble Sort

Basic implementation of Bubble Sort.

### (Personal, Basic) Quick Sort

Basic implementation of Quick Sort.

### (LeetCode, Easy) Palindrone Integer

Determine if integer is palindrone.  Easy, using reverse_integer.c.

### (LeetCode, Easy) Valid Paren

Determine if string has valid parens. Tricky small string edge cases.

### (LeetCode, Easy) Roman to Integer

Convert roman number string to integer.

### (LeetCode, Easy) Longest Prefix

Return longest prefix of given array of strings.

### (LeetCode, Easy) Remove Duplicates

Return duplicate from sorted list.

### (Personal, Easy) Build Set

Given a list of integers, return a set of unique integers from that list.

### (LeetCode, Easy) Merge Two

Merge 2 sorted linked lists.
