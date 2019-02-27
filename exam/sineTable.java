import java.util.ArrayList;

public class sineTable {
    public ArrayList<Double> sineValues = new ArrayList<>();
    int angle;

    sineTable(int angle) {
        this.angle = angle;
        double pi = 3.1415926;
        for (int i = 0; i <= 360; i = i + 10) {
            sineValues.add(Math.sin(i * pi / 180));
        }
    }

    public String toString() {
        for (int i = 0; i <= 360; i = i + 10) {
            return (i + ":" + sineValues.get(i / 10));
        }
    }

    public double calcValue(int angle) {
        if (angle % 10 == 0) {
            return sineValues.get(angle / 10);
        } else {
            double l = sineValues.get(angle - angle % 10);
            double u = sineValues.get((angle - angle % 10) + 1);
            double f = (angle % 10) / 10.0;
            double interp = l + f * (u - l);
        }

    }

}

