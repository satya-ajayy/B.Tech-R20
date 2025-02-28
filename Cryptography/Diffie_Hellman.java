package Cryptography;

class Diffie_Hellman{
    private static long power(long a, long b, long p) {
        if (b == 1)
            return a;
        else
            return (((long)Math.pow(a, b)) % p);
    }

    public static void main(String[] args) {
        long P=23, G=9, x, a=4, y, b=3, ka, kb;
        System.out.println("The value of P:" + P);
        System.out.println("The value of G:" + G);
        System.out.println("The private key a for Alice:" + a);
        System.out.println("The private key b for Bob:" + b);
        x = power(G, a, P);y = power(G, b, P);
        ka = power(y, a, P);kb = power(x, b, P);
        System.out.println("Secret key for the Alice is:" + ka);
        System.out.println("Secret key for the Bob is:" + kb);
    }
}
