package JavaLab;

import java.awt.*;
import java.util.*;
import javax.swing.*;


class Slice{
    Scanner sc = new Scanner(System.in);
    double value;
    Color color;
    public Slice(String subject, Color color) {
        System.out.printf("Enter %s Marks : ", subject);
        this.value = sc.nextInt();
        this.color = color;
    }
}

class MyComponent extends JComponent {
    Slice[] slices = {
            new Slice("JAVA", Color.black),
            new Slice("OS", Color.green),
            new Slice("MAD", Color.yellow),
            new Slice("DBMS", Color.white)};
    MyComponent() {}
    public void paint(Graphics g) {
        drawPie((Graphics2D) g, getBounds(), slices);
    }
    void drawPie(Graphics2D g, Rectangle area, Slice[] slices) {
        double total = 0.0D;

        for (Slice slice : slices) {
            total += slice.value;
        }
        double curValue = 0.0D;
        for (Slice slice : slices){
            int startAngle = (int) (curValue * 360 / total);
            int arcAngle = (int) (slice.value * 360 / total);
            g.setColor(slice.color);
            g.fillArc(area.x+20, area.y+20, area.width-50, area.height-50, startAngle, arcAngle);
            curValue += slice.value;
        }
    }
}

public class PieChart {
    public static void main(String[] argv) {
        JFrame frame = new JFrame();
        frame.add(new MyComponent());
        frame.setSize(350, 350);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
