package BigData;
import java.util.Scanner;

class TreeNode{
    int data;
    TreeNode left;
    TreeNode right;

    TreeNode(int d){
        data = d;
        left = right = null;
    }
}

public class Set {
    TreeNode root;

    Set(){
        root = null;
    }

    public TreeNode insert(TreeNode root, int element){
        if(root == null){
            root = new TreeNode(element);
            return root;
        }
        if(root.data < element){
            root.right = insert(root.right, element);
        }
        else if(root.data > element){
            root.left = insert(root.left, element);
        }
        return root;
    }

    public int inorderSuccessor(TreeNode root){
        TreeNode temp = root;
        while(temp.left != null)
            temp = temp.left;
        return temp.data;
    }

    public TreeNode remove(TreeNode root, int element){
        if(root == null)
            return null;
        if(root.data > element){
            root.left = remove(root.left, element);
        }
        else if(root.data < element){
            root.right = remove(root.right, element);
        }
        else{
            if(root.left == null)
                return root.right;
            else if(root.right == null)
                return root.left;
            root.data = inorderSuccessor(root.right);
            root.right = remove(root.right, root.data);
        }
        return root;
    }

    public void print(TreeNode root){
        if(root == null)
            return;
        print(root.left);
        System.out.print(root.data + " ");
        print(root.right);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Set s = new Set();
        System.out.println("1. Insert\n2. Remove\n3. Print\n4. Exit");
        while(true){
            System.out.print("Option: ");
            int option = scanner.nextInt();
            if(option == 1){
                System.out.print("Enter element: ");
                int element = scanner.nextInt();
                s.root = s.insert(s.root, element);
            }
            else if(option == 2){
                System.out.print("Enter element: ");
                int element = scanner.nextInt();
                s.root = s.remove(s.root, element);
            }
            else if(option == 3){
                s.print(s.root);
                System.out.println();
            }
            else{
                break;
            }
        }
    }
}
