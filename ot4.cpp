#include<iostream>
using namespace std;
class Mi
{
    private:
        char maMay[30], HSX[30];
        int SL;
        float donGia;
    public:
    Mi(const char * ma, const char * B, int soluong, float gia)
    {
        strcpy(maMay, ma);
        strcpy(HSX, B);
        SL = soluong;
        giaBan = gia;
    }
    
    float thanhtien()
    {
        return donGia * SL;
    }

    friend istream& operator>>(istream&x, Mi &y)
    {
        cout<<"Nhap ma may: "; x.getline(y.maMay, 30);
        cout<<"Nhap hang san xuat: "; x.getline(y.HSX, 30);
        
        do
        {
            cout<<"Nhap so luong: "; x>>y.SL;
        cout<<"Nhap don gia: "; x>>y.donGia;
        }while(y.SL<=0||y.donGia<=0);
        
        
        return x;

    }

    friend ostream& operator<<(ostream&x, Mi y)
    {
        x<<"Ma may: "<<y.maMay<<endl;
        x<<"Hang san xuat: "<<y.HSX<<endl;
         x<<"SL: "<<y.SL<<endl;
        x<<"Don gia: "<<y.donGia<<endl;
        

        return x;
    }

    Mi operator+(Mi y)
    {
        return thanhtien() + y.thanhtien();
    }

    bool operator<(Mi y)
    {
        if(strcmp(donGia < y.donGia))
        {
            return true;
        } 
        else return false;
    }


};

int main()
{
    Mi A, B("001", "Canon", 10, 500);
    cout<<"Nhap thong tin May in A\n";
    cin>>A;
    cout<<"Thong tin may in A: "<<A<<endl;
    cout<<"Thong tin may in B: "<<B<<endl;

    cout<<"Tong thanhtien may in A + B: "<<(A+B)<<endl;
    if(A<B)
    {
        cout<<"Gia tien may in A nho hon gia tien may in B !";
    }
    else if(B<A)
    {
        cout<<"Gia tien may in A lon hon gia tien may in B !";
    }
    else cout<<"Gia tien may in A bang gia tien may in B !";