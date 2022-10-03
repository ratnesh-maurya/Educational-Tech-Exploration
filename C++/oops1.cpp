#include<iostream>
#include<string>
using namespace std; 
class laptop{
    private:
    int b;
    public:
    string name;
    string brand;
    float price;
    string processor;
    void getdata(){
        cin>>name>>brand>>price>>processor>>b;
    }
    void showdata(){
        cout<<name<<brand<<price<<processor<<b<<endl;
    }
    void showdata(int a )
{
    cout<<a<<"int is a showdata"<<endl;

}
    };
int main() {
    laptop l;
    l.getdata();
    l.showdata();
    l.showdata(5);
    return 0;
}