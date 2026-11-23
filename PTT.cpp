#include<iostream>
#include<algorithm>
using namespace std;
class Mang
{
    private:
    float Value[100];
    int n;

    public:
    friend istream& operator>>(istream&x, Mang&y)
    {
        do
        {
            cout<<"Nhap so luong mang: "; x>>y.n;
        } while (y.n<=0|| y.n>100);
        for(int i=0;i<y.n;i++)
        {
            cout<<"a["<<i+1<<"]="; x>>y.Value[i];
        }
        return x;

    }

    friend ostream& operator<<(ostream&x, Mang y)
    {
        for(int i=0; i<y.n;i++)
        {
            x<<"a["<<i+1<<"]="<<y.Value[i]<<endl;
        }

        return x;

    }

    void operator++()
    {
        for(int i=0;i<n;i++)
        {
            for(int j = i + 1;j < n; j++)
            {
                if(Value[i]>Value[j])
                {
                    swap(Value[i], Value[j]);
                }
            }
        }
    }
    
    void operator--()
    {
        for(int i=0; i<n;i++)
        {
            for(int j = i + 1; j<n;j++)
            {
                if(Value[i]<Value[j])
                {
                    swap(Value[i], Value[j]);
                }
            }
        }
    }

};

int main()
{
    Mang A;
    cout<<"Nhap mang A \n"; cin>>A;
    cout<<"Mang A: "<<A<<endl;
    (++A);
    cout<<"Mang A sau khi sap xep tang dan: "<<endl;
    cout<<A<<endl;

    (--A);
    cout<<"Mang A sau khi sap xep giam dan: "<<endl;
    cout<<A<<endl;
    
}