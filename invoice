#include<iostream>
#include<string>
using namespace std;

//assignment 9.10

class Invoice // a constructor makes all 4 fields are initialized so that no one can create an invoice without setting all the fields.
{
	//include four data members
	public:
		string getPartNumber();
		void setPartNumber(string val);

		string getpartDescription();
		void setpartDescription(string hello);

		int getquantity();
		void setquantity(int stuff);
		
		int getprice();
		void setprice(int money);
		
		Invoice(); //constructor

		int getInvoiceAmount();

	private:
		string partNumber;
		string partDescription;
		int quantity;
		int price;
};// a constructor is just like a method(function) that is being called when an object of type invoice is generated
//a function is pure and a method or procedure is not necessarily
//procedure can also be a pure function but not the other way around


//access stuff in a class
//constructor
Invoice::Invoice()
{
	partNumber = " "; 
	partDescription = " ";
	quantity = 0;
	price = 0;
}


string Invoice::getPartNumber() {
	return partNumber;
}

void Invoice::setPartNumber(string val) {
	partNumber = val;
}

string Invoice::getpartDescription(){
	return partDescription;
}

void Invoice::setpartDescription(string hello){
	partDescription = hello;
}

int Invoice::getquantity(){
	return quantity;
}

void Invoice::setquantity(int stuff){
	if(stuff < 0){
		quantity = 0;
	}
	else quantity = stuff;
}

int Invoice::getInvoiceAmount(){
 	return price * quantity;

}

int Invoice::getprice(){
	return price;
}

void Invoice::setprice(int money){
	if(money < 0){
		price = 0;
	}else
		price = money;
}

void printInvoice( Invoice iv) {
	cout << iv.getPartNumber() << endl;
	cout << iv.getpartDescription() << endl;
	cout << "quantity " <<  iv.getquantity() << endl;
	cout << "price " <<  iv.getprice() << endl;
	cout << "amount " << iv.getInvoiceAmount() << endl;
}

int main() {
	Invoice myInvoice;
	myInvoice.setPartNumber("PN1234");
	myInvoice.setpartDescription("this is just a test");
	myInvoice.setquantity(10);
	myInvoice.setprice(8);
	cout << "printing test invoice:" << endl; 
	printInvoice(myInvoice);
}
