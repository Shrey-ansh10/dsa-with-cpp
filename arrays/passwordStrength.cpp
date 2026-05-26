
// LC-3941 : Password Strength

#include <iostream>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int passwordStrength(string password) {

        unordered_set<int> uniqueChars;
        int strength = 0;
        for(char c : password){
            if(uniqueChars.find(c) == uniqueChars.end()){ // if we don't find the char in the set then only we proceed
                if( 'a' <= c && c <= 'z'){
                    strength+=1;
                    uniqueChars.insert(c);
                }else if('A' <= c && c <= 'Z'){
                    strength+=2;
                    uniqueChars.insert(c);
                }else if('0'<= int(c) && int(c) <= '9'){
                    strength+=3;
                    uniqueChars.insert(c);
                }else if(c == '!' || c == '@' || c == '$' || c == '#'){
                    strength+=5;
                    uniqueChars.insert(c);
                }
            }
        }
        return strength;
    }
};