// given an array of no.s all no.s are repeating two times, but not two of them. find those two. 
// https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/bit-manipulation/all-repeating-except-two-official/ojquestion
// observe the property of xor, and then we partitioned best on RSB.
// base on same concept: Find Duplicate Number and Missing Number from 1 to N | One Duplicate One Missing | Bit Manipulation


import java.io.*;
import java.util.*;

public class Main {

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    int[] arr = new int[n];
    for (int i = 0; i < n; i++) {
      arr[i] = in.nextInt();
    }
    solution(arr);
    in.close();
  }

  public static void solution(int[] arr) {
    // write your code here
    int ans = arr[0];
    for (int i = 1; i < arr.length; i++)
      ans ^= arr[i];
    int rightMostSetBit = (ans & (-ans));
    int rmsb = rightMostSetBit;
    int num1 = 0, num2 = 0;
    for (int i = 0; i < arr.length; i++) {
      if ((arr[i] & rmsb) == 0) {
        num1 ^= arr[i];
      } else {
        num2 ^= arr[i];
      }
    }
    System.out.printf("%d\n%d", Math.min(num1, num2), Math.max(num1, num2));
  }
}
