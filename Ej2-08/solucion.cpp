// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include<algorithm>
using namespace std;


// función que resuelve el problema

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n,altura;
    cin>>n>>altura;
    if (! std::cin)
        return false;
    
    vector<pair<string,int>>v(n);
    for(auto&p:v)cin>>p.first>>p.second;

    vector<pair<string,int>>bajos,altos;
    // escribir sol
    for(auto&p:v){
        if(p.second<=altura){
            bajos.push_back(p);
        }else{
            altos.push_back(p);
        }
    }
    sort(bajos.begin(),bajos.end());
    sort(altos.begin(),altos.end());
    cout<<"Bajos: ";
    for(auto&b:bajos){
        cout<<b.first<<" ";
    }
    cout<<"\n";
    cout<<"Altos: ";
    for(auto&a:altos){
        cout<<a.first<<" ";
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