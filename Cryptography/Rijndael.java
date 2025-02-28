package Cryptography;

import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.nio.charset.StandardCharsets;
import java.util.Base64;
import java.util.Scanner;

class Rijndael {
    Cipher ecipher, dcipher;
    Rijndael(SecretKey key) throws Exception {
        ecipher = Cipher.getInstance("AES");
        dcipher = Cipher.getInstance("AES");
        ecipher.init(Cipher.ENCRYPT_MODE, key);
        dcipher.init(Cipher.DECRYPT_MODE, key);
    }

    public String encrypt(String message) throws Exception {
        byte[] byte_message = message.getBytes(StandardCharsets.UTF_8);
        byte[] encrypted = ecipher.doFinal(byte_message);
        return Base64.getEncoder().encodeToString(encrypted);
    }

    public String decrypt(String encrypted) throws Exception {
        byte[] dec = Base64.getDecoder().decode(encrypted);
        byte[] decrypted = dcipher.doFinal(dec);
        return new String(decrypted, StandardCharsets.UTF_8);
    }

    public static void main(String[] argv) throws Exception {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Any Message :");
        String message = sc.nextLine();
        SecretKey key = KeyGenerator.getInstance("AES").generateKey();
        Rijndael obj = new Rijndael(key);
        String encrypted = obj.encrypt(message);
        System.out.println("Encrypted Message :" + encrypted);
        String decrypted = obj.decrypt(encrypted);
        System.out.println("Decrypted Message :" + decrypted);
    }
}


