

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;




 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool esValida(vector<vector<int>> const& vetos,const int k,  const int i, vector<bool> const& marcas, vector<int>const& sol) {

    return (!marcas[i] && (k == 0 || vetos[i][sol[k - 1]] == 1));
}

void va(vector<int>& sol, vector<vector<int>> const& estimaciones, vector<vector<int>> const& vetos, const int n, 
    const int k, int& mx, int donaciones, vector<bool>& marcas, vector<int> const& mejSol, int& maxDonacionRestante, bool& solucion) {

    for (int i = 0; i < n; i++)
    {
        sol[k] = i; //En la solucion k (turno de actuacion) actua el artista i

        if (esValida(vetos, k, i, marcas, sol)) {

            donaciones += estimaciones[i][k]; //donaciones que llevamos hasta el momento
            maxDonacionRestante -= mejSol[k]; //maximo valor de donaciones que podemos alcanzar

            if (k == n - 1) {
                solucion = true;
                if (donaciones > mx) mx = donaciones;
            }
            else if (donaciones + maxDonacionRestante > mx) { //Miramos si las donaciones que llevamos hasta el momento mas lo maximo que podriamos
                                                              // alcanzar puede ser mejor que nuestra solucion
                marcas[i] = true;
                va(sol, estimaciones, vetos, n, k + 1, mx, donaciones, marcas, mejSol, maxDonacionRestante, solucion);
                marcas[i] = false;

            }

            donaciones -= estimaciones[i][k];
            maxDonacionRestante += mejSol[k];

        }

    }
}

int resolver(vector<vector<int>> const& estimaciones, vector<vector<int>> const& vetos, 
    const int n, vector<int>const& mejSol, int& maxDonacion, const int minDonacion) {

    int mx = minDonacion; //Iniciamos el valor mx que llevamos a lo minimo que podriamos obtener para asi saltar casos
    vector<int> artista(n);
    vector<int> sol(n);
    vector<bool> marcas(n);
    bool solucion = false;


    va(sol, estimaciones, vetos, n, 0, mx, 0, marcas, mejSol, maxDonacion, solucion);

    if (!solucion) return 0;
    return mx;
}

void resuelveCaso() {

    int n;
    cin >> n;
    vector<vector<int>> estimaciones(n, vector<int>(n));

    //Realizamos una cota superior e inferior del maximo y minimo beneficio que obtendriamos por cada turno de actuaciones

    //La cota superior sirve para ver si el beneficio que llevamos sumado al maximo que podriamos conseguir es mayor al 
    //mejor beneficio, en caso de que no lo sea es imposible que sea solucion.

    //La cota inferior sirve para iniciar el maximo beneficio inicial a un valor que no sea 0, ya que obtendremos uno mayor

    vector<int> mejSol(n);
    int maxDonacion = 0;

    vector<int> peorSol(n, INT_MAX);
    int minDonacion = 0;


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> estimaciones[i][j];

            if (mejSol[j] < estimaciones[i][j]) {  //Cota superior de las donaciones, lo maximo que podriamos conseguir

                if (mejSol[j] != 0) {
                    maxDonacion -= mejSol[j];
                }
                mejSol[j] = estimaciones[i][j];
                maxDonacion += mejSol[j];
            }

            if (peorSol[j] > estimaciones[i][j]) {  //Cota inferior de las donaciones, lo minimo que podriamos conseguir

                if (peorSol[j] != INT_MAX) {
                    minDonacion -= mejSol[j];
                }
                peorSol[j] = estimaciones[i][j];
                minDonacion += peorSol[j];
            }
        }
    }

    vector<vector<int>> vetos(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> vetos[i][j];

        }
    }

    int mx = resolver(estimaciones, vetos, n, mejSol, maxDonacion, minDonacion);

    if (mx == 0 ? cout << "NEGOCIA CON LOS ARTISTAS" : cout << mx);

    cout << "\n";
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ejExtra-15.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}