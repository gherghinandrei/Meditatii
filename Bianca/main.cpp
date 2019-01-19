#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<list>
#include<map>

using namespace std;

class IBooking{
    virtual double getTotalPrice()=0;
};

class BookingHotel : public IBooking{
private:
    string hotelName;
    int noDays;
    double pricePerDay;


public:

    BookingHotel(){
        this->hotelName = "Intercontinental";
        this->noDays = 0;
        this->pricePerDay = 100;
    }

    BookingHotel(string hotelName, int noDays, double pricePerDay ){
        this->hotelName = hotelName;
        this->noDays = noDays;
        this->pricePerDay = pricePerDay;
    }


    BookingHotel(const BookingHotel &bookingHotel){
        this->hotelName = bookingHotel.hotelName;
        this->noDays = bookingHotel.noDays;
        this->pricePerDay = bookingHotel.pricePerDay;
    }


    BookingHotel &operator=(const BookingHotel &bookingHotel){
        this->hotelName = bookingHotel.hotelName;
        this->noDays = bookingHotel.noDays;
        this->pricePerDay = bookingHotel.pricePerDay;
        return *this;
    }

    string getHotelName(){
        return hotelName;
    }

    int getNoDays(){
        return noDays;
    }

    double getPricePerDay(){
        return pricePerDay;
    }

    void setHotelName(string hotelName){
        this->hotelName = hotelName;
    }

    void setNoDays(int noDays){
        this->noDays = noDays;
    }

    void setPricePerDay(double pricePerDay){
        this->pricePerDay = pricePerDay;
    }

    friend istream &operator<<(istream &in, BookingHotel &temp){
        cout<<"Introduceti numele hotelului: ";
        in>>temp.hotelName;
        cout<<"Introduceti numarul de zile: ";
        in>>temp.noDays;
        cout<<"Introduceti pretul pe seara: ";
        in>>temp.noDays;

        return in;

    }

    friend ostream &operator<<(ostream &out, const BookingHotel &temp){
        out<<"Numele hotelului: "<<temp.hotelName<<endl;
        out<<temp.noDays<<" zile"<<endl;
        out<<"La pretul de "<<temp.pricePerDay<< "/zi\n";
        return out;
    }


    virtual double getTotalPrice(){
        double totalPrice = this->noDays * this->pricePerDay;
        cout<<"Pretul total este : "<<totalPrice<<endl;
        return totalPrice;
    }

    friend ofstream &operator<<(ofstream &out, const BookingHotel &temp){
        out<<temp.hotelName<<endl;
        out<<temp.noDays<<endl;
        out<<temp.pricePerDay<<endl;
        return out;
    }

    friend ifstream &operator>>(ifstream &in, BookingHotel &temp){
        in>>temp.hotelName;
        in>>temp.noDays;
        in>>temp.pricePerDay;
        return in;
    }


};






int main(){

    BookingHotel hotel1("Merriot",4,150);
    cout<<hotel1;

    hotel1.getTotalPrice();

    ofstream g("fisier.txt");
    ifstream f("fisier.txt");

    g<<hotel1;
    BookingHotel hotel2;
    f>>hotel2;
    cout<<hotel2;
    g.close();

    
    cout<<"*************************VECTOR**************************\n";
    vector<string> elevi;
    elevi.push_back("Bianca");
    elevi.push_back("Bogdan");
    elevi.push_back("Alexandra");
    elevi.push_back("Georgiana");
    elevi.push_back("Gabi");
    elevi.push_back("Florin");
    elevi.push_back("Laura");
    elevi.push_back("Cornel");

    cout<<"Iteratie folosind for loop\n";
    for(int i=0; i<elevi.size();i++){
        cout<<elevi[i]<<endl;
    }
    cout<<"Iteratie folosind iteratorul clasei vector\n";

    vector<string>::const_iterator vectorIterator;
    for(vectorIterator=elevi.begin(); vectorIterator!=elevi.end(); vectorIterator++)
    {
      cout << *vectorIterator << endl;
    }

    cout << endl << "Reverse Iterator:" << endl;
    vector<string>::reverse_iterator rerverseVectorIterator;
    for(rerverseVectorIterator=elevi.rbegin(); rerverseVectorIterator!=elevi.rend(); ++rerverseVectorIterator)
    {
       cout << *rerverseVectorIterator << endl;
    }
    cout << endl << "Sample Output:" << endl;
    cout << elevi.size() << endl;
    cout << elevi[2] << endl;
 
    swap(elevi[0], elevi[2]);
    cout << elevi[2] << endl;


    cout<<"*************************LIST**************************\n";

    list<int> L;
    L.push_back(0);              // Insert a new element at the end
    L.push_front(0);             // Insert a new element at the beginning
    L.insert(++L.begin(),2);     // Insert "2" before position of first argument
                                // (Place before second argument)
    L.push_back(5);
    L.push_back(6);
 
    list<int>::iterator i;
    for(i=L.begin(); i != L.end(); ++i) {
    cout << *i << " ";
    }
    cout << endl;

    cout<<"*************************MAP**************************\n";


    map<int, string> Employees;
    // 1) Assignment using array index notation
    Employees[5234] = "Mike C.";
    Employees[3374] = "Charlie M.";
    Employees[1923] = "David D.";
    Employees[7582] = "John A.";
    Employees[5328] = "Peter Q.";
    cout << "Employees[3374]=" << Employees[3374] << endl << endl;
    cout << "Map size: " << Employees.size() << endl;
 
    cout << endl << "Natural Order:" << endl;
    for( map<int,string>::iterator ii=Employees.begin(); ii!=Employees.end(); ++ii)
    {
        cout << (*ii).first << ": " << (*ii).second << endl;
    }
 
    cout << endl << "Reverse Order:" << endl;
    for( map<int,string>::reverse_iterator ii=Employees.rbegin(); ii!=Employees.rend(); ++ii)
    {
        cout << (*ii).first << ": " << (*ii).second << endl;
    }
    return 0;
}