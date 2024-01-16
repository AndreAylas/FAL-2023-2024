// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;

// función que resuelve el problema
int resolver(const vector<int>&v,int minPeso,int pesoTotal,int nviajes ) {
    if(minPeso==pesoTotal)return minPeso;
    else{
        int pesoPromedio=(minPeso+pesoTotal)/2;
        int numviajes=0,pesocamion=0;
        for(auto&i:v){
            pesocamion+=i;
            if(pesocamion>=pesoPromedio){
                numviajes++;
                if(pesocamion==pesoPromedio)pesocamion=0;
                else pesocamion=i;
            }
        }
         if(pesocamion > 0)numviajes++;
        if (numviajes <= nviajes)return resolver(v, minPeso, pesoPromedio, nviajes);
        else return resolver(v,pesoPromedio+1,pesoTotal, nviajes);
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nartes,nviajes;
    cin>>nartes>>nviajes;
    if (nartes==0 && nviajes==0)
        return false;
    vector<int> v(nartes);
    int sumaPesos=0,maxPeso=0;
    for(auto&i:v){
        cin>>i;
        sumaPesos+=i;
        maxPeso=max(maxPeso,i);
    }

    // escribir sol
    int sol = resolver(v,maxPeso,sumaPesos,nviajes);
    cout<<sol<<"\n";
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
