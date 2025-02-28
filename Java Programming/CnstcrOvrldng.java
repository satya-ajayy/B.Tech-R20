package JavaLab;
class Box {
    double breadth, length, height;

    Box(double l, double b, double h) {
        length = l;
        breadth = b;
        height = h;
    }

    Box(){
        length = 0;
        breadth = 0;
        height = 0;
    }
    Box(double a){
        length = a;
        breadth = a;
        height = a;
    }
    void printVolume(){
        System.out.print("Volume Of Box is : ");
        System.out.println(length*breadth*height);
    }
}

public class CnstcrOvrldng {
    public static void main(String[] args) {
        Box box1 = new Box();
        Box box2 = new Box(4);
        Box box3 = new Box(1,2,3);
        box1.printVolume();
        box2.printVolume();
        box3.printVolume();
    }
}
