/*
An efficient solution is to consider pattern of binary values from L to R. We can see that first bit from L to R either changes from 0 to 1 or it stays 1 i.e. 
if we take the XOR of any two numbers for maximum value their first bit will be fixed which will be same as first bit of XOR of L and R itself. 
After observing the technique to get first bit, we can see that if we XOR L and R, the most significant bit of this XOR will tell us the maximum value we can achieve 
i.e. let XOR of L and R is 1xxx where x can be 0 or 1 then maximum XOR value we can get is 1111 because from L to R we have all possible combination of xxx 
and it is always possible to choose these bits in such a way from two numbers such that their XOR becomes all 1. It is explained below with some examples, 
*/

// https://www.geeksforgeeks.org/maximum-xor-value-of-a-pair-from-a-range/
