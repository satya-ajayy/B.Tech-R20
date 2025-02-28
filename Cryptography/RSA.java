package Cryptography;

import java.io.IOException;
import java.math.BigInteger;
import java.util.*;


public class RSA {
    private final BigInteger N, e, d;
    public RSA() {
        Random r = new Random();
        int maxLength = 10;
        BigInteger p = BigInteger.probablePrime(maxLength, r);
        BigInteger q = BigInteger.probablePrime(maxLength, r);
        N = p.multiply(q);
        BigInteger PHI = p.subtract(BigInteger.ONE).multiply(q.subtract(BigInteger.ONE));
        e = BigInteger.probablePrime(maxLength / 2, r);
        d = e.modInverse(PHI);
    }

    public BigInteger encrypt(BigInteger message) {
        return message.modPow(e, N);
    }

    public BigInteger decrypt(BigInteger encrypted) {
        return encrypted.modPow(d, N);
    }

    public static void main(String[] args) throws IOException {
        RSA rsa = new RSA();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Any Message :");
        BigInteger message = sc.nextBigInteger();
        BigInteger encrypted = rsa.encrypt(message);
        System.out.println("Encrypted Message :" + encrypted);
        BigInteger decrypted = rsa.decrypt(encrypted);
        System.out.println("Decrypted Message :" + decrypted);
    }
}