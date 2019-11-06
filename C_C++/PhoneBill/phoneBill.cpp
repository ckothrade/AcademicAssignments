#include<iostream>
#include<string>
#include <cstdlib>
using namespace std;

//Basic cstomer class
class Customer
{
//protected attributes for inherited class
protected:
    int numCalls;
    string Name;
    int id;

//public functions
public:
    Customer();
    Customer(string,int);
    void setTotalCalls(int);
    void setName(string);
    void setID(int);
    int getTotalCalls();
    string getName();
    int getCustomerId();
    //compute bill function
    double virtual Compute_Bill();
};



//Public functions
    //default constructor
    Customer::Customer()
    {
        Name = "";
        id = 0;
        numCalls = 0;
    }
    //overloaded cunstructor
    Customer::Customer(string name,int numCalls1)
    {
        Name = name;
        numCalls = numCalls1;
    }
    //mutators
    void Customer::setID(int x)
    {
        id = x;
    }
    void Customer::setTotalCalls(int x)
    {
        numCalls = x;
    }
    void Customer::setName(string x)
    {
        Name = x;
    }
    //accessor
    int Customer::getCustomerId()
    {
        return id;
    }
    int Customer::getTotalCalls()
    {
        return numCalls;
    }
    string Customer::getName()
    {
    return Name;
    }
    //compute bill function for basic customer
    double Customer::Compute_Bill()
    {
        double bill = 10.0 + (0.5 * numCalls);
        return bill;
    }

//inherited Class
class Premium_Customer:public Customer
{
private:
    int totalMins;
public:
    Premium_Customer();
    Premium_Customer(string,int ,int);
    void setTotalMin(int);
    int getTotalMin();
    double virtual Compute_Bill();
};

//Public functions
    //default constructor
    Premium_Customer::Premium_Customer()
    {
        Name = "";
        id = 0;
        numCalls = 0;
        totalMins = 0;
    }
    //overloaded constructor
    Premium_Customer::Premium_Customer(string name, int numCalls1, int tMin)
    {
        Name = name;
        numCalls = numCalls1;
        totalMins = tMin;
    }
    //mutators
    void Premium_Customer::setTotalMin(int x)
    {
        totalMins = x;
    }
    //accessor
    int Premium_Customer::getTotalMin()
    {
        return totalMins;
    }
    //comput bill function for premium customer
    double Premium_Customer::Compute_Bill()
    {
        double bill = 20.0 + (0.05 * numCalls) + ( 0.1 * totalMins);
        return bill;
    }



int main ()
{
    

    Customer * list[6];										//making customers and setting theire attributes
    list[0] = new Customer("John Dough", 20);
    list[1] = new Customer("Bob Dough", 50);
    list[2] = new Customer("Ajay Bansal", 99);
    list[3] = new Customer("Ritchard  Whitehouse", 56);
    list[4] = new Customer("Rameen Khaliqi", 23);
    list[5] = new Premium_Customer("Jane Doe",100, 77);
    //printing customers and their computed bills
    for(int i = 0; i <= 5; i++)
    {
        cout << "Customer " << list[i]->getName() << " owes "<< list[i]->Compute_Bill() << " dollars." << endl;
    }
    

    //bonus
    Customer * bonus[11];
    int bll = 10;
    double avg = 0;
    for(int i = 1;i <= 10; i++){
    bonus[i]= new Customer("Customer ",bll);
    cout << bonus[i]->getName() << i << " owes "<< bonus[i]->Compute_Bill() << " dollars." << endl;
        bll += 10;
        avg += bonus[i]->Compute_Bill();
    }
    
    double avg2 = 0;
    Customer * bonus2[11];
    bll =10;
    for(int i = 1;i <= 10; i++){
        int mins = rand() % 7 + 2;
        bonus2[i]= new Premium_Customer("Premium Customer ",bll, mins);
        cout << bonus2[i]->getName() << i << " owes "<< bonus2[i]->Compute_Bill() << " dollars." << endl;
        bll += 10;
        avg2 += bonus2[i]->Compute_Bill();
    }
    
    
    cout << "premium plan seems better for most customers" << endl;
    cout <<  "average for basic = $" << avg/10.0 << endl;
    cout <<  "average for premium = $" << avg2/10.0 << endl;
    cout << "average savings for premium plan = $" << avg/10.0 - avg2/10.0 << endl;
    return 1;
}
