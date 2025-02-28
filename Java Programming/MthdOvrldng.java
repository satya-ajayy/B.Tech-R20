package JavaLab;

class Add{
    public void add(int a){
        System.out.printf("%d + 1 = ", a);
        System.out.println(a+1);
    }
    public void add(int a, int b){
        System.out.printf("%d + %d = ", a,b);
        System.out.println(a + b);
    }
    public void add(int a, int b, int c){
        System.out.printf("%d + %d + %d = ", a,b,c);
        System.out.println(a + b + c);
    }
}
public class MthdOvrldng {
    public static void main(String[] args) {
        Add a1 = new Add();
        a1.add(1);
        a1.add(1, 2);
        a1.add(1,2,3);
    }
}
