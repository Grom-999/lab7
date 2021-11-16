#include <iostream>
#include <vector>
#include <random>

//№1
struct coord {
    int x;
    int y;
    int z;
};

//№2
std::ostream &operator<<(std::ostream &out, const coord &c) {
    out << "x: " << c.x << " y: " << c.y << " z: " << c.z << std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, coord &c) {
    in >> c.x;
    in >> c.y;
    in >> c.z;
    return in;
}

coord operator-(coord c, int a) {
    c.x -= a;
    c.y -= a;
    c.z -= a;
    return c;
}

coord operator*(coord c, int a) {
    c.x *= a;
    c.y *= a;
    c.z *= a;
    return c;
}

int main() {

    //№1

    coord c;
    c.x = 1;
    c.y = 2;
    c.z = 3;

    //№2
    std::cout << c << std::endl; // оператор перегрузски вывода

    std::cout << "введите  3 значения :  " << std::endl; // оператор перегрузски ввода
    std::cin >> c;
    std::cout << c << std::endl;

    std::cout << "введите значения, которое хотите отнять :" << std::endl; // оператор перегрузки -
    int a;
    std::cin >> a;
    c = c - a;
    std::cout << c << std::endl;

    std::cout << "введите значения на которое хотите умножить :" << std::endl; // оператор перегрузки *
    int b;
    std::cin >> b;
    c = c * b;
    std::cout << c << std::endl;

    //№3
    std::vector<coord> vec;

    coord temp;

    std::random_device rd;
    for (size_t i = 0; i < 3; ++i) {

        temp.x = rd() % 10;
        temp.y = rd() % 10;
        temp.z = rd() % 10;
        vec.push_back(temp);
    }
    std::cout << "вектор, произвольных векторов : " << std::endl;
    for (size_t i = 0; i < 3; ++i) {
        std::cout << vec[i];
    }

    std::cout << "\n";

//№4

    sort(vec.begin(), vec.end(), [](const coord &vec, const coord &vec2) {
        if (vec.x != vec2.x) return vec.x < vec2.x;
        else if (vec.y != vec2.y) return vec.y < vec2.y;
        else if (vec.z != vec2.z) return vec.z < vec2.z;
        return true;
    });
    std::cout << "отсортированный вектор, произвольных векторов : " << std::endl;
    for (size_t i = 0; i < 3; ++i) {
        std::cout << vec[i];
    }

}
