// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;
using lli=long long int;
// función que resuelve el problema
/*
l1=tamaño de la lista 1
l2=tamaño de la lista 2
n=tamaño de la solucion
P=(0<=l1,l2<100000 && forall i: 0<=i<l1:v1[i]>0 && forall j:0<=j<l2:v2[j]>0)

func resolver(v1[],v2[],int l1,int l2)dev sol[]

Q=(ordendo(sol,n) && forall w:0<=w<n:pertenece(v1,sol,l1,w)||pertenece(v2,sol,l2,w))
ordenado(sol,n)=(forall i:0<=i<n-1:v[i]<v[i+1])
pertenece(v,sol,l,w)=(existe i:0<=i<l:v[i]=sol[w])
*/
vector<int> resolver(const vector<int>&v1, const vector<int>&v2) {
    vector<int> sol;

    int i=0,j=0;
    while(i<v1.size() && j<v2.size()){
        if(v1[i]<=v2[j]){
            sol.push_back(v1[i]);
            i++;
        }
        else if(v1[i]==v2[j]){
            sol.push_back(v1[i]);
            i++;
            j++;
        }
        else{
            sol.push_back(v2[j]);
            j++;
        }
    }
    while(i<v1.size()){
        sol.push_back(v1[i]);
        i++;
    }
    while(j<v2.size()){
        sol.push_back(v2[j]);
        j++;
    }
    return sol;    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n1,n2;
    cin>>n1>>n2;
    vector<int> PA(n1);
    vector<int> PB(n2);
    for(auto&i:PA)cin>>i;
    for(auto&j:PB)cin>>j;
    
    vector<int> sol = resolver(PA,PB);
    // escribir sol
    for(auto&i:sol){
        cout<<i<<" ";
    }
    cout<<"\n";
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