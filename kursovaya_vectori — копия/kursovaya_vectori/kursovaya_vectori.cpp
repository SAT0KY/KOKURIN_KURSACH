#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h> //для игноров

class Vector3D {
private:
    std::vector<double> coordinates;

public:
    Vector3D() {}

    // Метод для установки координат вектора
    void setCoordinates() {
        double coord;
        bool flag = true;
        while (flag) {
            coordinates.clear();
            std::cin >> coord;
            if (std::cin.fail()) {
                std::cout << "one of your coordinates is wrong. Pleasr try again\n";
                std::cin.clear(); //сбрасываем failbit
                std::cin.ignore(static_cast<std::streamsize>(std::numeric_limits<int>::max()), '\n'); //очищает поток
                continue;
            }
            std::cin.ignore(1);
            coordinates.push_back(coord);

            std::cin >> coord;
            if (std::cin.fail()) {
                std::cout << "one of your coordinates is wrong. Pleasr try again\n";
                std::cin.clear();
                std::cin.ignore(static_cast<std::streamsize>(std::numeric_limits<int>::max()), '\n');
                continue;
            }
            std::cin.ignore(1);
            coordinates.push_back(coord);

            std::cin >> coord;
            if (std::cin.fail()) {
                std::cout << "one of your coordinates is wrong. Pleasr try again\n";
                std::cin.clear();
                std::cin.ignore(static_cast<std::streamsize>(std::numeric_limits<int>::max()), '\n');
                continue;
            }
            coordinates.push_back(coord);
            flag = false;
        }
        std::cin.ignore(static_cast<std::streamsize>(std::numeric_limits<int>::max()), '\n');
    }

    // Метод для вывода координат вектора
    void print() {
        std::cout << "(";
        for (int i = 0; i < coordinates.size(); ++i) {
            std::cout << coordinates[i];
            if (i != coordinates.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << ")" << std::endl;
    }

    // Метод для сложения двух векторов
    Vector3D add(Vector3D other) {
        Vector3D result;
        for (int i = 0; i < coordinates.size(); ++i) {
            result.coordinates.push_back(coordinates[i] + other.coordinates[i]);
        }

        return result;
    }

    // Метод для вычитания одного вектора из другого
    Vector3D subtract(Vector3D other) {
        Vector3D result;
        for (int i = 0; i < coordinates.size(); ++i) {
            result.coordinates.push_back(coordinates[i] - other.coordinates[i]);
        }

        return result;
    }

    // Метод для умножения двух векторов
    Vector3D multiply(Vector3D other) {
        Vector3D result;
        for (int i = 0; i < coordinates.size(); ++i) {
            result.coordinates.push_back(coordinates[i] * other.coordinates[i]);
        }

        return result;
    }

    // Метод для вычисления скалярного произведения двух векторов
    double ScalarProduct(Vector3D other) {
        double product = 0.0;
        for (int i = 0; i < coordinates.size(); ++i) {
            product += coordinates[i] * other.coordinates[i];
        }

        return product;
    }

    // Метод для вычисления длины вектора
    double magnitude() {
        double sumOfSquares = 0.0;
        for (double coordinate : coordinates) {
            sumOfSquares += coordinate * coordinate;
        }

        return std::sqrt(sumOfSquares);
    }

    // Метод для вычисления угла между двумя векторами в градусах
    double angle(Vector3D other) {
        double dotProd = ScalarProduct(other);
        double mag1 = magnitude();
        double mag2 = other.magnitude();
        int counter = 0;

        for (int i = 0; i < coordinates.size(); ++i) {
            if (coordinates[i] == other.coordinates[i])
                counter++;
        }
        if (counter == 3) {return 0;}

        double angleRad = std::cos(dotProd / (mag1 * mag2));
        angleRad = std::acos(angleRad);
        angleRad = std::acos(angleRad);
        double angleDeg = angleRad * 180.0 / 3.1415; // Преобразование радиан в градусы
        return angleDeg;
    }

    void cleaner() {
        coordinates.clear();
    }
};  

int main() {
    Vector3D vec1, vec2;
    std::cout << "This programm was made by 4 year student Kokurin Konstantin from group M70-406C-20\nThe program was made to calculate the sum, difference, product, scalar product of vectors, as well as calculate the angle between them.\n";
    char choice = 'y';
    while (choice == 'y' || choice == 'Y') {
        choice = 0;
        std::cout << "Enter coordinates for vector 1:" << std::endl;
        vec1.setCoordinates();

        std::cout << "Enter coordinates for vector 2:" << std::endl;
        vec2.setCoordinates();

        std::cout << "Vector 1: ";
        vec1.print();

        std::cout << "Vector 2: ";
        vec2.print();
        std::cout << "\n=============================================\n\n";

        Vector3D sum = vec1.add(vec2);
        std::cout << "Sum of vector 1 and vector 2: ";
        sum.print();
        std::cout << "\n=============================================\n\n";

        Vector3D difference = vec1.subtract(vec2);
        std::cout << "Difference of vector 1 and vector 2: ";
        difference.print();
        std::cout << "\n=============================================\n\n";

        Vector3D product = vec1.multiply(vec2);
        std::cout << "Product of vector 1 and vector 2: ";
        product.print();
        std::cout << "\n=============================================\n\n";

        double dotProduct = vec1.ScalarProduct(vec2);
        std::cout << "Scalar product of vector 1 and vector 2: " << dotProduct <<"\n";
        std::cout << "\n=============================================\n\n";

        double angle = vec1.angle(vec2);

        std::cout << "Angle between vector 1 and vector 2: " << angle << " degrees\n\n";

        vec1.cleaner();
        vec2.cleaner();

        std::cout << "Do you want to enter new coordinates? (if YES, please write Y or y, if NO, please press any button): ";
        std::cin >> choice;
    }
    std::cout << "Thanks for using. See ya!";

    return 0;
}