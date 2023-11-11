// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
// función que resuelve el problema
bool resolver(const vector<int>&v,int num,int ini,int fin) {
    if(ini==fin)return false;
    else if(ini+1==fin)
        return v[ini]==num?true:false;
    else{
        int m=(ini+fin)/2;
        if(v[m]==num)return true;
        else if(v[m]>v[ini]){
            if(v[ini]<=num && num<=v[m])return resolver(v,num,ini,m);
            else return resolver(v,num,m,fin);
        }
        else{
            if(v[m]<=num && num<=v[fin-1]) return resolver(v,num,m,fin);
            else return resolver(v,num,ini,m);
        }
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tam,num;
    cin>>tam>>num;   
    if (tam==-1)
        return false;
    vector<int> v(tam);
    for(auto&i:v)cin>>i;
    bool sol = resolver(v,num,0,v.size());
    
    // escribir sol
    if(sol)cout<<"SI\n";
    else cout<<"NO\n";
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
