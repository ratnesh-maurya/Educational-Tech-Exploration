//abstract factory
#include <bits/stdc++.h>

using namespace std;

//Part --> 3
// All products
//Here one can create as many products as one wants to without varying the client code
class bike{
	public:
		virtual void bikeName() = 0;	
};

class HondaBike :public bike{
	public:
		void bikeName(){
			cout << "Your Honda bike is ready" << "\n";
		}	
};

class TataBike :public bike{
	public:
		void bikeName(){
			cout << "Your Tata bike is ready" << "\n";
		}	
};

class car{
	public:
		virtual void carName() = 0;	
};

class HondaCar :public car{
	public:
		void carName(){
			cout << "Your Honda car is ready" << "\n";
		}	
};

class TataCar :public car{
	public:
		void carName(){
			cout << "Your Tata car is ready" << "\n";
		}	
};

//Part --> 2
//factories of company
//factories of different company
class factory{
	public:
		virtual bike* createBike() = 0;
		virtual car* createCar() = 0;
};

class hondaFactory :public factory{
	public:
		bike* createBike(){
			return new HondaBike;
		}
		car* createCar(){
			return new HondaCar;
		}
};


class tataFactory :public factory{
	public:
		bike* createBike(){
			return new TataBike();
		}
		car* createCar(){
			return new TataCar();
		}  
};

//Part --> 1
//main factory
//client can make request to main factory to get the product
class mainFactory{
	public:
		static factory* createFactory(string s){
			if(s == "honda"){
				return new hondaFactory;
			}
			else if(s == "tata"){
				return new tataFactory;
			}
			//lets make one more company 
			
			// else if(s == "bmw"){
			// 	return new bmwFactory;
			// }
			
			//create new factory in part 2
			//create products in part 3
			//we're done with example :)
		}	
};


int main(){
		
		string s;
		cin >> s;
		
		factory* myFactory = mainFactory::createFactory(s);
		
		myFactory -> createBike() -> bikeName();
		myFactory -> createCar() -> carName();
		
	    return 0;
}


//For more details -> https://refactoring.guru/design-patterns/abstract-factory
//Zutok :>