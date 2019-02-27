import java.awt.Color;
import java.awt.GridLayout;
import java.awt.Dimension;
import java.awt.Insets;
import java.awt.image.BufferedImage;
import java.awt.Graphics;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.ImageIcon;
import javax.swing.BorderFactory;
import javax.swing.border.LineBorder;

public class SinglePanel {

    public static void setPixel(Graphics g, int x, int y, int red, int grn, int blu) {
        Color c = new Color(red,grn,blu);
        g.setColor(c);
        g.drawLine(x,y,x,y);
    }// setPixel()

    public static void main(String[] args) {

        ColorList cols = new ColorList(); // generate colors, to use for populating strips below

        JFrame frame = new JFrame(); // our outer window
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // grid of subcomponents, here, a 1x1 grid (just one subcomponent)Graphics
        GridLayout gl = new GridLayout(1,1);
        gl.setVgap(0);gl.setHgap(0);
        frame.setLayout(gl);

        JPanel p;
        Color c;

        // #1
        p = new JPanel();
        c = cols.colList.get(4); // 5th color (no good reason to pick this, just arbitrary!
        p.setBackground(c); // color our panel
        p.setPreferredSize(new Dimension(200,200)); // set the dimensions of our panel
        frame.add(p); // pop the panel into the frame
        BufferedImage pb1 = new BufferedImage(200,200,BufferedImage.TYPE_INT_RGB);
        JLabel pi1 = new JLabel(new ImageIcon(pb1));
        pi1.setPreferredSize(new Dimension(200,200));
        pi1.setBorder(BorderFactory.createEmptyBorder(0, 0, 0, 0));
        p.add(pi1);
        Graphics g1 = pb1.createGraphics();
        for(int i=0;i<200;i++) {
            for(int j=0;j<200;j++) {
                if((i+j)%20==0)
                    setPixel(g1,j,i,255,0,0);
                else
                    setPixel(g1,j,i,0,255,0);
            }
        }

        // can add #2, #3 etc - be sure to specify the total count in the GridLayout() constructor above
        // [eg. you can specify GridLayout(2,2) and add #2, #3 and #4 below, to create a 2x2 grid of JPanels]

        // all done
        frame.setVisible(true); // show to the world :)
        frame.setResizable(false);
        frame.pack(); // arrange all the panels
    }// main()
}// SinglePanel