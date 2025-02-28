package BigData;
import java.util.Scanner;

public class Stack {
    int[] arr;
    int top;
    int max;
    Stack(){
        max = 10;
        top = -1;
        arr = new int[max];
    }

    public void push(int element){
        if(top == max - 1){
            System.out.println("Stack overflow");
            return;
        }
        top += 1;
        arr[top] = element;
    }

    public void pop(){
        if(top == -1){
            System.out.println("Stack underflow");
            return;
        }
        System.out.println("Popped : " + arr[top]);
        top--;
    }

    public void print(){
        if(top == -1){
            System.out.println("Stack empty");
            return;
        }
        for(int i = 0; i <= top; i++){
            System.out.print(arr[i] + " ");
        }
        System.out.println("");
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("1. Push\n2. Pop\n3. Print\n4. Exit");
        Stack s = new Stack();
        while(true){
            System.out.print("Enter option: ");
            int option = scanner.nextInt();
            if(option == 1){
                System.out.print("Enter element: ");
                int element = scanner.nextInt();
                s.push(element);
            }
            else if(option == 2){
                s.pop();
            }
            else if(option == 3){
                s.print();
            }
            else{
                break;
            }
        }
    }
}
