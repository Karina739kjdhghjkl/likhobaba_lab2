#include <iostream>
#include <windows.h>

class Vector3D {
private:
    double x, y, z;

public:
  
    Vector3D() : x(0.0), y(0.0), z(0.0) {}

   
    Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}


    friend std::ostream& operator<<(std::ostream& os, const Vector3D& vec);
    friend std::istream& operator>>(std::istream& is, Vector3D& vec);

    Vector3D operator+(const Vector3D& other) const;

    Vector3D operator-(const Vector3D& other) const;

    Vector3D operator*(double scalar) const;

    double dotProduct(const Vector3D& other) const;

    bool operator==(const Vector3D& other) const;
    bool operator!=(const Vector3D& other) const;

    Vector3D& operator=(const Vector3D& other);

    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }
};

std::ostream& operator<<(std::ostream& os, const Vector3D& vec) {
    os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Vector3D& vec) {
    is >> vec.x >> vec.y >> vec.z;
    return is;
}

Vector3D Vector3D::operator+(const Vector3D& other) const {
    return Vector3D(x + other.x, y + other.y, z + other.z);
}

Vector3D Vector3D::operator-(const Vector3D& other) const {
    return Vector3D(x - other.x, y - other.y, z - other.z);
}

Vector3D Vector3D::operator*(double scalar) const {
    return Vector3D(x * scalar, y * scalar, z * scalar);
}

double Vector3D::dotProduct(const Vector3D& other) const {
    return x * other.x + y * other.y + z * other.z;
}

bool Vector3D::operator==(const Vector3D& other) const {
    return (x == other.x) && (y == other.y) && (z == other.z);
}

bool Vector3D::operator!=(const Vector3D& other) const {
    return !(*this == other);
}

Vector3D& Vector3D::operator=(const Vector3D& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
        z = other.z;
    }
    return *this;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    using namespace std;

    Vector3D v1;

    std::cout << "Введіть координати вектора (x y z): ";
    std::cin >> v1;

    Vector3D v2;

    std::cout << "Введіть координати вектора (x y z): ";
    std::cin >> v2;

    // Додавання векторів
    Vector3D sum = v1 + v2;
    std::cout << "Сума векторів: " << sum << std::endl;

    // Віднімання векторів
    Vector3D diff = v1 - v2;
    std::cout << "Різниця векторів: " << diff << std::endl;

    // Множення вектора на скаляр
    double scalar = 2.5;
    Vector3D scaled = v1 * scalar;
    std::cout << "Множення вектора на скаляр " << scalar << ": " << scaled << std::endl;

    // Скалярний добуток
    double dot = v1.dotProduct(v2);
    std::cout << "Скалярний добуток векторів: " << dot << std::endl;

    // Порівняння векторів
    if (v1 == v2) {
        std::cout << "Вектори рівні" << std::endl;
    }
    else {
        std::cout << "Вектори не рівні" << std::endl;
    }

    // Присвоєння векторів
    Vector3D v3 = v1;
    std::cout << "Присвоєння вектора: " << v3 << std::endl;

    return 0;
}
