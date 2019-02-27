import javax.swing.*;
import java.awt.*;
////IDE: IntelliJ
//done by Yiwen Lu, USCID 7759761380

public class ColorStrips {
    public static void main(String[] args) {
        ColorList cols = new ColorList(); // use of ColorList.java
        JFrame frame = new JFrame(); //create an outer frame window
        frame.setLayout(new GridLayout(256, 1)); //256 rows and 1 column

        for (int i = 0; i < 256; i++) {
            JPanel p = new JPanel();  //create a panel
            Color c = cols.colList.get(i); //get the color at ArrayList location of i
            p.setBackground(c); //set the color as the background
            p.setPreferredSize(new Dimension(100, 4)); //set the size of 100x4
            frame.add(p);// add the created panel to the frame
        }

        frame.pack(); // arrange al the panels
        frame.setVisible(true); //set visible to users
    }


}
