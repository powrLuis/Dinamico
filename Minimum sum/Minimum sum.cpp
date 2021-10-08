// Minimum sum.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int cell(vector<vector<int>>& matrix, int x, int y)
    {
        if (x==matrix.size()-1)
        {
            return matrix[x][y];
        }

        vector<int> fall;

        if (y>0)
        {
            fall.push_back(cell(matrix, x + 1, y - 1));
        }
        fall.push_back(cell(matrix, x + 1, y));
        if (y<matrix.size()-1)
        {
            fall.push_back(cell(matrix, x + 1, y + 1));
        }
        auto menor = min_element(fall.begin(), fall.end());
        return *menor + matrix[x][y];
    }
    vector<vector<int>> fill(vector<vector<int>>& matrix)
    {
        vector<vector<int>> temp = matrix;
        int n = temp.size();
        for (int i = n - 1; i > 0; i--)
        {
            for (size_t j = 0; j < n; j++)
            {
                int up = temp[i][j];
                if (j > 0 && temp[i][j - 1] < up)
                {
                    up = temp[i][j - 1];
                }
                if (j < n - 1 && temp[i][j + 1] < up)
                {
                    up = temp[i][j + 1];
                }
                temp[i - 1][j] += up;
            }
        }
        return temp;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        //NAIVE
        /*vector<int> fall;
        for (size_t i = 0; i < matrix.size(); i++)
        {
            fall.push_back(cell(matrix, 0, i));
        }
        auto menor = min_element(fall.begin(), fall.end());
        return *menor;*/

        auto values = fill(matrix);
        vector<int> fall;
        for (size_t i = 0; i < matrix.size(); i++)
        {
            fall.push_back(values[0][i]);
        }
        auto menor = min_element(fall.begin(), fall.end());
        return *menor;

    }
};

int main()
{
    Solution s;
    vector<vector<int>> m1 = { {2,1,3},{6,5,4},{7,8,9} };
    std::cout << "resultado: "<<s.minFallingPathSum(m1) << endl;
    vector<vector<int>> m2 = { {-19,57},{-40,-5}};
    std::cout << "resultado: " << s.minFallingPathSum(m2) << endl;
    vector<vector<int>> m3 = { {-48} };
    std::cout << "resultado: " << s.minFallingPathSum(m3) << endl;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
