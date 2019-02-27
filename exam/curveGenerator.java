import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintStream;

public class curveGenerator {
    public static void main(String[] args) throws java.io.FileNotFoundException {

        // open file
        File f = new File("C:\\Users\\Yiwen Lu\\Desktop\\curve.wrl");
        FileOutputStream fout = new FileOutputStream(f);
        PrintStream out = new PrintStream(fout);

        // write out the VRML2 header - this is necessary so that viewers
        // such as FreeWRL, BS Contact and meshlab are able to properly
        // identify and treat the format as VRML 2.0, as opposed to the
        // older VRML (1.0) format

        out.println("#VRML 2.0 utf8");

        double R = 9.0, r = 1.0, a = 4.0;
        double pi = 3.1415926;
        // write geometry
        for (double t = 0.0; t <= pi * 18; t = t + 0.05) {
            double x = (R + r) * Math.cos((r / R) * t) - a * Math.cos((1 + r / R) * t);
            double y = (R + r) * Math.sin((r / R) * t) - a * Math.sin((1 + r / R) * t);
            double z = 0.0;
            //System.out.println(x);
            outputSph(x, y, z, out);
        }// next

        // close file
        out.close();

    }// main()

    public static void outputSph(double x, double y, double z, PrintStream out) {
        out.println("# " + x + "," + y + "," + z);
        out.println("Transform {");
        out.println("  translation " + x + " " + y + " " + z);
        out.println("    children [");

        outputShape(0.1, out);

        out.println("    ]"); // children
        out.println("}"); // Transform
    }// outputSph()

    public static void outputShape(double rad, PrintStream out) {
        out.println("      Shape {");

        out.println("        appearance Appearance {");
        out.println("          material Material {}");
        out.println("        }");

        out.println("        geometry Sphere {");
        out.println("          radius " + rad);
        out.println("        }");
        out.println("      }#Shape");
    }// outputShape()
}// class spheres




