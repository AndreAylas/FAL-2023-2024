// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;

// función que resuelve el problema
struct tExtranyo{
	int sumapar ;
	int prodimpar ;
	bool comprobar;
};

tExtranyo resolver(vector<int>const& v, int ini, int fin,int &prodpar,int &sumaimpar) {

	if (v.empty()) return { 0,0,true };
	else if (ini + 1 == fin) {
		if (v[ini] % 2 == 0) {//par
			prodpar =v[ini];
			sumaimpar = 0;
			return{ v[ini],1,true};
		}
		else {//impar
			prodpar = 1;
			sumaimpar = v[ini];
			return{ 0,v[ini],true};
		}
		
	}
	else {
		int mitad = (ini + fin) / 2;
		int unoprodpar, unosumaimpar, dosprodpar, dossumaimpar;
		tExtranyo primeramitad = resolver(v, ini, mitad, unoprodpar, unosumaimpar);
	    tExtranyo segundamitad = resolver(v, mitad, fin, dosprodpar, dossumaimpar);
		
		bool aux = (primeramitad.sumapar + primeramitad.prodimpar <= dosprodpar + dossumaimpar) && (primeramitad.comprobar || segundamitad.comprobar);
		prodpar = dosprodpar * unoprodpar;
		sumaimpar = dossumaimpar + unosumaimpar;
		return{ primeramitad.sumapar + segundamitad.sumapar ,primeramitad.prodimpar * segundamitad.prodimpar ,aux };
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto&i:v)cin>>i;
    int a,b;
    auto sol = resolver(v,0,n,a,b);
    // escribir sol
    if(sol.comprobar) cout<<"SI\n";
    else cout<<"NO\n";
    
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