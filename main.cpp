#include <iostream>

const int COUNTCOLOR = 15;
const int MIN_X = -1;
const int MIN_Y = -1;
const int MAX_X = 10000;
const int MAX_Y = 10000;

class Styles {
protected:
    int color;
};

class Point : Styles {
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

    ~Point() {}

    int cord_x, cord_y;
};


class Properties : Styles {
public:
    Properties(int *cords[], int count, int styleColor) {
            for (int i = 0; i < count; i++) {
                this->cords.cord_x = (cords[i][0] > MIN_X && cords[i][0] < MAX_X) ? cords[i][0] : 0;
                this->cords.cord_y = (cords[i][1] > MIN_Y && cords[i][1] < MAX_Y) ? cords[i][1] : 0;
                std::cout << this->cords.cord_x << ' ' << this->cords.cord_y << ' ';
            }
            color = (styleColor > 0 && styleColor <= COUNTCOLOR) ? styleColor : 0;
    };

    ~Properties() {};

protected:
    Point cords;
};

class Line : public Properties {
public:
    Line() : Properties(0, 2, 0) {};

    Line(int *cords[], int colorStyle) : Properties(cords, 2, colorStyle) {
        std::cout << "created Line";
    }

    ~Line() {};
};

class ClosedLine : public Properties {
public:
    ClosedLine() : Properties(0, 3, 0) {};

    ClosedLine(int *cords[], int countPoint, int colorStyle) : Properties(cords, countPoint, colorStyle) {
        std::cout << "created ClosedLine";
    }

    ~ClosedLine() {};
};

class Polygon : public Properties {
public:
    Polygon() : Properties(0, 3, 0) {};

    Polygon(int *cords[], int countPoint, int colorStyle) : Properties(cords, countPoint, colorStyle) {
        std::cout << "created Polygon";
    }

    ~Polygon() {};
};


class Triangle : public Properties {
public:
    Triangle() : Properties(0, 3, 0) {};

    Triangle(int *cords[], int colorStyle) : Properties(cords, 3, colorStyle) {
        std::cout << "created Triangle";
    }

    ~Triangle() {};
};

class Trapezoid : public Properties {
public:
    Trapezoid() : Properties(0, 4, 0) {};

    Trapezoid(int *cords[], int colorStyle) : Properties(cords, 4, colorStyle) {
        std::cout << "created Rectangle";
    }

    ~Trapezoid() {};
};

class RegularPolygon : public Properties {
public:
    RegularPolygon() : Properties(0, 3, 0) {};

    RegularPolygon(int *cords[], int countPoint, int colorStyle) : Properties(cords, countPoint, colorStyle) {
        std::cout << "created Rectangle";
    }

    ~RegularPolygon() {};
};

int main() {
    int type, countPoints;
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
    if(type == 1){
        Point point(cords[0][0], cords[0][1], 1);
    };
    if(type == 2){
        Line line(p, 1);
    };
    if(type == 3){
        ClosedLine polygon(p, countPoints, 1);
    };
    if(type == 4){
        Polygon polygon(p, countPoints, 1);
    };
    if(type == 5){
        Triangle triangle(p, 1);
    };
    if(type == 6){
        Trapezoid trapezoid(p, 1);
    };
    if(type == 7){
        RegularPolygon regularPolygon(p, countPoints, 1);
    };
    return 0;
}
