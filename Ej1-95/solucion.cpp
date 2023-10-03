// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;

// función que resuelve el problema

/*
n=numero de elementos a analizar
r=datos erroneos;
P={existe i:0<=i<n:v[i]=r and (-2^63<r and r<2^63)}
func resolver(inout: v[],inout: n,int r) dev sol[]

Q={contar=(#i:0<=i<n:v[i]!=r)}
*/

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int error;int n;
    cin>>n>>error;
    vector<int> sol;
    // escribir sol
    int num;
    int r=-1;
    for(int i=0;i<n;i++){
        cin>>num;
        if(num!=error){
            sol.push_back(num);
            r=0;
        }
    }
    if(r==-1){
        cout<<"0\n";
        cout<<"\n";
    }
    else{
        cout<<sol.size()<<"\n";
        for(auto&i:sol)cout<<i<<" ";
        cout<<"\n";
    }
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.in");
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