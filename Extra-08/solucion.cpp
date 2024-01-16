// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;

struct tCanicas{
    string nombre;
    int canicas;
};

// función que resuelve el problema
tCanicas resolver(const vector<tCanicas> &v,int ini,int fin) {
    
    if(ini+1==fin){
        if(v[ini].canicas<v[fin].canicas){
            int cantidad=v[fin].canicas+v[ini].canicas*0.5;
            return {v[fin].nombre,cantidad};
        }else if(v[ini].canicas>v[fin].canicas){
            int cantidad=v[ini].canicas+v[fin].canicas*0.5;
            return {v[ini].nombre,cantidad};
        }else{
            int cantidad=v[ini].canicas+v[fin].canicas*0.5;
            return {v[ini].nombre,cantidad};
        }
    }else{
        int m=(ini+fin)/2;
        tCanicas izq=resolver(v,ini,m);
        tCanicas der=resolver(v,m+1,fin);
        if(izq.canicas<der.canicas){
            int cantidad=der.canicas+izq.canicas*0.5;
            return {der.nombre,cantidad};
        }
        else{//caso izq>=der
            int cantidad=izq.canicas+der.canicas*0.5;
            return {izq.nombre,cantidad};
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin>>n;
    if (! std::cin)
        return false;
    vector<tCanicas>v(n);
    for(auto&c:v)cin>>c.nombre>>c.canicas;
    // escribir sol
    auto sol = resolver(v,0,n-1);
    cout<<sol.nombre<<" "<<sol.canicas<<"\n";
    
    
    
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