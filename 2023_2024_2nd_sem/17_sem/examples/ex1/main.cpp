#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

class Complex {
  private:
    double re; // 5 + 4i
    double im;
  public:
    static size_t count;
    Complex(double num) : re(num), im(num) { count++;}
    Complex(double r, double im) {
      count++;
      this->im = im;
      re = r;
    }
    double getIm() const {
      return im;
    }
    double getRe() const {
      return re;
    }
    friend std::ostream& operator<<(std::ostream& out, const Complex& c);
    Complex operator+(const Complex& c) const {
      return Complex (this->re + c.re, this->im + c.im);
    }
    Complex operator-(const Complex& c) const {
      return Complex (this->re - c.re, this->im - c.im);
    }
    bool operator<(const Complex& c) const {
      return this->re < c.re;
    }
    bool operator>(const Complex& c) const {
      return c.re < this->re;
    }
};
std::ostream& operator<<(std::ostream& out, const Complex& c) {
  out << c.re << '+' << c.im << 'i' << '\n';
  return out;
}
size_t Complex::count = 0;
bool isGreater(const Complex& a, const Complex& b) {
    return (a.getRe() + a.getIm()) > (b.getRe() + b.getIm());
}
int main() {
  Complex c1 (2, 3); // 2 + 3i
  Complex c2 (5);    // 5 + 5i
  Complex c3 = c1 + c2;
  std::cout << c3;
  Complex c4 = c1 - c2;
  std::cout << c4;
  std::cout << "Count " << Complex::count << '\n';
  std::vector<Complex> vec;
  int n = 5;

  for (int i = 0; i < n; ++i) {
    vec.push_back(Complex(rand() % 10, rand() % 10));
  }
  for (auto& complex : vec) {
    std::cout << complex;
  }
  std::cout << '\n';
  //std::sort(vec.begin(), vec.end(), std::less<Complex>()); // <
  std::sort(vec.begin(), vec.end(), std::greater<Complex>()); // >
  for (auto& complex : vec) {
    std::cout << complex;
  }
  std::cout << "Count " << Complex::count << '\n';
  std::sort(vec.begin(), vec.end(), isGreater);
  std::cout << '\n';
  for (auto& complex : vec) {
    std::cout << complex;
  }

  return 0;
}
