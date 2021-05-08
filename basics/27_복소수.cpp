#include <iostream>
#include <cmath>
using namespace std;
enum COMPLEX_PART {RE, IM};

class Complex {
     double re, im;
     double norm() const { return sqrt(re*re + im*im); }
  public:
     Complex(double re=0, double im=0) : re(re), im(im) {}
     Complex(const Complex& c){ re=c.re; im=c.im;}
     Complex& operator=(const Complex& c);
     //Complex operator+(const Complex& c){Complex tmp(this->re+c.re, this->im+c.im); return tmp;}
     //friend Complex operator+(Complex lhs, const Complex& c);
     Complex operator-(){return Complex(-(this->re), -(this->im));}
friend Complex operator-(Complex lhs, const Complex& c);
     Complex operator*(double a);
friend Complex operator*(double a, const Complex& c);
friend Complex operator*(Complex lhs, const Complex& c);
     Complex operator~();

     Complex operator+(double a); 
friend Complex operator+(double a,const Complex& c); 

     Complex operator-(double a); 
friend Complex operator-(double a,const Complex& c); 
     Complex& operator++();
     Complex operator++(int);
     Complex& operator--();
     Complex operator--(int);
     Complex& operator+=(const Complex& c){re+=c.re; im+=c.im; return *this;}
     Complex& operator-=(const Complex& c){re-=c.re; im-=c.im; return *this;}
     Complex& operator*=(const Complex& c){int tmp_re=re*c.re - im*c.im; im=re*c.im + im*c.re; re=tmp_re; return *this;}

     double& operator[](COMPLEX_PART idx){ return idx?(*this).im : (*this).re;}
const double& operator[](COMPLEX_PART idx) const{ return (*this)[idx];}

    
friend bool operator==(const Complex& c1, const Complex& c2){
    return (c1.re==c2.re && c1.im==c2.im);
}
friend bool operator<(const Complex& c1, const Complex& c2){
    return c1.norm() < c2.norm();
}
friend bool operator>(const Complex& c1, const Complex& c2);
friend bool operator<=(const Complex& c1, const Complex& c2);
friend bool operator>=(const Complex& c1, const Complex& c2);

    
friend ostream& operator<< (ostream& os, const Complex& c);
friend istream& operator>> (istream& is, Complex& c);
};

Complex Complex::operator+(double a){
    return Complex(this->re+a, this->im);
}
Complex operator+(double a, const Complex& c){
    return Complex(a+c.re, c.im);
}
Complex Complex::operator-(double a){
    return Complex(this->re-a, this->im);
}    
Complex operator-(double a, const Complex& c){
    return Complex(a-c.re, -c.im);
}

istream& operator>> (istream& is, Complex& c){
  is >> c.re >> c.im;
  return is;
}
ostream& operator<< (ostream& os, const Complex& c){
  os << c.re <<( (c.im>=0.0)? '+':'-' ) << abs(c.im) << "i " ;
  return os;
}

Complex& Complex::operator=(const Complex& c){
    this->re = c.re;
    this->im = c.im;
    return *this;
}
Complex operator+(Complex lhs, const Complex& c){
    lhs+=c;
    return lhs;
}
Complex operator-(Complex lhs, const Complex& c){
    lhs-=c;
    return lhs;
}
Complex Complex::operator*(double a){
    Complex tmp(*this);
    tmp*=Complex(a);
    return tmp;
}
Complex operator*(double a, const Complex& c){
    return Complex(a)*=c;
    //return ;
}
Complex operator*(Complex lhs, const Complex& c){
    return lhs*=c;
}

Complex Complex::operator~(){
    return Complex(this->re, -(this->im));
}
Complex& Complex::operator++(){
    this->re = re+1;
    return *this;
}
Complex Complex::operator++(int){
    Complex tmp(*this);
    operator++();
    return tmp;
}
Complex& Complex::operator--(){
    this->re = re-1;
    return *this;
}
Complex Complex::operator--(int){
    Complex tmp(*this);
    operator--();
    return tmp;    
}


bool operator!=(const Complex& c1, const Complex& c2){
    return !(c1==c2);
}
bool operator>(const Complex& c1, const Complex& c2){
    return c2.norm() < c1.norm();
}
bool operator<=(const Complex& c1, const Complex& c2){
    return !(c1.norm()>c2.norm());
}
bool operator>=(const Complex& c1, const Complex& c2){
    return !(c1.norm()<c2.norm());
}

int main(void) {
    Complex c1, c2, c3, c4;
    Complex c5, c6, c7, c8, c9;
    cin >> c1 >> c2 >> c3 >> c4;

    cout << c1 << " " << c2 << " " << c3 << " " << c4 << endl;
    cout << (2 + c1 + 3)+ (2 - c2 - 3) * (2 * c3 * 3) - ( 2 * c4 - 3) << endl;

    c5 = c6 = c7 = c8 = c1;
    cout << (c5 == c2) << " " << (c5 != c2) << endl;
    cout << (c5 > c2) << " " << (c5 >= c2) << " " << (c5 < c2) << " " << (c5 <= c2) << endl;
    cout << (c5 == c6) << " " << (c5 != c6) << endl;
    cout << (c5 > c6) << " " << (c5 >= c6) << " " << (c5 < c6) << " " << (c5 <= c6) << endl;
    c5 += c2;
    c6 -= c3;
    c7 *= c4;
    c8 = c2[RE];
    c9 = c3[IM];
    cout << c5 << " " << c6 << " " << c7 << " " << c8 << " " << c9 << endl;

    c7 = -c6;
    c8 = (++c7) * 2;
    c9 = 2 * (c7++);
    cout << c7 << " " << c8 << " " << c9 << endl;

    c7 = ~c6;
    c8 = (++c7) * 2;
    c9 = 2 * (c7++);
    cout << c7 << " " << c8 << " " << c9 << endl;
}
