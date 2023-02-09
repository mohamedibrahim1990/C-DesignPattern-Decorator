#include <iostream>
#include <string>
#include <sstream>

struct Shape{
    virtual std::string str() const =0;
};

struct ColoredShape: Shape{
    Shape& shape;
    std::string color;
    ColoredShape(Shape& shape, const std::string & color): shape{shape}, color{color}{}

    std::string str() const override{
        std::ostringstream oss;
        oss <<shape.str() << " has the color " << color;
        return oss.str();
    }
};

struct Circle:Shape{
    float radius;
    explicit Circle(const float radius): radius{radius}{}
    void resize(float factor){radius *= factor;}
    std::string str() const override{
        std::ostringstream oss;
        oss<< "A Circle of radius" << radius;
        return oss.str();
    }
}; //square implementation omitted

struct Square:Shape{
    float side;
    explicit Square(const float side): side{side}{}
    void resize(float factor){side *= factor;}
    std::string str() const override{
        std::ostringstream oss;
        oss<< "A Square of side" << side;
        return oss.str();
    }
}; //square implementation omitted

struct TransparentShape:Shape{
    Shape& shape;
    uint8_t transparency;
    TransparentShape(Shape& shape, const uint8_t & transparency): shape{shape}, transparency{transparency}{}
    std::string str() const override{
        std::ostringstream oss;
        oss << shape.str() << " has " << static_cast<float>(transparency)/255.f*100.f << "% transparency";
        return oss.str();
            
    }
};

int main(){
    Circle circle{0.5f};
    ColoredShape redCircle{circle, "red"};
    std::cout << redCircle.str() <<std::endl;
    Square square{3};
    TransparentShape demiSquare{square , 85};
    std::cout <<demiSquare.str()<<std::endl;
    // A square with side 3 has 33.333% transparency
    TransparentShape myCircle{
        redCircle, 64
    };
    std::cout << myCircle.str();
}

