package JavaLab;

class Car{
    public void show(){
        System.out.print("I am a Car Of ");
    }
}

class Benz extends Car{
    @Override
    public void show(){
        System.out.println("Company : BENZ");
    }

    public void print() {
        super.show();
        show();
    }
}

class Audi extends Car{
    @Override
    public void show(){
        System.out.println("Company : AUDI");
    }

    public void print() {
        super.show();
        show();
    }
}

public class SprKwd {
    public static void main(String[] args) {
        Audi a = new Audi();
        Benz b = new Benz();
        a.print();
        b.print();
    }
}
