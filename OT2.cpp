#include<iostream>
using namespace std;
class TG
{
    private:
    float a, b, c;

    public:
    // phuong thuc khoi tao khong doi
    TG()
    {
        a = 0;
        b = 0;
        c = 0;
    }

    // phuong thuc khoi tao co doi
    TG(float x, float y, float z)
    {
        a = x;
        b = y;
        c = z;
    }
};