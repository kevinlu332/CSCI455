import static java.lang.Math.pow;
import static java.lang.Math.sqrt;
//IDE: IntelliJ
//done by Yiwen Lu, USCID 7759761380

public class ComplexNumber { //for representing a complex number, and doing ops on it

    private double real;
    private double imag;

    ComplexNumber(double i, double j) //constructor
    {
        real = i;
        imag = j;
    }

    ComplexNumber add(ComplexNumber c2) //add complex numbers
    {
        double a, b;
        a = this.real + c2.real;
        b = this.imag + c2.imag;
        return new ComplexNumber(a, b);
    }

    ComplexNumber squared() //square a complex number
    {
        double a, b, temp = real;
        a = (pow(real, 2) - pow(imag, 2));
        b = (2 * temp * imag);
        return new ComplexNumber(a, b);

    }

    double abs() // abs a complex number
    {
        double sol = sqrt(real * real + imag * imag);
        return sol;
    }
}
