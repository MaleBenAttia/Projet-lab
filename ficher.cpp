#include "foc.h"
#include <locale>
#include <windows.h>
using namespace std;





// Fonction pour lire et afficher les mots d'un fichie
void lireEtAfficherMots(const string &nomFichier, int n, int m, int& khrouj, int niv1);
int main()
{

SetConsoleOutputCP(65001);
int niveau;
  // Boucle pour sélectionner le niveau
  do {
    cout << "=============================================" << endl;
    cout << "  Bienvenue dans le Labyrinthe Mystérieux !  " << endl;
    cout << "=============================================" << endl;
    cout << "Choisissez votre niveau de difficulté :" << endl;
    cout << "1. Débutant : Parfait pour explorer et apprendre." << endl;
    cout << "2. Amateur : Un défi pour les aventuriers aguerris." << endl;
    cout << "3. Expert : Seuls les plus courageux osent s'aventurer ici." << endl;
    cout << "=============================================" << endl;
    cout << "Entrez votre choix (1 à 3) : ";
    cin >> niveau;
} while (niveau > 3 || niveau < 1);

// Affichage du niveau sélectionné avec des messages amusants
switch (niveau) {
    case 1:
        cout << "=============================================" << endl;
        cout << "  Vous avez choisi le niveau Débutant !        " << endl;
        cout << "=============================================" << endl;
        break;
    case 2:
        cout << "=============================================" << endl;
        cout << "  Vous avez choisi le niveau Amateur !        " << endl;
        cout << "=============================================" << endl;
        break;
    default:
        cout << "=============================================" << endl;
        cout << "  Vous avez choisi le niveau Expert !         " << endl;
        cout << "=============================================" << endl;
        break;
}
countdown(3);

    do
{
     cout << "Donnez la taille de la matrice (n x m) : " <<  endl;
     cin >> n;
     cin >> m;

    if (n > 100 || m > 100)
    {
         cout << "Erreur : La taille de la matrice ne doit pas dépasser 100 x 100. Veuillez réessayer.\n";
    }
} while (n > 100 || m > 100);

  string nomFichier = "mehdi.txt"; // Remplacez par le nom de votre fichier
lireEtAfficherMots(nomFichier, n, m,khrouj,niveau);
afficheMatrice2(Matric,n, m+1); // Affiche la matrice




int nb1 = combienDeUn(n, m); // Compte les '1' dans la matrice
cout << "Le nombre de '1' dans la matrice est : " << nb1 <<  endl;

do
{
     cout << "Donnez la position de départ (n1 et m1) : " <<  endl;
     cin >> n1;

     cin >> m1;

    if (n1 >= n || n1 < 0 || m1 >= m || m1 < 0 )
    {
         cout << "Erreur : La position de départ doit être dans les limites de la matrice. Veuillez réessayer.\n";
    }
    if (Matric[n1][m1] =='1'){
        cout << "opss il y a un mur"<<endl;
    }
} while (n1 >= n || n1 < 0 || m1 >= m || m1 < 0 || Matric[n1][m1] =='1');

T[0] =  Matric[n1][m1];
char abda = Matric[n1][m1]; // Sauvegarde la valeur actuelle de la case
      // Marque la position initiale dans la matrice
direction(n, m, n1, m1, m/*ena lezem nhotou akber kelma fel txt*/, 1, abda,niveau); // Appelle la fonction de direction

return 0;

}