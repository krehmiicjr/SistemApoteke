#include <iostream> // Za unos i ispis podataka s konzole
#include <stdlib.h> // Za korištenje funkcije system() za manipulaciju operativnim sistemom
#include <string> // Za rad s nizovima znakova (stringovima)
#include <vector> // Za rad s vektorima
#include <cctype> // Za rad s karakterima (npr. provjera je li karakter slovo)
#include <cmath> // Za matematičke funkcije poput sqrt(), sin(), cos(), itd.
#include <cstdio> // Za ulazno-izlazne operacije
#include <fstream> // Za rad s datotekama (ulazno-izlazne operacije s datotekama)
#include <iomanip> // Za formatiranje ispisa
#define MAX 10 // Definicija maksimalnog broja elemenata u nizu

using namespace std;

// Definicija strukture 'node' za čuvanje podataka o narudžbi lijeka
struct node {
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

    node *next; // Pokazivač na sljedeći čvor
} *temp;

node *starting_point = NULL; // Pokazivač na početni čvor
node *lasting_point = NULL; // Pokazivač na zadnji čvor

// Struktura koja predstavlja radnika
struct Radnik {
    string imePrezime;
    string password;
};

// Lista svih radnika
vector<Radnik> radnici = {
        {"Narcisa Hadžajlić", "password0"},
        {"Ensar Krehmić", "password1"},
        {"Nadina Muračević", "password2"},
        {"Besim Škorić", "password3"},
};

const string FILENAME = "pacijenti.txt";

void unosPacijenta(vector<node>& pacijenti) {
    system("cls"); // Briše sadržaj konzole
    node noviPacijent;

    cout << "Unesite ime pacijenta:";
    cin >> noviPacijent.imeKupca;
    cin.ignore();

    cout << "Unesite datum rodjenja pacijenta:";
    getline(cin, noviPacijent.datum);

    cout << "Unesite broj računa pacijenta:";
    cin >> noviPacijent.brojRacuna;
    cin.ignore();

    pacijenti.push_back(noviPacijent);

    // Spremanje podataka u datoteku
    ofstream outputFile(FILENAME, ios::app); // Otvori datoteku u modu za dodavanje
    if (outputFile.is_open()) {
        outputFile << noviPacijent.imeKupca << "," << noviPacijent.datum << "," << noviPacijent.brojRacuna << endl;
        outputFile.close();
        cout << "Pacijent uspješno dodat." << endl;
    }
    else {
        cout << "Nije moguće otvoriti datoteku za pisanje." << endl;
    }
}

void prikaziSvePacijente(const vector<node>& pacijenti) {
    system("cls"); // Briše sadržaj konzole
    if (pacijenti.empty()) {
        cout << "Nema dostupnih pacijenata." << endl;
        return;
    }

    cout << "Svi pacijenti:" << endl;
    for (const node& pacijent : pacijenti) {
        cout << "Ime: " << pacijent.imeKupca << endl;
        cout << "--------------------------" << endl;
    }
}

void prikaziPacijente(const vector<node>& pacijenti) {
    system("cls"); // Briše sadržaj konzole
    if (pacijenti.empty()) {
        cout << "Nema dostupnih pacijenata." << endl;
        return;
    }

    cout << "Dostupni pacijenti:" << endl;
    for (int i = 0; i < pacijenti.size(); i++) {
        const node& pacijent = pacijenti[i];
        cout << "Indeks: " << i << endl;
        cout << "Ime: " << pacijent.imeKupca << endl;
        cout << "--------------------------" << endl;
    }

    int indeks;
    cout << "Unesite indeks pacijenta:";
    cin >> indeks;
    cin.ignore();

    if (indeks >= 0 && indeks < pacijenti.size()) {
        const node& pacijent = pacijenti[indeks];
        cout << "Informacije o pacijentu:" << endl;
        cout << "Ime: " << pacijent.imeKupca << endl;
        cout << "Datum rodjenja:" << pacijent.datum << endl;
        cout << "Broj računa:" << pacijent.brojRacuna << endl;
        // Dodajte dodatne informacije o pacijentu ovisno o potrebama
    }
    else {
        cout << "Neispravan indeks pacijenta." << endl;
    }
}

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

        cout << "-----------------------------------------------------------------------------\n";
        cout << "ID LIJEKA" << "\tVRSTA LIJEKA" << "\t\tIME LIJEKA" << "           CIJENA LIJEKA(KM)"
             << endl; // Ispis zaglavlja tablice
        cout << "-----------------------------------------------------------------------------\n";
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
        cout << "Unesite ime i prezime kupca: ";
        cin.ignore();
        getline(cin, temp->imeKupca);
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

                cout << "Unesite svoj odabir:"; // Unos odabira lijeka
                cin >> temp->menu2[i];

                cout << "Ime lijeka: " << temp->imeLijeka[temp->menu2[i] - 1] << endl;  // Ispis imena odabranog lijeka
                cout << "Koliko lijekova želite:";
                cin >> temp->kolicinaLijeka[i];  // Unos količine lijeka
                temp->iznosNarudzbe[i] =
                        temp->kolicinaLijeka[i] * temp->cijenaLijeka[temp->menu2[i] - 1];  // Izračunaj ukupan iznos
                cout << "Iznos koji trebate platiti:" << temp->iznosNarudzbe[i] << " KM"
                     << endl;  // Ispis ukupnog iznosa
                system("PAUSE");

            }
            cout << "-----------------------------------------------------------------------------" << endl;
            cout << "Narudžba uspješno zabilježena" << endl;
            cout << "-----------------------------------------------------------------------------" << endl;
            cout << "Idite na izbornik računa za plaćanje računa" << endl;
            cout << "-----------------------------------------------------------------------------" << endl;
            system("PAUSE");

            temp->next = NULL;
            if (starting_point != NULL) {
                temp->next = starting_point;
            }
            starting_point = temp;
            system("cls");
        }
    }

    void delete_item() // Metoda za brisanje posljednje narudžbe lijeka
    {
        system("cls"); // Briše sadržaj konzole
        int i, num, count;
        cout << "Unesite podatak koji želite izbrisati:\n";
        cin >> num;
        node *q;
        node *temp;
        bool found;

        if (starting_point == NULL)
            cerr << "Nemoguće je izbrisati iz prazne liste.\n";
        else
        {
            if (starting_point->brojRacuna == num) // Ako je prvi element liste jednak broju koji želimo izbrisati
            {
                q = starting_point;
                starting_point = starting_point->next; // Promjena početne tačke na sljedeći element
                count--;
                if (starting_point == NULL)
                    lasting_point = NULL;
                delete q; // Oslobađanje memorije prvog elementa
                cout << "Račun je uspješno obrisan" << endl;
            }
            else
            {
                found = false;
                temp = starting_point;
                q = starting_point->next;

                while ((!found) && (q != NULL)) // Traženje broja koji želimo izbrisati u ostatku liste
                {
                    if (q->brojRacuna != num)
                    {
                        temp = q;
                        q = q->next;
                    }
                    else
                        found = true;
                }

                if (found) // Ako je broj pronađen
                {
                    temp->next = q->next; // Preskakanje čvora koji sadrži broj koji želimo izbrisati
                    count--;

                    if (lasting_point == q)
                        lasting_point = temp; // Ako je posljednji element lista, ažuriraj posljednju tačku
                    delete q; // Oslobađanje memorije čvora koji sadrži broj koji želimo izbrisati
                    cout << "Račun je uspješno obrisan" << endl;
                }
                else
                    cout << "Stavka koju želite izbrisati se ne nalazi u listi." << endl;
            }
        }

    }

    void update_order() // Metoda za izmjenu liste narudžbi
    {
        system("cls"); // Briše sadržaj konzole
        int i, ch, sid;
        bool found;
        found = false;
        temp = starting_point;
        cout << "Unesite broj računa za izmjenu: ";
        cin >> sid;
        if (temp == NULL && sid == 0)
        {
            cout << "NEMA ZAPISA ZA IZMJENU..!" << endl;
        }
        else
        {
            while (temp != NULL && !found)
            {
                if (temp->brojRacuna == sid)
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
                cout << "Promijeni broj računa: ";
                cin >> temp->brojRacuna;
                cout << "Promijeni ime kupca: ";
                cin.ignore();
                getline(cin, temp->imeKupca);
                cout << "Promijeni datum: ";
                cin >> temp->datum;
                cout << "Koliko novih lijekova želite promijeniti:" << endl;
                cout << "(Maksimalno 10 narudžbi po transakciji)\n";
                cout << "  ";
                cin >> temp->x;
                if (temp->x > 10)
                {
                    cout << "Količina lijekova koje ste naručili premašuje maksimalni iznos narudžbe!";
                    system("pause");
                }
                else
                {
                    for (i = 0; i < temp->x; i++)
                    {
                        cout << "Unesite svoj odabir za promjenu: " << endl;
                        cin >> temp->menu2[i];
                        cout << "Promijeni ime lijeka: " << temp->imeLijeka[temp->menu2[i] - 1] << endl;
                        cout << "Koliko novih lijekova želite: ";
                        cin >> temp->kolicinaLijeka[i];
                        temp->iznosNarudzbe[i] = temp->kolicinaLijeka[i] * temp->cijenaLijeka[temp->menu2[i] - 1];
                        cout << "Iznos koji morate platiti nakon izmjene je: " << temp->iznosNarudzbe[i] << " RM" << endl;
                        system("PAUSE");
                    }
                    temp = temp->next;
                    system("cls");
                }
                cout << "ZAPIS JE IZMJENJEN....!" << endl;
            }
            else
            {
                if (temp != NULL && temp->brojRacuna != sid)
                {
                    cout << "Nevažeći broj računa...!" << endl;
                }
            }
        }
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
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "\t\t\tOvdje je lista narudžbi" << endl;
        cout << "-----------------------------------------------------------------------------" << endl;

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

            cout << "-----------------------------------------------------------------------------" << endl;
            cout << "|  Vrsta lijeka    |     Ime lijeka     |    Količina    |   Ukupna cijena   |" << endl;
            cout << "-----------------------------------------------------------------------------" << endl;
            for (i = 0; i < temp->x; i++)
            {
                cout << "     " << temp->vrstaLijeka << "     " << "  \t\t";
                cout << "  " << temp->imeLijeka[temp->menu2[i] - 1] << "\t\t\t  ";
                cout << temp->kolicinaLijeka[i] << "\t\t";
                cout << temp->iznosNarudzbe[i] << " KM" << endl;
                cout << "-----------------------------------------------------------------------------" << endl;
            }

            temp->ukupnoNarudzbe = temp->iznosNarudzbe[0] + temp->iznosNarudzbe[1] + temp->iznosNarudzbe[2] + temp->iznosNarudzbe[3] + temp->iznosNarudzbe[4] + temp->iznosNarudzbe[5] + temp->iznosNarudzbe[6] + temp->iznosNarudzbe[7] + temp->iznosNarudzbe[8] + temp->iznosNarudzbe[9];
            cout << "Ukupan iznos računa: " << temp->ukupnoNarudzbe << " KM" << endl;
            cout << "Unesite iznos koji trebate platiti: ";
            cin >> num;

            cout << "\n";
            cout << "\n";
            cout << "Plaćanje izvršeno\nZahvaljujemo\n";
            cout << "\n-----------------------------------------------------------------------------\n";
        }
    }

    void summary() // Metoda za dnevni pregled ukupne prodaje
    {
        system("cls");
        node *temp;
        temp = starting_point;

        if (temp == NULL)
        {
            cout << "\t\t\tNema narudžbi za prikazivanje\n";
        }
        else
        {
            cout << "\n";
            cout << "-----------------------------------------------------------------------------\n" << endl;
            cout << " \tEvo dnevnog pregleda svih narudžbi \n"; // ispisuje sve račune

            while (temp != NULL)
            {

                cout << "Broj računa:" << temp->brojRacuna;
                cout << "\n";
                cout << "Ime kupca:" << temp->imeKupca << endl;
                cout << "\n";
                cout << "Datum narudžbe:" << temp->datum << endl;

                cout << "*****************************************************************************" << endl;

                cout << "-----------------------------------------------------------------------------" << endl;
                cout << "|  Vrsta lijeka  |   Ime lijeka    |    Količina     |    Ukupna cijena |" << endl;
                cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                for (int i = 0; i < temp->x; i++)
                {
                    cout << temp->vrstaLijeka << "  \t\t";
                    cout << temp->imeLijeka[temp->menu2[i] - 1] << "\t\t";
                    cout << temp->kolicinaLijeka[i] << "\t\t";
                    cout << temp->iznosNarudzbe[i] << " RM" << endl;
                    cout << "*****************************************************************************" << endl;
                }

                temp->ukupnoNarudzbe = temp->iznosNarudzbe[0] + temp->iznosNarudzbe[1] + temp->iznosNarudzbe[2] + temp->iznosNarudzbe[3] + temp->iznosNarudzbe[4] + temp->iznosNarudzbe[5] + temp->iznosNarudzbe[6] + temp->iznosNarudzbe[7] + temp->iznosNarudzbe[8] + temp->iznosNarudzbe[9];
                cout << "Ukupni iznos računa:" << temp->ukupnoNarudzbe;

                cout << "\n";
                cout << "\n";
                cout << "\n******************************************************************************\n";

                temp = temp->next;
            }
        }
    }

    void quit() // Metoda za izlaz iz programa
    {
        cout << "\nIzabrali ste izlazak.\n" << endl;
    }

    void odjava_radnika()
    {
        cout << "Da li ste sigurni da se želite odjaviti? (da/ne):";
        string odjavaOdgovor;
        cin >> odjavaOdgovor;
        cin.ignore();

        if (odjavaOdgovor == "da") {
            cout << "Radnik je odjavljen." << endl;
            throw runtime_error("ODJAVA");  // Bacanje izuzetka za povratak na početak programa
        }
        else {
            cout << "Nastavak rada." << endl;
            return;  // Nastavak izvršavanja programa
        }
    }

    MedType(); // Konstruktor klase MedType
};

MedType::MedType()
{
    // Implementacija konstruktora klase MedType
}

int main() {
    vector<node> pacijenti;
    // Učitavanje podataka iz datoteke prilikom pokretanja programa
    ifstream inputFile(FILENAME);
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            node pacijent;
            size_t delimiterPos1 = line.find(",");
            size_t delimiterPos2 = line.find(",", delimiterPos1 + 1);
            pacijent.imeKupca = line.substr(0, delimiterPos1);
            pacijent.datum = line.substr(delimiterPos1 + 1, delimiterPos2 - delimiterPos1 - 1);
            pacijent.brojRacuna = std::stoi(line.substr(delimiterPos2 + 1)); // Pretvorba u int
            pacijenti.push_back(pacijent);
        }
        inputFile.close();
    }

    system("COLOR 0F"); // Postavlja boju konzole (u ovom slučaju crna pozadina i bijeli tekst)
    MedType medType; // Kreiranje objekta klase medType
    int menu;

    string imePrezime;
    string password;

    cout << "\nDobrodošli! Unesite vaše ime i prezime:";
    getline(cin, imePrezime);

    bool validanRadnik = false;
    for (const Radnik& radnik : radnici) {
        if (radnik.imePrezime == imePrezime) {
            cout << "Unesite lozinku:";
            getline(cin, password);
            cin.ignore();

            if (radnik.password == password) {
                validanRadnik = true;
                break;
            }
        }
    }

    if (!validanRadnik) {
        cout << "Neispravno ime/prezime ili lozinka. Izlazak iz programa." << endl;
        return 0;
    }

    // Očisti ekran
    system("cls");

    // Ispisivanje poruke dobrodošlice za radnika
    cout << "Dobrodošli, " << imePrezime << "! Sretan rad!" << endl;

    if (validanRadnik) {
        vector<node> pacijenti;
        int izbor;

        bool odjava = false;
        while (!odjava) {
            cout << "\nSISTEM ZA VOĐENJE APOTEKE" << endl;
            cout << "-----------------------------------------------------------------------------------" << endl;
            cout << "Izaberite opciju:" << endl;
            cout << "\n\t1. Unesi novu narudžbu lijeka" << endl;
            cout << "\t2. Obriši posljednju narudžbu lijeka" << endl;
            cout << "\t3. Izmijeni listu narudžbi" << endl;
            cout << "\t4. Ispisi račun i izvrši plaćanje" << endl;
            cout << "\t5. Dnevni pregled ukupne prodaje" << endl;
            cout << "\t6. Unesi pacijenta" << endl;
            cout << "\t7. Prikaži sve pacijente" << endl;
            cout << "\t8. Prikaži pojedinačnog pacijenta" << endl;
            cout << "\t9. Izlaz" << endl;
            cout << "\t10. Odjava\n" << endl;
            cout << "Unesite broj opcije:";
            cin >> izbor;
            cin.ignore();

            switch (izbor) {
                case 1:
                    // Ako je izabrana opcija 1, poziva se metoda za unos nove narudžbe lijeka
                    medType.order();
                    break;

                case 2:
                    // Ako je izabrana opcija 2, poziva se metoda za brisanje posljednje narudžbe lijeka
                    medType.delete_item();
                    break;

                case 3:
                    // Ako je izabrana opcija 3, poziva se metoda za izmjenu liste narudžbi
                    medType.update_order();
                    break;

                case 4:
                    // Ako je izabrana opcija 4, poziva se metoda za ispisivanje liste narudžbi
                    medType.order_list();
                    break;

                case 5:
                    // Ako je izabrana opcija 5, poziva se metoda za dnevni pregled ukupne prodaje
                    medType.summary();
                    break;

                case 6:
                    // Ako je izabrana opcija 6, poziva se metoda za unos pacijenta
                    unosPacijenta(pacijenti);
                    break;

                case 7:
                    // Ako je izabrana opcija 7, poziva se metoda za prikaz svih unesenih pacijenata
                    prikaziSvePacijente(pacijenti);
                    break;

                case 8:
                    // Ako je izabrana opcija 8, poziva se metoda za dšrikaz pojedinačnih pacijenata
                    prikaziPacijente(pacijenti);
                    break;

                case 9:
                    // Ako je izabrana opcija 9, poziva se metoda za izlazak iz programa
                    medType.quit();
                    cout << "Hvala na korištenju programa. Izlazak iz programa." << endl;
                    return 0;
                    break;

                case 10:
                    // Ako je izabrana opcija 10, poziva se metoda za odjavu radnika
                    medType.odjava_radnika();
                    odjava = true;
                    break;

                default:
                    cout << "Neispravan izbor. Molimo unesite ponovo." << endl;
                    break;
            }
        }
    }

    // Spremanje podataka u datoteku prilikom završetka programa
    ofstream outputFile(FILENAME);
    if (outputFile.is_open()) {
        for (const node& pacijent : pacijenti) {
            outputFile << pacijent.imeKupca << "," << pacijent.datum << "," << pacijent.brojRacuna << endl;
        }
        outputFile.close();
    }
    else {
        cout << "Nije moguće otvoriti datoteku za pisanje." << endl;
    }

    system("PAUSE");
    return 0;
}