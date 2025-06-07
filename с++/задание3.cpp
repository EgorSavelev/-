//задание 3
#include iostream 
using namespace std;

class Rectangle {
private:
    double width;
    double heigth;
public:
    Rectangle(double w, double h):
    width(w), heigth(h){}
    double area(){
        return width*heigth;
    double perimetr();{
        return 2*(width+heigth);
    }
    }
};
int main(){
    Rectangle rect(5.0,3.0);
    std::cout<<"Площадь прямоугольника"<<std::endl;
    std::cout<<"Периметр прямоугольника"<<std::endl;
    return 0;
}