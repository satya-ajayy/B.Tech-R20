package JavaLab;
import java.awt.*;
import java.awt.event.*;


public class Mouse extends Frame implements MouseListener{
    Label l;
    Mouse(){
        addMouseListener(this);
        l=new Label();
        l.setBounds(40,150,230,22);
        l.setFont(new Font(null,Font.BOLD, 30));
        add(l);
        setSize(300,300);
        setLayout(null);
        setVisible(true);
        addWindowListener (new WindowAdapter() {
            public void windowClosing (WindowEvent e) {
                dispose();
            }
        });
    }
    public void mouseClicked(MouseEvent e) {
        l.setText("Mouse Clicked");
    }
    public void mouseEntered(MouseEvent e) {
        l.setText("Mouse Entered");
    }
    public void mouseExited(MouseEvent e) {
        l.setText("Mouse Exited");
    }
    public void mousePressed(MouseEvent e) {
        l.setText("Mouse Pressed");
    }
    public void mouseReleased(MouseEvent e) {
        l.setText("Mouse Released");
    }
    public static void main(String[] args) {
        new Mouse();
    }
}
