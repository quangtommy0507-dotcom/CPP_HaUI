#include<iostream>
using namespace std;
class Vector3D
{
    private:
    float x, y, z;
    public:
    Vector3D()
    {
        x=y=z=0;
    }

    Vector3D(float a, float b, float c)
    {
        x=a; y=b; z=c;
    }

    friend istream& operator>>(istream&a, Vector3D &b)
    {
        cout<<"Nhap x: "; a>>b.x;
        cout<<"Nhap y: "; a>>b.y;
        cout<<"Nhap z: "; a>>b.z;

        return a;
    }

    friend ostream& operator<<(ostream&a, Vector3D b)
    {
        a<<"("<<b.x<<","<<b.y<<","<<b.z<<")"<<endl;

        return a;
    }

    Vector3D operator+(Vector3D b)
    {
        Vector3D kq;
        kq.x = x + b.x;
        kq.y = y + b.y;
        kq.z = z + b.z;

        return kq;
    }

    Vector3D operator-(Vector3D b)
    {
        Vector3D kq;
        kq.x = x - b.x;
        kq.y = y - b.y;
        kq.z = z - b.z;

        return kq;
    }

    Vector3D operator-()
    {
        Vector3D kq;
        kq.x = -x;
        kq.y = -y;
        kq.z = -z;
        return kq;
    }

    float operator*(Vector3D b)
    {
        return x * b.x + y * b.y + z * b.z;
    }
};

int main()
{
    Vector3D A, B(2, 4, 5);
    cout<<"Nhap Vector A: "; cin>>A;
    cout<<"Vector A= "<<A<<endl;
    cout<<"Vector B= "<<B<<endl;
    cout<<"Tong A + B: "<<(A+B)<<endl;
    cout<<"Hieu A - B: "<<(A-B)<<endl;
    cout<<"Vector doi cua A: "<<(-A)<<endl;
    cout<<"Tich vo huong cua A va B: "<<(A*B)<<endl;
}