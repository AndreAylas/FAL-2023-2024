// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX=10001;
// función que resuelve el problema
/*
n=numero de tiro de dados
valor=puntaje maximo de las tiradas
tam=numero de caras
m=tamaño de la solucion
P=(6<=tam<10000 && 0<n<=200000 && forall i:0<=i<n:v[i]>0 && v[i]<valor)

func (v[],int n ,int valor) dev sol[]
forall i:0<=i<10001:frecuencia[i]=0
Q=( forall j:0<=j<n:frecuencia[v[i]]=frecuencia[v[i]]+1 && maxfrecuencia=forall 0<=i<n:max(maxfrecuencia:frecuencia[i])
                                            &&
    forall l:0<=l<m:sol[l]=(forall k:0<=k<n && frecuencia[k]=maxfrecuencia:k))
*/
vector<int> resolver(const vector<int>&dados,int valor) {
    vector<int> frecuencia(MAX,0);
    int maxfrecuencia=0;
    for(auto&i:dados){
        frecuencia[i]++;
        maxfrecuencia=max(maxfrecuencia,frecuencia[i]);
    }
    vector<int> carasrepetidas;
    for (int i = 0; i < frecuencia.size(); ++i) {
        if (frecuencia[i] == maxfrecuencia) {
            carasrepetidas.push_back(i);
        }
    }

    sort(carasrepetidas.rbegin(), carasrepetidas.rend());

    return carasrepetidas;
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n,v;
    cin>>n;
    if (n==-1)
        return false;
    cin>>v;
    vector<int> dados(n);
    for(int&i:dados)cin>>i;
    vector<int> sol = resolver(dados,v);
    
    // escribir sol
    for(int&i:sol){
        cout<<i<<" ";
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
