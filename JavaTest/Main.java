class Point {
    private int x, y;

    Point(int a, int b) {
        x = a;
        y = b;
    }

    @Override
    public String toString() {
        return "(" + String.valueOf(x) + "," + String.valueOf(y) + ")";
    }

    public double distance(Point other) {
        return Math.sqrt((other.x-x)*(other.x-x)+(other.y-y)*(other.y-y));
    }
}

class Main {
    public static void main(String[] args) {
        System.out.println("Hello World!");

        Point p = new Point(3, 4);
        System.out.println(p);

        Point q = new Point(6,8);
        System.out.println("The distance between "+p+" and "+q+" is:"+p.distance(q));
    }
}
