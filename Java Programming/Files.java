package JavaLab;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;


public class Files {
    public static void main(String[] args)throws IOException {
        try{
            int lines=1, words=1, n;
            try (FileInputStream f = new FileInputStream("-------PATH-TO-TEXTFILE-------")) {
                n = f.available();
                for (int i = 0; i < n; i++) {
                    char ch = (char) f.read();
                    if (ch == '\n') lines++;
                    if (ch == ' ') words++;
                }
            }
            System.out.printf("Chars : %d\n",n);
            System.out.printf("Words : %d\n",words+lines-1);
            System.out.printf("Lines : %d\n",lines);
        }

        catch (FileNotFoundException e) {
            System.out.println("File is Not Found");
            e.printStackTrace();
        }
    }
}
