package Cryptography;

import java.util.Scanner;
public class SubstitutionCipher {
    static String a = "abcdefghijklmnopqrstuvwxyz";
    static String b = "zyxwvutsrqponmlkjihgfedcba";
    static Scanner sc = new Scanner(System.in);

    public static String encrypt(String str){
        StringBuilder encrypted = new StringBuilder();
        for(int i=0;i<str.length();i++) {
            char c = str.charAt(i);
            int j = a.indexOf(c);
            encrypted.append(b.charAt(j));
        }
        return encrypted.toString();
    }

    public static String decrypt(String str){
        StringBuilder decrypted = new StringBuilder();
        for(int i=0;i<str.length();i++) {
            char c = str.charAt(i);
            int j = b.indexOf(c);
            decrypted.append(a.charAt(j));
        }
        return decrypted.toString();
    }

    public static void main(String[] args) {
        System.out.print("Enter Any Message : ");
        String str = sc.nextLine();
        String encrypted = encrypt(str);
        System.out.println("Encrypted Message :" + encrypted);
        String decrypted = decrypt(encrypted);
        System.out.println("Decrypted Message :" + decrypted);
    }
}
