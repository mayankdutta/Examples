// How many 1's in given bitset. 
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    int count = 0;
    while (n > 0) {
      count++;
      int rsb = n & (-n);
      n &= ~(rsb); // subtracting rsb from original no, n -= rsb will also do. 
    }
    System.out.printf("%d\n", count);
    in.close();
  }
}
