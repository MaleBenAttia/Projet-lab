<<<<<<< HEAD

#ifndef finc
#define finc
#include <windows.h>
#include <locale>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <cctype> // Pour isalpha()
#include <thread> // Pour std::this_thread::sleep_for
#include <chrono> // Pour std::chrono::seconds
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <ctime>
using namespace std;
vector<string> motsSelectionnes(100); // vecteur ll mot Selectionnes mel ficher.txt
int x = 0,
    khrouj = 0, // bch narfou position taa el nejma ll khrouj
    kk = 0;
int T1[100]; // tableau li nalkaw fih el a9se path binet el hrouf
#define connb (Matric[i][j] == '2' || Matric[i][j] == '3' || Matric[i][j] == '4' || Matric[i][j] == '5' || Matric[i][j] == '6' || Matric[i][j] == '7' || Matric[i][j] == '8' || Matric[i][j] == '9')
#define conYO (rec != 'Y' && rec != 'y' && rec != 'N' && rec != 'n')
#define BLOQ(valeurVoisin) (valeurVoisin < '1' || valeurVoisin > '9')
// les conditioon ta3 el hyout fel les mouvement
#define H (Matric[n1 - 1][m1] == '1' || Matric[n1 - 1][m1] == '2' || Matric[n1 - 1][m1] == '3' || \
           Matric[n1 - 1][m1] == '4' || Matric[n1 - 1][m1] == '5' || Matric[n1 - 1][m1] == '6' || \
           Matric[n1 - 1][m1] == '7' || Matric[n1 - 1][m1] == '8' || Matric[n1 - 1][m1] == '9')

#define B (Matric[n1 + 1][m1] == '1' || Matric[n1 + 1][m1] == '2' || Matric[n1 + 1][m1] == '3' || \
           Matric[n1 + 1][m1] == '4' || Matric[n1 + 1][m1] == '5' || Matric[n1 + 1][m1] == '6' || \
           Matric[n1 + 1][m1] == '7' || Matric[n1 + 1][m1] == '8' || Matric[n1 + 1][m1] == '9')

#define G (Matric[n1][m1 - 1] == '1' || Matric[n1][m1 - 1] == '2' || Matric[n1][m1 - 1] == '3' || \
           Matric[n1][m1 - 1] == '4' || Matric[n1][m1 - 1] == '5' || Matric[n1][m1 - 1] == '6' || \
           Matric[n1][m1 - 1] == '7' || Matric[n1][m1 - 1] == '8' || Matric[n1][m1 - 1] == '9')

#define D (Matric[n1][m1 + 1] == '1' || Matric[n1][m1 + 1] == '2' || Matric[n1][m1 + 1] == '3' || \
           Matric[n1][m1 + 1] == '4' || Matric[n1][m1 + 1] == '5' || Matric[n1][m1 + 1] == '6' || \
           Matric[n1][m1 + 1] == '7' || Matric[n1][m1 + 1] == '8' || Matric[n1][m1 + 1] == '9')

#define HG (Matric[n1 - 1][m1 - 1] == '1' || Matric[n1 - 1][m1 - 1] == '2' || Matric[n1 - 1][m1 - 1] == '3' || \
            Matric[n1 - 1][m1 - 1] == '4' || Matric[n1 - 1][m1 - 1] == '5' || Matric[n1 - 1][m1 - 1] == '6' || \
            Matric[n1 - 1][m1 - 1] == '7' || Matric[n1 - 1][m1 - 1] == '8' || Matric[n1 - 1][m1 - 1] == '9')

#define HD (Matric[n1 - 1][m1 + 1] == '1' || Matric[n1 - 1][m1 + 1] == '2' || Matric[n1 - 1][m1 + 1] == '3' || \
            Matric[n1 - 1][m1 + 1] == '4' || Matric[n1 - 1][m1 + 1] == '5' || Matric[n1 - 1][m1 + 1] == '6' || \
            Matric[n1 - 1][m1 + 1] == '7' || Matric[n1 - 1][m1 + 1] == '8' || Matric[n1 - 1][m1 + 1] == '9')

#define BG (Matric[n1 + 1][m1 - 1] == '1' || Matric[n1 + 1][m1 - 1] == '2' || Matric[n1 + 1][m1 - 1] == '3' || \
            Matric[n1 + 1][m1 - 1] == '4' || Matric[n1 + 1][m1 - 1] == '5' || Matric[n1 + 1][m1 - 1] == '6' || \
            Matric[n1 + 1][m1 - 1] == '7' || Matric[n1 + 1][m1 - 1] == '8' || Matric[n1 + 1][m1 - 1] == '9')

#define BD (Matric[n1 + 1][m1 + 1] == '1' || Matric[n1 + 1][m1 + 1] == '2' || Matric[n1 + 1][m1 + 1] == '3' || \
            Matric[n1 + 1][m1 + 1] == '4' || Matric[n1 + 1][m1 + 1] == '5' || Matric[n1 + 1][m1 + 1] == '6' || \
            Matric[n1 + 1][m1 + 1] == '7' || Matric[n1 + 1][m1 + 1] == '8' || Matric[n1 + 1][m1 + 1] == '9')
// Déclaration de la matrice globale
char Matric[100][100];  // matrice principale
char Matric1[100][100]; // matrice de contole pour la generation de grille
char Matric3[100][100]; // lena el matrice eli bch yal3eb aleha djikstra
char T[20];
int m, n, choix, n1, m1;

// ll matrice eli bch yal3eb aleha djikstra
void recopiematrice(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            Matric3[i][j] = Matric[i][j];
        }
    }
}

void countdown(int seconds)
{
    for (int i = seconds; i > 0; i--)
    {
        cout << "Début du jeu dans " << i << "..." << endl;
#ifdef _WIN32
        Sleep(1000); // Pause de 1 seconde (Windows)
#endif
    }
    cout << "C'est parti ! Bonne chance !" << endl;
}

// bch taref el matrice eloula 9adech feha men 1 w zeda ll les fonction li generiw el grille
int combienDeUn(int n, int m)
{
    int count = 0; // Compteur initialisé à 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (Matric[i][j] == '1')
            {
                count++; // Incrémenter le compteur si le caractère est '1'
            }
        }
    }
    return count;
}

// Fonction pour afficher la matrice
void afficheMatrice(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << " " << Matric[i][j] << " "; // Affichage du caractère
        }
        cout << endl; // Retour à la ligne après chaque ligne de la matrice
    }
}
// hedha el menu taa el laba bch yaref el user chnwa yakhtar
void menu()
{

    cout << "\n--- Menu de déplacement ---\n";
    cout << "1. Haut\n";
    cout << "2. Bas\n";
    cout << "3. Gauche\n";
    cout << "4. Droite\n";
    cout << "5. Diagonale Haut-Gauche\n";
    cout << "6. Diagonale Haut-Droite\n";
    cout << "7. Diagonale Bas-Gauche\n";
    cout << "8. Diagonale Bas-Droite\n";
    cout << endl;
}
// hedhi bch tabi matrice d'une facon aleatoire
void remplirMatrice(int n, int m)
{

    srand(time(0)); // Initialisation de la graine aléatoire
    int range = 30; // 26 lettres + 4 pour le chiffre '1'

    for (int i = 0; i < n; i++)
    {
        bool hasOne = false; // Vérifie si la ligne contient au moins un '1'

        for (int j = 0; j < m; j++)
        {
            int randomValue = rand() % range; // Génère une valeur entre 0 et 29

            // Génération des caractères aléatoires
            if (randomValue < 4)
            {
                Matric[i][j] = '1'; // Cas pour '1'
                hasOne = true;      // Marque qu'il y a un '1' dans cette ligne
            }
            else
            {
                Matric[i][j] = 'A' + (randomValue - 4); // Cas pour 'A' à 'Z'
            }
        }

        // Si la ligne n'a pas de '1', force l'ajout d'un '1'
        if (!hasOne)
        {
            int randomColumn = rand() % m; // Choisir une colonne aléatoire
            Matric[i][randomColumn] = '1';
        }
    }
}

// lena el matrice andha nejma ama fama hyout nafss el ligne ta3 el nejma donc invisible ll user lena el affichage ysir bel behi
// ekher colone nraw ken el nejma ama howa fama nejma w hyout
void afficheMatrice2(char Matri[][100], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j == m - 1 && Matri[i][j] == '1')
            {
                cout << " ";
            }

            else
            {
                cout << " " << Matri[i][j] << " "; // Affichage du caractère
            }
        }

        // Vérification si le dernier élément de la ligne est '1'

        cout << endl; // Retour à la ligne après chaque ligne de la matrice
    }
}

void remplirMatriceN1(int n, int m, vector<string> motsSelectionnes, int &khrouj)
{
    int randomValue;
    srand(time(0)); // Initialisation de la graine aléatoire
    int range = 30; // 26 lettres (A-Z) + 4 pour le chiffre '1'

    for (int i = 0; i < n; i++)
    {
        string motCourant = motsSelectionnes[i];
        for (int j = 0; j < motCourant.length(); j++)
        {
            Matric[i][j] = motCourant[j];
            // cout << Matric[i][j] << " ";
        }
        //  cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        bool hasOne = false; // Vérifie si la ligne contient au moins un '1'

        for (int j = 0; j < m; j++)
        {
            if (!isalpha(Matric[i][j])) // Remplir uniquement les cases vides
            {
                randomValue = rand() % range; // Génère une valeur entre 0 et 29

                // Génération des caractères aléatoires
                if (randomValue < 4)
                {
                    Matric[i][j] = '1'; // Cas pour '1'
                    hasOne = true;      // Marque qu'il y a un '1' dans cette ligne
                }
                else
                {
                    Matric[i][j] = 'A' + (randomValue - 4); // Cas pour 'A' à 'Z'
                }
            }
        }

        // Si la ligne n'a pas de '1', on force l'ajout d'un '1' quelque part
        if (!hasOne)
        {
            int randomColumn = motsSelectionnes[i].length() + (rand() % (m - motsSelectionnes[i].length()));
            Matric[i][randomColumn] = '1';
        }
    }

    for (int i = 0; i < n; i++)
    {
        Matric[i][m] = '1';
    }
    // Ajouter un `*` à une ligne aléatoire à la dernière colonne
    khrouj = rand() % n;
    Matric[khrouj][m] = '*'; // `m` étant la dernière colonne après les données
    Matric[khrouj][m - 1] = 'A' + m;
    recopiematrice(n, m);
}

void remplirMatriceN3(int n, int m, vector<string> motsSelectionnes, int &khrouj)
{
    srand(time(0)); // Initialisation de la graine aléatoire
    int range = 30; // 26 lettres (A-Z) + 4 pour le chiffre '1'
    char Matric1[100][100];

    // Initialisation des matrices

    for (int i = 0; i < n; i++)
    {
        bool hasOne = false; // Vérifie si la ligne contient au moins un '1'

        for (int j = 0; j < m; j++)
        {
            int randomValue = rand() % range; // Génère une valeur entre 0 et 29
            Matric1[i][j] = 'r';
            // Génération des caractères aléatoires
            if (randomValue < 4)
            {
                Matric[i][j] = '1'; // Cas pour '1'
                hasOne = true;      // Marque qu'il y a un '1' dans cette ligne
            }
            else
            {
                Matric[i][j] = 'A' + (randomValue - 4); // Cas pour 'A' à 'Z'
            }
        }

        // Si la ligne n'a pas de '1', force l'ajout d'un '1'
        if (!hasOne)
        {
            int randomColumn = rand() % m; // Choisir une colonne aléatoire
            Matric[i][randomColumn] = '1';
        }
    }

    // Placement des mots
    for (int rep = 0; rep < motsSelectionnes.size(); rep++)
    {
        string mot = motsSelectionnes[rep];
        int k = mot.length();
        int c = 0;
        while (c < k)
        {
            int row = rand() % n;
            int col = rand() % m;

            // Vérifier si la case est disponible
            while (Matric1[row][col] == '1')
            {
                row = rand() % n;
                col = rand() % m;
            }

            Matric[row][col] = mot[c]; // Placement du caractère
            Matric1[row][col] = '1';   // Marquer la case comme occupée
            c++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        Matric[i][m] = '1';
    }
    // Ajouter un `*` à une ligne aléatoire à la dernière colonne
    khrouj = rand() % n;
    Matric[khrouj][m] = '*'; // `m` étant la dernière colonne après les données
    Matric[khrouj][m - 1] = 'A' + m;
    recopiematrice(n, m);
    /*
    // Affichage de la matrice Matric
    cout << "Matrice principale : " << endl;
    afficheMatrice2(n + 1, m + 1);

    // Affichage de la matrice Matric1
    cout << "Matrice des indices (1 = mot placé, 0 = vide) : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << " " << Matric1[i][j] << " ";
        }
        cout << endl;
    }*/
}

void remplirMatriceN2(int n, int m, vector<string> motsSelectionnes, int &khrouj)
{
    srand(time(0)); // Initialisation de la graine aléatoire
    int range = 30; // 26 lettres (A-Z) + 4 pour '1'

    // Initialisation de la matrice avec des caractères aléatoires
    for (int i = 0; i < n; i++)
    {
        bool hasOne = false; // Vérifie si la ligne contient au moins un '1'

        for (int j = 0; j < m; j++)
        {
            int randomValue = rand() % range;
            if (randomValue < 4)
            {
                Matric[i][j] = '1'; // Placement de quelques '1'
                hasOne = true;
            }
            else
            {
                Matric[i][j] = 'A' + (randomValue - 4); // Lettre aléatoire
            }
        }

        // Si la ligne n'a pas de '1', en ajouter un
        if (!hasOne)
        {
            int randomColumn = rand() % m;
            Matric[i][randomColumn] = '1';
        }
    }

    // **Placement des mots avec inversion**
    int totalMots = motsSelectionnes.size();
    for (int i = 0; i < totalMots; i++)
    {
        string motCourant = motsSelectionnes[i];
        int longueurMot = motCourant.length();
        int milieu = longueurMot / 2;

        // Ligne normale
        int rowNormale = i % n;
        // Ligne inversée
        int rowInverse = (n - 1 - i) % n;

        // **Placer la première moitié**
        for (int j = 0; j < milieu; j++)
        {
            Matric[rowNormale][j] = motCourant[j];
        }

        // **Placer la deuxième moitié dans la ligne inverse**
        for (int j = milieu; j < longueurMot; j++)
        {
            Matric[rowInverse][m - longueurMot + j] = motCourant[j]; // Mettre à la fin de la ligne inverse
        }
    }

    // Ajouter un `*` à une ligne aléatoire à la dernière colonne
    khrouj = rand() % n;
    Matric[khrouj][m] = '*';
    Matric[khrouj][m - 1] = 'A' + m;
    recopiematrice(n, m);
    /*
        cout << "Bara mrigel" << endl;

        // Affichage de la matrice Matric
        cout << "Matrice principale : " << endl;
        afficheMatrice2(Matrice,n + 1, m + 1);
    */
    // Affichage de la matrice Matric1
}

void remplirMatrice2(int n, int m, int khrouj)
{
    srand(time(0)); // Initialisation de la graine aléatoire
    int range = 30; // 26 lettres + 4 pour le chiffre '1'

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            if (connb) // Vérifie si la case contient '2', '3', ..., '9'
            {
                int randomValue = rand() % range; // Génère une valeur entre 0 et 29

                // Génération des caractères aléatoires
                if (randomValue < 4)
                {
                    Matric[i][j] = '1'; // Cas pour '1'
                }
                else
                {
                    Matric[i][j] = 'A' + (randomValue - 5); // Cas pour 'A' à 'Z'
                }
            }
        }
    }
    // baed ma tekhdem t3bi matrice 3 bch djikstra yekhdem
    recopiematrice(n, m);
}

void afficheTab(char T[], int mac, int step)
{

    cout << "mot courant: ";
    for (int i = 0; i < mac; i++)
    {
        cout << T[i];
    }
    cout << endl;
    cout << "avec nb step= : " << step << endl;
}

void afficheTab1(char T[], int mac)
{

    cout << "mot courant: ";
    for (int i = 0; i < mac; i++)
    {
        cout << T[i];
    }
    cout << endl;
}

// afichage ll fin kif compare mot
void CompMot1(string verif, int &Score, int long1, int niveau, int Tab[], int step, vector<string> &motsSelectionnes)
{
    bool motTrouve = false;
    int totalChemin = 0;

    // Recherche du mot dans le vecteur
    for (int i = 0; i < motsSelectionnes.size(); i++)
    {
        if (motsSelectionnes[i] == verif)
        {
            motTrouve = true;

            // Supprimer le mot trouvé (Décalage des éléments)
            for (int j = i; j < motsSelectionnes.size() - 1; j++)
            {
                motsSelectionnes[j] = motsSelectionnes[j + 1];
            }
            motsSelectionnes.pop_back(); // Réduire la taille du vecteur
            break;
        }
    }

    if (motTrouve)
    {
        // Calcul du chemin total parcouru
        for (int i = 0; i < verif.length(); i++)
        {
            totalChemin += Tab[i];
        }

        // Calcul du score
        int bonusNiveau = 30 * niveau;
        int bonusLongueur = long1;
        int bonusChemin = (step <= totalChemin) ? (niveau * 20) : 0;

        Score += bonusNiveau + bonusLongueur + bonusChemin;
    }

    // ✅ Affichage des résultats finaux ✅
    cout << "\n\033[1;36m========================================\033[0m" << endl;
    cout << "\033[1;32m🎉 Fin du jeu ! Résultats 🎉\033[0m" << endl;
    cout << "\033[1;36m========================================\033[0m\n"
         << endl;

    cout << "\033[1;33m🏆 Score final : \033[1;34m" << Score << "\033[0m" << endl;
    cout << "\033[1;35m📊 Niveau atteint : \033[1;34m" << niveau << "\033[0m" << endl;
    cout << "\033[1;36m📝 Mot recherché : \033[1;32m" << verif << "\033[0m" << endl;
    cout << "\033[1;34m🔢 Chemin parcouru : \033[1;33m" << totalChemin << "\033[0m" << endl;
    cout << "\033[1;34m🚀 Chemin optimal : \033[1;33m" << step << "\033[0m" << endl;

    if (motTrouve)
    {
        if (step <= totalChemin)
        {
            cout << "\n\033[1;32m✅ Bravo ! Tu as trouvé le mot avec le chemin optimal !\033[0m" << endl;
        }
        else
        {
            cout << "\n\033[1;33m⚠️ Bien joué ! Mais tu aurais pu trouver un chemin plus court.\033[0m" << endl;
        }
    }
    else
    {
        cout << "\n\033[1;31m❌ Dommage... Le mot n'a pas été trouvé.\033[0m" << endl;
    }

    // 🔍 Afficher les mots restants 🔍
    cout << "\n\033[1;36mMots restants : \033[0m";
    if (motsSelectionnes.empty())
    {
        cout << "\033[1;32mAucun, tous les mots ont été trouvés ! 🎉\033[0m" << endl;
    }
    else
    {
        for (const auto &mot : motsSelectionnes)
        {
            cout << mot << " ";
        }
        cout << "\033[0m" << endl;
    }

    cout << "\n\033[1;36mMerci d'avoir joué ! À bientôt ! 🎮\033[0m" << endl;
    cout << "\033[1;36m========================================\033[0m\n"
         << endl;
}

void CompMot(string verif, int &Score, int long1, int niveau, int Tab[], int step, vector<string> &motsSelectionnes)
{
    bool motTrouve = false;
    int totalChemin = 0;

    // Recherche du mot avec une boucle simple
    for (int i = 0; i < motsSelectionnes.size(); i++)
    {
        // yrlawej al kelma fel vecteur
        if (motsSelectionnes[i] == verif)
        {
            motTrouve = true;

            // Supprimer le mot en décalant les éléments suivants
            for (int j = i; j < motsSelectionnes.size() - 1; j++)
            {
                motsSelectionnes[j] = motsSelectionnes[j + 1];
            }
            motsSelectionnes.pop_back(); // Réduire la taille du vecteur

            break; // Sortir de la boucle après avoir trouvé le mot
        }
    }
    // ken l9aha bch ye7seb el score
    if (motTrouve)
    {
        // Calcul du chemin total parcouru
        for (int i = 0; i < verif.length(); i++)
        { // bch yra a9ser chemain
            totalChemin += Tab[i];
        }

        // Calcul du score
        int bonusNiveau = 30 * niveau;
        int bonusLongueur = long1;
        // hedhi macro bch ysahel el khedma ken l9a el chemin el ahsen bch yatih el poinet snn el mara jeya
        int bonusChemin = (step <= totalChemin) ? (niveau * 20) : 0;
        // lena yehseb kol chay el formule taa el hesba ll score
        Score += bonusNiveau + bonusLongueur + bonusChemin;

        // Affichage du succès
        cout << "✅ Bravo ! Tu as trouvé le mot " << verif << " !" << endl;
        cout << "🔢 Chemin parcouru : " << totalChemin << endl;
        cout << "🚀 Chemin optimal : " << step << endl;

        if (step <= totalChemin)
        {
            cout << "🏆 Excellent ! Tu as trouvé le mot avec le chemin optimal !" << endl;
        }
        else
        {
            cout << "⚠️ Tu aurais pu trouver un chemin plus court." << endl;
        }
    }
    else
    {
        cout << "❌ Dommage... Le mot " << verif << " n'est pas dans le vecteur." << endl;
    }
}

// redhi el fonction bch yhel beha elficher w yjib el kelm ala kober el ligne w colone matalan user -- (5,7) doncf 7 mots longeur
// max taa kol wahda 4 bch najmou nkhaliw blayes ll hyout

void lireEtAfficherMots(const string &nomFichier, int nbligne, int m, int &khrouj, int niv1)
{

    char Mot[m];
    int index;
    char TAB[nbligne];
    string atwelklema;
    int i = 0;

    vector<string> mots; // Vecteur pour stocker tous les mots du fichier
    string mot;          // Variable pour stocker chaque mot

    ifstream fichier(nomFichier); // Ouvrir le fichier en lecture

    if (!fichier)
    {
        cerr << "Erreur : Impossible d'ouvrir le fichier !" << endl;
        return;
    }

    // Lire tous les mots du fichier et les stocker dans le vecteur
    while (fichier >> mot)
    {
        mots.push_back(mot);
    }

    fichier.close(); // Fermer le fichier
    // Vérifier si le fichier contient au moins 10 mots
    if (mots.size() < 10)
    {
        cerr << "Erreur : Le fichier contient moins de 10 mots !" << endl;
        return;
    }

    // Initialiser le générateur de nombres aléatoires
    srand(static_cast<unsigned int>(time(0)));

    // lena bch nrakhou el kelma
    while (i < nbligne)
    { // bch nwariwah el klem eli ffama fel vecteur donc matrice
        int index = rand() % mots.size();
        if (mots[index].length() <= m - 1)
        {
            motsSelectionnes[i] = mots[index];
            cout << "Mot sélectionné : " << motsSelectionnes[i] << endl;
            i++;
        }
    }

    atwelklema = motsSelectionnes[0]; // Initialiser avec le premier mot

    for (int i = 1; i < nbligne; i++)
    {
        if (motsSelectionnes[i].length() > atwelklema.length())
        {
            atwelklema = motsSelectionnes[i]; // Mettre à jour si un mot plus long est trouvé
        }
        //   std::this_thread::sleep_for(std::chrono::seconds(1)); // Pause d'une seconde
    }

    int k = atwelklema.length();
    // std::this_thread::sleep_for(std::chrono::seconds(4));

    cout << "le mot le plus long est :  " << atwelklema << "  avec un nombre de " << k << " characteres" << endl;
    if (niv1 == 1)
    {

        remplirMatriceN1(nbligne, m, motsSelectionnes, khrouj);
    }

    else if (niv1 == 2)
    {

        remplirMatriceN2(nbligne, m, motsSelectionnes, khrouj);
    }
    else
    {
        remplirMatriceN3(nbligne, m, motsSelectionnes, khrouj);
    }
}

// lena el djikstra bch namlou Node eli feha el daplacment al X Y w cost taa el deplacement el cost lena dima 1
struct Node
{
    int x, y, cost;
    bool operator>(const Node &other) const
    {
        return cost > other.cost;
    }
};

// les 8 direction li ana
const int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

// pour trouver l'ocurance de carcter dans le mot ken fama bch nkhadmou djikstra snn ntadew toul
vector<pair<int, int>> trouverOccurrences(char lettre, int n, int m)
{
    vector<pair<int, int>> positions;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (Matric3[i][j] == lettre)
            {
                positions.push_back({i, j});
            }
        }
    }
    return positions;
}

vector<pair<int, int>> dijkstra(int startX, int startY, int endX, int endY, int n, int m)
{
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    vector<vector<pair<int, int>>> prev(n, vector<pair<int, int>>(m, {-1, -1}));

    pq.push({startX, startY, 0});
    dist[startX][startY] = 0;

    while (!pq.empty())
    {
        Node current = pq.top();
        pq.pop();
        int x = current.x, y = current.y, cost = current.cost;

        if (x == endX && y == endY)
            break;

        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            // bch nekhdmou all matrice 3
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && Matric3[nx][ny] != '1')
            {
                int newCost = cost + 1;
                if (newCost < dist[nx][ny])
                {
                    dist[nx][ny] = newCost;
                    prev[nx][ny] = {x, y};
                    pq.push({nx, ny, newCost});
                }
            }
        }
    }

    vector<pair<int, int>> path;
    for (int x = endX, y = endY; x != -1 && y != -1; tie(x, y) = prev[x][y])
    {
        path.push_back({x, y});
    }
    reverse(path.begin(), path.end());
    return path;
}

void direction(int n, int m, int n1, int m1, int max, int mloul, char loul, int niv)
{ // lena fel fonc hedhi heya el kol feha el la3ba el kol ta9ribb
    T[0] = loul;
    char rec, mot, pt;
    int j = 0, i = 0, step = 0, mac = 16, Score = 0, k = 0, t = 1, lon = 0, o = m1, p = n1;
    bool test = 0, vizita = 0;
    vector<string> motsCorrespondants;
    j++;
    // lena bch ntakdou ken nahna awel mara dkhalna ll loop wala le ken awel mara c'est deja zeedna el Tab feha el harf el loul eli lezem yekhdhou bessif
    if (j == 1)
    {
        i = mloul;
    }
    else
    {
        i = 0;
    }
    step = 0;
    // lena bch no93dou nal3bou 7ataa lin yousel el nejma el condition el wahida ta el khrouj
    while (i < mac)
    {
        // kol ma nabdew fi awel el kelma maneha nhezou wel haref nlansiw Djikstra ama lenna djikstra bch yekhdem ala matrice okhra bch el haref li yekhdhou yma3adech yatjalou
        // w zid bch mayfasadech el matrice te3na w el matrice3 heya el matrice ta djikstra kol ma nbadlou fel matrice nmchiw nbadlou fel matrice3
        if (i == 1 && vizita == 0)
        {
            // bch netakdou li nodkhlou ken awel el haref w ken el kelma mwjouda fel vecteur
            vizita = 1;
            char c = Matric[n1][m1];
            p = n1;
            o = m1;

            cout << "Lettre sélectionnée : " << c << endl;

            // Réinitialiser les variables pour garantir un nouveau mot à chaque exécution
            motsCorrespondants.clear();
            kk = 0; // Réinitialiser l'index du mot sélectionné

            for (string mot : motsSelectionnes)
            {
                if (mot[0] == c)
                {
                    // lena el test yemchi maneha fama kelma tabda bel haref hedheka
                    test = 1;
                    motsCorrespondants.push_back(mot);
                }
            }

            if (motsCorrespondants.empty())
            {
                cout << "Aucun mot trouvé avec la lettre " << c << endl;
                for (int i = 0; i < m; i++)
                { // lena el cout infini
                    T1[i] = 3000;
                    cout << T1[i] << endl;
                }
            }
            else
            {

                // Vérification de kk avant d'accéder à un élément
                if (kk >= motsCorrespondants.size())
                {
                    cout << "Erreur : kk dépasse la taille de motsCorrespondants." << endl;
                }

                // Sélectionner un nouveau mot
                string motChoisi = motsCorrespondants[kk];
                cout << "Mot choisi : " << motChoisi << endl;

                vector<pair<int, int>> positions = {{p, o}};
                int i12 = 0;

                int maxIterations = 100; // Pour éviter boucle infinie
                t = 1;                   // Réinitialiser t pour un nouveau mot
                while (t < motChoisi.length() && maxIterations > 0)
                {
                    maxIterations--;

                    vector<pair<int, int>> positionsMot = trouverOccurrences(motChoisi[t], n, m);

                    if (positionsMot.empty())
                    {
                        cout << "Impossible de trouver un chemin vers " << motChoisi[t] << endl;
                        t++;
                        continue;
                    }

                    vector<pair<int, int>> chemin = dijkstra(p, o, positionsMot[0].first, positionsMot[0].second, n, m);

                    if (chemin.empty())
                    {
                        cout << "Aucun chemin trouvé vers la lettre " << motChoisi[t] << "." << endl;
                    }
                    else
                    {
                        cout << "Chemin trouvé :" << endl;
                        for (auto [x, y] : chemin)
                        { // lena bch nkaydou eli r9inehom w el path li lezem ymcheha
                            cout << "(" << x << ", " << y << ") ";
                            lon++;
                            p = x;
                            o = y;
                        }
                        lon--;
                        cout << endl;
                        Matric3[p][o] = '1';
                    }

                    T1[i12] = lon;
                    i12++;
                    lon = 0;
                    t++;
                }

                if (maxIterations == 0)
                {
                    cout << "Erreur : boucle infinie détectée !" << endl;
                    return;
                }

                cout << "Les longueurs des plus courts chemins sont :" << endl;
                for (int i = 0; i < i12; i++)
                { // lena nstokiw kol 7aref 9adech el path el 9sira lih
                    cout << T1[i] << endl;
                }

                // Réinitialiser `t` et mettre à jour la matrice
                t = 1;
                Matric[n1][m1] = static_cast<char>((0 + 2) + '0');
            }
            // hedhi nafichiw el matrice li khdem aleha djkstra w kifech walet
            afficheMatrice2(Matric3, n, m + 1);
        }

        if (k == 0)
        {
            cout << "Vous etes actuellement à la position : " << "(" << n1 << "," << m1 << ")" << endl;
            afficheTab1(T, mac);
            k++;
            Matric[n1][m1] = '2';
        }
        cout << "Choisissez une option (entre 1 et 8) : " << endl;
        menu();
        afficheMatrice2(Matric, n, m + 1);
        cin >> choix;

        // Validation de l'entrée (entre 1 et 8)
        while (choix < 1 || choix > 8)
        {
            cout << "Oups ! Veuillez entrer une valeur entre 1 et 8 : ";
            menu();
            afficheMatrice2(Matric, n, m);
            cin >> choix;
        }

        switch (choix)
        {
        case 1: // Haut
            if (n1 - 1 >= 0)
            {
                if (H)
                {
                    cout << "Vous avez choisi de monter (Haut).\nMais il y a un mur.\n";
                }
                else
                {
                    n1 -= 1;
                    step++;

                    do
                    {
                        cout << "Tu veux prendre la valeur (" << Matric[n1][m1] << ") ? Si oui, tape Y. Sinon, tape N : ";
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);
                    // lena verification ll mot ken theb tekhou el char ken le yzid el step ken ey mayzidech
                    if (rec == 'Y' || rec == 'y')
                    {
                        T[i] = Matric[n1][m1];
                        i++;
                        if (i != 1)
                        {
                            int step1 = step;
                            // ken hazit el char lena namlou hit ama el hit juste ll wakt taw khater ki tkonfermi bch nremplaciw el casset hedhom bahrouf alea
                            if (step > 9)
                            {
                                step1 = step % 10;
                            }
                            Matric[n1][m1] = static_cast<char>((step1 + 2) + '0');
                        }
                    }
                    cout << "Vous êtes maintenant dans la case :  (" << n1 << "," << m1 << ")" << endl;

                    do
                    {
                        // ken theb tkonfermi wala le
                        cout << "t7eb tkamel ??  ken ey Y snn N : " << endl;
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {
                        // ken EY nhesbou score w ncompariw w namlou kol chy w namlou inisalisation ll tableau li fih el chars
                        string kelma(T, i); // lena nekhdhou el klma

                        for (int k = 0; k < i; k++)
                        {
                            T[k] = ' ';
                        }

                        cout << "tu as le mot " << kelma << endl;

                        CompMot(kelma, Score, i, niv, T1, step, motsSelectionnes);

                        cout << "tu as un Score de  " << Score << endl;

                        /*std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes*/
                        vizita = 0;
                        i = 0;
                        remplirMatrice2(n, m, khrouj); // lena bch nabiw el klem eli hazineh w fared el wakt nabiwah fel matrice ta3 djiktra
                        step = 0;
                    }
                }
            }
            // ken el mouv ghalet bch ykolek impossible
            else
            {
                cout << "Mouvement impossible (hors de la matrice).\n";
            }
            break;

        case 2: // Bas
            if (n1 + 1 < n)
            {
                if (B)
                {
                    cout << "Vous avez choisi de descendre (Bas).\nMais il y a un mur.\n";
                }
                else
                {
                    n1 += 1;
                    step++;

                    do
                    {
                        cout << "Tu veux prendre la valeur (" << Matric[n1][m1] << ") ? Si oui, tape Y. Sinon, tape N : ";
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {
                        T[i] = Matric[n1][m1];
                        i++;
                        if (i != 1)
                        {
                            int step1 = step;
                            if (step > 9)
                            {
                                step1 = step % 10;
                            }
                            Matric[n1][m1] = static_cast<char>((step1 + 2) + '0');
                        }
                    }
                    cout << "Vous êtes maintenant dans la case :  (" << n1 << "," << m1 << ")" << endl;

                    do
                    {
                        cout << "t7eb tkamel ??  ken ey Y snn N : " << endl;
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {

                        string kelma(T, i); // lena nekhdhou el klma

                        for (int k = 0; k < i; k++)
                        {
                            T[k] = ' ';
                        }
                        cout << "tu as le mot " << kelma << endl;

                        CompMot(kelma, Score, i, niv, T1, step, motsSelectionnes);

                        cout << "tu as un Score de  " << Score << endl;

                        /*std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes*/
                        step = 0;
                        vizita = 0;
                        i = 0;
                        remplirMatrice2(n, m, khrouj);
                    }
                }
            }
            else
            {
                cout << "Mouvement impossible (hors de la matrice).\n";
            }
            break;

        case 3: // Gauche
            if (m1 - 1 >= 0)
            {
                if (G)
                {
                    cout << "Vous avez choisi de bouger à gauche.\nMais il y a un mur.\n";
                }
                else
                {
                    m1 -= 1;
                    step++;

                    do
                    {
                        cout << "Tu veux prendre la valeur (" << Matric[n1][m1] << ") ? Si oui, tape Y. Sinon, tape N : ";
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {
                        T[i] = Matric[n1][m1];
                        i++;
                        if (i != 1)
                        {
                            int step1 = step;
                            if (step > 9)
                            {
                                step1 = step % 10;
                            }
                            Matric[n1][m1] = static_cast<char>((step1 + 2) + '0');
                        }
                    }

                    cout << "Vous êtes maintenant dans la case :  (" << n1 << "," << m1 << ")" << endl;
                }
                do
                {
                    cout << "t7eb tkamel ??  ken ey Y snn N : " << endl;
                    cin >> rec;

                    if (conYO)
                    {
                        cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                    }
                } while (conYO);

                if (rec == 'Y' || rec == 'y')
                {

                    string kelma(T, i); // lena nekhdhou el klma

                    for (int k = 0; k < i; k++)
                    {
                        T[k] = ' ';
                    }

                    cout << "tu as le mot " << kelma << endl;

                    CompMot(kelma, Score, i, niv, T1, step, motsSelectionnes);

                    cout << "tu as un Score de  " << Score << endl;

                    /*std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes*/
                    step = 0;
                    vizita = 0;
                    i = 0;
                    remplirMatrice2(n, m, khrouj);
                }
            }

            else
            {
                cout << "Mouvement impossible (hors de la matrice).\n";
            }
            break;

        case 4: // Droite
            if (m1 + 1 < m || Matric[n1][m1 + 1] != '*')
            {
                if (D)
                {
                    cout << "Vous avez choisi de bouger à droite.\nMais il y a un mur.\n";
                }
                else
                {
                    m1 += 1;
                    step++;

                    do
                    {
                        cout << "Tu veux prendre la valeur (" << Matric[n1][m1] << ") ? Si oui, tape Y. Sinon, tape N : ";
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {
                        T[i] = Matric[n1][m1];
                        i++;
                        if (i != 1)
                        {
                            int step1 = step;
                            if (step > 9)
                            {
                                step1 = step % 10;
                            }
                            Matric[n1][m1] = static_cast<char>((step1 + 2) + '0');
                        }
                    }

                    cout << "Vous êtes maintenant dans la case :  (" << n1 << "," << m1 << ")" << endl;
                    do
                    {
                        cout << "t7eb tkamel ??  ken ey Y snn N : " << endl;
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {

                        string kelma(T, i); // lena nekhdhou el klma

                        for (int k = 0; k < i; k++)
                        {
                            T[k] = ' ';
                        }

                        cout << "tu as le mot " << kelma << endl;

                        CompMot(kelma, Score, i, niv, T1, step, motsSelectionnes);

                        cout << "tu as un Score de  " << Score << endl;

                        /*std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes*/
                        step = 0;
                        vizita = 0;
                        i = 0;
                        remplirMatrice2(n, m, khrouj);
                    }
                }
            }
            else if (Matric[n1][m1 + 1] == '*')
            {

                m1 += 1;
            }
            else
            {
                cout << "Mouvement impossible (hors de la matrice).\n";
            }
            break;

        case 5: // Diagonale Haut-Gauche
            if (n1 - 1 >= 0 && m1 - 1 >= 0)
            {
                if (HG)
                {
                    cout << "Vous avez choisi de monter en diagonale (Haut-Gauche).\nMais il y a un mur.\n";
                }
                else
                {
                    n1 -= 1;
                    m1 -= 1;
                    step++;

                    do
                    {
                        cout << "Tu veux prendre la valeur (" << Matric[n1][m1] << ") ? Si oui, tape Y. Sinon, tape N : ";
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {
                        T[i] = Matric[n1][m1];
                        i++;
                        if (i != 1)
                        {
                            int step1 = step;
                            if (step > 9)
                            {
                                step1 = step % 10;
                            }
                            Matric[n1][m1] = static_cast<char>((step1 + 2) + '0');
                        }
                    }

                    cout << "Vous êtes maintenant dans la case :  (" << n1 << "," << m1 << ")" << endl;
                }
                do
                {
                    cout << "t7eb tkamel ??  ken ey Y snn N : " << endl;
                    cin >> rec;

                    if (conYO)
                    {
                        cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                    }
                } while (conYO);

                if (rec == 'Y' || rec == 'y')
                {

                    string kelma(T, i); // lena nekhdhou el klma

                    for (int k = 0; k < i; k++)
                    {
                        T[k] = ' ';
                    }

                    cout << "tu as le mot " << kelma << endl;

                    CompMot(kelma, Score, i, niv, T1, step, motsSelectionnes);

                    cout << "tu as un Score de  " << Score << endl;

                    /*std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes*/
                    step = 0;
                    vizita = 0;
                    i = 0;
                    remplirMatrice2(n, m, khrouj);
                }
            }

            else
            {
                cout << "Mouvement impossible (hors de la matrice).\n";
            }
            break;

        case 6: // Diagonale Haut-Droite
            if (n1 - 1 >= 0 && m1 + 1 < m && Matric[n1 - 1][m1 + 1] != '*')
            {
                if (HD)
                {
                    cout << "Vous avez choisi de monter en diagonale (Haut-Droite).\nMais il y a un mur.\n";
                }
                else
                {
                    n1 -= 1;
                    m1 += 1;
                    step++;

                    do
                    {
                        cout << "Tu veux prendre la valeur (" << Matric[n1][m1] << ") ? Si oui, tape Y. Sinon, tape N : ";
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {
                        T[i] = Matric[n1][m1];
                        i++;
                        if (i != 1)
                        {
                            int step1 = step;
                            if (step > 9)
                            {
                                step1 = step % 10;
                            }
                            Matric[n1][m1] = static_cast<char>((step1 + 2) + '0');
                        }
                    }

                    cout << "Vous êtes maintenant dans la case :  (" << n1 << "," << m1 << ")" << endl;

                    do
                    {
                        cout << "t7eb tkamel ??  ken ey Y snn N : " << endl;
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {

                        string kelma(T, i); // lena nekhdhou el klma

                        for (int k = 0; k < i; k++)
                        {
                            T[k] = ' ';
                        }

                        cout << "tu as le mot " << kelma << endl;

                        CompMot(kelma, Score, i, niv, T1, step, motsSelectionnes);

                        cout << "tu as un Score de  " << Score << endl;

                        /*std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes*/
                        step = 0;
                        vizita = 0;
                        i = 0;
                        remplirMatrice2(n, m, khrouj);
                    }
                }
            }
            else if (Matric[n1 - 1][m1 + 1] == '*')
            {
                n1 -= 1;
                m1 += 1;
            }

            else
            {
                cout << "Mouvement impossible (hors de la matrice).\n";
            }
            break;

        case 7: // Diagonale Bas-Gauche
            if (n1 + 1 < n && m1 - 1 >= 0)
            {
                if (BG)
                {
                    cout << "Vous avez choisi de descendre en diagonale (Bas-Gauche).\nMais il y a un mur.\n";
                }
                else
                {
                    n1 += 1;
                    m1 -= 1;
                    step++;

                    do
                    {
                        cout << "Tu veux prendre la valeur (" << Matric[n1][m1] << ") ? Si oui, tape Y. Sinon, tape N : ";
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {
                        T[i] = Matric[n1][m1];
                        i++;
                        if (i != 1)
                        {
                            int step1 = step;
                            if (step > 9)
                            {
                                step1 = step % 10;
                            }
                            Matric[n1][m1] = static_cast<char>((step1 + 2) + '0');
                        }
                    }

                    cout << "Vous êtes maintenant dans la case :  (" << n1 << "," << m1 << ")" << endl;

                    do
                    {
                        cout << "t7eb tkamel ??  ken ey Y snn N : " << endl;
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {

                        string kelma(T, i); // lena nekhdhou el klma

                        for (int k = 0; k < i; k++)
                        {
                            T[k] = ' ';
                        }

                        cout << "tu as le mot " << kelma << endl;

                        CompMot(kelma, Score, i, niv, T1, step, motsSelectionnes);

                        cout << "tu as un Score de  " << Score << endl;

                        /*std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes*/
                        step = 0;
                        vizita = 0;
                        i = 0;
                        remplirMatrice2(n, m, khrouj);
                    }
                }
            }
            else
            {
                cout << "Mouvement impossible (hors de la matrice).\n";
            }
            break;

        case 8: // Diagonale Bas-Droite
            if (n1 + 1 < n && m1 + 1 < m && Matric[n1 + 1][m1 + 1] != '*')
            {
                if (BD)
                {
                    cout << "Vous avez choisi de descendre en diagonale (Bas-Droite).\nMais il y a un mur.\n";
                }
                else
                {
                    n1 += 1;
                    m1 += 1;
                    step++;

                    do
                    {
                        cout << "Tu veux prendre la valeur (" << Matric[n1][m1] << ") ? Si oui, tape Y. Sinon, tape N : ";
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {
                        T[i] = Matric[n1][m1];
                        i++;
                        if (i != 1)
                        {
                            int step1 = step;
                            if (step > 9)
                            {
                                step1 = step % 10;
                            }
                            Matric[n1][m1] = static_cast<char>((step1 + 2) + '0');
                        }
                    }

                    cout << "Vous êtes maintenant dans la case :  (" << n1 << "," << m1 << ")" << endl;

                    do
                    {
                        cout << "t7eb tkamel ??  ken ey Y snn N : " << endl;
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {

                        string kelma(T, i); // lena nekhdhou el klma

                        for (int k = 0; k < i; k++)
                        {
                            T[k] = ' ';
                        }
                        cout << "tu as le mot " << kelma << endl;

                        CompMot(kelma, Score, i, niv, T1, step, motsSelectionnes);

                        cout << "tu as un Score de  " << Score << endl;

                        /*std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes*/
                        step = 0;
                        vizita = 0;
                        i = 0;
                        remplirMatrice2(n, m, khrouj);
                    }
                }
            }
            else if (Matric[n1 + 1][m1 + 1] == '*')
            {
                n1 += 1;
                m1 += 1;
            }
            else
            {
                cout << "Mouvement impossible (hors de la matrice).\n";
            }
            break;

        default:
            cout << "Aucun mouvement valide sélectionné.\n";
            break;
        }
        // 9bal ma t3awed etloopi lena nchoufou ken wselna ll nejma ken ey bch nmchiw nehsbou el score w baed kel w namlou kel ada ama lena rahou rbeh
        // nehsboulou el socre el lekher w nojhrjou
        if (Matric[n1][m1] == '*')
        {

            string kelma(T, i); // lena nekhdhou el klma

            cout << "Victoire!" << endl;

            CompMot1(kelma, Score, i, niv, T1, step, motsSelectionnes);

            cout << "Score Final: " << Score << endl;
            // lena i ++++++++++++++++ donc nbrekiw kol cgay wnokhrjou
            i = 222;
            /*std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes*/

            // lezzem lena bch najmou nokhrjou mel while w najmou narfou kober el kelma
        }
    }
    // lena lezem n3abiw aka les 2 avec des lettres
}

=======

#ifndef finc
#define finc
#include <windows.h>
#include <locale>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <cctype> // Pour isalpha()
#include <thread> // Pour std::this_thread::sleep_for
#include <chrono> // Pour std::chrono::seconds
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <ctime>
#include <cmath> 
using namespace std;
vector<string> motsSelectionnes(100); // vecteur ll mot Selectionnes mel ficher.txt
int x = 0,
    khrouj = 0, // bch narfou position taa el nejma ll khrouj
    kk = 0;
int T1[100]; // tableau li nalkaw fih el a9se path binet el hrouf
#define connb (Matric[i][j] == '2' || Matric[i][j] == '3' || Matric[i][j] == '4' || Matric[i][j] == '5' || Matric[i][j] == '6' || Matric[i][j] == '7' || Matric[i][j] == '8' || Matric[i][j] == '9')
#define conYO (rec != 'Y' && rec != 'y' && rec != 'N' && rec != 'n')
#define BLOQ(valeurVoisin) (valeurVoisin < '1' || valeurVoisin > '9')
// les conditioon ta3 el hyout fel les mouvement
#define H (Matric[n1 - 1][m1] == '1' || Matric[n1 - 1][m1] == '2' || Matric[n1 - 1][m1] == '3' || \
           Matric[n1 - 1][m1] == '4' || Matric[n1 - 1][m1] == '5' || Matric[n1 - 1][m1] == '6' || \
           Matric[n1 - 1][m1] == '7' || Matric[n1 - 1][m1] == '8' || Matric[n1 - 1][m1] == '9')

#define B (Matric[n1 + 1][m1] == '1' || Matric[n1 + 1][m1] == '2' || Matric[n1 + 1][m1] == '3' || \
           Matric[n1 + 1][m1] == '4' || Matric[n1 + 1][m1] == '5' || Matric[n1 + 1][m1] == '6' || \
           Matric[n1 + 1][m1] == '7' || Matric[n1 + 1][m1] == '8' || Matric[n1 + 1][m1] == '9')

#define G (Matric[n1][m1 - 1] == '1' || Matric[n1][m1 - 1] == '2' || Matric[n1][m1 - 1] == '3' || \
           Matric[n1][m1 - 1] == '4' || Matric[n1][m1 - 1] == '5' || Matric[n1][m1 - 1] == '6' || \
           Matric[n1][m1 - 1] == '7' || Matric[n1][m1 - 1] == '8' || Matric[n1][m1 - 1] == '9')

#define D (Matric[n1][m1 + 1] == '1' || Matric[n1][m1 + 1] == '2' || Matric[n1][m1 + 1] == '3' || \
           Matric[n1][m1 + 1] == '4' || Matric[n1][m1 + 1] == '5' || Matric[n1][m1 + 1] == '6' || \
           Matric[n1][m1 + 1] == '7' || Matric[n1][m1 + 1] == '8' || Matric[n1][m1 + 1] == '9')

#define HG (Matric[n1 - 1][m1 - 1] == '1' || Matric[n1 - 1][m1 - 1] == '2' || Matric[n1 - 1][m1 - 1] == '3' || \
            Matric[n1 - 1][m1 - 1] == '4' || Matric[n1 - 1][m1 - 1] == '5' || Matric[n1 - 1][m1 - 1] == '6' || \
            Matric[n1 - 1][m1 - 1] == '7' || Matric[n1 - 1][m1 - 1] == '8' || Matric[n1 - 1][m1 - 1] == '9')

#define HD (Matric[n1 - 1][m1 + 1] == '1' || Matric[n1 - 1][m1 + 1] == '2' || Matric[n1 - 1][m1 + 1] == '3' || \
            Matric[n1 - 1][m1 + 1] == '4' || Matric[n1 - 1][m1 + 1] == '5' || Matric[n1 - 1][m1 + 1] == '6' || \
            Matric[n1 - 1][m1 + 1] == '7' || Matric[n1 - 1][m1 + 1] == '8' || Matric[n1 - 1][m1 + 1] == '9')

#define BG (Matric[n1 + 1][m1 - 1] == '1' || Matric[n1 + 1][m1 - 1] == '2' || Matric[n1 + 1][m1 - 1] == '3' || \
            Matric[n1 + 1][m1 - 1] == '4' || Matric[n1 + 1][m1 - 1] == '5' || Matric[n1 + 1][m1 - 1] == '6' || \
            Matric[n1 + 1][m1 - 1] == '7' || Matric[n1 + 1][m1 - 1] == '8' || Matric[n1 + 1][m1 - 1] == '9')

#define BD (Matric[n1 + 1][m1 + 1] == '1' || Matric[n1 + 1][m1 + 1] == '2' || Matric[n1 + 1][m1 + 1] == '3' || \
            Matric[n1 + 1][m1 + 1] == '4' || Matric[n1 + 1][m1 + 1] == '5' || Matric[n1 + 1][m1 + 1] == '6' || \
            Matric[n1 + 1][m1 + 1] == '7' || Matric[n1 + 1][m1 + 1] == '8' || Matric[n1 + 1][m1 + 1] == '9')
// Déclaration de la matrice globale
char Matric[100][100];  // matrice principale
char Matric1[100][100]; // matrice de contole pour la generation de grille
char Matric3[100][100]; // lena el matrice eli bch yal3eb aleha djikstra
char T[20];
int m, n, choix, n1, m1;

// ll matrice eli bch yal3eb aleha djikstra
void recopiematrice(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            Matric3[i][j] = Matric[i][j];
        }
    }
}

void countdown(int seconds)
{
    for (int i = seconds; i > 0; i--)
    {
        cout << "Début du jeu dans " << i << "..." << endl;
#ifdef _WIN32
        Sleep(1000); // Pause de 1 seconde (Windows)
#endif
    }
    cout << "C'est parti ! Bonne chance !" << endl;
}

// bch taref el matrice eloula 9adech feha men 1 w zeda ll les fonction li generiw el grille
int combienDeUn(int n, int m)
{
    int count = 0; // Compteur initialisé à 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (Matric[i][j] == '1')
            {
                count++; // Incrémenter le compteur si le caractère est '1'
            }
        }
    }
    return count;
}

// Fonction pour afficher la matrice
void afficheMatrice(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << " " << Matric[i][j] << " "; // Affichage du caractère
        }
        cout << endl; // Retour à la ligne après chaque ligne de la matrice
    }
}
// hedha el menu taa el laba bch yaref el user chnwa yakhtar
void menu()
{

    cout << "\n--- Menu de déplacement ---\n";
    cout << "1. Haut\n";
    cout << "2. Bas\n";
    cout << "3. Gauche\n";
    cout << "4. Droite\n";
    cout << "5. Diagonale Haut-Gauche\n";
    cout << "6. Diagonale Haut-Droite\n";
    cout << "7. Diagonale Bas-Gauche\n";
    cout << "8. Diagonale Bas-Droite\n";
    cout << endl;
}
// hedhi bch tabi matrice d'une facon aleatoire
void remplirMatrice(int n, int m)
{

    srand(time(0)); // Initialisation de la graine aléatoire
    int range = 30; // 26 lettres + 4 pour le chiffre '1'

    for (int i = 0; i < n; i++)
    {
        bool hasOne = false; // Vérifie si la ligne contient au moins un '1'

        for (int j = 0; j < m; j++)
        {
            int randomValue = rand() % range; // Génère une valeur entre 0 et 29

            // Génération des caractères aléatoires
            if (randomValue < 4)
            {
                Matric[i][j] = '1'; // Cas pour '1'
                hasOne = true;      // Marque qu'il y a un '1' dans cette ligne
            }
            else
            {
                Matric[i][j] = 'A' + (randomValue - 4); // Cas pour 'A' à 'Z'
            }
        }

        // Si la ligne n'a pas de '1', force l'ajout d'un '1'
        if (!hasOne)
        {
            int randomColumn = rand() % m; // Choisir une colonne aléatoire
            Matric[i][randomColumn] = '1';
        }
    }
}

// lena el matrice andha nejma ama fama hyout nafss el ligne ta3 el nejma donc invisible ll user lena el affichage ysir bel behi
// ekher colone nraw ken el nejma ama howa fama nejma w hyout
void afficheMatrice2(char Matri[][100], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j == m - 1 && Matri[i][j] == '1')
            {
                cout << " ";
            }

            else
            {
                cout << " " << Matri[i][j] << " "; // Affichage du caractère
            }
        }

        // Vérification si le dernier élément de la ligne est '1'

        cout << endl; // Retour à la ligne après chaque ligne de la matrice
    }
}

void remplirMatriceN1(int n, int m, vector<string> motsSelectionnes, int &khrouj)
{
    int randomValue;
    srand(time(0)); // Initialisation de la graine aléatoire
    int range = 30; // 26 lettres (A-Z) + 4 pour le chiffre '1'

    for (int i = 0; i < n; i++)
    {
        string motCourant = motsSelectionnes[i];
        for (int j = 0; j < motCourant.length(); j++)
        {
            Matric[i][j] = motCourant[j];
            // cout << Matric[i][j] << " ";
        }
        //  cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        bool hasOne = false; // Vérifie si la ligne contient au moins un '1'

        for (int j = 0; j < m; j++)
        {
            if (!isalpha(Matric[i][j])) // Remplir uniquement les cases vides
            {
                randomValue = rand() % range; // Génère une valeur entre 0 et 29

                // Génération des caractères aléatoires
                if (randomValue < 4)
                {
                    Matric[i][j] = '1'; // Cas pour '1'
                    hasOne = true;      // Marque qu'il y a un '1' dans cette ligne
                }
                else
                {
                    Matric[i][j] = 'A' + (randomValue - 4); // Cas pour 'A' à 'Z'
                }
            }
        }

        // Si la ligne n'a pas de '1', on force l'ajout d'un '1' quelque part
        if (!hasOne)
        {
            int randomColumn = motsSelectionnes[i].length() + (rand() % (m - motsSelectionnes[i].length()));
            Matric[i][randomColumn] = '1';
        }
    }

    for (int i = 0; i < n; i++)
    {
        Matric[i][m] = '1';
    }
    // Ajouter un `*` à une ligne aléatoire à la dernière colonne
    khrouj = rand() % n;
    Matric[khrouj][m] = '*'; // `m` étant la dernière colonne après les données
    Matric[khrouj][m - 1] = 'A' + m;
    recopiematrice(n, m);
}

void remplirMatriceN3(int n, int m, vector<string> motsSelectionnes, int &khrouj)
{
    srand(time(0)); // Initialisation de la graine aléatoire
    int range = 30; // 26 lettres (A-Z) + 4 pour le chiffre '1'
    char Matric1[100][100];

    // Initialisation des matrices

    for (int i = 0; i < n; i++)
    {
        bool hasOne = false; // Vérifie si la ligne contient au moins un '1'

        for (int j = 0; j < m; j++)
        {
            int randomValue = rand() % range; // Génère une valeur entre 0 et 29
            Matric1[i][j] = 'r';
            // Génération des caractères aléatoires
            if (randomValue < 4)
            {
                Matric[i][j] = '1'; // Cas pour '1'
                hasOne = true;      // Marque qu'il y a un '1' dans cette ligne
            }
            else
            {
                Matric[i][j] = 'A' + (randomValue - 4); // Cas pour 'A' à 'Z'
            }
        }

        // Si la ligne n'a pas de '1', force l'ajout d'un '1'
        if (!hasOne)
        {
            int randomColumn = rand() % m; // Choisir une colonne aléatoire
            Matric[i][randomColumn] = '1';
        }
    }

    // Placement des mots
    for (int rep = 0; rep < motsSelectionnes.size(); rep++)
    {
        string mot = motsSelectionnes[rep];
        int k = mot.length();
        int c = 0;
        while (c < k)
        {
            int row = rand() % n;
            int col = rand() % m;

            // Vérifier si la case est disponible
            while (Matric1[row][col] == '1')
            {
                row = rand() % n;
                col = rand() % m;
            }

            Matric[row][col] = mot[c]; // Placement du caractère
            Matric1[row][col] = '1';   // Marquer la case comme occupée
            c++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        Matric[i][m] = '1';
    }
    // Ajouter un `*` à une ligne aléatoire à la dernière colonne
    khrouj = rand() % n;
    Matric[khrouj][m] = '*'; // `m` étant la dernière colonne après les données
    Matric[khrouj][m - 1] = 'A' + m;
    recopiematrice(n, m);
    /*
    // Affichage de la matrice Matric
    cout << "Matrice principale : " << endl;
    afficheMatrice2(n + 1, m + 1);

    // Affichage de la matrice Matric1
    cout << "Matrice des indices (1 = mot placé, 0 = vide) : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << " " << Matric1[i][j] << " ";
        }
        cout << endl;
    }*/
}

void remplirMatriceN2(int n, int m, vector<string> motsSelectionnes, int &khrouj)
{
    srand(time(0)); // Initialisation de la graine aléatoire
    int range = 30; // 26 lettres (A-Z) + 4 pour '1'

    // Initialisation de la matrice avec des caractères aléatoires
    for (int i = 0; i < n; i++)
    {
        bool hasOne = false; // Vérifie si la ligne contient au moins un '1'

        for (int j = 0; j < m; j++)
        {
            int randomValue = rand() % range;
            if (randomValue < 4)
            {
                Matric[i][j] = '1'; // Placement de quelques '1'
                hasOne = true;
            }
            else
            {
                Matric[i][j] = 'A' + (randomValue - 4); // Lettre aléatoire
            }
        }

        // Si la ligne n'a pas de '1', en ajouter un
        if (!hasOne)
        {
            int randomColumn = rand() % m;
            Matric[i][randomColumn] = '1';
        }
    }

    // **Placement des mots avec inversion**
    int totalMots = motsSelectionnes.size();
    for (int i = 0; i < totalMots; i++)
    {
        string motCourant = motsSelectionnes[i];
        int longueurMot = motCourant.length();
        int milieu = longueurMot / 2;

        // Ligne normale
        int rowNormale = i % n;
        // Ligne inversée
        int rowInverse = (n - 1 - i) % n;

        // **Placer la première moitié**
        for (int j = 0; j < milieu; j++)
        {
            Matric[rowNormale][j] = motCourant[j];
        }

        // **Placer la deuxième moitié dans la ligne inverse**
        for (int j = milieu; j < longueurMot; j++)
        {
            Matric[rowInverse][m - longueurMot + j] = motCourant[j]; // Mettre à la fin de la ligne inverse
        }
    }

    // Ajouter un `*` à une ligne aléatoire à la dernière colonne
    khrouj = rand() % n;
    Matric[khrouj][m] = '*';
    Matric[khrouj][m - 1] = 'A' + m;
    recopiematrice(n, m);
    /*
        cout << "Bara mrigel" << endl;

        // Affichage de la matrice Matric
        cout << "Matrice principale : " << endl;
        afficheMatrice2(Matrice,n + 1, m + 1);
    */
    // Affichage de la matrice Matric1
}

void remplirMatrice2(int n, int m, int khrouj)
{
    srand(time(0)); // Initialisation de la graine aléatoire
    int range = 30; // 26 lettres + 4 pour le chiffre '1'

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            if (connb) // Vérifie si la case contient '2', '3', ..., '9'
            {
                int randomValue = rand() % range; // Génère une valeur entre 0 et 29

                // Génération des caractères aléatoires
                if (randomValue < 4)
                {
                    Matric[i][j] = '1'; // Cas pour '1'
                }
                else
                {
                    Matric[i][j] = 'A' + (randomValue - 5); // Cas pour 'A' à 'Z'
                }
            }
        }
    }
    // baed ma tekhdem t3bi matrice 3 bch djikstra yekhdem
    recopiematrice(n, m);
}

void afficheTab(char T[], int mac, int step)
{

    cout << "mot courant: ";
    for (int i = 0; i < mac; i++)
    {
        cout << T[i];
    }
    cout << endl;
    cout << "avec nb step= : " << step << endl;
}

void afficheTab1(char T[], int mac)
{

    cout << "mot courant: ";
    for (int i = 0; i < mac; i++)
    {
        cout << T[i];
    }
    cout << endl;
}

// afichage ll fin kif compare mot
void CompMot1(string verif, int &Score, int long1, int niveau, int Tab[], int step, vector<string> &motsSelectionnes)
{
    bool motTrouve = false;
    int totalChemin = 0;

    // Recherche du mot dans le vecteur
    for (int i = 0; i < motsSelectionnes.size(); i++)
    {
        if (motsSelectionnes[i] == verif)
        {
            motTrouve = true;

            // Supprimer le mot trouvé (Décalage des éléments)
            for (int j = i; j < motsSelectionnes.size() - 1; j++)
            {
                motsSelectionnes[j] = motsSelectionnes[j + 1];
            }
            motsSelectionnes.pop_back(); // Réduire la taille du vecteur
            break;
        }
    }

    if (motTrouve)
    {
        // Calcul du chemin total parcouru
        for (int i = 0; i < verif.length(); i++)
        {
            totalChemin += Tab[i];
        }

        // Calcul du score
        int bonusNiveau = 30 * niveau;
        int bonusLongueur = long1;
        int bonusChemin = (step <= totalChemin) ? (niveau * 20) : 0;

        Score += bonusNiveau + bonusLongueur + bonusChemin;
    }

    // ✅ Affichage des résultats finaux ✅
    cout << "\n\033[1;36m========================================\033[0m" << endl;
    cout << "\033[1;32m🎉 Fin du jeu ! Résultats 🎉\033[0m" << endl;
    cout << "\033[1;36m========================================\033[0m\n"
         << endl;

    cout << "\033[1;33m🏆 Score final : \033[1;34m" << Score << "\033[0m" << endl;
    cout << "\033[1;35m📊 Niveau atteint : \033[1;34m" << niveau << "\033[0m" << endl;
    cout << "\033[1;36m📝 Mot recherché : \033[1;32m" << verif << "\033[0m" << endl;
    cout << "\033[1;34m🔢 Chemin parcouru : \033[1;33m" << totalChemin << "\033[0m" << endl;
    cout << "\033[1;34m🚀 Chemin optimal : \033[1;33m" << step << "\033[0m" << endl;

    if (motTrouve)
    {
        if (step <= totalChemin)
        {
            cout << "\n\033[1;32m✅ Bravo ! Tu as trouvé le mot avec le chemin optimal !\033[0m" << endl;
        }
        else
        {
            cout << "\n\033[1;33m⚠️ Bien joué ! Mais tu aurais pu trouver un chemin plus court.\033[0m" << endl;
        }
    }
    else
    {
        cout << "\n\033[1;31m❌ Dommage... Le mot n'a pas été trouvé.\033[0m" << endl;
    }

    // 🔍 Afficher les mots restants 🔍
    cout << "\n\033[1;36mMots restants : \033[0m";
    if (motsSelectionnes.empty())
    {
        cout << "\033[1;32mAucun, tous les mots ont été trouvés ! 🎉\033[0m" << endl;
    }
    else
    {
        for (const auto &mot : motsSelectionnes)
        {
            cout << mot << " ";
        }
        cout << "\033[0m" << endl;
    }

    cout << "\n\033[1;36mMerci d'avoir joué ! À bientôt ! 🎮\033[0m" << endl;
    cout << "\033[1;36m========================================\033[0m\n"
         << endl;
}

void CompMot(string verif, int &Score, int long1, int niveau, int Tab[], int step, vector<string> &motsSelectionnes)
{
    bool motTrouve = false;
    int totalChemin = 0;

    // Recherche du mot avec une boucle simple
    for (int i = 0; i < motsSelectionnes.size(); i++)
    {
        // yrlawej al kelma fel vecteur
        if (motsSelectionnes[i] == verif)
        {
            motTrouve = true;

            // Supprimer le mot en décalant les éléments suivants
            for (int j = i; j < motsSelectionnes.size() - 1; j++)
            {
                motsSelectionnes[j] = motsSelectionnes[j + 1];
            }
            motsSelectionnes.pop_back(); // Réduire la taille du vecteur

            break; // Sortir de la boucle après avoir trouvé le mot
        }
    }
    // ken l9aha bch ye7seb el score
    if (motTrouve)
    {
        // Calcul du chemin total parcouru
        for (int i = 0; i < verif.length(); i++)
        { // bch yra a9ser chemain
            totalChemin += Tab[i];
        }

        // Calcul du score
        int bonusNiveau = 30 * niveau;
        int bonusLongueur = long1;
        // hedhi macro bch ysahel el khedma ken l9a el chemin el ahsen bch yatih el poinet snn el mara jeya
        int bonusChemin = (step <= totalChemin) ? (niveau * 20) : 0;
        // lena yehseb kol chay el formule taa el hesba ll score
        Score += bonusNiveau + bonusLongueur + bonusChemin;

        // Affichage du succès
        cout << "✅ Bravo ! Tu as trouvé le mot " << verif << " !" << endl;
        cout << "🔢 Chemin parcouru : " << totalChemin << endl;
        cout << "🚀 Chemin optimal : " << step << endl;

        if (step <= totalChemin)
        {
            cout << "🏆 Excellent ! Tu as trouvé le mot avec le chemin optimal !" << endl;
        }
        else
        {
            cout << "⚠️ Tu aurais pu trouver un chemin plus court." << endl;
        }
    }
    else
    {
        cout << "❌ Dommage... Le mot " << verif << " n'est pas dans le vecteur." << endl;
    }
}

// redhi el fonction bch yhel beha elficher w yjib el kelm ala kober el ligne w colone matalan user -- (5,7) doncf 7 mots longeur
// max taa kol wahda 4 bch najmou nkhaliw blayes ll hyout

void lireEtAfficherMots(const string &nomFichier, int nbligne, int m, int &khrouj, int niv1)
{

    char Mot[m];
    int index;
    char TAB[nbligne];
    string atwelklema;
    int i = 0;

    vector<string> mots; // Vecteur pour stocker tous les mots du fichier
    string mot;          // Variable pour stocker chaque mot

    ifstream fichier(nomFichier); // Ouvrir le fichier en lecture

    if (!fichier)
    {
        cerr << "Erreur : Impossible d'ouvrir le fichier !" << endl;
        return;
    }

    // Lire tous les mots du fichier et les stocker dans le vecteur
    while (fichier >> mot)
    {
        mots.push_back(mot);
    }

    fichier.close(); // Fermer le fichier
    // Vérifier si le fichier contient au moins 10 mots
    if (mots.size() < 10)
    {
        cerr << "Erreur : Le fichier contient moins de 10 mots !" << endl;
        return;
    }

    // Initialiser le générateur de nombres aléatoires
    srand(static_cast<unsigned int>(time(0)));

    // lena bch nrakhou el kelma
    while (i < nbligne)
    { // bch nwariwah el klem eli ffama fel vecteur donc matrice
        int index = rand() % mots.size();
        if (mots[index].length() <= m - 1)
        {
            motsSelectionnes[i] = mots[index];
            cout << "Mot sélectionné : " << motsSelectionnes[i] << endl;
            i++;
        }
    }

    atwelklema = motsSelectionnes[0]; // Initialiser avec le premier mot

    for (int i = 1; i < nbligne; i++)
    {
        if (motsSelectionnes[i].length() > atwelklema.length())
        {
            atwelklema = motsSelectionnes[i]; // Mettre à jour si un mot plus long est trouvé
        }
        //   std::this_thread::sleep_for(std::chrono::seconds(1)); // Pause d'une seconde
    }

    int k = atwelklema.length();
    // std::this_thread::sleep_for(std::chrono::seconds(4));

    cout << "le mot le plus long est :  " << atwelklema << "  avec un nombre de " << k << " characteres" << endl;
    if (niv1 == 1)
    {

        remplirMatriceN1(nbligne, m, motsSelectionnes, khrouj);
    }

    else if (niv1 == 2)
    {

        remplirMatriceN2(nbligne, m, motsSelectionnes, khrouj);
    }
    else
    {
        remplirMatriceN3(nbligne, m, motsSelectionnes, khrouj);
    }
}

// lena el djikstra bch namlou Node eli feha el daplacment al X Y w cost taa el deplacement el cost lena dima 1
struct Node
{
    int x, y, cost;
    bool operator>(const Node &other) const
    {
        return cost > other.cost;
    }
};

// les 8 direction li ana
const int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

// pour trouver l'ocurance de carcter dans le mot ken fama bch nkhadmou djikstra snn ntadew toul
vector<pair<int, int>> trouverOccurrences(char lettre, int n, int m)
{
    vector<pair<int, int>> positions;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (Matric3[i][j] == lettre)
            {
                positions.push_back({i, j});
            }
        }
    }
    return positions;
}

vector<pair<int, int>> dijkstra(int startX, int startY, int endX, int endY, int n, int m)
{
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    vector<vector<pair<int, int>>> prev(n, vector<pair<int, int>>(m, {-1, -1}));

    pq.push({startX, startY, 0});
    dist[startX][startY] = 0;

    while (!pq.empty())
    {
        Node current = pq.top();
        pq.pop();
        int x = current.x, y = current.y, cost = current.cost;

        if (x == endX && y == endY)
            break;

        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            // bch nekhdmou all matrice 3
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && Matric3[nx][ny] != '1')
            {
                int newCost = cost + 1;
                if (newCost < dist[nx][ny])
                {
                    dist[nx][ny] = newCost;
                    prev[nx][ny] = {x, y};
                    pq.push({nx, ny, newCost});
                }
            }
        }
    }

    vector<pair<int, int>> path;
    for (int x = endX, y = endY; x != -1 && y != -1; tie(x, y) = prev[x][y])
    {
        path.push_back({x, y});
    }
    reverse(path.begin(), path.end());
    return path;
}

void direction(int n, int m, int n1, int m1, int max, int mloul, char loul, int niv)
{ // lena fel fonc hedhi heya el kol feha el la3ba el kol ta9ribb
    T[0] = loul;
    char rec, mot, pt;
    int j = 0, i = 0, step = 0, mac = 16, Score = 0, k = 0, t = 1, lon = 0, o = m1, p = n1;
    bool test = 0, vizita = 0; int lost=0;
    vector<string> motsCorrespondants;
    j++;
    // lena bch ntakdou ken nahna awel mara dkhalna ll loop wala le ken awel mara c'est deja zeedna el Tab feha el harf el loul eli lezem yekhdhou bessif
    if (j == 1)
    {
        i = mloul;
    }
    else
    {
        i = 0;
    }
    step = 0;
    // lena bch no93dou nal3bou 7ataa lin yousel el nejma el condition el wahida ta el khrouj
    while (i < mac)
    {
        // kol ma nabdew fi awel el kelma maneha nhezou wel haref nlansiw Djikstra ama lenna djikstra bch yekhdem ala matrice okhra bch el haref li yekhdhou yma3adech yatjalou
        // w zid bch mayfasadech el matrice te3na w el matrice3 heya el matrice ta djikstra kol ma nbadlou fel matrice nmchiw nbadlou fel matrice3
        if (i == 1 && vizita == 0)
        {
            // bch netakdou li nodkhlou ken awel el haref w ken el kelma mwjouda fel vecteur
            vizita = 1;
            char c = Matric[n1][m1];
            p = n1;
            o = m1;

            cout << "Lettre sélectionnée : " << c << endl;

            // Réinitialiser les variables pour garantir un nouveau mot à chaque exécution
            motsCorrespondants.clear();
            kk = 0; // Réinitialiser l'index du mot sélectionné

            for (string mot : motsSelectionnes)
            {
                if (mot[0] == c)
                {
                    // lena el test yemchi maneha fama kelma tabda bel haref hedheka
                    test = 1;
                    motsCorrespondants.push_back(mot);
                }
            }

            if (motsCorrespondants.empty())
            {
                cout << "Aucun mot trouvé avec la lettre " << c << endl;
                for (int i = 0; i < m; i++)
                { // lena el cout infini
                    T1[i] = 3000;
                    cout << T1[i] << endl;
                }
            }
            else
            {

                // Vérification de kk avant d'accéder à un élément
                if (kk >= motsCorrespondants.size())
                {
                    cout << "Erreur : kk dépasse la taille de motsCorrespondants." << endl;
                }

                // Sélectionner un nouveau mot
                string motChoisi = motsCorrespondants[kk];
                cout << "Mot choisi : " << motChoisi << endl;

                vector<pair<int, int>> positions = {{p, o}};
                int i12 = 0;

                int maxIterations = 100; // Pour éviter boucle infinie
                t = 1;                   // Réinitialiser t pour un nouveau mot
                while (t < motChoisi.length() && maxIterations > 0)
                {
                    maxIterations--;

                    vector<pair<int, int>> positionsMot = trouverOccurrences(motChoisi[t], n, m);

                    if (positionsMot.empty())
                    {
                        cout << "Impossible de trouver un chemin vers " << motChoisi[t] << endl;
                        t++;
                        continue;
                    }

                    vector<pair<int, int>> chemin = dijkstra(p, o, positionsMot[0].first, positionsMot[0].second, n, m);

                    if (chemin.empty())
                    {
                        cout << "Aucun chemin trouvé vers la lettre " << motChoisi[t] << "." << endl;
                    }
                    else
                    {
                        cout << "Chemin trouvé :" << endl;
                        for (auto [x, y] : chemin)
                        { // lena bch nkaydou eli r9inehom w el path li lezem ymcheha
                            cout << "(" << x << ", " << y << ") ";
                            lon++;
                            p = x;
                            o = y;
                        }
                        lon--;
                        cout << endl;
                        Matric3[p][o] = '1';
                    }

                    T1[i12] = lon;
                    i12++;
                    lon = 0;
                    t++;
                }

                if (maxIterations == 0)
                {
                    cout << "Erreur : boucle infinie détectée !" << endl;
                    return;
                }

                cout << "Les longueurs des plus courts chemins sont :" << endl;
                for (int i = 0; i < i12; i++)
                { // lena nstokiw kol 7aref 9adech el path el 9sira lih
                    cout << T1[i] << endl;
                }

                // Réinitialiser `t` et mettre à jour la matrice
                t = 1;
                Matric[n1][m1] = static_cast<char>((0 + 2) + '0');
            }
            // hedhi nafichiw el matrice li khdem aleha djkstra w kifech walet
            afficheMatrice2(Matric3, n, m + 1);
        }

        if (k == 0)
        {
            cout << "Vous etes actuellement à la position : " << "(" << n1 << "," << m1 << ")" << endl;
            afficheTab1(T, mac);
            k++;
            Matric[n1][m1] = '2';
        }
        cout << "Choisissez une option (entre 1 et 8) : " << endl;
        menu();
        afficheMatrice2(Matric, n, m + 1);
        cin >> choix;

        // Validation de l'entrée (entre 1 et 8)
        while (choix < 1 || choix > 8)
        {
            cout << "Oups ! Veuillez entrer une valeur entre 1 et 8 : ";
            menu();
            afficheMatrice2(Matric, n, m);
            cin >> choix;
        }

        switch (choix)
        {
        case 1: // Haut
            if (n1 - 1 >= 0)
            {
                if (H)
                { lost++;
                    cout << "Vous avez choisi de monter (Haut).\nMais il y a un mur.\n";
                }
                else
                {
                    n1 -= 1;
                    step++;

                    do
                    {
                        cout << "Tu veux prendre la valeur (" << Matric[n1][m1] << ") ? Si oui, tape Y. Sinon, tape N : ";
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);
                    // lena verification ll mot ken theb tekhou el char ken le yzid el step ken ey mayzidech
                    if (rec == 'Y' || rec == 'y')
                    {
                        T[i] = Matric[n1][m1];
                        i++;
                        if (i != 1)
                        {
                            int step1 = step;
                            // ken hazit el char lena namlou hit ama el hit juste ll wakt taw khater ki tkonfermi bch nremplaciw el casset hedhom bahrouf alea
                            if (step > 9)
                            {
                                step1 = step % 10;
                            }
                            Matric[n1][m1] = static_cast<char>((step1 + 2) + '0');
                        }
                    }
                    cout << "Vous êtes maintenant dans la case :  (" << n1 << "," << m1 << ")" << endl;

                    do
                    {
                        // ken theb tkonfermi wala le
                        cout << "t7eb tkamel ??  ken ey Y snn N : " << endl;
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {
                        // ken EY nhesbou score w ncompariw w namlou kol chy w namlou inisalisation ll tableau li fih el chars
                        string kelma(T, i); // lena nekhdhou el klma

                        for (int k = 0; k < i; k++)
                        {
                            T[k] = ' ';
                        }

                        cout << "tu as le mot " << kelma << endl;

                        CompMot(kelma, Score, i, niv, T1, step, motsSelectionnes);

                        cout << "tu as un Score de  " << Score << endl;

                        /*std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes*/
                        vizita = 0;
                        i = 0;
                        remplirMatrice2(n, m, khrouj); // lena bch nabiw el klem eli hazineh w fared el wakt nabiwah fel matrice ta3 djiktra
                        step = 0;
                    }
                }
            }
            // ken el mouv ghalet bch ykolek impossible
            else
            { lost++;
                 cout << "Mouvement impossible (hors de la matrice).\n";
                cout << "tu as : "<< lost << "  Sanctions"<< endl;
            }
            break;

        case 2: // Bas
            if (n1 + 1 < n)
            {
                if (B)
                {lost++;
                    cout << "Vous avez choisi de descendre (Bas).\nMais il y a un mur.\n";
                }
                else
                {
                    n1 += 1;
                    step++;

                    do
                    {
                        cout << "Tu veux prendre la valeur (" << Matric[n1][m1] << ") ? Si oui, tape Y. Sinon, tape N : ";
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {
                        T[i] = Matric[n1][m1];
                        i++;
                        if (i != 1)
                        {
                            int step1 = step;
                            if (step > 9)
                            {
                                step1 = step % 10;
                            }
                            Matric[n1][m1] = static_cast<char>((step1 + 2) + '0');
                        }
                    }
                    cout << "Vous êtes maintenant dans la case :  (" << n1 << "," << m1 << ")" << endl;

                    do
                    {
                        cout << "t7eb tkamel ??  ken ey Y snn N : " << endl;
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {

                        string kelma(T, i); // lena nekhdhou el klma

                        for (int k = 0; k < i; k++)
                        {
                            T[k] = ' ';
                        }
                        cout << "tu as le mot " << kelma << endl;

                        CompMot(kelma, Score, i, niv, T1, step, motsSelectionnes);

                        cout << "tu as un Score de  " << Score << endl;

                        /*std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes*/
                        step = 0;
                        vizita = 0;
                        i = 0;
                        remplirMatrice2(n, m, khrouj);
                    }
                }
            }
            else
            {lost++;
                 cout << "Mouvement impossible (hors de la matrice).\n";
                cout << "tu as : "<< lost << "  Sanctions"<< endl;
            }
            break;

        case 3: // Gauche
            if (m1 - 1 >= 0)
            {
                if (G)
                {lost++;
                    cout << "Vous avez choisi de bouger à gauche.\nMais il y a un mur.\n";
                }
                else
                {
                    m1 -= 1;
                    step++;

                    do
                    {
                        cout << "Tu veux prendre la valeur (" << Matric[n1][m1] << ") ? Si oui, tape Y. Sinon, tape N : ";
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {
                        T[i] = Matric[n1][m1];
                        i++;
                        if (i != 1)
                        {
                            int step1 = step;
                            if (step > 9)
                            {
                                step1 = step % 10;
                            }
                            Matric[n1][m1] = static_cast<char>((step1 + 2) + '0');
                        }
                    }

                    cout << "Vous êtes maintenant dans la case :  (" << n1 << "," << m1 << ")" << endl;
                }
                do
                {
                    cout << "t7eb tkamel ??  ken ey Y snn N : " << endl;
                    cin >> rec;

                    if (conYO)
                    {
                        cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                    }
                } while (conYO);

                if (rec == 'Y' || rec == 'y')
                {

                    string kelma(T, i); // lena nekhdhou el klma

                    for (int k = 0; k < i; k++)
                    {
                        T[k] = ' ';
                    }

                    cout << "tu as le mot " << kelma << endl;

                    CompMot(kelma, Score, i, niv, T1, step, motsSelectionnes);

                    cout << "tu as un Score de  " << Score << endl;

                    /*std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes*/
                    step = 0;
                    vizita = 0;
                    i = 0;
                    remplirMatrice2(n, m, khrouj);
                }
            }

            else
            {lost++;
                 cout << "Mouvement impossible (hors de la matrice).\n";
                cout << "tu as : "<< lost << "  Sanctions"<< endl;
            }
            break;

        case 4: // Droite
            if (m1 + 1 < m || Matric[n1][m1 + 1] != '*')
            {
                if (D)
                {lost++;
                    cout << "Vous avez choisi de bouger à droite.\nMais il y a un mur.\n";
                }
                else
                {
                    m1 += 1;
                    step++;

                    do
                    {
                        cout << "Tu veux prendre la valeur (" << Matric[n1][m1] << ") ? Si oui, tape Y. Sinon, tape N : ";
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {
                        T[i] = Matric[n1][m1];
                        i++;
                        if (i != 1)
                        {
                            int step1 = step;
                            if (step > 9)
                            {
                                step1 = step % 10;
                            }
                            Matric[n1][m1] = static_cast<char>((step1 + 2) + '0');
                        }
                    }

                    cout << "Vous êtes maintenant dans la case :  (" << n1 << "," << m1 << ")" << endl;
                    do
                    {
                        cout << "t7eb tkamel ??  ken ey Y snn N : " << endl;
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {

                        string kelma(T, i); // lena nekhdhou el klma

                        for (int k = 0; k < i; k++)
                        {
                            T[k] = ' ';
                        }

                        cout << "tu as le mot " << kelma << endl;

                        CompMot(kelma, Score, i, niv, T1, step, motsSelectionnes);

                        cout << "tu as un Score de  " << Score << endl;

                        /*std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes*/
                        step = 0;
                        vizita = 0;
                        i = 0;
                        remplirMatrice2(n, m, khrouj);
                    }
                }
            }
            else if (Matric[n1][m1 + 1] == '*')
            {

                m1 += 1;
            }
            else
            {lost++;
                 cout << "Mouvement impossible (hors de la matrice).\n";
                cout << "tu as : "<< lost << "  Sanctions"<< endl;
            }
            break;

        case 5: // Diagonale Haut-Gauche
            if (n1 - 1 >= 0 && m1 - 1 >= 0)
            {
                if (HG)
                {lost++;
                    cout << "Vous avez choisi de monter en diagonale (Haut-Gauche).\nMais il y a un mur.\n";
                }
                else
                {
                    n1 -= 1;
                    m1 -= 1;
                    step++;

                    do
                    {
                        cout << "Tu veux prendre la valeur (" << Matric[n1][m1] << ") ? Si oui, tape Y. Sinon, tape N : ";
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {
                        T[i] = Matric[n1][m1];
                        i++;
                        if (i != 1)
                        {
                            int step1 = step;
                            if (step > 9)
                            {
                                step1 = step % 10;
                            }
                            Matric[n1][m1] = static_cast<char>((step1 + 2) + '0');
                        }
                    }

                    cout << "Vous êtes maintenant dans la case :  (" << n1 << "," << m1 << ")" << endl;
                }
                do
                {
                    cout << "t7eb tkamel ??  ken ey Y snn N : " << endl;
                    cin >> rec;

                    if (conYO)
                    {
                        cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                    }
                } while (conYO);

                if (rec == 'Y' || rec == 'y')
                {

                    string kelma(T, i); // lena nekhdhou el klma

                    for (int k = 0; k < i; k++)
                    {
                        T[k] = ' ';
                    }

                    cout << "tu as le mot " << kelma << endl;

                    CompMot(kelma, Score, i, niv, T1, step, motsSelectionnes);

                    cout << "tu as un Score de  " << Score << endl;

                    /*std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes*/
                    step = 0;
                    vizita = 0;
                    i = 0;
                    remplirMatrice2(n, m, khrouj);
                }
            }

            else
            {lost++;
                 cout << "Mouvement impossible (hors de la matrice).\n";
                cout << "tu as : "<< lost << "  Sanctions"<< endl;
            }
            break;

        case 6: // Diagonale Haut-Droite
            if (n1 - 1 >= 0 && m1 + 1 < m && Matric[n1 - 1][m1 + 1] != '*')
            {
                if (HD)
                {lost++;
                    cout << "Vous avez choisi de monter en diagonale (Haut-Droite).\nMais il y a un mur.\n";
                }
                else
                {
                    n1 -= 1;
                    m1 += 1;
                    step++;

                    do
                    {
                        cout << "Tu veux prendre la valeur (" << Matric[n1][m1] << ") ? Si oui, tape Y. Sinon, tape N : ";
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {
                        T[i] = Matric[n1][m1];
                        i++;
                        if (i != 1)
                        {
                            int step1 = step;
                            if (step > 9)
                            {
                                step1 = step % 10;
                            }
                            Matric[n1][m1] = static_cast<char>((step1 + 2) + '0');
                        }
                    }

                    cout << "Vous êtes maintenant dans la case :  (" << n1 << "," << m1 << ")" << endl;

                    do
                    {
                        cout << "t7eb tkamel ??  ken ey Y snn N : " << endl;
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {

                        string kelma(T, i); // lena nekhdhou el klma

                        for (int k = 0; k < i; k++)
                        {
                            T[k] = ' ';
                        }

                        cout << "tu as le mot " << kelma << endl;

                        CompMot(kelma, Score, i, niv, T1, step, motsSelectionnes);

                        cout << "tu as un Score de  " << Score << endl;

                        /*std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes*/
                        step = 0;
                        vizita = 0;
                        i = 0;
                        remplirMatrice2(n, m, khrouj);
                    }
                }
            }
            else if (Matric[n1 - 1][m1 + 1] == '*')
            {
                n1 -= 1;
                m1 += 1;
            }

            else
            {lost++;
                 cout << "Mouvement impossible (hors de la matrice).\n";
                cout << "tu as : "<< lost << "  Sanctions"<< endl;
            }
            break;

        case 7: // Diagonale Bas-Gauche
            if (n1 + 1 < n && m1 - 1 >= 0)
            {
                if (BG)
                {lost++;
                    cout << "Vous avez choisi de descendre en diagonale (Bas-Gauche).\nMais il y a un mur.\n";
                }
                else
                {
                    n1 += 1;
                    m1 -= 1;
                    step++;

                    do
                    {
                        cout << "Tu veux prendre la valeur (" << Matric[n1][m1] << ") ? Si oui, tape Y. Sinon, tape N : ";
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {
                        T[i] = Matric[n1][m1];
                        i++;
                        if (i != 1)
                        {
                            int step1 = step;
                            if (step > 9)
                            {
                                step1 = step % 10;
                            }
                            Matric[n1][m1] = static_cast<char>((step1 + 2) + '0');
                        }
                    }

                    cout << "Vous êtes maintenant dans la case :  (" << n1 << "," << m1 << ")" << endl;

                    do
                    {
                        cout << "t7eb tkamel ??  ken ey Y snn N : " << endl;
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {

                        string kelma(T, i); // lena nekhdhou el klma

                        for (int k = 0; k < i; k++)
                        {
                            T[k] = ' ';
                        }

                        cout << "tu as le mot " << kelma << endl;

                        CompMot(kelma, Score, i, niv, T1, step, motsSelectionnes);

                        cout << "tu as un Score de  " << Score << endl;

                        /*std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes*/
                        step = 0;
                        vizita = 0;
                        i = 0;
                        remplirMatrice2(n, m, khrouj);
                    }
                }
            }
            else
            {lost++;
                 cout << "Mouvement impossible (hors de la matrice).\n";
                cout << "tu as : "<< lost << "  Sanctions"<< endl;
            }
            break;

        case 8: // Diagonale Bas-Droite
            if (n1 + 1 < n && m1 + 1 < m && Matric[n1 + 1][m1 + 1] != '*')
            {
                if (BD)
                {lost++;
                    cout << "Vous avez choisi de descendre en diagonale (Bas-Droite).\nMais il y a un mur.\n";
                }
                else
                {
                    n1 += 1;
                    m1 += 1;
                    step++;

                    do
                    {
                        cout << "Tu veux prendre la valeur (" << Matric[n1][m1] << ") ? Si oui, tape Y. Sinon, tape N : ";
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {
                        T[i] = Matric[n1][m1];
                        i++;
                        if (i != 1)
                        {
                            int step1 = step;
                            if (step > 9)
                            {
                                step1 = step % 10;
                            }
                            Matric[n1][m1] = static_cast<char>((step1 + 2) + '0');
                        }
                    }

                    cout << "Vous êtes maintenant dans la case :  (" << n1 << "," << m1 << ")" << endl;

                    do
                    {
                        cout << "t7eb tkamel ??  ken ey Y snn N : " << endl;
                        cin >> rec;

                        if (conYO)
                        {
                            cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                        }
                    } while (conYO);

                    if (rec == 'Y' || rec == 'y')
                    {

                        string kelma(T, i); // lena nekhdhou el klma

                        for (int k = 0; k < i; k++)
                        {
                            T[k] = ' ';
                        }
                        cout << "tu as le mot " << kelma << endl;

                        CompMot(kelma, Score, i, niv, T1, step, motsSelectionnes);

                        cout << "tu as un Score de  " << Score << endl;

                        /*std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes*/
                        step = 0;
                        vizita = 0;
                        i = 0;
                        remplirMatrice2(n, m, khrouj);
                    }
                }
            }
            else if (Matric[n1 + 1][m1 + 1] == '*')
            {
                n1 += 1;
                m1 += 1;
            }
            else
            {lost++;
                 cout << "Mouvement impossible (hors de la matrice).\n";
                cout << "tu as : "<< lost << "  Sanctions"<< endl;
            }
            break;

        default:
            cout << "Aucun mouvement valide sélectionné.\n";
            break;
        }

if (niv==1){

    if (lost>=(m+n)){i=200; cout<<"PPAW PAW pour la famille pour les gang "<<endl;}  
}
else if (niv==2){
//pythagore
    if (lost>=(sqrt(pow(m, 2)+pow(n, 2)))) {i=200; cout<<"PPAW PAW pour la famille pour les gang "<<endl;}   
}
else {
    if (lost>=m){i=200; cout<<"PPAW PAW pour la famille pour les gang "<<endl;}    
}
        // 9bal ma t3awed etloopi lena nchoufou ken wselna ll nejma ken ey bch nmchiw nehsbou el score w baed kel w namlou kel ada ama lena rahou rbeh
        // nehsboulou el socre el lekher w nojhrjou
        if (Matric[n1][m1] == '*')
        {

            string kelma(T, i); // lena nekhdhou el klma

            cout << "Victoire!" << endl;

            CompMot1(kelma, Score, i, niv, T1, step, motsSelectionnes);

            cout << "Score Final: " << Score << endl;
            // lena i ++++++++++++++++ donc nbrekiw kol chay wnokhrjou
            i = 222;
            std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause de 3 secondes*/

            // lezzem lena bch najmou nokhrjou mel while w najmou narfou kober el kelma
        }
    }
    // lena lezem n3abiw aka les 2 avec des lettres
}

>>>>>>> d363830 (Ajout initial du projet)
#endif