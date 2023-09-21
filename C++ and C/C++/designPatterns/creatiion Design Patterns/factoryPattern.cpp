//factory code of design pattern

#include <bits/stdc++.h>

using namespace std;





//vehicle class
class vehicle{
   public:
      virtual void createVehicle() = 0;
};



// vehicle definations
class car : public vehicle{
   public:
   void createVehicle(){
      cout << "creating car";
   }
};

class bike : public vehicle{
   public:
      void createVehicle(){
         cout << "creating bike";
      }
};


class ship : public vehicle{
   public:
      void createVehicle(){
         cout << "creating ship";
      }
};


//factory class --> it will return obj acc to input of user
class vehicleFactory{
   public:
      static vehicle* createVehicle(string s){
         vehicle* vv;
    
      if(s == "car"){
         vv = new car;
      
      }
      else if(s == "ship"){
         vv = new ship;
      }
      else{
         vv = new bike;
      }
         
         return vv;
      }
} ;




int main(){
    string s;
    cin >> s;
    
    vehicle* ff  = vehicleFactory::createVehicle(s);
    
    ff->createVehicle();    
}

//for more details -> https://refactoring.guru/design-patterns/factory-method