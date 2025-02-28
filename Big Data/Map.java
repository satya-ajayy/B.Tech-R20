package BigData;
import java.util.Scanner;

class HashNode{
    int key;
    int value;
    HashNode next;
    HashNode(int k, int v){
        key = k;
        value = v;
        next = null;
    }
}


public class Map {
    HashNode[] ht;

    Map(){
        ht = new HashNode[10];
    }

    public int hash(int key){
        return key % 10;
    }

    public void insert(HashNode data){
        int index = hash(data.key);
        HashNode temp = ht[index];
        if(temp == null) {
            // System.out.println("insert at null");
            ht[index] = new HashNode(data.key, data.value);
            return;
        }
        while(temp.next != null){
            temp = temp.next;
        }
        temp.next = new HashNode(data.key, data.value);
    }

    public void remove(HashNode data){
        int index = hash(data.key);
        HashNode temp = ht[index];
        if(temp == null){
            System.out.println("Error");
            return;
        }
        HashNode prev = null;
        while(temp != null){
            if(temp.key == data.key){
                if(temp == ht[index]){
                    ht[index] = ht[index].next;
                    temp = ht[index];
                }
                else{
                    prev.next = temp.next;
                    temp = temp.next;
                }
            }
            else{
                prev = temp;
                temp = temp.next;
            }
        }
    }

    public void print(){
        for(int i = 0; i < 10; i++){
            HashNode temp = ht[i];
            System.out.print(i + ":\t");
            while(temp != null){
                System.out.print(" ( " + temp.key + " , " + temp.value + ") ");
                temp = temp.next;
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("1. Insert\n2. Remove\n3. Print\n4. Exit");
        Map m = new Map();
        while(true){
            System.out.print("Enter option: ");
            int option = scanner.nextInt();
            if(option == 1){
                System.out.print("Enter key: ");
                int key = scanner.nextInt();
                System.out.print("Enter value: ");
                int value = scanner.nextInt();
                m.insert(new HashNode(key, value));
            }
            else if(option == 2){
                System.out.print("Enter key: ");
                int key = scanner.nextInt();
                System.out.print("Enter value: ");
                int value = scanner.nextInt();
                m.remove(new HashNode(key, value));
            }
            else if(option == 3){
                m.print();
            }
            else break;
        }
    }
}
