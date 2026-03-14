#include <iostream>
#include <vector>

int main()
{
    // create 3x3 matrix arr with numbers 1 to 9
    std::vector<std::vector<int>> arr(3, std::vector<int>(3));
    int val = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr.at(i).at(j) = val;
            val++;
        }
    }

    std::cout << "Matrix:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << arr.at(i).at(j) << " ";
        }
        std::cout << "\n";
    }

    // assign variables to each element for easier reading
    int a = arr.at(0).at(0);
    int b = arr.at(0).at(1);
    int c = arr.at(0).at(2);
    int d = arr.at(1).at(0);
    int e = arr.at(1).at(1);
    int f = arr.at(1).at(2);
    int g = arr.at(2).at(0);
    int h = arr.at(2).at(1);
    int i = arr.at(2).at(2);

    // compute determinant
    int det = a*(e*i - f*h) - b*(d*i - f*g) + c*(d*h - e*g);
    std::cout << "\nDeterminant: " << det << "\n";

    if (det == 0) {
        std::cout << "Matrix is not invertible.\n";
        return 0;
    }

    // compute minors
    std::vector<std::vector<int>> minor(3, std::vector<int>(3));
    minor[0][0] = e*i - f*h;
    minor[0][1] = d*i - f*g;
    minor[0][2] = d*h - e*g;
    minor[1][0] = b*i - c*h;
    minor[1][1] = a*i - c*g;
    minor[1][2] = a*h - b*g;
    minor[2][0] = b*f - c*e;
    minor[2][1] = a*f - c*d;
    minor[2][2] = a*e - b*d;

    std::cout << "\nMinor matrix:\n";
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            std::cout << minor[i][j] << " ";
        }
        std::cout << "\n";
    }

    // compute cofactor matrix (alternate signs)
    std::vector<std::vector<int>> cofactor(3, std::vector<int>(3));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cofactor[i][j] = ((i+j)%2==0 ? 1 : -1) * minor[i][j];
        }
    }

    std::cout << "\nCofactor matrix:\n";
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            std::cout << cofactor[i][j] << " ";
        }
        std::cout << "\n";
    }

    // compute adjugate (transpose of cofactor)
    std::vector<std::vector<int>> adj(3, std::vector<int>(3));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            adj[i][j] = cofactor[j][i];
        }
    }

    std::cout << "\nAdjugate matrix:\n";
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            std::cout << adj[i][j] << " ";
        }
        std::cout << "\n";
    }

    // compute inverse = (1/det) * adj
    std::vector<std::vector<double>> inv(3, std::vector<double>(3));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            inv[i][j] = adj[i][j] / double(det);
        }
    }

    std::cout << "\nInverse matrix:\n";
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            std::cout << inv[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
