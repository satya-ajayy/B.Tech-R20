package JavaLab;
import java.util.Arrays;
import java.util.Scanner;


public class MatMul {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Rows And Cols of Mat1 : ");
        int r1 = sc.nextInt();
        int c1 = sc.nextInt();
        System.out.print("Enter Rows And Cols of Mat2 : ");
        int r2 = sc.nextInt();
        int c2 = sc.nextInt();

        if (c1 == r2) {
            int[][] Mat1 = new int[r1][c1];
            int[][] Mat2 = new int[r2][c2];
            int[][] Mat3 = new int[r1][c2];
            int[][] Mat4 = new int[r1][c2];

            System.out.printf("Enter %d Elements of Mat1 : ", r1 * c1);
            for (int i = 0; i < r1; i++) {
                for (int j = 0; j < c1; j++) {
                    Mat1[i][j] = sc.nextInt();
                }
            }
            System.out.print("Matrix 1 : " + Arrays.deepToString(Mat1) + "\n");
            System.out.printf("Enter %d Elements of Mat2: ", r2 * c2);
            for (int i = 0; i < r1; i++) {
                for (int j = 0; j < c1; j++) {
                    Mat2[i][j] = sc.nextInt();
                }
            }
            System.out.print("Matrix 2 : " + Arrays.deepToString(Mat2)+ "\n");
            for (int i = 0; i < r1; i++) {
                for (int j = 0; j < c2; j++) {
                    for (int k = 0; k < c1; k++) {
                        Mat3[i][j] += Mat1[i][k] * Mat2[k][j];
                    }
                }
            }
            for (int i = 0; i < r1; i++) {
                for (int j = 0; j < c2; j++) {
                    Mat4[i][j] = Mat3[j][i];
                }
            }
            System.out.print("Matrix 3 : " + Arrays.deepToString(Mat3)+ "\n");
            System.out.print("Matrix 3T : " + Arrays.deepToString(Mat4)+ "\n");
        } else {
            System.out.println("Multiplication Can't be Performed");
        }
    }
}
