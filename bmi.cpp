#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

/**
 * funkcja obliczajaca bmi
 * @param masa - waga podana w kg
 * @param wzrost - wzrost podany w kg, odzielone kropka np 1.80
 * @return bmi
 */
int bmi(double, double);

/**
 * funkcja informujaca o interpretacji wyniku
 * @param wynik
 * @return opis
 */
string opis(float);
/**
 * funkcja wyswietlajaca opis wyniku
 * @param witaj
 */
void welcome(string); 

double masa, wzrost;
float wynik;
float *wsk = &wynik;
string witaj = " WITAJ";
string info = " Oto kalkulator BMI ";
string autor = " autor: Adam Kuchto ";
char praca;
int main()
{
    welcome(witaj);

    do
    {

        cout << "Podaj wage: ";
        cin >> masa;
        if (cin.fail())
        {
            cout << "podano niewlasciwe dane" << endl;
            return 1;
        }
        cout << setw(6) << "Podaj wzrost: ";
        cin >> wzrost;
        if (cin.fail())
        {
            cout << "podano niewlasciwe dane" << endl;
            return 1;
        }

        wynik = bmi(masa, wzrost);
        cout << "Twoje BMI to: " << wynik << opis(*wsk) << endl;

        cout << "czy chcesz kontynuowac? T/N " << endl;
        cin >> praca;
        cout << endl;

    } while (praca == 't' || praca == 'T');

    return 0;
}
int bmi(double, double)
{
    float bmi = masa / pow(wzrost, 2);
    return bmi;
}
string opis(float)
{
    string opis;
    if (wynik <= 16)
    {
        opis = " WYGLODZENIE ";
    }
    else if ((wynik > 16) && (wynik < 16.99))
    {
        opis = " WYCHUDZENIE ";
    }
    else if ((wynik > 17) && (wynik < 18.49))
    {
        opis = " NIEDOWAGA ";
    }
    else if ((wynik > 18.5) && (wynik < 24.99))
    {
        opis = " OPTIMUM ";
    }
    else if ((wynik > 25) && (wynik < 29.99))
    {
        opis = " NADWAGA ";
    }
    else if ((wynik > 30) && (wynik < 34.99))
    {
        opis = " OTYLOSC I STOPNIA ";
    }
    else if ((wynik > 35) && (wynik < 39.99))
    {
        opis = " OTYLOSC II STOPNIA ";
    }
    else if (wynik > 40)
    {
        opis = " OTYLOSC III STOPNIA ";
    }

    return opis;
}
void welcome(string)
{
    int str = info.length();
    for (int i = 0; i < str + 2; i++)
    {
        cout << "-";
    }
    cout << endl;

    cout << setw(12) << witaj << endl;
    cout << info << endl;
    cout << setw(2) << autor << endl;
    for (int i = 0; i < str + 2; i++)
    {
        cout << "-";
    }
    cout << endl;
}