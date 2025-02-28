package JavaLab;
import java.util.Scanner;
import java.util.StringTokenizer;


public class Tokens {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Line of Numbers :");
        String str = sc.nextLine();
        StringTokenizer st = new StringTokenizer(str, " ");
        int sum = 0;
        while (st.hasMoreTokens()) {
            String t = st.nextToken();
            System.out.printf("%s ", t);
            sum += Integer.parseInt(t);
        }
        System.out.printf("\nsum : %d  ", sum);
    }
}
