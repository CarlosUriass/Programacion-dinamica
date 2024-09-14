#include <iostream>
#include <string>
#include <algorithm> 
#include <cstdlib>  


using namespace std;

void capturarDatos();
int numMes();
string signoZodical();
void imprimirResultados();
void continuar();
void clearConsole();

void clearConsole() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls"); // Comando para limpiar consola en Windows
    #else
        system("clear"); // Comando para limpiar consola en Unix/Linux/Mac
    #endif
}

void continuar(){
    string continuar = "";

    cout << "¿Desea verificar otro signo zodiacal ? (SI/NO) " << endl;
    cin >> continuar;

   
    transform(continuar.begin(), continuar.end(), continuar.begin(), :: tolower);

    if (continuar == "si") {
        clearConsole();
        capturarDatos();
    } else {
        return;
    }
}

string signoZodiacal(int dia, int mes){
    string signo = "";

   if ((mes == 3 && dia >= 21) || (mes == 4 && dia <= 20)) {
        signo = "Aries";
    } else if ((mes == 4 && dia >= 21) || (mes == 5 && dia <= 20)) {
        signo = "Tauro";
    } else if ((mes == 5 && dia >= 21) || (mes == 6 && dia <= 21)) {
        signo = "Geminis";
    } else if ((mes == 6 && dia >= 22) || (mes == 7 && dia <= 22)) {
        signo = "Cáncer";
    } else if ((mes == 7 && dia >= 23) || (mes == 8 && dia <= 23)) {
        signo = "Leo";
    } else if ((mes == 8 && dia >= 24) || (mes == 9 && dia <= 22)) {
        signo = "Virgo";
    } else if ((mes == 9 && dia >= 23) || (mes == 10 && dia <= 22)) {
        signo = "Libra";
    } else if ((mes == 10 && dia >= 23) || (mes == 11 && dia <= 22)) {
        signo = "Escorpio";
    } else if ((mes == 11 && dia >= 23) || (mes == 12 && dia <= 21)) {
        signo = "Sagitario";
    } else if ((mes == 12 && dia >= 22) || (mes == 1 && dia <= 20)) {
        signo = "Capricornio";
    } else if ((mes == 1 && dia >= 21) || (mes == 2 && dia <= 19)) {
        signo = "Acuario";
    } else if ((mes == 2 && dia >= 20) || (mes == 3 && dia <= 20)) {
        signo = "Piscis";
}

    

    return signo;
}


int numMes(string mes){

    transform(mes.begin(), mes.end(), mes.begin(), :: tolower);

    int numeroMes = 0;

  if (mes == "enero") {
        numeroMes = 1;
    } else if (mes == "febrero") {
        numeroMes = 2;
    } else if (mes == "marzo") {
        numeroMes = 3;
    } else if (mes == "abril") {
        numeroMes = 4;
    } else if (mes == "mayo") {
        numeroMes = 5;
    } else if (mes == "junio") {
        numeroMes = 6;
    } else if (mes == "julio") {
        numeroMes = 7;
    } else if (mes == "agosto") {
        numeroMes = 8;
    } else if (mes == "septiembre") {
        numeroMes = 9;
    } else if (mes == "octubre") {
        numeroMes = 10;
    } else if (mes == "noviembre") {
        numeroMes = 11;
    } else if (mes == "diciembre") {
        numeroMes = 12;
    } else {
        cout << "Su entrada es incorrecta. Intente de nuevo" << endl;
        capturarDatos();
    }

    return numeroMes;

}


void imprimirResultados(int dia, int mes){
    string resultado = "";

    resultado = signoZodiacal(dia, mes);

    cout << "Su signo zodiacal es: " << resultado << endl;

    continuar();

}


void capturarDatos(){
    int dia = 0;
    string mes = "";
    int numeroMes = 0;

    cout << "Ingrese su dia de nacimiento: " << endl;
    cin >> dia;

    if(dia > 31 || dia < 1) {
        cout << "Dia de nacimiento incorrecto. Intente de nuevo." << endl;
        capturarDatos();
    }

    cout << "Ingrese su mes de nacimiento" << endl;
    cin.ignore(); 
    cin >> mes;

    numeroMes = numMes(mes);

    imprimirResultados(dia, numeroMes);


}

int main(){

    capturarDatos();

    return 0;
}