package JavaLab;

class One extends Thread{
    public void run(){
        for (int i = 0; i < 3; i++) {
            try{
                Thread.sleep(1000L);
            }
            catch(InterruptedException e){
                System.out.println("Exception Occurred");
            }
            System.out.println("Good Morning");
        }
    }
}

class Two extends Thread{
    public void run(){
        for (int i = 0; i < 3; i++) {
            try{
                Thread.sleep(2000L);
            }
            catch(InterruptedException e){
                System.out.println("Exception Occurred");
            }
            System.out.println("Hello");
        }
    }
}

class Three extends Thread{
    public void run(){
        for (int i = 0; i < 3; i++) {
            try{
                Thread.sleep(3000L);
            }
            catch(InterruptedException e){
                System.out.println("Exception Occurred");
            }
            System.out.println("Welcome");
        }
    }
}
public class ThreadEx13_1 {
    public static void main(String[] args) {
        One one = new One();
        Two two = new Two();
        Three three = new Three();
        System.out.println(Thread.currentThread());
        System.out.println(one);
        System.out.println(two);
        System.out.println(three);
        one.start();
        two.start();
        three.start();
    }
}
