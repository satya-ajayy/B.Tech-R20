package JavaLab;
import java.awt.*;
import java.awt.event.*;


public class KeyBoard extends Frame implements KeyListener {
    Label l;
    TextArea area;
    KeyBoard() {
        l = new Label();
        l.setBounds (100, 50, 200, 30);
        l.setFont(new Font(null,Font.BOLD, 30));
        area = new TextArea();
        area.setBounds (20, 80, 370, 310);
        area.setFont(new Font(null,Font.PLAIN, 20));
        area.addKeyListener(this);
        add(l);
        add(area);
        setSize (400, 400);
        setLayout (null);
        setVisible (true);
        addWindowListener (new WindowAdapter() {
            public void windowClosing (WindowEvent e) {
                dispose();
            }
        });
    }
    public void keyPressed (KeyEvent e) {
        l.setText("Key Pressed");
    }
    public void keyReleased (KeyEvent e) {
        l.setText("Key Released");
    }
    public void keyTyped (KeyEvent e) {
        l.setText("Key Typed");
    }
    public static void main(String[] args) {
        new KeyBoard();
    }
}   