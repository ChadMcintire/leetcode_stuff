#include <iostream>
int countDigit(int n) 
{ 
    int count = 0; 
    while (n != 0) { 
        n = n / 10; 
        ++count; 
    } 
    return count; 
} 

int reverse(int n){
   int reversed = 0;
   while (n)
   {
       int adder = n % 10;
       n=n/10;
       if (reversed != 0){
           if (reversed <= 214748364)
           {
               reversed *= 10;
           }
           else{
               return false;
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
                   return 0;
               }
           }
           else{
               return false;
           }
       }
       else{
           reversed += adder;
       }
   }
   return reversed;
}

bool checkPalindrome(int a, int b){
    //std::cout << " a-orig " << a << " b " << b << "\n\n";
    while (a && b) {
       int aNum = a % 10;
       int bNum = b % 10;
       a = a / 10;
       b = b / 10;
       //std::cout << " a " << a << " b " << b << "\n\n";
       //std::cout << " aNum " << aNum << " bNum " << bNum << "\n\n";
       if(aNum != bNum){
       //std::cout << " " << aNum << " " << bNum << " if " << "\n\n";
          return false;
        }
    }
    return true;
}

class Solution {
public:
    bool isPalindrome(int x) {
        int reversed;

        if (x < 0){
            return false;
        }

        reversed = reverse(x); 
        int revCount = countDigit(reversed);
        int count = countDigit(x);

        if (revCount != count){
            return false;
        }
                
        //std::cout << revCount << "\n\n";
        //std::cout << count << "\n\n";
        bool isPalindrome = checkPalindrome(x, reversed);
        //std::cout << isPalindrome << "\n\n";
        return isPalindrome;
    }
};

int main(){
    int x = 12121;
    Solution s;
    s.isPalindrome(x);
}
