// Nombre del alumno .....
// Usuario del Juez ......
/*
oscar andre aylas Henrnadez F04
Carlos Mayorga Santiago F58
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;

/*
n=tamaño de la muestra

P=( 0<n<100.000 && forall u:0<=u<n:-1000<v[u] && v[u]<1000)

func resolver(v[],acum[],int n) dev b:bool

Q=(b=(existe u:0<=u<n-1:v[u]=(sum j: u+1<=j<=n-1:v[j])))

coste O(n) donde n: es la longitud de secuencia de valores contables


*/

// función que resuelve el problema
bool resolver(const vector<int>& v, int &suma) {
    int i=0,n=v.size();
    bool b=false;

    //cota=n-i 
    //Invariante={b=(existe a:-1<a<n && v[a]=(sum b:a<b<n:v[b]))}
    while(!b && i<n){
        suma=suma-v[i];
        if(v[i]==suma)
            b=true;
        
        i++;
    }
    return b;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n,suma=0;
    cin>>n;
    if (n==0)
        return false;
    vector<int> v(n);
    for(auto&i:v){
        cin>>i;
        suma+=i;
    }
    vector<int> aux(n);

    // escribir sol
    bool resul=resolver(v,suma);
    if(resul)
        cout<<"YES\n";
    else
        cout<<"NO\n";
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
