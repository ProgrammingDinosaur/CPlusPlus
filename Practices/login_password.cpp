#include <iostream>
#include <string>

using namespace std;

bool preguntar_contrasena(string pass){
    string passwordin="";
    cout << "Inserte su password, por favor: ";
    cin >> passwordin;
    if (passwordin == pass) {
        cout << "Password correcto!\nInicializando... ";
        return true;
    }else {
        cout << "Password incorrecto, intente de nuevo\n";
        return false;
    }
}

bool preguntar_correo(){
    string correoin = "";
    cout << "Inserte su correo, por favor: ";
    cin >> correoin;
    if (correoin.find("@")<correoin.length()) {
        cout << "Correo inicialzado!\n";
        return true;
    }
    else {
        cout << "Esto no parece ser un correo, intente de nuevo\n";
        return false;
    }
}

int main(){
bool correo = false;
bool passw = false;
while (correo == false){
    correo = preguntar_correo();
}
while (passw == false){
    passw = preguntar_contrasena("admin1234");
}
cout << "Proceso Finalizado, felicidades!";


return 0;
}