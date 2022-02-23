#include <iostream>
#include <vector>
#include "math.h"


const int COUNTCOLOR = 15;
const int MIN_X = -10000;
const int MIN_Y = -10000;
const int MAX_X = 10000;
const int MAX_Y = 10000;

class Styles {
protected:
    int color;
};

class Point : public Styles {
public:
    Point() {
        cord_x = 0;
        cord_y = 0;
    };

    Point(int x1, int y1, int styleColor) {
        cord_x = (x1 > MIN_X && x1 < MAX_X) ? x1 : 0;
        cord_y = (y1 > MIN_Y && y1 < MAX_Y) ? y1 : 0;
        color = (styleColor > 0 && styleColor <= COUNTCOLOR) ? styleColor : 0;
    };

    ~Point() {std::cout << "Point has destroyed";}

    int cord_x, cord_y;
};


class Properties : public Styles {
public:
    Properties() {};

    Properties(int *cord[], int count, int styleColor) {
        cords.resize(count);
        for (int i = 0; i < count; i++) {
            this->cords[i].cord_x = (cord[i][0] > MIN_X && cord[i][0] < MAX_X) ? cord[i][0] : 0;
            this->cords[i].cord_y = (cord[i][1] > MIN_Y && cord[i][1] < MAX_Y) ? cord[i][1] : 0;
            this->count = count;
        }
        color = (styleColor > 0 && styleColor <= COUNTCOLOR) ? styleColor : 0;
        std::cout << "Base constructor";
    }


    ~Properties() {
        cords.resize(0);
        std::cout << "Properties has destroyed";
    };

    void setCords(int positionCord, int x, int y) {
        cords[positionCord].cord_y = y;
        cords[positionCord].cord_x = x;
    }

    void getCords() {
        for (int i = 0; i < count; i++) {
            std::cout << "cord " << i + 1 << " : X: " << cords[i].cord_x << " Y: " << cords[i].cord_y;
        }
    }

    int length(int firstPosition, int secondPoint) {
        return std::sqrt((cords[secondPoint].cord_x - cords[firstPosition].cord_x) *
                         (cords[secondPoint].cord_x - cords[firstPosition].cord_x) +
                         (cords[secondPoint].cord_y - cords[firstPosition].cord_y) *
                         (cords[secondPoint].cord_y - cords[firstPosition].cord_y));
    }

    virtual void perimeter() {
        int per = 0;
        for (int i = 0; i < count - 1; i++) {
            per += length(i, i + 1);
        }
        //per += length(count - 1, 0);
        std::cout << "Perimeter: " << per << '\n';
    }

protected:
    int count;
    std::vector<Point> cords;
};

class Line : public Properties {
public:
    Line(Line &otherLine) {
        otherLine.cords = this->cords;
        otherLine.count = this->count;
    };

    Line() : Properties(0, 2, 0) {};

    Line(int *cords[], int count, int colorStyle) : Properties(cords, count, colorStyle) {
        std::cout << "created Line";
    }

    ~Line() {std::cout << "Line has destroyed";};
};

class ClosedLine : public Line {
public:
    ClosedLine(ClosedLine &otherClosedLine) {
        otherClosedLine.cords = this->cords;
        otherClosedLine.count = this->count;
    };

    ClosedLine() : Line(0, 3, 0) {};

    ClosedLine(int *cords[], int countPoint, int colorStyle) : Line(cords, countPoint, colorStyle) {
        std::cout << "created ClosedLine";
    }

    virtual void perimeter() {
        int per = 0;
        for (int i = 0; i < count - 1; i++) {
            per += length(i, i + 1);
        }
        per += length(count - 1, 0);
        std::cout << "Perimeter: " << per << '\n';
    }
    ~ClosedLine() {};
};

class Polygon : public ClosedLine {
public:
    Polygon(Polygon &otherPolygon) {
        otherPolygon.cords = this->cords;
        otherPolygon.count = this->count;
    };

    Polygon() : ClosedLine(0, 3, 0) {};

    Polygon(int *cords[], int countPoint, int colorStyle) : ClosedLine(cords, countPoint, colorStyle) {
        std::cout << "created Polygon";
    }

    void square() {
        int tempArr[count + 1];
        int sqrt = 0;
        int tempSquare = 0;
        for (int i = 0; i < count - 1; i++) {
        }
        for (int i = 0; i < count - 1; i++) {
            sqrt += cords[i].cord_x * cords[i + 1].cord_y;
        }
        sqrt += cords[count - 1].cord_x * cords[0].cord_y;
        for (int i = 0; i < count - 1; i++) {
            sqrt -= cords[i].cord_y * cords[i + 1].cord_x;
        }
        sqrt -= cords[count - 1].cord_y * cords[0].cord_x;
        sqrt = abs(sqrt / 2);
        std::cout << '\n' << "Square: " << sqrt;
    }

    ~Polygon() {std::cout << "Polygon has destroyed";};
};


class Triangle : public Polygon {
public:
    Triangle(Triangle &otherTriangle) {
        otherTriangle.cords = this->cords;
        otherTriangle.count = this->count;
    };

    Triangle() : Polygon(0, 3, 0) {};

    Triangle(int *cords[], int colorStyle) : Polygon(cords, 3, colorStyle) {
        std::cout << "created Triangle";
    }

    ~Triangle() {std::cout << "Triangle has destroyed";};
};

class Trapezoid : public Polygon {
public:
    Trapezoid(Trapezoid &otherTrapezoid) {
        otherTrapezoid.cords = this->cords;
        otherTrapezoid.count = this->count;
    };

    Trapezoid() : Polygon(0, 4, 0) {};

    Trapezoid(int *cords[], int colorStyle) : Polygon(cords, 4, colorStyle) {
        std::cout << "created Rectangle";
    }

    ~Trapezoid() {std::cout << "Trapezoid has destroyed";};
};

class RegularPolygon : public Polygon {
public:
    RegularPolygon(RegularPolygon &otherRegularPolygon) {
        otherRegularPolygon.cords = this->cords;
        otherRegularPolygon.count = this->count;
    };

    RegularPolygon() : Polygon(0, 3, 0) {};

    RegularPolygon(int *cords[], int countPoint, int colorStyle) : Polygon(cords, countPoint, colorStyle) {
        std::cout << "created Rectangle";
    }

    ~RegularPolygon() {std::cout << "RegularPolygon has destroyed";};
};

int main() {
    int countPoints, type;
    std::cout << "Choose what you wanna create \n";
    std::cout << "1 - Point \n"
                 "2 - Line \n"
                 "3 - ClosedLine \n"
                 "4 - Polygon \n"
                 "5 - Triangle \n"
                 "6 - Trapezoid \n"
                 "7 - Regular Polygon \n";
    std::cin >> type;
    switch (type) {
        case 1:
            countPoints = 1;
            break;
        case 2:
            countPoints = 2;
            break;
        case 3:
            std::cout << "Input count of points for ClosedLine ";
            std::cin >> countPoints;
            break;
        case 4:
            std::cout << "Input count of points for Polygon ";
            std::cin >> countPoints;
            break;
        case 5:
            countPoints = 3;
            break;
        case 6:
            countPoints = 4;
            break;
        case 7:
            std::cout << "Input count of points for Regular Polygon ";
            std::cin >> countPoints;
            break;
    };
    int cords[countPoints][2];
    int *p[countPoints];
    for (int i = 0; i < countPoints; i++) {
        std::cin >> cords[i][0] >> cords[i][1];
        p[i] = cords[i];
    };
    if (type == 1) {
        Point point(cords[0][0], cords[0][1], 1);
    };
    if (type == 2) {
        Line line(p, 2, 1);
        line.perimeter();
    };
    if (type == 3) {
        ClosedLine closedLine(p, countPoints, 1);
        closedLine.perimeter();
    };
    if (type == 4) {
        Polygon polygon(p, countPoints, 1);
        polygon.perimeter();
        polygon.square();
    };
    if (type == 5) {
        Triangle triangle(p, 1);
        triangle.perimeter();
        triangle.square();
    };
    if (type == 6) {
        Trapezoid trapezoid(p, 1);
        trapezoid.perimeter();
        trapezoid.square();
    };
    if (type == 7) {
        RegularPolygon regularPolygon(p, countPoints, 1);
        regularPolygon.perimeter();
        regularPolygon.square();
    };
    return 0;
}
