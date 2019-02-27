import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.io.IOException;
import java.util.Random;

public class RandPPM
{

    static Random rng = new Random();

    public static Pixel genRandPixel() {
        Pixel p = new Pixel(); // RGB=0,0,0
        // note that nextInt(256) gives us 0..255
        p.r = rng.nextInt(256);
        p.g = rng.nextInt(256);
        p.b = rng.nextInt(256);
        return p;
    }// genRandPixel()

    public static void main(String[] args) throws IOException {

        int xRes=256, yRes=256;


        File f = new File("C:\\Users\\Yiwen Lu\\Desktop\\rand.ppm");
        FileOutputStream fout = new FileOutputStream(f);
        PrintStream out = new PrintStream(fout);

        // header
        out.println("P3\r\n" + xRes + " " + yRes + "\r\n255\r\n"); // P2 xres yres maxval

        // pixel data: RGB triplets, each value 0..255
        for(int y=0;y<yRes;y++) {
            for(int x=0;x<xRes;x++) {

                Pixel pxl = genRandPixel();
                out.println(pxl.r + " " + pxl.g + " " + pxl.b);

            }// next x
        }// next y

        // done, close
        out.close();
    }// main()

    // static inner class
    private static class Pixel {
        int r=0, g=0, b=0;
    }// class Pixel

}// class RandPPM


