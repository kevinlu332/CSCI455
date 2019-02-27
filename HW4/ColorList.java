import java.awt.*;
import java.util.ArrayList;
import java.util.Random;
//IDE: IntelliJ
//done by Yiwen Lu, USCID 7759761380

public class ColorList { // for creating a randomized color list (ArrayList<Color>) with 256 entries

    public ArrayList<java.awt.Color> colList = new ArrayList<Color>();

    ColorList() {
        Random rng = new Random();
        for (int i = 0; i < 256; i++) { // loop 256 times
            int r = rng.nextInt(255); //get a random number of 0...255
            int g = rng.nextInt(255);
            int b = rng.nextInt(255);
            Color c = new Color(r, g, b); // core line!!!: create a Color c
            colList.add(c); // add c to the ArrayList
        }
    }


}
