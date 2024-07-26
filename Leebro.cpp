#include <iostream>
#include <string>
#include <unistd.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <term.h>
#endif

void tipoTexto(const std::string& texto, useconds_t delay) {
    std::cout << "\033[33m"; // Cambia el color a amarillo
    for (size_t i = 0; i < texto.length(); ++i) {
        std::cout << texto[i] << std::flush;
        usleep(delay);
    }
    std::cout << "\033[0m" << std::endl; // Resetea el color
}

void clearConsole() {
#ifdef _WIN32
    system("CLS");
#else
    system("clear");
#endif
}

using namespace std;


void mostrarMenuPrincipal() {
    cout << "\t Leebro " << endl;
    cout << " " << endl;
    cout << "\033[90m";
    cout << "/////////////////////////////////////////////////////////" << endl;
    cout << " " << endl;
    cout << "Mejora y practica tu lectura con nosotros" << endl;
    cout << " " << endl;
    cout << "/////////////////////////////////////////////////////////" << endl;
    cout << " " << endl;
    cout << "\033[32m"; // Cambia el color a verde
    cout << "Menu Principal" << endl;
    cout << "\033[90m";
    cout << "---------------------------------" << endl;
    cout << "\033[32m"; // Cambia el color a verde
    cout << " 1- Leer" << endl;
    cout << " 2- Salir" << endl;
    cout << "\033[90m";
    cout << "---------------------------------" << endl;
    cout << "\033[0m"; // Resetea el color
    cout << " " << endl;
    cout << "Indique su opción: ";
}

void mostrarMenuTiempos() {
    cout << "\033[32m"; // Cambia el color a verde
    cout << "\033[90m";
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << " " << endl;
    cout << "El texto consta de 100 palabras selecciona el tiempo en el cual quieras leerlo" << endl;
    cout << " " << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
    cout << " " << endl;
    cout << "\033[32m"; // Cambia el color a verde
    cout << "Tiempos" << endl;
    cout << "\033[90m";
    cout << "---------------------------------" << endl;
    cout << "\033[32m"; // Cambia el color a verde
    cout << " 1- 1:15 minutos" << endl;
    cout << " 2- 1:00 minutos" << endl;
    cout << " 3- 0:40 minutos" << endl;
    cout << " 4- 0:20 minutos" << endl;
    cout << " 5- Volver" << endl;
    cout << "\033[90m";
    cout << "---------------------------------" << endl;
    cout << "\033[0m"; // Resetea el color
    cout << "Indique su opción: ";
}

void opcionesPostTipeo(int& opTiempo, const std::string& texto, useconds_t delay) {
    int opcion;
    cout << "\033[32m"; // Cambia el color a verde
    cout << " " << endl;
    cout << "Opciones:"<< endl;
    cout << "\033[90m";
    cout << "---------------------------------" << endl;
    cout << "\033[32m"; // Cambia el color a verde
    cout << " 1- Repetir\n 2- Opciones de lectura\n 3- Menu principal\n";
    cout << "\033[90m";
    cout << "---------------------------------" << endl;
    cout << "\033[0m"; // Resetea el color
    cout << "Indique su opción: ";
    cin >> opcion;
    switch (opcion) {
        case 1: // Repetir
            clearConsole();
            tipoTexto(texto, delay);
            opcionesPostTipeo(opTiempo, texto, delay);
            break;
        case 2: // Volver al menú de opciones de tiempo
            opTiempo = -1; // Valor especial para volver al menú de opciones de tiempo
            break;
        case 3: // Volver al menú principal
            opTiempo = 5;
            break;
        default:
            cout << "Opción incorrecta, volviendo al menú de opciones de juego..." << endl;
            opTiempo = -1; // Valor especial para volver al menú de opciones de tiempo
            break;
    }
}

int main() {
    int opPrincipal, opTiempo;
    do {
        clearConsole();
        mostrarMenuPrincipal();
        cin >> opPrincipal;
        if (opPrincipal == 1) {
            do {
                clearConsole();
                mostrarMenuTiempos();
                cin >> opTiempo;
                switch (opTiempo) {
                    case 1: {
                        clearConsole();
                        std::string texto = "\n Leer es una actividad fundamental para el desarrollo personal y profesional. A través de la lectura, adquirimos conocimientos, ampliamos la riqueza de nuestro vocabulario y mejoramos nuestras habilidades de comunicación. Además, leer nos permite viajar a diferentes mundos, conocer diversas culturas y perspectivas, y estimular nuestra imaginación. También es una excelente manera de reducir el estrés y mejorar la concentración. La lectura fomenta el pensamiento crítico y nos ayuda a comprender y analizar la información de manera más efectiva. En resumen, leer no solo enriquece nuestra mente, sino que también nos convierte en personas más informadas y empáticas. Sigue así :)";
                        useconds_t delay = 100000; // 100000 microsegundos = 0.1 segundos
                        tipoTexto(texto, delay);
                        opcionesPostTipeo(opTiempo, texto, delay);
                        break;
                    }
                    case 2: {
                        clearConsole();
                        std::string texto = "\n Leer es una actividad fundamental para el desarrollo personal y profesional. A través de la lectura, adquirimos conocimientos, ampliamos la riqueza de nuestro vocabulario y mejoramos nuestras habilidades de comunicación. Además, leer nos permite viajar a diferentes mundos, conocer diversas culturas y perspectivas, y estimular nuestra imaginación. También es una excelente manera de reducir el estrés y mejorar la concentración. La lectura fomenta el pensamiento crítico y nos ayuda a comprender y analizar la información de manera más efectiva. En resumen, leer no solo enriquece nuestra mente, sino que también nos convierte en personas más informadas y empáticas. Sigue así :)";
                        useconds_t delay = 80000; // 80000 microsegundos = 0.08 segundos
                        tipoTexto(texto, delay);
                        opcionesPostTipeo(opTiempo, texto, delay);
                        break;
                    }
                    case 3: {
                        clearConsole();
                        std::string texto = "\n Leer es una actividad fundamental para el desarrollo personal y profesional. A través de la lectura, adquirimos conocimientos, ampliamos la riqueza de nuestro vocabulario y mejoramos nuestras habilidades de comunicación. Además, leer nos permite viajar a diferentes mundos, conocer diversas culturas y perspectivas, y estimular nuestra imaginación. También es una excelente manera de reducir el estrés y mejorar la concentración. La lectura fomenta el pensamiento crítico y nos ayuda a comprender y analizar la información de manera más efectiva. En resumen, leer no solo enriquece nuestra mente, sino que también nos convierte en personas más informadas y empáticas. Sigue así :)";
                        useconds_t delay = 50000; // 50000 microsegundos = 0.05 segundos
                        tipoTexto(texto, delay);
                        opcionesPostTipeo(opTiempo, texto, delay);
                        break;
                    }
                    case 4: {
                        clearConsole();
                        std::string texto = "\n Leer es una actividad fundamental para el desarrollo personal y profesional. A través de la lectura, adquirimos conocimientos, ampliamos la riqueza de nuestro vocabulario y mejoramos nuestras habilidades de comunicación. Además, leer nos permite viajar a diferentes mundos, conocer diversas culturas y perspectivas, y estimular nuestra imaginación. También es una excelente manera de reducir el estrés y mejorar la concentración. La lectura fomenta el pensamiento crítico y nos ayuda a comprender y analizar la información de manera más efectiva. En resumen, leer no solo enriquece nuestra mente, sino que también nos convierte en personas más informadas y empáticas. Sigue así :)";
                        useconds_t delay = 20000; // 20000 microsegundos = 0.02 segundos
                        tipoTexto(texto, delay);
                        opcionesPostTipeo(opTiempo, texto, delay);
                        break;
                    }
                    case 5: {
                        cout << "Saliendo" << endl;
                        break;
                    }
                    default: {
                        cout << "Opción incorrecta" << endl;
                    }
                }
                if (opTiempo== -1) {
                    continue; // Volver al menú de opciones de juego
                }
                if (opTiempo!= 5) {
                    cout << "Presione Enter para continuar...";
                    cin.ignore();
                    cin.get();
                }
            } while (opTiempo != 5);
        }
    } while (opPrincipal != 2);
    return 0;
}
