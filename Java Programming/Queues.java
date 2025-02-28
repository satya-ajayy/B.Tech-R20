package JavaLab;
import java.util.*;
import java.lang.*;


class QueueError extends Exception{
    public QueueError(String error){
        super(error);
    }
}


class Que{
    private final int size;
    private int front = - 1;
    private int rear = -1;
    private final int [] arr;

    public Que(int size){
        this.size = size;
        this.arr = new int[size];
    }
    public void enqueue(int val) throws QueueError {
        try{
            if(rear == size-1){
                throw new QueueError("Queue OverFlow");
            }
            else if(front == -1){
                rear++;
                arr[rear] = val;
                front = rear;
            }
            else{
                rear++;
                arr[rear] = val;
            }
        }
        catch(QueueError error){
            error.printStackTrace();
        }
    }

    public void dequeue() throws QueueError{
        try{
            if(front == -1){
                throw new QueueError("Queue Under Flow");
            }
            else if(rear==front){
                System.out.printf("%d is Removed From Queue\n",arr[front]);
                front = -1;
                rear = -1;
            }
            else{
                System.out.printf("%d is Removed From Queue\n",arr[front]);
                front++;
            }
        }
        catch(QueueError error){
            error.printStackTrace();
        }
    }

    public void Display(){
        try{
            if(front == -1){
                throw new QueueError("Queue is Empty");
            }
            else{
                for (int i = front; i <= rear; i++) {
                    System.out.printf("%d  ",arr[i]);
                }
                System.out.println();
            }
        }
        catch(QueueError error){
            error.printStackTrace();
        }
    }
}
public class Queues {
    public static void main(String[] args)throws Exception{
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Size of Queue : ");
        int size = sc.nextInt();
        Que q = new Que(size);
        try{
            System.out.println("---OPERATIONS---");
            System.out.println("1) ENQUEUE");
            System.out.println("2) DEQUEUE");
            System.out.println("3) DISPLAY");
            System.out.println("4) EXIT");
            while(true){
                System.out.print("Enter Your Choice : ");
                int choice = sc.nextInt();
                switch (choice) {
                    case 1 -> {
                        System.out.print("Enter Value To Insert : ");
                        q.enqueue(sc.nextInt());
                    }
                    case 2 -> q.dequeue();
                    case 3 -> q.Display();
                    case 4 -> {
                        System.out.println("You Exited From Program");
                        return;
                    }
                    default -> System.out.println("Wrong Choice.");
                }
            }
        }
        catch(QueueError error){
            error.printStackTrace();
        }
    }
}
