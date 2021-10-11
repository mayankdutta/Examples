/*
 * 1. You are given a number n.
 * 2. Print the number produced on setting its i-th bit.
 * 3. Print the number produced on unsetting its j-th bit.
 * 4. Print the number produced on toggling its k-th bit.
 * 5. Also, Check if its m-th bit is on or off. Print 'true' if it is on, otherwise print 'false'.
 */

import java.io.*;
import java.util.*;

public class Main {

  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);
    int n = scn.nextInt();
    
    int i = scn.nextInt();
    int j = scn.nextInt();
    int k = scn.nextInt();
    int m = scn.nextInt();

    int onMask = (1 << i); // if i is 2 then it will form, 1 -> 100
    int offMask = ~(1 << j); // if j is 3 it will form, 1 -> 1000 -> 0111
    int toggleMask = (1 << k);    
    int checkMask = (1 << m);

    
    System.out.printf("%d", (onMask | n));
    System.out.printf("%d", (offMask & n));
    System.out.printf("%d", (toggleMask ^ n));
    
    System.out.printf("%s", ((checkMask & n) != 0 ? "true" : "false")); 
    // if it come out to be 0, then at position m there was no 1 to begin with.
  }
}
