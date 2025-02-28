package JavaLab;
import java.util.Scanner;

public class Fibonacci {
    public static int recFib(int n) {
        if(n==1 || n==2)
            return 1;
        return recFib(n - 1) + recFib(n - 2);
    }

    public static int itrFib(int n){
        int a = 1, b = 1, c;
        if (n == 1) return 1;
        for (int i = 2; i < n; i++) {
            c = a + b;
            a = b; b = c;
        }
        return b;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter n :");
        int n = sc.nextInt();
        System.out.println("Recursive :" + recFib(n));
        System.out.println("Iterative :" + itrFib(n));
    }
}

