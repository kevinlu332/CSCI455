import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.*;
//IDE: IntelliJ
//done by Yiwen Lu, USCID 7759761380

public class Mandelbrot { //for the fractal calculation

    private int[][] xtable; //2D array
    private int xRes, yRes;
    private double cxMin, cxMax, cyMin, cyMax;
    ColorList colors;

    public Mandelbrot(int xRes, int yRes, double cxMin, double cxMax, double cyMin, double cyMax) { //constructor
        this.xRes = xRes;
        this.yRes = yRes;
        this.cxMin = cxMin;
        this.cxMax = cxMax;
        this.cyMin = cyMin;
        this.cyMax = cyMax;
        colors = new ColorList();
        xtable = new int[xRes][yRes];
        for (int y = 0; y < yRes; y++) {
            for (int x = 0; x < xRes; x++) {
                ComplexNumber c = new ComplexNumber((cxMin + (double) x / (xRes - 1) * (cxMax - cxMin)), (cyMin + (double) y / (yRes - 1) * (cyMax - cyMin))); //[maps x to cxmin..cxmax][maps y to cymin..cymax]
                ComplexNumber z = new ComplexNumber(0, 0);  //initialize
                int maxIter = 255, iter = 0;
                while (iter < maxIter && z.abs() < 2) {
                    z = z.squared().add(c);
                    iter++;
                } //end_while: either iter has exceeded maxIter, or abs(z) has exceeded 2
                if (z.abs() >= 2) {
                    xtable[x][y] = iter;
                } else xtable[x][y] = 0;

            }
        }
        //fill the 'colors' ColorList object with colors
    }

    public static void setPixel(Graphics g, int x, int y, int red, int grn, int blu) { //to set RGB of a single pixel
        Color c = new Color(red, grn, blu);
        g.setColor(c);
        g.drawLine(x, y, x, y);
    }// setPixel()

    public void displayFractal(Graphics g) { //to render the fractal pixel-by-pixel on the screen
        for (int y = 0; y < yRes; y++) {
            for (int x = 0; x < xRes; x++) {

                Color c = colors.colList.get(xtable[x][y]);
                setPixel(g, x, y, c.getRed(), c.getGreen(), c.getBlue());
            }
        }
    }

    public void saveFractal(String fileName) throws IOException { // to output the fractal as a .ppm image

        File f = new File("C:\\Users\\Yiwen Lu\\Desktop\\" + fileName);
        FileOutputStream fout = new FileOutputStream(f);

        PrintStream out = new PrintStream(fout);
        out.println("P3\r\n" + xRes + " " + yRes + "\r\n255\r\n");
        // pixel data
        for (int y = 0; y < yRes; y++) {
            for (int x = 0; x < xRes; x++) {
                Color c = colors.colList.get(xtable[x][y]);
                out.println(c.getRed() + " " + c.getGreen() + " " + c.getBlue());
            }// next column
        }// next row
        // all done!
        out.close();
        ////////above: to output ppm image/////////////////////////////////
    }

    public static void main(String[] args) throws IOException {

        JFrame frame = new JFrame(); // our outer window
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // grid of subcomponents, here, a 1x1 grid (just one subcomponent)Graphics
        GridLayout gl = new GridLayout(1, 1);
        gl.setVgap(0);
        gl.setHgap(0);
        frame.setLayout(gl);
        JPanel p;

        // #1
        p = new JPanel();
        p.setPreferredSize(new Dimension(640, 480)); // set the dimensions of our panel
        frame.add(p); // pop the panel into the frame
        BufferedImage pb1 = new BufferedImage(640, 480, BufferedImage.TYPE_INT_RGB);
        JLabel pi1 = new JLabel(new ImageIcon(pb1));
        pi1.setPreferredSize(new Dimension(640, 480));
        pi1.setBorder(BorderFactory.createEmptyBorder(0, 0, 0, 0));
        p.add(pi1);
        Graphics g1 = pb1.createGraphics();

        Mandelbrot mand = new Mandelbrot(640, 480, -2, 1, -1, 1);
        mand.displayFractal(g1);
        mand.saveFractal("ColoredFractral.ppm");

        frame.setVisible(true); // show to the world :)
        frame.setResizable(false);
        frame.pack(); // arrange all the panels
    }
}


