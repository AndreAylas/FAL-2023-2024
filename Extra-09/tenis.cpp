// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;
 struct tPartidos {
    int numpart;
    int rondas;
    bool haycontrincante;
};

tPartidos resolver(vector<string>const& v, int ini, int fin, int rondas) {
    if (ini + 2 == fin) {
        if (v[ini] == "NP" && v[ini + 1] == "NP") return { 0,1,false };
        else if (v[ini] == "NP" || v[ini + 1] == "NP") return { 0,1,true };
        else return{ 1,1,true };
    }
    else {
        int m = (ini + fin) / 2;
        tPartidos ladiz = resolver(v, ini, m, rondas);
        tPartidos ladder = resolver(v, m, fin, rondas);
        int rondaActual = ladiz.rondas + 1;
        if (rondaActual <= rondas) {
            if (ladiz.haycontrincante && ladder.haycontrincante)return { ladder.numpart + ladiz.numpart + 1,rondaActual,true };
            else if (ladiz.haycontrincante || ladder.haycontrincante) return { ladder.numpart + ladiz.numpart ,rondaActual,true };
            else return{ ladder.numpart + ladiz.numpart ,rondaActual,false };
        }
        else {
            return{ ladder.numpart + ladiz.numpart ,rondaActual,false };
        }
    }
}
bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    int tam, ronda;
    cin >> tam >> ronda;
    if (!std::cin)
        return false;
    vector<string> v(tam);
    for (auto& i : v)cin >> i;
    tPartidos sol = resolver(v, 0, tam, ronda);
    cout << sol.numpart << "\n";
    //Resolver problema
    //Escribir resultado
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