
Am folosit 4 biblioteci: iostream,conio(pt getch),math(pt pow),string(strcmp)

Am creat o structura de tip arbore binar numita casuta cu campurile culoare, na(numar de apariti al culorii respective) si pointerii catre adresele elementelor de pe ramurile arborelui(stanga si dreapta).

1)
Prima functie(citeste_casuta) este una de citire a campurilor unui nod de tip structura(cea mentionata mai sus).

Aceasta functie citeste si aloca memorie pentru campurile culoare si na si initializeaza pointerii stanga si dreapta cu NULL.


2)
A doua functie(creare_oras) este una de tip cautare si introducere element in arbore, aceasta verifica recursiv unde trebuie introdus nod-ul ,apoi face acest lucru.

Este de tip void deoarece nu se modifica adresa radacinii ,iar elementele vor ramane legate de aceasta indiferent de ce modificari vor fi facute.

Functia are 2 parametrii radacina si nodul care trebuie introdus, la reapelare parametrul radacina se va modifica in functie de cum trebuie introdus nodul in arbore.

3)
A treia functie(evidenta_oras) are doar un parametru (radacina) si aceasta este de tip void.

Parcurge arborele recursiv si afiseaza nodurile in inordine (stanga – radacina – dreapta SRD).


4)
A patra functie(calculare_nr_frunze) are 2 parametrii(radacina si n) ,n este un pointer de tip int. L-am folosit ca pointer deoarece am nevoie de valoarea lui finala.

Functia calculeaza cate frunze are arborele.


5)
A cincea functie(culori_periferie) este pentru afisarea numarului de frunze, are un parametru(radacina) si apeleaza functia 4.

6)
A sasea functie (inaltime)  calculeaza inaltimea arborelui si returneaza aceasta valoare.

7)
A saptea functie(cautare) cauta primul nod de culoare galbena si returneaza adresa acestui nod.

8)
A opta functie(sterge_casa) verifica daca radacina are culoarea galbena, daca o are transforma subarborele drept in arbore principal si adauga subarborele stang la acesta.

Daca radacina nu este de culoare galbena apeleaza functia sapte si utilizeaza adresa nodului pentru a-l sterge, adaugand(daca exista) subarborele stang si subarborele drept la arbore.

9)
A noua functie(verific) verifica daca arborele este binar complet folosind o formula matematica.

Main-ul este de tip meniu folosind un switch in care sunt apelate toate functiile de mai sus.