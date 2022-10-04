#include <iostream>
using namespace std;

class distance2;
class distance1
{
  float miles;
  public:
  distance1()
{
    miles = 0;
}
    
    void takeinput();
    void convert1(){
        miles = miles * 1.609;
    }
    friend void totaldistance(distance1,distance2);
   
};

class distance2{
    float kilometers,meters;
    float conv;
    public:
        distance2(){
            kilometers = 0;
            meters = 0;
        }
       
        void takeinput1();
        void convert();
        void add(){
            conv = kilometers + meters;
        }
        friend void totaldistance(distance1,distance2);
       
       
};


void distance1::takeinput(){
    cout << "ENTER THE DISTANCE IN MILES: " << endl;
    cin >> miles;
}

void distance2::takeinput1(){
    cout << "ENTER THE DISTANCE IN KILOMETERS :"<< endl;
    cin >> kilometers;
    cout << "ENTER THE DISTANCE IN METERS : " << endl;
    cin >> meters;
   
}

void distance2::convert(){
    meters = meters/1000;
}

void totaldistance(distance1 x, distance2 y){
    float t;
    t = x.miles + y.conv;
    cout << "THE TOTAL DISTANCE IS :" << t << endl;
}

int main()
{
    distance1 x;
    distance2 y;
   
    x.takeinput();
    y.takeinput1();
    y.convert();
    x.convert1();
    y.add();
    totaldistance(x,y);
   
    return 0;
}
