class Point {
    private int x,y;

    Point(int a, int b) {
        x=a; y=b;
    }

    @Override
    public String toString() {
        return "("+String.valueOf(x)+","+String.valueOf(y)+")";
    }
}

class Main {
    public static void main(String[] args) {
        System.out.println("Hello World!");

        Point p = new Point(3, 4);
        System.out.println(p);
    }
}