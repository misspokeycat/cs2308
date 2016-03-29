#ifndef Product_h
#define Product_h
#include <string>

using namespace std;
class Product{
	private:
		string name;
		string locator;
		int quantity;
		float price;
	public:
		Product();
		Product(string pname, string plocator, int qty, float pr);
		//• set and get all instance variables (make the instance variables private).
		string getName();
		void setName(string newval);
		string getLocator();
		void setLocator(string newval);
		int getQuantity();
		void setQuantity(int newval);
		float getPrice();
		void setPrice(float newval);
		bool isEqual(Product p);
		bool greaterThan(Product p);
};

#endif
