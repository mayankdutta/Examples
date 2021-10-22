`n + x == n ^ x`

[Problem](https://www.hackerrank.com/challenges/sum-vs-xor/problem) <br>

XOR represents binary addition without the "carry" for each digit.<br>
We want to see how many values of x that will give us n+x = n^x, <br>
**which is when XOR is the same as ADDITION.**<br>
This happens when there are no "carries". <br>
To make sure there are no carries, for each digit in "n" that is a 1, <br>
we must have the corresponding digit in "x" be a 0.<br>

```java
public class Solution {
    public static void main(String [] args) {
        /* Save input */
        Scanner scan = new Scanner(System.in);
        long n = scan.nextLong();
        scan.close();

        /* Calculate number of "x" values that will satisfy n+x = n^x */
        int zeroes = numZeroes(n);
        long result = 1L << zeroes; // same as (long) Math.pow(2, zeroes);
        System.out.println(result);
    }
    
    private static int numZeroes(long n) {
        int count = 0;
        while (n > 0) {
            if ((n & 1) == 0) {
                count++;
            }
            n >>= 1; // divides by 2
        }
        return count;
    }
}
```
