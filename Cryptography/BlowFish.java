package Cryptography;

import java.nio.charset.StandardCharsets;
import java.util.Base64;
import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.util.Scanner;

public class BlowFish {
    Cipher ecipher,dcipher;
    BlowFish(SecretKey key) throws Exception {
        ecipher = Cipher.getInstance("Blowfish");
        dcipher = Cipher.getInstance("Blowfish");
        ecipher.init(Cipher.ENCRYPT_MODE, key);
        dcipher.init(Cipher.DECRYPT_MODE, key);
    }

    public String encrypt(String message) throws Exception{
        byte[] byte_message = message.getBytes(StandardCharsets.UTF_8);
        byte[] encrypted = ecipher.doFinal(byte_message);
        return Base64.getEncoder().encodeToString(encrypted);
    }

    public String decrypt(String encrypted) throws Exception {
        byte[] dec = Base64.getDecoder().decode(encrypted);
        byte[] decrypted = dcipher.doFinal(dec);
        return new String(decrypted, StandardCharsets.UTF_8);
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Any Message :");
        String message = sc.nextLine();
        SecretKey key = KeyGenerator.getInstance("Blowfish").generateKey();
        BlowFish obj = new BlowFish(key);
        String encrypted = obj.encrypt(message);
        System.out.println("Encrypted Message :" + encrypted);
        String decrypted = obj.decrypt(encrypted);
        System.out.println("Decrypted Message :" + decrypted);
    }
}