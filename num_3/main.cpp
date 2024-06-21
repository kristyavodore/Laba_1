#include <iostream>
#include <cmath>
using namespace std;

class Complex{
    double a,b;

public:
Complex(double deist, double mnim);
Complex():a(0), b(0){};
Complex operator+(Complex const &ob)const;
Complex operator-(Complex const &ob)const;
Complex operator/(Complex const &ob)const;
double Module_2()const;
void Module_1()const;
double Argument()const;
void Print()const;
double get_a(){return a;}
double get_b(){return b;}
void set_a(double value_a){
        a=value_a;
    }
void set_b(double value_b){
        b=value_b;
    }
};

Complex::Complex(double deist, double mnim){
        a=deist;
        b=mnim;
}

Complex Complex::operator+(Complex const &ob)const{
        Complex result(0,0);
        result.a=a+ob.a;
        result.b=b+ob.b;
        return result;
}

Complex Complex::operator-(Complex const &ob)const{
        Complex result;
        result.a=a-ob.a;
        result.b=b-ob.b;
        return result;
}

Complex Complex::operator/(Complex const &ob)const{
        Complex result;
        result.a = (a*ob.a + b*ob.b)/pow(ob.a, 2)+pow(ob.a, 2);
        result.b = (ob.a*b - a*ob.b)/pow(ob.a, 2)+pow(ob.b, 2);
        return result;
    }

double Complex::Module_2()const{
        double i=pow(a, 2)+pow(b, 2);
        return sqrt(i);
}

void Complex::Module_1()const{
        double i=pow(a, 2)+pow(b, 2);
        cout<<sqrt(i)<<endl;
}

double Complex::Argument()const{
        return atan(a/b);
}

void Complex::Print()const{
        cout<<a<<endl;
        cout<<b<<endl;
}


int main(){
    Complex n1(3, 4);
    Complex n2(1.4, 1.5);
    Complex n3(1.6, 1.7);
    Complex n4(0, 0);
    Complex n5;
    n4=n1+n1;
    n4.Print();

    n1.Module_1();
    cout<<n1.Module_2()<<endl;
    cout<<n1.Argument()<<endl;

    n5 = n1 + n2;
    n5.Print();

}