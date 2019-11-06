#include<iostream>
#include<string>
using namespace std;



//creating a template class
template<class T>
class SimpleVector
{
private:
    T *specifiedData;   //a pointer to the specific template data type
    int size;
    
    //public functions
public:
    SimpleVector();
    SimpleVector(int);
    SimpleVector(int a,T b[]);
    int getSize();
    void setArray(T,int);
    T getElementAt(int);
    T operator[](int);
    ~SimpleVector();
};


//public functions

//Default constructor
template < class T>
SimpleVector<T>::SimpleVector()
{
    specifiedData = NULL;
    size = 0;
}
//overloaded constructor
template < class T>
SimpleVector<T>::SimpleVector(int x)
{
    specifiedData = new T[x];
    size = x;
}
//overloaded constructor to make a deep copy
template < class T>
SimpleVector<T>::SimpleVector(int x, T specifiedData2[])
{
    size = x;
    specifiedData = new T[x];
    for (int i = 0; i < x; i++)
    {
        specifiedData[i] = specifiedData2[i];
    }
}
//mutators
template < class T>
void SimpleVector<T>::setArray(T a,int index)
{
    specifiedData[index]=a;
}

//Overloaded [] operator
template < class T>
T SimpleVector<T>::operator[](int index)
{
    if (index > size)
    {
        cout << "Invalid argument" <<endl;
        // return first element.
        return specifiedData[0];
    }
    return specifiedData[index];
}

//function to return the value at certain index
template < class T>
T SimpleVector<T>::getElementAt(int ind)
{
    if(ind > size || size < 0)
    {
        cout << "Invalid argument" << endl;
        return NULL;
    }
    else
    {
        return this->specifiedData[ind];
    }
}

//accessors
template < class T>
int SimpleVector<T>::getSize()
{
    return size;
}

//Destructor
template < class T>
SimpleVector<T>::~SimpleVector()
{
    for (int i = 0; i < size; i++)
    {
        delete specifiedData[i];
    }
    specifiedData = NULL;
    size = 0;
}
int main()
 {
 //used variables
 int dataType = 0;
 int size = 0;
 int index = 0;
 char choice='y';
 //the 3 choices variables
 int x;
 double y;
 string z;
 
 while(choice != 'N'&& choice != 'n')
 {
     cout << "What type of data do you want to enter (1 for integer, 2 for double and 3 for strings): " << endl;
     cin >> dataType;   //determining data type
     
     
     if(dataType != 1 && dataType != 2 && dataType != 3)
     {
         cout << "Invalid data type"<< endl;
     }
 
     else{
         cout << "how many data inputs do you have? " << endl;
         cin >> size;   //determining size
 
        if(dataType == 1) //for integer
        {
            //creating a new class object
            SimpleVector<int> *newArray = new SimpleVector<int>(size);
            //putting data in the class object array
            for (int i = 0; i < size; i++)
            {
                cout << "Enter data at index " << i << ": ";
                cin >> x;
                newArray->setArray(x,i);
            }
            //Retrieving data using class object
            cout << "Enter an index to retrieve the data from: ";
            cin >> index;
            if(index<newArray->getSize())
            {
                cout << "Retrived data from index " << index << " is: " << newArray->getElementAt(index) << endl;
            }
            else
            {
                cout << "Index doesn't exists" << endl;
            }
            //Retrieving data using class object overloading []
            cout << "Enter an index to retrieve the data from: ";
            cin >> index;
            if(index < newArray->getSize())
            {
                cout << "Retrived data from index " << index << " is: " << newArray->getElementAt(index) << endl;
            }
            else
            {
                cout<<"Index doesn't exists"<<endl;
            }
            //saving data in a temporary array to send to copy it
            int *arr=new int[newArray->getSize()];
            for (int i = 0; i < newArray->getSize(); i++)
            {
                arr[i]=newArray->getElementAt(i);
            }
            //creating a class object and using the copy overloading constructor
            SimpleVector<int> *arrayCopy=new SimpleVector<int>(size,arr);
            //printing the data from the object array
            for (int i = 0; i < size; i++)
            {
                cout << arrayCopy->getElementAt(i)<<" ";
            }
            //asking user to do it again
            cout << endl << "Do you want to enter the data again (y/n) ";
            cin >> choice;
        }
     
     
     
     
     
     
     
        else if(dataType == 2)   //for double
        {
            //creating a new class object
            SimpleVector<double> *newArray=new SimpleVector<double>(size);
            //putting data in the class object array
            for (int i = 0; i < size; i++)
            {
                cout <<"Enter data at index " << i << ": ";
                cin >> y;
                newArray->setArray(y,i);
            }
            //Retrieving data using class object
            cout<<"Enter an index to retrieve the data from: ";
            cin>>index;
            if(index<newArray->getSize())
            {
                cout << "Retrived data from index " << index << " is: " << newArray->getElementAt(index) << endl;
            }
            else
            {
                cout<<"Index doesn't exists"<<endl;
            }
            //Retrieving data using class object overloading []
            cout<<"Enter an index to retrieve the data from: ";
            cin>>index;
            if(index<newArray->getSize())
            {
                cout << "Retrived data from index " << index << " is: " << newArray->getElementAt(index) << endl;
            }
            else
            {
                cout<<"Index doesn't exists"<<endl;
            }
            //saving data in a temporary array to send to copy it
            double *arr=new double[newArray->getSize()];
            for (int i = 0; i < newArray->getSize(); i++)
            {
                arr[i]=newArray->getElementAt(i);
            }
            //creating a class object and using the copy overloading constructor
            SimpleVector<double> *myCopyArray=new SimpleVector<double>(size,arr);
            //printing the data from the object array
            for (int i = 0; i < size; i++)
            {
                cout<<myCopyArray->getElementAt(i)<<" ";
            }
            //asking user to do it again
            cout << endl << "Do you want to enter the data again (y/n) ";
            cin >> choice;
        }
     
     
     
     
     
     
        else if(dataType == 3) //for string
        {
            //creating a new class object
            SimpleVector<string> *newArray = new SimpleVector<string>(size);
            //putting data in the class object array
            for (int i = 0; i < size; i++)
            {
                cout <<"Enter data at index " << i << ": ";
                cin >> z;
                newArray->setArray(z, i);
            }
            //Retrieving data using class object
            cout<<"Enter an index to retrieve the data from: ";
            cin>>index;
            if(index < newArray->getSize())
            {
                cout << "Retrived data from index " << index << " is: " << newArray->getElementAt(index) << endl;
            }
            else
            {
                cout << "Index doesn't exists" << endl;
            }
            //Retrieving data using class object overloading []
            cout<<"Enter an index to retrieve the data from: ";
            cin>>index;
            if(index < newArray->getSize())
            {
                cout << "Retrived data from index " << index << " is: " << newArray->getElementAt(index) << endl;
            }
            else
            {
                cout<<"Index doesn't exists"<<endl;
            }

            //saving data in a temporary array to send to copy it
            string *arr = new string[newArray->getSize()];
            for (int i = 0; i < newArray->getSize(); i++)
            {
                arr[i] = newArray->getElementAt(i);
            }
            //creating a class object and using the copy overloading constructor
            SimpleVector<string> *arrayDuplicate = new SimpleVector<string>(size,arr);
            cout << "Displaying data " << endl;
            //printing data from the object array
            for (int i = 0; i < size; i++)
            {
                cout << arrayDuplicate->operator[](i) << " ";
            }
            //asking user to do it again
            cout << endl << "Do you want to enter the data again (y/n) ";
            cin >> choice;
        }
    }
 }
 return 1;
 }
