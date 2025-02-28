package JavaLab;

class A{
    public void func(){
        System.out.println("In Class A");
    }
}

class B extends A{
    public void func(){
        System.out.println("In Class B");
    }
}

class C extends A{
    public void func(){
        System.out.println("In Class C");
    }
}

public class RntmPlysm {
    public static void main(String[] args) {
        A a1 = new A();
        A a2 = new B();
        A a3 = new C();
        a1.func();
        a2.func();
        a3.func();
    }
}
