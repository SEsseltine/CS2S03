# Assignment 6

## Problem 1 - Left Shifting Computations
Left shifting an unsigned integer by 1 bit is equivalent to multiplying the value 2. Write function **power2** that takes two integer arguments number and pow and calculates :
<p align="center">
  <code>number x 2<sup>pow</sup></code>
</p>

Use the shift operator to calculate the result. Print the values as integers and as bits.

## Problem 2 - Pack two Character Values
The left-shift operator can be used to pack two character values into an unsigned integer variable. Write a program that inputs two characters from the keyboard and passes them to function packCharacters. To pack two characters into an unsigned integer variable, assign the first character to the unsigned variable, shift the unsigned variable left by 8- bit positions and combine the unsigned variable with the second character using the bitwise inclusive OR operator. The program should output the characters in their bit format before and after they are packed into the unsigned integer to prove that the characters are in fact packed correctly in the unsigned variable. See the following example:

```
Enter two characters: A B
'A' in bits as an unsigned integers is:
65 = 00000000 01000001

'B' in bits as an unsigned integers is:
66 = 00000000 01000010

'A' and 'B' packed in an unsigned integer:
16706 = 01000001 01000010
```

## Problem 3 - Unpack two Character Values
Using the right-shift operator, the bitwise AND operator and a mask, write function unpackCharacters that takes the unsigned integer from **Problem 2** and unpacks it into two characters. To unpack two characters from an unsigned integer, combine the unsigned integer with the mask 65280 (00000000 00000000 11111111 00000000) and right shift the result 8 bits. Assign the resulting value to a char variable. Then combine the unsigned integer with the mask 255 (00000000 0000000000000000 11111111). Assign the result to another char variable. The program should print the unsigned integer in bits before it is unpacked, then print the characters in bits to confirm that they were unpacked correctly.
