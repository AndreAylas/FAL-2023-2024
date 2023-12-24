// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
struct tCristal{
    int nivel=0;//nivel de grupo
    int totalAttack=0;//total de ataque en grupo
    vector<int> gHeroes;//party heroes

};
struct tHeroes{
    vector<int>clase;
    vector<int>nivel;
    vector<int>attack;
    tHeroes(int H):clase(H),nivel(H),attack(H){}
};
// función que resuelve el problema
const int MAXIMO=1e9;
void dragon(int k,vector<int>&sol,int & minCristales,const int H,const int N,const int M,const int PV,const tHeroes &h,vector<tCristal> &grupos,int &cristales,int &ataque,int &huecos){
    //probamos a asignar al heroe a un cristal ya usado
    for(int i=0;i<cristales;i++){
        if(compatible(k,grupos[i],M,h.clase,h.nivel)){
            sol[k]=i;
            
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    int H,N,M,PV;
    cin>>H>>N>>M>>PV;
    tHeroes h(H);
    for(auto&i:h.clase)cin>>i;
    for(auto&i:h.nivel)cin>>i;
    for(auto&i:h.attack)cin>>i;

    vector<int> sol(H);
    int minimoCristal=MAXIMO;
    int cristal=0;
    vector<tCristal> grupos;


    // escribir sol
    
    
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