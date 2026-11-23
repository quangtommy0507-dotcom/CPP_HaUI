// ============================================================
//  OOP Practices - C++
//  Cac khai niem: Encapsulation, Abstraction, Inheritance,
//  Polymorphism, Composition, Operator Overloading, Template,
//  Smart Pointer, RAII
//  Bien dich: g++ -std=c++17 -Wall -Wextra OOP_Practices.cpp -o oop
// ============================================================

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <stdexcept>
#include <iomanip>

using namespace std;

// ------------------------------------------------------------
// 1. ENCAPSULATION (Dong goi)
//    Du lieu private, chi truy cap qua phuong thuc public.
// ------------------------------------------------------------
class BankAccount {
private:
    string owner_;
    double balance_;

public:
    BankAccount(string owner, double balance = 0.0)
        : owner_(std::move(owner)), balance_(balance) {}

    void deposit(double amount) {
        if (amount <= 0) throw invalid_argument("So tien nap phai > 0");
        balance_ += amount;
    }

    void withdraw(double amount) {
        if (amount <= 0) throw invalid_argument("So tien rut phai > 0");
        if (amount > balance_) throw runtime_error("So du khong du");
        balance_ -= amount;
    }

    double balance() const { return balance_; }
    const string& owner() const { return owner_; }
};

void practiceEncapsulation() {
    cout << "\n=== 1. Encapsulation ===\n";
    BankAccount acc("Tommy", 100);
    acc.deposit(50);
    cout << acc.owner() << " co " << acc.balance() << "\n";
    try {
        acc.withdraw(500);
    } catch (const exception& e) {
        cout << "Loi: " << e.what() << "\n";
    }
}

// ------------------------------------------------------------
// 2. ABSTRACTION + 3. INHERITANCE + 4. POLYMORPHISM
//    Shape la lop truu tuong (abstract class) voi ham thuan ao.
// ------------------------------------------------------------
class Shape {
protected:
    string name_;

public:
    explicit Shape(string name) : name_(std::move(name)) {}
    virtual ~Shape() = default;  // destructor ao: bat buoc khi dung da hinh

    virtual double area() const = 0;       // ham thuan ao
    virtual double perimeter() const = 0;

    virtual void describe() const {
        cout << left << setw(10) << name_
             << " | dien tich: " << setw(8) << fixed << setprecision(2) << area()
             << " | chu vi: " << perimeter() << "\n";
    }
};

class Circle : public Shape {
    double r_;

public:
    explicit Circle(double r) : Shape("Circle"), r_(r) {}
    double area() const override { return 3.14159265 * r_ * r_; }
    double perimeter() const override { return 2 * 3.14159265 * r_; }
};

class Rectangle : public Shape {
protected:
    double w_, h_;

public:
    Rectangle(double w, double h, string name = "Rectangle")
        : Shape(std::move(name)), w_(w), h_(h) {}
    double area() const override { return w_ * h_; }
    double perimeter() const override { return 2 * (w_ + h_); }
};

class Square : public Rectangle {
public:
    explicit Square(double s) : Rectangle(s, s, "Square") {}
};

void practicePolymorphism() {
    cout << "\n=== 2-4. Abstraction, Inheritance, Polymorphism ===\n";
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Circle>(3));
    shapes.push_back(make_unique<Rectangle>(4, 5));
    shapes.push_back(make_unique<Square>(2));

    for (const auto& s : shapes) {
        s->describe();  // goi dung phien ban cua tung lop con
    }
}

// ------------------------------------------------------------
// 5. COMPOSITION (Ket hop): "has-a" thay vi "is-a"
// ------------------------------------------------------------
class Engine {
public:
    void start() const { cout << "Dong co khoi dong\n"; }
};

class Car {
    string model_;
    Engine engine_;  // Car "co" Engine

public:
    explicit Car(string model) : model_(std::move(model)) {}
    void drive() const {
        cout << model_ << ": ";
        engine_.start();
        cout << model_ << " dang chay\n";
    }
};

void practiceComposition() {
    cout << "\n=== 5. Composition ===\n";
    Car car("Toyota");
    car.drive();
}

// ------------------------------------------------------------
// 6. OPERATOR OVERLOADING
// ------------------------------------------------------------
class Vector2D {
public:
    double x, y;
    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}

    Vector2D operator+(const Vector2D& o) const { return {x + o.x, y + o.y}; }
    Vector2D operator-(const Vector2D& o) const { return {x - o.x, y - o.y}; }
    Vector2D operator*(double k) const { return {x * k, y * k}; }
    bool operator==(const Vector2D& o) const { return x == o.x && y == o.y; }

    friend ostream& operator<<(ostream& os, const Vector2D& v) {
        return os << "(" << v.x << ", " << v.y << ")";
    }
};

void practiceOperators() {
    cout << "\n=== 6. Operator Overloading ===\n";
    Vector2D a(1, 2), b(3, 4);
    cout << "a + b = " << (a + b) << "\n";
    cout << "b - a = " << (b - a) << "\n";
    cout << "a * 3 = " << (a * 3) << "\n";
    cout << "a == b ? " << boolalpha << (a == b) << "\n";
}

// ------------------------------------------------------------
// 7. TEMPLATE CLASS (Generic programming)
// ------------------------------------------------------------
template <typename T>
class Stack {
    vector<T> data_;

public:
    void push(const T& v) { data_.push_back(v); }
    T pop() {
        if (data_.empty()) throw runtime_error("Stack rong");
        T v = data_.back();
        data_.pop_back();
        return v;
    }
    bool empty() const { return data_.empty(); }
    size_t size() const { return data_.size(); }
};

void practiceTemplates() {
    cout << "\n=== 7. Template ===\n";
    Stack<int> si;
    si.push(1); si.push(2); si.push(3);
    cout << "Stack<int> pop: " << si.pop() << ", con lai " << si.size() << "\n";

    Stack<string> ss;
    ss.push("xin"); ss.push("chao");
    cout << "Stack<string> pop: " << ss.pop() << " " << ss.pop() << "\n";
}

// ------------------------------------------------------------
// 8. RAII + Rule of Five
//    Lop tu quan ly tai nguyen: constructor cap phat, destructor giai phong.
// ------------------------------------------------------------
class Buffer {
    size_t size_;
    int* data_;

public:
    explicit Buffer(size_t n) : size_(n), data_(new int[n]()) {
        cout << "  [Buffer] cap phat " << size_ << " phan tu\n";
    }

    ~Buffer() {
        delete[] data_;
        cout << "  [Buffer] giai phong\n";
    }

    Buffer(const Buffer& o) : size_(o.size_), data_(new int[o.size_]) {
        copy(o.data_, o.data_ + size_, data_);
        cout << "  [Buffer] copy\n";
    }

    Buffer& operator=(const Buffer& o) {
        if (this != &o) {
            Buffer tmp(o);
            swap(size_, tmp.size_);
            swap(data_, tmp.data_);
        }
        return *this;
    }

    Buffer(Buffer&& o) noexcept : size_(o.size_), data_(o.data_) {
        o.size_ = 0;
        o.data_ = nullptr;
        cout << "  [Buffer] move\n";
    }

    Buffer& operator=(Buffer&& o) noexcept {
        if (this != &o) {
            delete[] data_;
            size_ = o.size_;
            data_ = o.data_;
            o.size_ = 0;
            o.data_ = nullptr;
        }
        return *this;
    }

    int& operator[](size_t i) { return data_[i]; }
    size_t size() const { return size_; }
};

void practiceRAII() {
    cout << "\n=== 8. RAII + Rule of Five ===\n";
    Buffer a(3);
    a[0] = 42;
    Buffer b = a;             // copy
    Buffer c = std::move(a);       // move
    cout << "  c[0] = " << c[0] << ", b[0] = " << b[0] << "\n";
}   // ra khoi ham: destructor tu dong chay

// ------------------------------------------------------------
// MAIN
// ------------------------------------------------------------
int main() {
    cout << "===== OOP Practices (C++) =====\n";
    practiceEncapsulation();
    practicePolymorphism();
    practiceComposition();
    practiceOperators();
    practiceTemplates();
    practiceRAII();
    cout << "\nHoan thanh!\n";
    return 0;
}
