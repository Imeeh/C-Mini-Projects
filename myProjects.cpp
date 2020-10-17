///Some Personal C++ Sets of Codes I put together

#include<iostream>
#include<cmath>
using namespace std;

const double PI = 3.1415126536;

int t[100000];

//This program reads an array and outputs to the console the positions of the smallest value
void f0(int n) {
    int i,min;
    for(i=0;i<n;i++) {
        cin>>t[i];
    }
    min=t[0];
    for(i=1;i<n;i++) {

        if(t[i]<min) {
            min=t[i];
        }
    }

    for(i=0;i<n;i++) {
        if(t[i]==min) {
            cout<<i+1 << " ";
        }
    }
    cout << endl;
}

// This program will read, sorts and print an array of numbers
void f1(int n) {
    int i,j,m;
    for(i=0;i<n;i++) {
        cin>>t[i];
    }
    for(i=0;i<n-1;i++) {
        for(j=i+1;j<n;j++) {
            if(t[i]<t[j]) {
                m=t[i];
                t[i]=t[j];
                t[j]=m;
            }
        }
    }
    for(i=0;i<n;i++) {
        cout<<t[i]<<" ";
    }
    cout<<endl;

}


/// The program to find the "Euclidean Distance"
void f2(int n) {
    int i,sum=0;
    for(i=0;i<n;i++) {
        cin>>t[i];
    }
    for(i=0;i<n;i++) {
        sum+=t[i]*t[i];
    }
    cout<<(int)sqrt(sum)<<endl;
}


/// This program to find the standard deviation
void f3(int n) {
    long double y[10000];
    int i;
    long double mean, sum = 0, theta = 0;
    for(i=0;i<n;i++) {
        cin>>y[i];
    }
    for(i=0;i<n;i++) {
        sum+=y[i];
    }
    mean = (double) sum / n;
    for(int i =0; i<n; i++) {
        double deviation = y[i] - mean;
        theta += deviation * deviation;
    }
    cout<<(int)sqrt(theta/n)<<endl;
}

///The program to find reverse array and print
void f4(int n) {
    int i;
    for(i=0;i<n;i++) {
        cin>>t[i];
    }
    for(i=0;i<n/2;i++) {
        int temp = t[i];
        t[i] = t[n - i - 1];
        t[n-i-1] = temp;
    }
    for(i=0;i<n;i++) {
        cout<<t[i]<<" ";
    }
}

int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }
    if (n <= 3) {
        return 1;
    }

    if (n % 2 == 0 || n % 3 == 0) {
        return 0;
    }

    for (int i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0)  {
            return 0;
        }
    }
    return 1;
}

/// The program to check prime numbers
void f5(int n) {
    int i, j;
    for(i=0;i<n;i++) {
        cin>>t[i];
    }
    for(i=0;i<n;i++) {
        int number = t[i];
        cout<<isPrime(number) << " ";
    }
    cout<<endl;
}

struct Point {
    double x; double y;
};

///The program that solved the area of a complex polygon
void f6(int n)
{
    struct Point points[100];
    int i;
    double sum = 0;
    for(i=0;i<n/2;i++) {
        double x,y;
        cin>>x>>y;
        points[i].x = x;
        points[i].y = y;
    }

    int j = n / 2 -1;
    for(i = 0; i<n/2; i++) {
        sum+= (points[i].x + points[j].x) * (points[j].y - points[i].y);
        j = i;
    }

    /// The program to derive the absolute value
    if(sum < 0) {
        sum*=-1;
    }
    cout<<floor(sum/2)<<endl;
}

struct Complex {
    int real;
    int imaginary;

    void print();
    double getValue();
    int lessThan(Complex other);
};

int Complex :: lessThan(Complex other) {
    if(real < other.real) {
        return 1;
    } else if (real > other.real) {
        return 0;
    } else {
        if(imaginary < other.imaginary) {
            return 1;
        }
        return 0;
    }
}

void Complex::print() {
    if(real == 0 && imaginary == 0) {
        cout<<0;
    } else if(real != 0 && imaginary == 0) {
        cout<<real;
    } else if(real == 0 && imaginary != 0) {
        if(imaginary == 1) {
            cout<<"i";
        }
        else if(imaginary == -1) {
            cout<<"-i";
        }
        else {
            cout<<imaginary<<"i";
        }

    } else {
        //real != 0 and imaginary !=0
        cout<<real;
        if(imaginary == 1) {
            cout<< "+i";
        } else if (imaginary == -1) {
            cout<<"-i";
        } else {
            if(imaginary > 0) {
                cout<<"+"<<imaginary;
            } else {
                cout<<imaginary;
            }
            cout<<"i";
        }
    }
}

double Complex::getValue() {
    return sqrt(real* real + imaginary * imaginary);
}


void compareAndPrintComplexObjects(Complex c1, Complex c2, Complex c3) {

    Complex c[3];
    if(c1.lessThan(c2) && c1.lessThan(c3)) {
        c[0] = c1;
        if(c2.lessThan(c3)) {
            c[1] = c2;
            c[2] = c3;
        } else {
            c[1] = c3;
            c[2] = c2;
        }
    } else if (c2.lessThan(c1) && c2.lessThan(c3)) {
        c[0] = c2;
        if(c1.lessThan(c3)) {
            c[1] = c1;
            c[2] = c3;
        } else {
            c[1] = c3;
            c[2] = c1;
        }

    } else {
        c[0] = c3;
        if(c1.lessThan(c1)) {
            c[1] = c1;
            c[2] = c2;
        } else {
            c[1] = c2;
            c[2] = c1;
        }
    }

    for(int i = 0; i<3; i++) {
        c[i].print();
        cout<<" ";
    }
    cout<<endl;
}

void solveSquareEquation(double a, double b, double c) {
    if (a == 0) {
        cout<<b/c * - 1;
    } else {
        double discriminant = b*b - 4 * a * c;
        if(discriminant == 0) {
            cout<< b/(double)(-2*a) <<endl;
        } else if (discriminant > 0) {
            double x1 = (sqrt(discriminant) - b) / (double)(2*a);
            double x2 = (sqrt(discriminant) + b) / (double)(-2 * a);
            if(x1 < x2) {
                cout << floor(x1) <<" " << floor(x2) <<endl;
            } else {
                cout << floor(x2) << " " << floor(x1) <<endl;
            }
        } else {
            int real = floor(b/ (double)(-2 * a));
            double doubleImaginary = sqrt(discriminant * -1)/(2*a);
            int imaginary1 = floor(doubleImaginary);
            int imaginary2 = floor(-doubleImaginary);

            Complex c1;
            Complex c2;
            c1.imaginary = imaginary1;
            c1.real = real;
            c2.real = real;
            c2.imaginary = imaginary2;
            c1.print();
            cout<<" ";
            c2.print();
            cout<<endl;
        }
    }
}

void solveCubicEquation(double a, double b, double c, double d) {
    Complex c1, c2, c3;
    if(d == 0) {
        c3.real = 0;
        c3.imaginary = 0;
        int x3 = 0;
        if (a == 0) {
            int x2 = floor(b/c * -1);
            if(x2 > x3) {
                cout<<x2 <<" "<<x3<<endl;
            }else {
                cout<<x3 <<" " <<x2<<endl;
            }
        } else {
            double discriminant = b*b - 4 * a * c;
            if(discriminant == 0) {
                int x2 = floor(b/(double) -2*a);
                if(x2 > x3) {
                    cout<<x2 <<" "<<x3<<endl;
                }else {
                    cout<<x3 <<" "<<x2<<endl;
                }
            } else if (discriminant > 0) {
                double x1 = (sqrt(discriminant) - b) / (double)(2*a);
                double x2 = (-sqrt(discriminant) - b) / (double)(2 * a);
                c1.real = floor(x1);
                c2.real = floor(x2);
                c1.imaginary = c2.imaginary = 0;
                compareAndPrintComplexObjects(c1, c2, c3);
            } else {
                int real = floor(b/ (double)(-2 * a));
                double imaginary = sqrt(discriminant * -1)/(2*a);

                c1.real = real;
                c1.imaginary = floor(imaginary);
                c2.real = real;
                c2.imaginary = floor(-imaginary);
                compareAndPrintComplexObjects(c1, c2, c3);
            }
        }
    } else {
        b/=a;
        c/=a;
        d/=a;
        double q = (3.0*c - (b*b))/9.0;
        double r = -(27.0 * d) + b*(9.0*c - 2.0*(b*b));
        r/=54.0;
        double disc = q*q*q + r*r;
        double term1 = b/3.0;
        double s;
        double t;
        double x1, x2, x3, r13;
        Complex c1;
        Complex c2;
        Complex c3;

        if(disc > 0) {
            ///one real value and two complex values

            s = r + sqrt(disc);
            s = ((s < 0) ? -pow(-s, (1.0/3.0)) : pow(s, (1.0/3.0)));
            t = r - sqrt(disc);
            t = ((t < 0) ? -pow(-t, (1.0/3.0)) : pow(t, (1.0/3.0)));
            x1 = -term1 + s + t;
            term1 += (s + t)/2.0;
            int real = floor(-term1);
            term1 = sqrt(3.0)*(-t + s)/2;
            c1.imaginary = floor(term1);
            c1.real = real;
            c2.real = real;
            c2.imaginary = floor(-term1);
            c3.real = floor(x1);
            c3.imaginary = 0;

        } else if (disc == 0) {
            ///all roots are real and at least two are equal

            r13 = ((r < 0) ? -pow(-r,(1.0/3.0)) : pow(r,(1.0/3.0)));
            x1 = -term1 + 2.0*r13;
            x3 = x2 = -(r13 + term1);
            c1.real = floor(x1);
            c2.real = floor(x2);
            c3.real = floor(x3);
            c1.imaginary = c2.imaginary = c3.imaginary = 0;
        } else {
            //disc < 0, all roots are real
            q = -q;
            double dum1 = q*q*q;
            dum1 = acos(r/sqrt(dum1));
            r13 = 2.0*sqrt(q);
            x1 = -term1 + r13*cos(dum1/3.0);
            x2 = -term1 + r13*cos((dum1 + 2.0 * 3.1415126536)/3.0);
            x3 = -term1 + r13*cos((dum1 + 4.0 * 3.1415126536)/3.0);
            c1.real = floor(x1);
            c2.real = floor(x2);
            c3.real = floor(x3);
            c1.imaginary = c2.imaginary = c3.imaginary = 0;
        }
        compareAndPrintComplexObjects(c1, c2, c3);
    }

}

///The program to solve the square or cubic root
void f7(int n) {
    int i;
    double y[10000];
    for(i = 0; i<n; i++) {
        cin>>y[i];
    }

    if(y[0] == 0) {
        solveSquareEquation(y[1], y[2], y[3]);
    } else {
        solveCubicEquation(y[0], y[1], y[2], y[3]);
    }
}

/// The program to find the value of n(n+1)^2
void f8(int n)
{
    int i, j;
    for(i = 0; i<n; i++) {
        cin>>t[i];
    }
    for(i = 0; i<n; i++) {
        unsigned long long sum = 0;
        int number = t[i];
        for(j = 1; j<=number; j++) {
            sum += j* (j+1) * (j+1);
        }
        cout<<sum<<" ";
    }
    cout<<endl;
}


void countNumberOfOnes(unsigned long long number) {
    int count = 0;
    while(number > 0) {
        if(number %2 == 1) {
            count++;
        }
        number/=2;
    }
    cout<<count<<" ";
}

///count the number of ones in a binary number
void f9(int n)
{
    int i;
    unsigned long long numbers[10000];

    for(i=0;i<n;i++) {
        cin>>numbers[i];
    }
    for(i=0;i<n;i++) {
        countNumberOfOnes(numbers[i]);
    }
    cout<<endl;
}

int main(){
    int subprogram, n;

    while(cin >> subprogram >> n) {
        switch (subprogram){
            case 0: {
                f0(n);
                break;
            }
            case 1: {
                f1(n);
                break;
            }
            case 2: {
                f2(n);
                break;
            }
            case 3: {
                f3(n);
                break;
            }
            case 4: {
                f4(n);
                break;
            }
            case 5: {
                f5(n);
                break;
            }
            case 6: {
                f6(n);
                break;
            }
            case 7: {
                f7(n);
                break;
            }
            case 8: {
                f8(n);
                break;
            }
            case 9: {
                f9(n);
                break;
            }
        }
    };
    return 0;
}
