//Michael Limberg, Section 011, Lab9 Part1
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>

using namespace std;

class Point {

    // cout implementation for Point class
    friend ostream & operator<<( ostream &output, const Point &P ){
        output << "x: " << P.x << " y: " << P.y;
        return output;
    }

    // cin implementation for Point class
    friend istream & operator>>( istream &input, Point &P ){
        input >> P.x >> P.y;
        return input;
    }

public:
    bool operator == (Point &rhs){
        return (rhs.x == x && rhs.y == y);
    }
    Point(){
        x = 0;
        y = 0;
    }

    Point(int in_x, int in_y){
        x = in_x;
        y = in_y;
    }

    // Add your functions here
    double getX(){
        return x;
    }
    double getY(){
        return y;
    }
    void setX(int in_x){
        x= in_x;
    }
    void setY(int in_y){
        y= in_y;
   }

private:
    int x,y;
};

class Line {
    // implement cout for Line classes objects
    friend ostream & operator<<( ostream &output, const Line &L ){
        output << "Point 1: " << L.P1 << endl << "Point 2: " << L.P2;
        return output;
    }

    // implement cin for Line classes objects
    friend istream & operator>>( istream &input, Line &L ){
        input >> L.P1 >> L.P2;
        return input;
    }

public:
    // Add your functions/methods here //
    bool operator == (Line &rhs){
        return (rhs.P1.getY() == P2.getY() && rhs.P1.getX() == P2.getX());
    }
    Line(){
       P1.setX(0);
       P1.setY(0);
       P2.setX(0);
       P2.setY(0);
    }
    Line(int x1, int y1, int x2, int y2){
        P1.setX(x1);
        P1.setY(y1);
        P2.setX(x2);
        P2.setY(y2);
    }
    double isCircle(){
        if((P1.getX() == P2.getX()) && (P1.getY() == P2.getY())){
            return 0;
        }else{
            return 1;
        }
    }
    double cirRadius(){
            double radius = sqrt(pow(P2.getX()-P1.getX(),2)+pow(P2.getY()-P1.getY(),2));
            return radius;
    }
    double cirDia(){
            double diameter = (sqrt(pow(P2.getX()-P1.getX(),2)+pow(P2.getY()-P1.getY(),2)))*2;
            return diameter;

    }
    double cirArea(){
            double area = M_PI*(pow(P2.getX()-P1.getX(),2)+pow(P2.getY()-P1.getY(),2));
            return area;
    }
    double cirCirc(){
            double circumference = M_PI*2*sqrt(pow(P2.getX()-P1.getX(),2)+pow(P2.getY()-P1.getY(),2));
            return circumference;
    }

    double solutions(){
        cout<<"Object is a Circle."<<endl;
        cout<<"Radius: "<<cirRadius()<<endl;
        cout<<"Diameter: "<<cirDia()<<endl;
        cout<<"Area: "<<cirArea()<<endl;
        cout<<"Circumference: "<<cirCirc()<<endl;
        return 0;
    }
    double cirSolution(){
        if(isCircle() == 1){
          return solutions();
        }else if(isCircle() == 0) {
            cout<<"Object fails Circle colinear test."<<endl;
        }
    }

private:
    Point P1, P2;
};

int main(){
    Line L1;
    Line L2(5,6,7,8);
    cout << "L1: should have all zeros for values" << endl;
    cout << L1 << endl;
    cout << "Enter Two Points For Line: ";
    cin >> L1;
    cout << L1 << endl;  //Trying to call.
    cout<<L1.cirSolution();
    //cout<<"Radius: "<<L1.cirRadius()<<endl;
    //cout<<"Diameter: "<<L1.cirDia()<<endl;
   // cout<<"Area: "<<L1.cirArea()<<endl;
    //cout<<"Circumference: "<<L1.cirCirc()<<endl;

    return 0;
}
