package Cryptography;

import java.security.*;
import java.util.Scanner;

class SHA_1 {
    public static void main(String[] args) {
        try {
            MessageDigest md = MessageDigest.getInstance("SHA1");
            System.out.println("Message digest object info: ");
            System.out.println("   Algorithm = "+md.getAlgorithm());
            System.out.println("   Provider = "+md.getProvider());
            System.out.println("   toString = "+md);

            Scanner sc = new Scanner(System.in);
            System.out.print("Enter Message :");
            String input = sc.nextLine();
            md.update(input.getBytes());
            byte[] output = md.digest();
            System.out.println("SHA-1(" + input + ")=" + bytesToHex(output));
        } catch (Exception e) {
            System.out.println("Exception: " + e);
        }
    }

    public static String bytesToHex(byte[] b) {
        char[] hexDigit = {'0', '1', '2', '3', '4', '5', '6', '7',
                '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
        StringBuilder buf = new StringBuilder();
        for (byte value : b) {
            buf.append(hexDigit[(value >> 4) & 0x0f]);
            buf.append(hexDigit[value & 0x0f]);
        }
        return buf.toString();
    }
}