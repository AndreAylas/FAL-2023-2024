// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
/*
ini=año de inicio
fin=año de fin
P={1700<=ini<fin<=100000 and forall i:0<=i<N and N=fin-ini+1: -2^31+1<=v[i] and v[i]<2^31+1}

func resolver(v,ini) dev v[]:vector<int>

Q=

*/

vector<int> resolver(const vector<int>&v,int ini) {
    vector<int> sol;
    int ventas=v[0];
    for(int i=1;i<v.size();i++){
        if(ventas<v[i]){
            ventas=v[i];
            sol.push_back(ini+i);
        }
    }
    return sol;
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int p,q;//año de inicio y año de fin respectivamente
    cin>>p>>q;
    int n=q-p+1;
    vector<int> v(n);
    for(auto&i:v)cin>>i;

    vector<int> sol = resolver(v,p);
    // escribir sol
    if(!sol.empty()){
        for(auto&i:sol){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    else{
        cout<<" \n";
    }
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}