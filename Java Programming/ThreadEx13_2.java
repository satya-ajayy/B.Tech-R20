package JavaLab;

class NewThread implements Runnable{
    String thread_name;
    Thread t;
    int sec;
    NewThread(String name,int i){
        thread_name = name;
        t = new Thread(this,thread_name);
        sec = i;
    }
    public void run()
    {
        for(int i=0;i<3;i++){
            try {
                Thread.sleep(sec* 1000L);
            }
            catch (Exception e) {
                System.out.println("Exception is caught");
            }
            System.out.println(thread_name);
        }
    }
}
public class ThreadEx13_2 {
    public static void main(String[] args)
    {
        NewThread t1 = new NewThread("Good morning ",1);
        NewThread t2 = new NewThread("Hello",2);
        NewThread t3 = new NewThread("Welcome",3);
        Thread t = Thread.currentThread();
        System.out.println(t);
        t1.t.start();
        t2.t.start();
        t3.t.start();
    }
}