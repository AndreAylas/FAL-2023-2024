// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX=10001;
// función que resuelve el problema
vector<int> resolver(const vector<int>&dados,int valor) {
    vector<int> frecuencia(MAX,0);
    int maxfrecuencia=0;
    for(auto&i:dados){
        frecuencia[i]++;
        maxfrecuencia=max(maxfrecuencia,frecuencia[i]);
    }
    vector<int> carasrepetidas;
    for (int i = 0; i < frecuencia.size(); ++i) {
        if (frecuencia[i] == maxfrecuencia) {
            carasrepetidas.push_back(i);
        }
    }

    sort(carasrepetidas.rbegin(), carasrepetidas.rend());

    return carasrepetidas;
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n,v;
    cin>>n;
    if (n==-1)
        return false;
    cin>>v;
    vector<int> dados(n);
    for(int&i:dados)cin>>i;
    vector<int> sol = resolver(dados,v);
    
    // escribir sol
    for(int&i:sol){
        cout<<i<<" ";
    }
    cout<<"\n";
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}
