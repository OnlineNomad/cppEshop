#include <iostream>

using namespace std;

class Eshop {
    public:
        void sellProduct() {
            cout << "Sell" << endl;
        }
        void fillProduct() {
            cout << "Fill" << endl;
        }
};
class AbstractProduct: public Eshop {
    private: 
        int ProductAmount;
        float ProductPrice;
    protected:
        string ProductName;
    public:
        static int ProductCount;
        
        AbstractProduct (string ProductName, float ProductPrice, int ProductAmount) {
            this -> ProductName = ProductName;
            this -> ProductPrice = ProductPrice;
            this -> ProductAmount = ProductAmount;
            
            ProductCount++;
            
        }
        
        virtual void productConsume()=0;
        
        void sellProduct(int xAmount) {
            cout << xAmount << " of " << ProductName << " sold." << endl;
            ProductAmount -= xAmount;
        }
        void fillProduct(int yAmount) {
            cout << yAmount << " of " << ProductName << " filled." << endl;
            ProductAmount += yAmount;
        }
        void getDescription() {
            cout << "\nName: " << ProductName << endl;
            cout << "Product Price: " << ProductPrice << endl;
            cout << "ProductAmount: " << ProductAmount << endl;
        }
};
int AbstractProduct::ProductCount;

class Product: public AbstractProduct {
    public:
        
        Product(string ProductName, float ProductPrice, int ProductAmount): AbstractProduct(ProductName, ProductPrice, ProductAmount){
            
        }
        void productConsume() {
            cout << "Consumed: " << ProductName << endl;
        }
};

int main()
{
    Eshop shop;
    Product bread("Bread", 10.5, 4000);
    bread.sellProduct(300);
    bread.fillProduct(100);
    bread.getDescription();
    
    
    
    
    cout << "count of products: "  << AbstractProduct::ProductCount << endl;
    
    return 0;
}
