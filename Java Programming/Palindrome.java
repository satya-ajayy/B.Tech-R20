package JavaLab;
import java.util.Scanner;

public class Palindrome {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string : ");
        String str = sc.nextLine();
        int len = str.length();
        int flag = 0;
        for (int i = 0; i < len / 2; i++) {
            if (str.charAt(i) != str.charAt(len - i - 1)) {
                flag = 1;
                break;
            }
        }
        System.out.println(flag == 0 ? "YES" : "NO");
    }
}