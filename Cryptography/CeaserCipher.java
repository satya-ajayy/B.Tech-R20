package Cryptography;

import java.util.Scanner;
public class CeaserCipher {
    static Scanner sc=new Scanner(System.in);

    public static String encrypt(String str, int key){
        StringBuilder encrypted = new StringBuilder();
        for(int i = 0; i < str.length(); i++) {
            int c = str.charAt(i);
            if (Character.isUpperCase(c)) {
                c = c + (key % 26);
                if (c > 'Z') c = c - 26;
            }
            else if (Character.isLowerCase(c)) {
                c = c + (key % 26);
                if (c > 'z') c = c - 26;
            }
            encrypted.append((char) c);
        }
        return encrypted.toString();
    }

    public static String decrypt(String str, int key){
        StringBuilder decrypted = new StringBuilder();
        for(int i = 0; i < str.length(); i++) {
            int c = str.charAt(i);
            if (Character.isUpperCase(c)) {
                c = c - (key % 26);
                if (c < 'A') c = c + 26;
            }
            else if (Character.isLowerCase(c)) {
                c = c - (key % 26);
                if (c < 'a') c = c + 26;
            }
            decrypted.append((char) c);
        }
        return decrypted.toString();
    }

    public static void main(String[] args) {
        System.out.print("Enter Any Message :");
        String str = sc.nextLine();
        System.out.print("Enter the Key :");
        int key = sc.nextInt();
        String encrypted = encrypt(str, key);
        System.out.println("Encrypted Message :" + encrypted);
        String decrypted = decrypt(encrypted, key);
        System.out.println("Decrypted Message :" + decrypted);
    }
}