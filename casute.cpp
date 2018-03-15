#include<iostream>
#include<conio.h>
#include<string.h>
#include<math.h>

#define MAX_LENGTH 20

using namespace std;

struct casuta
{
	char culoare[MAX_LENGTH];
	int na;

	casuta *st;
	casuta *dr;

};

//functie pt citirea unui nod
casuta* citeste_casuta()
{
	casuta *nod1;
	nod1 = new casuta;
	cout << "Culoarea casei: ";
	cin >> nod1->culoare;

	cout << " Numarul de aparitii: ";
	cin >> nod1->na;
	nod1->st = NULL;
	nod1->dr = NULL;
	return nod1;
}

//functie pt crearea arborelui 

void creare_oras(casuta *radacina, casuta *nod)
{
	if (strcmp(nod->culoare, radacina->culoare) < 0)
	{
		if (radacina->st != NULL)
			creare_oras(radacina->st, nod);
		else
			radacina->st = nod;
	}
	else
		if (strcmp(nod->culoare, radacina->culoare) >0)
	
	{
		if (radacina->dr != NULL)
			creare_oras(radacina->dr, nod);
		else
			radacina->dr = nod;
	}
	else 
		cout<<"casuta se gaseste deja in oras"<<endl;
	
}

//functia de parcurgere in inordine

void evidenta_oras(casuta *radacina)
{
	if (radacina)
	{
		evidenta_oras(radacina->st);
		cout << radacina->culoare << radacina->na << " ";
		evidenta_oras(radacina->dr);
	}
}


//functie pt calcularea nr de frunze din arbore

void calculare_nr_frunze(casuta *radacina, int *n)
{

	if (radacina->dr == NULL && radacina->st == NULL)
		(*n)++;
	else
	{
		if (radacina->dr != NULL)
			calculare_nr_frunze(radacina->dr, n);
		if (radacina->st != NULL)
			calculare_nr_frunze(radacina->st, n);
	}
}


//functie care determina greutatea arborelui,nr de frunze,apeleaza functia anterioara,si afiseaza n(nr de frunze)

int culori_periferie(casuta *radacina)
{
	int n = 0;

	calculare_nr_frunze(radacina, &n);
	cout << "Numarul de frunze este: " << n << endl;
	return n;
}

//functie ce determina inaltimea(nr de nivele din arbore)

int inaltime(casuta *radacina)
{

	int stanga = 0;
	int dreapta = 0;

	if (radacina == NULL)
	{
		return 0;
	}

	else

	{
		stanga = inaltime(radacina->st);
		dreapta = inaltime(radacina->dr);

		if (stanga>dreapta || stanga == dreapta)

		{
			return (stanga + 1);
		}

		else

		{
			return (dreapta + 1);
		}

	}

}

//functia cauta daca nodul de culoare galbena se gaseste in arbore si imi returneaza adresa lui

casuta* cautare(casuta *radacina, casuta *locatie, int *ok)
{
	if (*ok == 1 || *ok == 2)
		return locatie;
	if (radacina->st != NULL)
		if (strcmp(radacina->st->culoare, "galben") != 0)
			cautare(radacina->st, locatie, ok);
		else
		{
			if (radacina->st->na > 1)
			{
				radacina->st->na--;
				locatie = NULL;
				*ok = 2;
				return locatie;
			}
			else
			{
				*ok = 1;
				locatie = radacina->st;
				radacina->st = NULL;
				return locatie;
			}
		}
	if (*ok != 1 && *ok != 2)
		if (radacina->dr != NULL)
		{
			if (strcmp(radacina->dr->culoare, "galben") != 0)
				cautare(radacina->dr, locatie, ok);
			else
			{
				if (radacina->dr->na > 1)
				{
					radacina->dr->na--;
					*ok = 2;
					locatie = NULL;
					return locatie;
				}
				else
				{
					*ok = 1;
					locatie = radacina->dr;
					radacina->dr = NULL;
					return locatie;
				}
			}
		}
}

/*functia de stergere a nodului galben ,apeleaza functia anterioara,
daca casa galbena se gaseste si nr de aparitii este 1 o sterge,altfel decrementeaza nr de aparitii
*/
casuta* sterge_casa(casuta *radacina)
{
	int ok = 0;
	casuta *a;
	if (strcmp(radacina->culoare, "galben") == 0)
	{
		if (radacina->na > 1)
			radacina->na--;
		else
		{
			a = radacina;
			if (a->dr)
			{
				radacina = a->dr;
				if (a->st)
					creare_oras(radacina, a->st);
			}
			else
				radacina = a->st;
			delete(a);
		}
	}
	else
	{
		a = cautare(radacina, NULL, &ok);
		if (ok == 0)
			cout << "nu s-a gasit casa";
		else
			if (ok == 1)
			{
				if (a->st != NULL)
					creare_oras(radacina, a->st);
				if (a->dr != NULL)
					creare_oras(radacina, a->dr);
			}
	}
	return radacina;
}

//functia verifica daca arborele este binar de cautare
int verific(casuta *p)
{
	int k = 2;
	cout << inaltime(p) << " " << culori_periferie(p) << endl;
	if (culori_periferie(p) == pow(2, inaltime(p) - 1))

		return 1;

	else

		return 0;

}

int main()
{



	int k, aux = 0, i;
	casuta *radacina = NULL;
	char cerinta;
	do
	{
		cout << "Ce doriti sa faceti? " << endl << "creare-> c " << endl << "afisare->  a" << endl << "adaugare-> A " << endl << "stergere-> S" << endl;
		cout << "inaltime-> i" << endl << "greutate-> g" << endl << "verificare-> v" << endl;
		cin >> cerinta;

		switch (cerinta)
		{
		case 'c':
			int n;
			cout << "Cate casute va avea orasul? ";
			cin >> n;
			for (i = 0;i < n;i++)
			{
				casuta *nod;
				nod = citeste_casuta();
				if (radacina == NULL)
					radacina = nod;
				else
					creare_oras(radacina, nod);
			}

			cout << "--------------------------------------";
			cout << endl;
			break;

		case 'a':
			evidenta_oras(radacina);
			cout << "--------------------------------------";
			cout << endl;
			break;

		case 'A':
			casuta *nod;
			nod = citeste_casuta();
			creare_oras(radacina, nod);
			cout << "--------------------------------------";
			cout << endl;
			break;

		case 'S':
			radacina = sterge_casa(radacina);
			cout << "--------------------------------------";
			cout << endl;
			break;

		case 'i':
			cout << inaltime(radacina);
			cout << "--------------------------------------";
			cout << endl;
			break;

		case 'g':

			culori_periferie(radacina);
			cout << "--------------------------------------";
			cout << endl;
			break;

		case 'v':
			if (verific(radacina) == 1)	cout << "arborele este binar complet";
			else	cout << "nu este binar complet";
			cout << "--------------------------------------";
			cout << endl;
			break;

		}

		cout << "Continuati programul? <cititi un intreg; pentru a iesi, cititi valoarea 0>: ";
		cin >> k;

	} while (k != 0);




	getch();
	return 0;

}
