// Dinamico.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;
class Solution {
public:
    map<int, int> valores;

    int coinChange(vector<int>& coins, int amount) {
        /*
        NAIVE SOLUTION
        if(amount<0)
            return -1;
        if (amount == 0)
            return 0;
        vector<int> rutas;
        for (auto c : coins)
        {
            rutas.push_back(coinChange(coins, amount - c));
        }
        int answer = 10'000;
        for (auto r : rutas)
        {
            if (r < 0)
                continue;
            if (r < answer)
                answer = r;
        }
        if (answer == 10'000)
        {
            return -1;
        }
        else
            return answer + 1;
        */
        if (amount < 0)
        {
            valores.insert(pair<int,int>(amount, -1));
            return -1;
        }

        if (amount == 0)
        {
            valores.insert(pair<int, int>(amount, 0));
            return 0;
        }
        vector<int> rutas;
        for (auto c : coins)
        {
            auto it=valores.find(amount - c);
            if (it!=valores.end())
            {
                rutas.push_back(it->second);
            }
            else
                rutas.push_back(coinChange(coins, amount - c));
        }
        int answer = 10'000;
        for (auto r : rutas)
        {
            if (r < 0)
                continue;
            if (r < answer)
                answer = r;
        }
        if (answer == 10'000)
        {
            valores.insert(pair<int, int>(amount, -1));
            return -1;

        }
        else
        {
            valores.insert(pair<int, int>(amount, answer+1));
            return answer + 1;
        }
            
    }
};

int main()
{
    Solution s;
    vector<int> c1 = { 1,2,5 };
    int a1 = 11;
    s.valores.clear();
    std::cout << "Respuesta: "<<s.coinChange(c1,a1)<<endl;

    vector<int> c2 = { 2 };
    int a2 = 3;
    s.valores.clear();
    std::cout << "Respuesta: " << s.coinChange(c2, a2) << endl;

    vector<int> c3 = { 1 };
    int a3 = 0;
    s.valores.clear();
    std::cout << "Respuesta: " << s.coinChange(c3, a3) << endl;

    vector<int> c4 = { 1 };
    int a4 = 1;
    s.valores.clear();
    std::cout << "Respuesta: " << s.coinChange(c4, a4) << endl;

    vector<int> c5 = { 1 };
    int a5 = 2;
   s.valores.clear();
    std::cout << "Respuesta: " << s.coinChange(c5, a5) << endl;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
