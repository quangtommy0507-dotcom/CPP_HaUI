#include<iostream>
using namespace std;
class TG
{
    private:
    float a, b, c;

    public:
   
    //phuong thuc toan tu chu vi TG
    float operator+()
    {
        return (a+b+c);
    }

    // phuogn thuc toan tu nhap

    friend istream& operator>>(istream&x, TG&y)
    {
        cout<<"\nNhap canh a: "; x>>y.a;
        cout<<"Nhap canh b: "; x>>y.b;
        cout<<"Nhap canh c: "; x>>y.c;
        return x;
    }
    // phuong thuc toan tu xuat

    friend ostream& operator<<(ostream&x, TG y)
    {
        x<<"a= "<<y.a<<" b= "<<y.b<<" c= "<<y.c<<endl;
        return x;
    }

};

int main()
{
    TG P, Q;
    cout<<"Nhap thong tin TG P: "; cin>>P;
    cout<<"Nhap thong tin TG Q: "; cin>>Q;
    cout<<"Thong tin TG P: "<<P<<endl;
    cout<<"Thong tin TG Q: "<<Q<<endl;
    cout<<"Chu vi TG P: "<<(+P)<<endl;
    cout<<"Chu vi TG Q: "<<(+Q)<<endl;

}