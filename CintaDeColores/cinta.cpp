// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include<algorithm>

using namespace std;

// función que resuelve el problema
struct tCintas {
    char c;
    int l;
};
bool operator<(tCintas a, tCintas b) {
    return (a.c == b.c && a.l < b.l) || (a.c != b.c && a.l < b.l);
}
void resolver(vector<tCintas>& v, int& ini, int& med, int& fin) {

    while (ini <= fin) {
        if (v[ini].c == 'v') {
            ini++;
        }
        else if (v[ini].c == 'a') {
            swap(v[ini], v[med]);
            ini++;
            med++;
        }
        else {
            swap(v[ini], v[fin]);
            fin--;
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (!std::cin)
        return false;
    vector<tCintas> v;
    char c;
    int l;
    for (int i = 0;i < n;i++) {
        cin >> c >> l;
        v.push_back({ c,l });
    }
    int idx_ini = 0, idx_med = 0, idx_fin = v.size() - 1;
    resolver(v, idx_ini, idx_med, idx_fin);
    sort(v.begin(), v.begin() + idx_med);
    sort(v.begin() + idx_med, v.begin() + 1 + idx_fin);
    sort(v.begin() + 1 + idx_fin, v.end());
    cout << "Azules:";
    // escribir sol
    for (int i = 0;i < idx_med;i++) {
        cout << " " << v[i].l;
    }
    cout << "\n";
    cout << "Verdes:";
    for (int i = idx_med;i <= idx_fin;i++) {
        cout << " " << v[i].l;
    }
    cout << "\n";
    cout << "Rojas:";
    for (int i = idx_fin+1;i < v.size();i++) {
        cout << " " << v[i].l;
    }
    cout << "\n";
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
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