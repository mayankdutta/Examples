// printing the rightmost set bit, i.e. the rightmost bit which is one in the given bitset. 
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    System.out.printf("%s", Integer.toBinaryString(n & ((~n) + 1)));
    in.close();
  }
}
