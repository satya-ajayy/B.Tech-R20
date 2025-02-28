package Cryptography;

import java.nio.charset.StandardCharsets;
import java.util.Base64;
import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;

public class Hworld {
    Cipher ecipher,dcipher;
    Hworld(String key) throws Exception {
        ecipher = Cipher.getInstance("Blowfish");
        // dcipher = Cipher.getInstance("Blowfish");
        byte[] KeyData = key.getBytes();
        SecretKeySpec KS = new SecretKeySpec(KeyData, "Blowfish");
        ecipher.init(Cipher.ENCRYPT_MODE, KS);
        // dcipher.init(Cipher.DECRYPT_MODE, KS);
    }

    public String encrypt(String message) throws Exception{
        byte[] byte_message = message.getBytes(StandardCharsets.UTF_8);
        byte[] encrypted = ecipher.doFinal(byte_message);
        return Base64.getEncoder().encodeToString(encrypted);
    }

    public static void main(String[] args) throws Exception {
        final String message = "Hello World";
        final String key = "CNS LAB";
        Hworld obj = new Hworld(key);
        String encrypted = obj.encrypt(message);
        System.out.println("Encrypted Message :" + encrypted);
    }
}
