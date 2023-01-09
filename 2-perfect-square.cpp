// Kunsang Tsering
#include <iostream>
using namespace std;
int main() {
    // for each number, square it and check if the last 2 digits are odd
   for (int i = 1; i <= 99; ++i) { 
      int square = i * i;
   // if you find a solution, exit the program (so the error message below won't be printed)
      if (square % 2 != 0 && (square / 10) % 2 != 0) {
         cout << square;
         return 0; 
      }
   }
   // Testing only the first 99 numbers is sufficient,
  // because the last 2 digits of a square depends only on the last 2 digits of the number being squared.
   cout << "There is no solution that exist";
   
   return 0;
}