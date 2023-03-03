#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>


using namespace std;

class Point
{
    
private: 
    double x;
    double y;
    
public:
    // Constructors
    
    
    //default constructor
    Point() : x(0.0), y(0.0) {}
    
    
     //parametrized constructor
    Point(double _x, double _y) : x(_x), y(_y) {}
    
    
    //Destructor
    ~Point() {}
    
    
    // Setters(Mutators)
    void setX(double x){
        this->x = x;
    }
    
    void setY(double y){
        this->y = y;
    }
    
    void setXY(double x, double y){
        this->x = x;
        this->y = y;
    }
    
    
    // Getters(Accessors)
    double getX(void) const{
        return (this->x);
    }
    
    double getY(void) const{
        return (this->y);
    }
    
    //operator overloading
    Point operator + (const Point &p)
    {
        Point tmp;
        tmp.x = this->x + p.x;
        tmp.y = this->y + p.y;
        
        return (tmp);
    }
    
    Point operator - (const Point &p)
    {
        Point tmp;
        tmp.x = this->x - p.x;
        tmp.y = this->y - p.y;
        
        return (tmp);
    }
    
    Point operator * (const Point &p)
    {
        Point tmp;
        tmp.x = this->x * p.x;
        tmp.y = this->y * p.y;
        
        return (tmp);
    }
    
    bool operator == (const Point &p) const
    {
        
        return ( (this->x == p.x) && (this->y == p.y) );
    }
    
    Point operator + (int num)
    {
         // point + 10
         Point p;
         p.x = this->x + num;
         p.y = this->y + num;
         
         return (p);
    }
    
    friend Point operator+(int num, const Point &p)
      {
        // 10 + point
        Point tmp;
        tmp.x = p.x + num;
        tmp.y = p.y + num;
        
        return (tmp);
    }
    
    
    // Methods
    void disp(void) const
    {
        printf("(%lf, %lf) \n", this->x, this->y);
    }
    
     static Point midPoint(const Point &p, const Point &q)
    {
        Point m;
        m.x = (p.x + q.x) / 2;
        m.y = (p.y + q.y) / 2;
        
        return (m);
    }
    
     static double getDistance(const Point &p, const Point &q)
    {
        double distance;
        distance  = (p.x - q.x) * (p.x - q.x);
        distance += (p.y - q.y) * (p.y - q.y);
        
        return (sqrt(distance));
    }

    
};

    

int main()
{
    
    Point o, p{3, 2}, q(7, 8), r(q);
    
    Point x = p * q;
    x.disp();
    
    Point m = Point::midPoint(p, q);
    m.disp();
    
    cout << Point::getDistance(p, q) << "\n";
    
    if(r == q)
    {
        cout <<"equal points"<<"\n";
    }
    Point t = 3 + o;
    t.disp();
    t = t + 2;
    t.disp();
    
    return 0;
}
