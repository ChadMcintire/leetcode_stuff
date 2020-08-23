#include <iostream>

class Solution {
public:
    int reverse(int x) {
        int neg = 0;
        int reversed = 0;
        
        std::cout << x << "\n";
        if (x < 0 && x > -2147483648){
            neg++;
            x = x *-1;
        }
        else if (x == -2147483648){
            neg += 2;
            x += 1;
            x *= -1;
        }
        //std::cout << x << "inside the loop" << "\n";
        //std::cout << neg << "inside the loop" << "\n";
        //std::cout << x << "\n";

        
        while (x)
        {
            int adder = x % 10;
            x=x/10;
            std::cout << reversed << "\n\n";
            if (reversed != 0){
                if (reversed <= 214748364)
                {
                    reversed *= 10;
                }
                else{
                    std::cout << "<= 214748364 *10";
                    return 0;
                }
                
                if (reversed <= 2147483638){
                    reversed += adder;
                }
                else if (reversed > 2147483638)
                {
                    while (reversed < 2147483647 && adder > 0){
                    adder--;
                    reversed++;
                    }
                    if (adder > 0){
                        std::cout << "adder greater than 0";
                        return 0;
                    }
                }
                else if(reversed <= 2147483640 && adder == 8 && neg == 1){
                    reversed += adder;
                    reversed *= -1;
                    neg--;
                }
                else{
                    return 0;
                }
            }
            else{
                if (neg == 2){
                    adder+=1;
                    neg--;
                }
                std::cout << "first else";
                reversed += adder;
            }
        }
        
        if (neg != 0)
        {
            reversed *=-1;
        }

        if (reversed  < -2147483648 || reversed > 2147483647) {
            return 0;              
        }

        std::cout << reversed << "final\n";
        return reversed;
    }
};

int main(){
    int x = -2147483648;
    //int x = -123;
    Solution s;
    s.reverse(x);
}
