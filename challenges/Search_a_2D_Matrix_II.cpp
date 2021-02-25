#include <vector>
#include <iostream>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

using namespace std;

class Solution {
private:
    int vertMax;
    int horMax;
    int currentRow = 0;
    int currentCol = 0;
    bool cycle = true;
public:
    bool findColMax(vector<vector<int>>& matrix, int target){
        for (int i = currentRow; i < vertMax; i++){
            if (matrix[i].at(currentCol) == target){
                std::cout << "found in row cycle2 =" <<
                matrix[i].at(currentCol) << "\n";
                return true;
            }
            else if (matrix[i].at(currentCol)>target){
                vertMax = i;
                std::cout <<  (matrix[i].at(currentCol)>target);
                break;
            }
        }
        currentCol++;
        return false;
    }

    bool findMax(vector<vector<int>>& matrix, int target){
        //cout << currentRow;
        for (int i = currentRow; i < horMax; i++){
          std::cout << "\nValue of row i " << i;
          std::cout << "\nValue " << matrix[currentRow].at(i);
          std::cout << "\nValue of target" << target;
            if (matrix[currentRow].at(i) == target){
                std::cout << "found in row cycle1=" << 
                matrix[currentRow].at(i) << "\n";
                return true;
            }
            if ( matrix[currentRow].at(i) > target){
                std::cout << "\nDid I reach this " << matrix[currentRow].at(i);
                horMax = i; 
                break; 
            }
        }
        currentRow++;
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    horMax = matrix[0].size();
    int count = 0;
    vertMax = matrix.size();
    cout << "\nbvert max = " << vertMax << "\nbhorMap = " << horMax << '\n';
    if (horMax == 1 && vertMax == 1)
    {
        cout << "\nmade it to the 1x1";
        if (target == matrix[0].at(0)){
            cout << "\nfound target made it to the 1x1";
            return true;
        }
        else{
            cout << "\ndidn't find target made it to the 1x1";
            return false;
        }
    }

    cout << "\nbefore sleep ";
    std::this_thread::sleep_for (std::chrono::seconds(2));

    while (cycle){
        cout << "\nvert max = " << vertMax << "\nhorMax = " << horMax << '\n';
        cout << "\ncurrentRow= " << currentRow << 
        "\ncurrentCol = " << currentCol << '\n';
        //std::this_thread::sleep_for (std::chrono::seconds(2));
        if (currentRow >= horMax || currentCol >= vertMax){
            cout << "found nothing";
            return false;
        }
        if(findMax(matrix, target) == true || 
        findColMax(matrix, target) == true){
            cout << "returning true";
            return true;
        }
        cout << "last part of while";
    }
        cout << "after while";
    
//        max = matrix[0].size();
//        int newmax = 0;
//        //cout << "Max = " << max << '\n';
//        for (int i = 0; i < matrix.size(); i++){
//            //cout << "Max = " << max << '\n';
//            cout << "\nvalue of i = " << i;
//            cout << "\nmatrix size = " << matrix[i].size();
//            for (int j = 0; j < matrix[i].size(); j++){
//                cout << "\nvalue of j = " << j;
//                cout << "\nvalue at i bot for " << matrix[i].at(j) << "\n";
//
//                if (matrix[i].at(j) == target){
//                    return true;
//                }
//                else if (matrix[i].at(j)<target){
//                //cout << "value at i else if" << matrix[0].at(i) << "\n";
//
//                //newmax = j;
//                //cout << newmax;
//                }
//              
//            }
//            //max = newmax;  
//        }
        std::cout << "didn't find it" << '\n';
        return false;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> matrix
    {
        //{1, 4, 7, 11, 15},
        //{2, 5, 8, 12, 19},
        //{3, 6, 9, 16, 22},
        //{10, 13, 14, 17, 24},
        //{18, 21, 23, 26, 30}

        //{1, 1} //0
        {1, 1} //2

        //{-1},
    };

    int target =2;
    cout << "does it return correctly";
    if (sol.searchMatrix(matrix, target) == false){
        cout << "really nothing was found";
    }

}
