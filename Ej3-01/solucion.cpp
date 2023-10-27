// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;
// función que resuelve el problema
int sumaDigitos(int num){
    int result=0;
    if(num<10){
        return num;
    }
    else{
        int res=num%10;
        result+=res+sumaDigitos(num/10);
        return result;
    }
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n,num;
    cin>>n>>num;
    int sol=sumaDigitos(num);
    for(int i=0;i<n;i++){
        cin>>num;
        int r1=sumaDigitos(num);
        if(r1==sol){
            cout<<num<<" ";
        }
        else{
            cout<<" ";
        }
    }
    cout<<"\n";
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