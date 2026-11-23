/*
LC 1352. Product of the Last K Numbers

Design an algorithm that accepts a stream of integers and retrieves the product of the last k integers of the stream.

Implement the ProductOfNumbers class:
- ProductOfNumbers() Initializes the object with an empty stream.
- void add(int num) Appends the integer num to the stream.
- int getProduct(int k) Returns the product of the last k numbers in the current list. You can assume that always the current list has at least k numbers.
The test cases are generated so that, at any time, the product of any contiguous sequence of numbers will fit into a single 32-bit integer without overflowing.


Consitions:
    0 <= num <= 100
    1 <= k <= 4 * 104
    At most 4 * 104 calls will be made to add and getProduct.
    The product of the stream at any point in time will fit in a 32-bit integer.    

*/

#include <iostream>
using namespace std;


// Solution 1
class ProductOfNumbers {
    vector<int> productsTillN; // stores the product of numbers till n
    int product;

public:
    ProductOfNumbers(){
        productsTillN = {};
        product = 1;
    }

    void add(int num){
        // for the first num

        if(num == 0){ // reset everything
            productsTillN = {};
            product = 1;
            return;
        }

        product *= num;
        productsTillN.push_back(product);
    }
        
    int getProduct(int k) {
        // as it's give in the condition k >= 1 
        int n = productsTillN.size();
        if(k>n) return 0;
        if(n == k) return productsTillN[n-1];
        else return productsTillN[n-1]/productsTillN[n-k-1];
    }
};


/*
Solution - 2 : Standard solution
class ProductOfNumbers {
    vector<int> productsTillN;

public:
    ProductOfNumbers(){
        productsTillN = {1};
    }

    void add(int num){
        if(num == 0){
            productsTillN = {1};
        }else{
            productsTillN.push_back( productsTillN.back() * num );
        }
    }
        
    int getProduct(int k) {
        int n = productsTillN.size();
        if (k >= n) return 0;    // window reaches past the last zero
        return productsTillN[n-1] / productsTillN[n-k-1];
    }
};

*/