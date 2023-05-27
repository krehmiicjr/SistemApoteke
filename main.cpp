#include <iostream> // Za unos i ispis podataka s konzole
#include <stdlib.h> // Za korištenje funkcije system() za manipulaciju operativnim sistemom
#include <string> // Za rad s nizovima znakova (stringovima)
#include <cctype> // Za rad s karakterima (npr. provjera je li karakter slovo)
#include <cmath> // Za matematičke funkcije poput sqrt(), sin(), cos(), itd.
#include <cstdio> // Za ulazno-izlazne operacije
#include <fstream> // Za rad s datotekama (ulazno-izlazne operacije s datotekama)
#include <iomanip> // Za formatiranje ispisa

#define max 10 // Definicija maksimalnog broja elemenata u nizu

using namespace std;

class MedType
{
public:
    void order(); // Metoda za unos nove narudžbe lijeka
    void delete_item(); // Metoda za brisanje posljednje narudžbe lijeka
    void update_order(); // Metoda za izmjenu liste narudžbi
    void order_list(); // Metoda za ispisivanje liste narudžbi
    void summarry(); // Metoda za dnevni pregled ukupne prodaje
    void quit(); // Metoda za izlaz iz programa
    MedType(); // Konstruktor klase MedType
};

MedType::MedType()
{
    // Implementacija konstruktora klase MedType
}

int main() {
    system("COLOR 0F"); // Postavlja boju konzole (u ovom slučaju crna pozadina i bijeli tekst)
    MedType medicine; // Kreiranje objekta klase MedType
    int menu;

    do {
        system("cls"); // Čisti ekran konzole
        cout << "\t\t\t    Sistem za vođenje apoteke \n"; // Ispisuje naziv programa
        cout << "\t\t||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n"; // Ispisuje liniju razdjeljivača
        cout << "\t\t||||||||||||||||||||||||||||||||||||||||||||||||||||\n"; // Ispisuje liniju razdjeljivača
        cout << "\t\t\t1. Unesi novu narudžbu lijeka \t\t\n"; // Ispisuje opciju za unos nove narudžbe
        cout << "\t\t\t2. Obriši posljednju narudžbu lijeka\t\t\n"; // Ispisuje opciju za brisanje posljednje narudžbe
        cout << "\t\t\t3. Izmijeni listu narudžbi \t\t\t\n"; // Ispisuje opciju za izmjenu liste narudžbi
        cout
                << "\t\t\t4. Ispiši račun i izvrši plaćanje \t\n"; // Ispisuje opciju za ispis računa i izvršavanje plaćanja
        cout << "\t\t\t5. Dnevni pregled ukupne prodaje \t\t \n"; // Ispisuje opciju za dnevni pregled ukupne prodaje
        cout << "\t\t\t6. Izlaz\t\t\t\t\t\n"; // Ispisuje opciju za izlaz iz programa
        cout << "\t\t||||||||||||||||||||||||||||||||||||||||||||||||||||\n"; // Ispisuje liniju razdjeljivača
        cout << "Unesi izbor: "; // Traži unos korisnikovog izbora

        cin >> menu; // Unos korisnikovog izbora

        switch (menu) {
            case 1: {
                // Ako je izabrana opcija 1, poziva se metoda za unos nove narudžbe lijeka
                medicine.order();
                break;
            }

            case 2: {
                // Ako je izabrana opcija 2, poziva se metoda za brisanje posljednje narudžbe lijeka
                medicine.delete_item();
                system("PAUSE");
                break;
            }

            case 3: {
                // Ako je izabrana opcija 3, poziva se metoda za izmjenu liste narudžbi
                medicine.update_order();
                system("PAUSE");
                break;
            }

            case 4: {
                // Ako je izabrana opcija 4, poziva se metoda za ispisivanje liste narudžbi
                medicine.order_list();
                system("PAUSE");
                break;
            }

            case 5: {
                // Ako je izabrana opcija 5, poziva se metoda za dnevni pregled ukupne prodaje
                medicine.summarry();
                system("PAUSE");
                break;
            }

            case 6: {
                // Ako je izabrana opcija 6, poziva se metoda za izlaz iz programa i prekida se petlja
                medicine.quit();
                goto a;
                break;
            }

            default: {
                // Ako je unesen neispravan izbor, ispisuje se poruka o neispravnom unosu
                cout << "Unijeli ste nevažeći unos\\nPonovno unesite izbor\\n" << endl;
                break;
            }
        }

    } while (menu != 6); // Petlja se ponavlja sve dok korisnik ne odabere izlaz (6)

    a:
    cout << "Zahvaljujemo!" << endl;
    system("PAUSE");
    return 0;
    }

    return 0; // Završava izvršavanje programa
}