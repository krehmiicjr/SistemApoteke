#include <iostream> // Za unos i ispis podataka s konzole
#include <stdlib.h> // Za korištenje funkcije system() za manipulaciju operativnim sistemom
#include <string> // Za rad s nizovima znakova (stringovima)
#include <cctype> // Za rad s karakterima (npr. provjera je li karakter slovo)
#include <cmath> // Za matematičke funkcije poput sqrt(), sin(), cos(), itd.
#include <cstdio> // Za ulazno-izlazne operacije
#include <fstream> // Za rad s datotekama (ulazno-izlazne operacije s datotekama)
#include <iomanip> // Za formatiranje ispisa

#define MAX 10 // Definicija maksimalnog broja elemenata u nizu

using namespace std;

// Definicija strukture 'node' za čuvanje podataka o narudžbi lijeka
struct node
{
    int brojRacuna; // Broj računa
    string imeKupca; // Ime kupca
    string datum; // Datum narudžbe
    int kolicinaLijeka[10]; // Količina lijeka
    string vrstaLijeka = {"OTC"}; // Vrsta lijeka (over-the-counter)
    int x, menu2[10]; // Dodatne varijable za unos
    double iznosNarudzbe[10]; // Iznos narudžbe za svaki lijek
    string imeLijeka[MAX] = { "Lijek1", "Lijek2", "Lijek3", "Lijek4", "Lijek5", "Lijek6", "Lijek7", "Lijek8", "Lijek9", "Lijek10" }; // Imena lijekova
    double cijenaLijeka[MAX] = { 1.50, 2.20, 3.00, 2.80, 1.90, 4.50, 3.70, 2.40, 1.80, 3.20 }; // Cijene lijekova
    double ukupnoNarudzbe; // Ukupan iznos narudžbe

    node *prev; // Pokazivač na prethodni čvor
    node *next; // Pokazivač na sljedeći čvor
    node *link; // Dodatni pokazivač

}*q, *temp;

node *starting_point = NULL; // Pokazivač na početni čvor
node *head_point = NULL; // Pokazivač na glavni čvor
node *lasting_point = NULL; // Pokazivač na zadnji čvor

class MedType {
public:
    void order() // Metoda za unos nove narudžbe lijeka
    {
        system("cls");
        int i;
        int opcija, kolicina, cijena, None;

        cout << "\nUnesite detalje narudžbe!\n";

        node *temp;
        temp = new node;

        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
        cout << "ID LIJEKA" << "\tVRSTA LIJEKA" << "\t\tIME LIJEKA" << "           CIJENA LIJEKA(KM)"
             << endl; // Ispis zaglavlja tablice
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
        cout << "0001" << "\t" << "\tOTC" << "\t\t" << "    Lijek1" << "			1.50 KM" << endl; // Lijek1
        cout << "0002" << "\t" << "\tOTC" << "\t\t" << "    Lijek2" << "			2.20 KM" << endl; // Lijek2
        cout << "0003" << "\t" << "\tOTC" << "\t\t" << "    Lijek3" << "			3.00 KM" << endl; // Lijek3
        cout << "0004" << "\t" << "\tOTC" << "\t\t" << "    Lijek4" << "			2.80 KM" << endl; // Lijek4
        cout << "0005" << "\t" << "\tOTC" << "\t\t" << "    Lijek5" << "			1.90 KM" << endl; // Lijek5
        cout << "0006" << "\t" << "\tOTC" << "\t\t" << "    Lijek6" << "			4.50 KM" << endl; // Lijek6
        cout << "0007" << "\t" << "\tOTC" << "\t\t" << "    Lijek7" << "			3.70 KM" << endl; // Lijek7
        cout << "0008" << "\t" << "\tOTC" << "\t\t" << "    Lijek8" << "			2.40 KM" << endl; // Lijek8
        cout << "0009" << "\t" << "\tOTC" << "\t\t" << "    Lijek9" << "			1.80 KM" << endl; // Lijek9
        cout << "0010" << "\t" << "\tOTC" << "\t\t" << "    Lijek10" << "                     3.20 KM" << endl; // Lijek10
        cout << " " << endl;

        temp = new node;
        cout << "Unesite broj narudžbe: ";
        cin >> temp->brojRacuna;
        cout << "Unesite ime kupca: ";
        cin >> temp->imeKupca;
        cout << "Unesite datum: ";
        cin >> temp->datum;
        cout << "Koliko lijekova želite naručiti:" << endl;
        cout << "(Maksimalno je 10 lijekova po narudžbi)\n";
        cout << "  ";
        cin >> temp->x;
        if (temp->x > 10) {
            cout << "Količina lijekova koje naručujete premašuje maksimalni broj narudžbi!";
            system("pause");
        } else {
            for (i = 0; i < temp->x; i++) {

                cout << "Unesite svoj odabir: "; // Unos odabira lijeka
                cin >> temp->menu2[i];

                cout << "Ime lijeka: " << temp->imeLijeka[temp->menu2[i] - 1] << endl;  // Ispis imena odabranog lijeka
                cout << "Koliko lijekova želite: ";
                cin >> temp->kolicinaLijeka[i];  // Unos količine lijeka
                temp->iznosNarudzbe[i] =
                        temp->kolicinaLijeka[i] * temp->cijenaLijeka[temp->menu2[i] - 1];  // Izračunaj ukupan iznos
                cout << "Iznos koji trebate platiti: " << temp->iznosNarudzbe[i] << " KM"
                     << endl;  // Ispis ukupnog iznosa
                system("PAUSE");

            }
            cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
            cout << "Narudžba uspješno zabilježena" << endl;
            cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
            cout << "Idite na izbornik računa za plaćanje računa" << endl;
            cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
            system("PAUSE");

            temp->next = NULL;
            if (starting_point != NULL) {
                temp->next = starting_point;
            }
            starting_point = temp;
            system("cls");
        }
    }
        // Ova funkcija je ovde samo da bi omogućila uspešnu kompilaciju projekta.
        // Nije implementirana niti ima stvarnu funkcionalnost.
        void delete_item() // Metoda za brisanje posljednje narudžbe lijeka
        {
            // Komentar: Ovde bi trebala biti implementacija brisanja stavke.
            // Međutim, trenutno ova funkcija samo postoji kako bi se projekat mogao kompajlirati.
        }

        // Ova funkcija je ovde samo da bi omogućila uspešnu kompilaciju projekta.
        // Nije implementirana niti ima stvarnu funkcionalnost.
        void update_order() // Metoda za izmjenu liste narudžbi
        {
            // Komentar: Ovde bi trebala biti implementacija ažuriranja redosleda.
            // Međutim, trenutno ova funkcija samo postoji kako bi se projekat mogao kompajlirati.
        }

        void order_list() // Metoda za ispisivanje liste narudžbi
        {
            int i, num, num2;
            bool found;
            system("cls");
            node *temp;

            temp = starting_point;
            found = false;

            cout << "Unesite broj računa za ispis računa: ";
            cin >> num2;
            cout << "\n";
            cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
            cout << "\t\t\tOvdje je lista narudžbi" << endl;
            cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

            if (temp == NULL)
            {
                cout << "\t\t\tNema narudžbi za prikazivanje\n";
            }
            while (temp != NULL && !found)
            {
                if (temp->brojRacuna == num2)
                {
                    found = true;
                }
                else
                {
                    temp = temp->next;
                }
            }
            if (found)
            {
                cout << "Broj računa: " << temp->brojRacuna << endl;
                cout << "\n";
                cout << "Ime kupca: " << temp->imeKupca << endl;

                cout << "Datum narudžbe: " << temp->datum << endl;

                cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                cout << "|  Vrsta lijeka    |     Ime lijeka     |    Količina    |   Ukupna cijena   |" << endl;
                cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                for (i = 0; i < temp->x; i++)
                {
                    cout << "     " << temp->vrstaLijeka << "     " << "  \t\t";
                    cout << "  " << temp->imeLijeka[temp->menu2[i] - 1] << "\t\t\t  ";
                    cout << temp->kolicinaLijeka[i] << "\t\t";
                    cout << temp->iznosNarudzbe[i] << " KM" << endl;
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                }

                temp->ukupnoNarudzbe = temp->iznosNarudzbe[0] + temp->iznosNarudzbe[1] + temp->iznosNarudzbe[2] + temp->iznosNarudzbe[3] + temp->iznosNarudzbe[4] + temp->iznosNarudzbe[5] + temp->iznosNarudzbe[6] + temp->iznosNarudzbe[7] + temp->iznosNarudzbe[8] + temp->iznosNarudzbe[9];
                cout << "Ukupan iznos računa: " << temp->ukupnoNarudzbe << " KM" << endl;
                cout << "Unesite iznos koji trebate platiti: ";
                cin >> num;

                cout << "\n";
                cout << "\n";
                cout << "Plaćanje izvršeno\nZahvaljujemo\n";
                cout << "\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
            }
        }

        // Ova funkcija je ovde samo da bi omogućila uspešnu kompilaciju projekta.
        // Nije implementirana niti ima stvarnu funkcionalnost.
        void summary() // Metoda za dnevni pregled ukupne prodaje
        {
            // Komentar: Ovde bi trebala biti implementacija generisanja rezimea.
            // Međutim, trenutno ova funkcija samo postoji kako bi se projekat mogao kompajlirati.
        }

        // Ova funkcija je ovde samo da bi omogućila uspešnu kompilaciju projekta.
        // Nije implementirana niti ima stvarnu funkcionalnost.
        void quit() // Metoda za izlaz iz programa
        {
            // Komentar: Ovde bi trebala biti implementacija zatvaranja programa.
            // Međutim, trenutno ova funkcija samo postoji kako bi se projekat mogao kompajlirati.
        }
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
        cout << "\t\t||||||||||||||||||||||||||||||||||||||||||||||||||||\n"; // Ispisuje liniju razdjeljivača
        cout << "\t\t\t1. Unesi novu narudžbu lijeka \t\t\n"; // Ispisuje opciju za unos nove narudžbe
        cout << "\t\t\t2. Obriši posljednju narudžbu lijeka\t\t\n"; // Ispisuje opciju za brisanje posljednje narudžbe
        cout << "\t\t\t3. Izmijeni listu narudžbi \t\t\t\n"; // Ispisuje opciju za izmjenu liste narudžbi
        cout << "\t\t\t4. Ispiši račun i izvrši plaćanje \t\n"; // Ispisuje opciju za ispis računa i izvršavanje plaćanja
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
                medicine.summary();
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
