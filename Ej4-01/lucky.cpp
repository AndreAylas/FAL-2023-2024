// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
using lli=long long int;
// función que resuelve el problema
int searchleft(const vector<lli>&v,int alt,int ini,int fin) {
    if(ini==fin){
        return v[ini]==alt?ini:v.size();
    }
    else if(ini+1==fin){
        if(v[ini]==alt)
            return ini;
        else if(v[fin]==alt)
            return fin;
        else
            return v.size();
    }
    else{
        int m=(ini+fin)/2;
        if(alt<=v[m])
            return searchleft(v,alt,ini,m);
        else
            return searchleft(v,alt,m+1,fin);
    }
    
}

int searchright(const vector<lli>&v,int alt,int ini,int fin) {
    if(ini==fin){
        return v[fin]==alt?fin:v.size();
    }
    else if(ini+1==fin){
        if(v[fin]==alt)
            return fin;
        else if(v[ini]==alt)
            return ini;
        else
            return v.size();
    }
    else{
        int m=(ini+fin)/2;
        if(alt>=v[m])
            return searchright(v,alt,m,fin);
        else
            return searchright(v,alt,ini,m-1);
    }
    
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    lli num;
    int h;
    cin>>num>>h;
    if (! std::cin)
        return false;
    vector<lli> alturas(num);
    for(auto&i:alturas)cin>>i;
    int ini=0,fin=alturas.size()-1;
    int ladLeft=searchleft(alturas,h,ini,fin);
    // escribir sol
    if(ladLeft==alturas.size()){
        cout<<"NO EXISTE\n";
    }
    else{
        int ladRight=searchright(alturas,h,ini,fin);
        if(ladLeft==ladRight)
        {
            cout<<ladLeft<<"\n";
        }
        else{
            cout<<ladLeft<<" "<<ladRight<<"\n";
        }
    }
    
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