// game.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include"mayne.h"
#include"mayne_player.h"
#include"mayne_computer.h"


using namespace std;


int how_many_mayne=0;
int how_many_mayne_player = 0;
int how_many_mayne_computer = 0;
int how_many_rounds = 0;

//functions-prototypes
void load();
void round(mayne_player*, mayne_computer*, mayne*);
void stats(mayne_player*, mayne_computer*);


int main()
{
    //generating random numbers
    srand(time(NULL));

    mayne* x = new mayne;
    mayne_player* ja = new mayne_player;
    mayne_computer* komp = new mayne_computer;

    //game takes place in rounds, in loop
    do
    {
        round(ja, komp, x);
        if (getchar() == '/n')
            continue;
    } while (1 == 1);
}

void load();

void round(mayne_player* j, mayne_computer* k, mayne* x)
{
   how_many_rounds += 1;

   //draw in range<-15;15>
   float losowa = rand() % 31 - 15;

   //indicator
   x = k;
   float a = (j->fire() + losowa / 100 + j->getexperience()/100)-x->getshield();
   cout <<"**************************" << endl;
   cout << "|         Round:" << how_many_rounds <<"        |"<< endl;
   cout << "**************************" << endl;
   cout << "my fire:" << a<<endl;
   x->sethp(x->gethp() - a);
   if (x->gethp() <= 0)
       x->remove();

//if computer soldiers =0, game comes to end with our victory
   if (how_many_mayne_computer == 0)
   {
       cout << "**************************" << endl;
       cout << "|        You won          |" << endl;
       cout << "state of the player's army:" << endl;
       cout << "number of soldiers:" << how_many_mayne_player << endl;
       cout << "life: " << j->gethp() << endl;
       cout << "experience: " << j->getexperience() << endl;
       exit(EXIT_SUCCESS);
   }
       //draw from range<-15;15>
       losowa = rand() % 31 - 15;

       x = j;
       float b = (k->fire() + losowa / 100 + k->getexperience() / 100) - x->getshield();
       cout << "computer fire " << endl;
       cout << b << endl;
       x->sethp(x->gethp() - b);
       if (x->gethp() <= 0)
           x->remove();

       //if number of soldiers=0, game comes to end, computer win

       if (how_many_mayne_player == 0)
       {
           cout << "**************************" << endl;
           cout << "|        Computer won       |" << endl;
           cout << "state of the computer's army:" << endl;
           cout << "number of soldiers:" << how_many_mayne_computer << endl;
           cout << "life: " << k->gethp() << endl;
           cout << "experience: " << k->getexperience() << endl;
           exit(EXIT_SUCCESS);
       }
       //gaining experience by player
       if (a > b)
           j->setexperience(j->getexperience() + 10);
       else
           k->setexperience(k->getexperience() + 10);

       //fucntion stats
       stats(j, k);
 }

void stats(mayne_player* j, mayne_computer* k)
{
    cout << "state of the player's army:" << endl;
    cout << "number of soldiers:" << how_many_mayne_player << endl;
    cout << "Life: " << j->gethp() << endl;
    cout << "Experience: " << j->getexperience() << endl;


    cout << "state of the computer's army:" << endl;
    cout << "number of soldiers:" << how_many_mayne_computer << endl;
    cout << "life: " << k->gethp() << endl;
    cout << "experience: " << k->getexperience() << endl;
}


// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
