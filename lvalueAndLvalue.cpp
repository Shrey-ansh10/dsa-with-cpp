// What are lvalues and rvalues?

#include<iostream>
using namespace std;

int main(){

    // lvalues came left-values, but left means little in lvalue. 
    // Instead it is more about generally is towards the left of the = sign. 
    // generally we assign some value to the variable to the left of the =
    // the variable occupies some memory, can store some values and has a name. 
    // that's what lvalue is 

    // lvalue reference : it's a reference to lvalue
    // defined as -> 'dataType&'(writng the datatype it's refering to followed by & symbol)
    // 'int& m' <- here m is a lvalue reference variable or commonly called lvalue ref
    // it can refer to a lvalue only.

    int x = 10; // so here x is a 'lvalue', cos it's occupying some memory and has a memory address
    int& y = x; // y is a lvalue reference, it refers to x, the exact same memory location and hence the exact same value 
    // all operation that can be done on x can be done on y  
    // that also raises a point, is y just another name of x? yes it is, it's an alias for x, both name's belong to the same perosn.

    cout << "Value of x = " << x << endl;
    cout << "Value of y = " << y << endl; // will be same as x

    cout << "Address of x : " << &x << endl; 
    cout << "Addredd of y : " << &y << endl; // same as x's address


    // if we expirement, many will try to do this
    // int& m = 10; // this will produce error --- WHY? 'int&' is a reference to a variable/lvalue, and 10 is a literal, not a vriable in memory with a memory location. 
 
    
    // Move Semantics : Transfer large resources from temp objects.

    // rvalues :
    // r came from right, which refers to values on right side of =, but of course it has very less to do with it. Basicallu a bad naming.
    // SO, rvalue literally means 'literals'
    // eg. 5, 10, 25, "Hello", 'm', {1,2,4}, "chipotle", etc are all literals, and hence considered rvalues. 
    // Now we know why it's kinda shit naming
    // anyways, rvalues represent something that's temp, that not stored in memory
    // if we lean more towards defination, it goes as follow
    // Rvalue = a temporary value that doesn't have a persistent identity.
        // It's produced by an expression and typically dies at the end of that expression.
        // You cannot normally take its address 

    // rvalue reference : introduced in C++11
    // rvalue reference simply menas 'refereing/reference to rvalue'.
    // The purpose of introducing rvalue references were :
    // 1. Move Semantics: Stealing expensive resources (like heap memory) from temporary objects instead of deep-copying them. 
    // 2. Lifetime Extension: Keeping a temporary object alive until the reference goes out of scope.
 
    // I can say this is how you code it -> int&& r = 100; well that's techically right, but possily the worst and dumbest way to explain rvalue reference.
    // So let's go by an example - not perfect but at least better than the latter 

    // we have a function sum
    auto add2values = [](const int& val1, const int& val2){ // notice here both of the inputs are lvalues references, but in the function call we're passing rvalues, so therefore we needed to make these lvalue references as const (it's an excetion in lvalue reference - which i've discussed later) 
        // because "const int&"" can bind to BOTH 'lvalues' and 'rvalues'. 
 
        return val1 + val2; // imagine : this sum of val1 and val2 is calculated and stored in memory, which is temperary memory, as soon as this function ends, all it's data will go out of scope/deleted. 
        // with rvalues, we try to preserve the already allocated memory to the data it produces and directly refer to that data, mitigating the copy step. (this is just an anology to explain how it works on complex datatypes) 
        // Note : That's not completely true, but imagine instead of this 'int' if we have a very big complex object initiated at runtime, with many attributes, some of those attributes are pointers and some are objects themselves with many attributes in them. 
            // Copying such big complex object would be a hastel, and then deleting this one would be a little dumb, so instead we just transfet the ownership or imagine like this object stays at the memory, we just tell the rvalue reference to refer this object's memory location. 
            // When the data is complex, That's when rvalues are most useful, they mitigate the need of copying.

        /* 
            (Note: For a simple 'int' (i.e. "val1 + val2"), the C++17 compiler is already smart enough to 
                    build the result directly into the receiver's memory, so no copy happens here for our int)
        */
    };

    int&& r = add2values(10, 20); // now this 'r' is a rvalue reference, the values passes inside are rvalues(although they can be lvalues), the return is an rvalue as well.

    /* 
     * WHY USE 'int&&' HERE?
     * Simple datatype like 'int', 'int r' and 'int&& r' perform identically (no copy happens).
     * However, using '&&' explicitly tells the compiler and other programmers:
     * "I am intentionally catching a temporary value, and I am extending its 
     * lifetime to match the scope of 'r'." 
     * 
     * If this were a complex object (like std::string), using '&&' here would 
     * trigger the "Move Constructor", stealing the internal memory instead of 
     * performing a slow, deep copy.
     */

    // generally rvalue raference is used to avoid doing deep copy od complex objects, and rather transfer the ownership to a rvalue reference


    return 0;
}

