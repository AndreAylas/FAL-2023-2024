// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>   
#include<math.h>
using namespace std;

struct tSol{
    bool disp;
};


// función que resuelve el problema
tSol resolver(const vector<int> &v,int k,int ini,int fin) {
    if(ini==fin){
        return {true};
    }
    else if(abs(v[ini]-v[fin])<k){
        return {false};
    }
    else{
        int m=(ini+fin)/2;
        tSol izq=resolver(v,k,ini,m);
        tSol der=resolver(v,k,m+1,fin);
        return {izq.disp && der.disp};
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n,k;
    cin>>n>>k;
    if (! std::cin)
        return false;
    vector<int> v(n);
    for(auto&i:v)cin>>i;

    tSol s = resolver(v,k,0,v.size()-1);
    if(s.disp)
        cout<<"SI";
    else
        cout<<"NO";
    cout<<"\n";
    // escribir sol
    
    
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