
#ifndef finc
#define finc
#include <windows.h>

#include <algorithm>
#include <cctype>  // Pour isalpha()
#include <chrono>  // Pour std::chrono::seconds
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <locale>
#include <queue>
#include <string>
#include <thread>  // Pour std::this_thread::sleep_for
#include <vector>
using namespace std;
vector<string> motsSelectionnes(
    100);  // vecteur de mots Selectionnes a partir du dictionnaire
int x = 0,
    khrouj = 0,  // pour connaitre la position de '*' (point d'arrivee)
    kk = 0, vizita1 = 0;
int T1[100];  // tableau pour stocker le plus court chemin vers le mot
// connb : detecter le lettres selectionnes dans la fonction remplirMatrice2
#define connb                                                           \
  (Matric[i][j] == '2' || Matric[i][j] == '3' || Matric[i][j] == '4' || \
   Matric[i][j] == '5' || Matric[i][j] == '6' || Matric[i][j] == '7' || \
   Matric[i][j] == '8' || Matric[i][j] == '9')

#define conYO (rec != 'Y' && rec != 'y' && rec != 'N' && rec != 'n')

// les conditions pour les mouvements dans la matrice :
#define H                                                    \
  (Matric[n1 - 1][m1] == '1' || Matric[n1 - 1][m1] == '2' || \
   Matric[n1 - 1][m1] == '3' || Matric[n1 - 1][m1] == '4' || \
   Matric[n1 - 1][m1] == '5' || Matric[n1 - 1][m1] == '6' || \
   Matric[n1 - 1][m1] == '7' || Matric[n1 - 1][m1] == '8' || \
   Matric[n1 - 1][m1] == '9')

#define B                                                    \
  (Matric[n1 + 1][m1] == '1' || Matric[n1 + 1][m1] == '2' || \
   Matric[n1 + 1][m1] == '3' || Matric[n1 + 1][m1] == '4' || \
   Matric[n1 + 1][m1] == '5' || Matric[n1 + 1][m1] == '6' || \
   Matric[n1 + 1][m1] == '7' || Matric[n1 + 1][m1] == '8' || \
   Matric[n1 + 1][m1] == '9')

#define G                                                    \
  (Matric[n1][m1 - 1] == '1' || Matric[n1][m1 - 1] == '2' || \
   Matric[n1][m1 - 1] == '3' || Matric[n1][m1 - 1] == '4' || \
   Matric[n1][m1 - 1] == '5' || Matric[n1][m1 - 1] == '6' || \
   Matric[n1][m1 - 1] == '7' || Matric[n1][m1 - 1] == '8' || \
   Matric[n1][m1 - 1] == '9')

#define D                                                    \
  (Matric[n1][m1 + 1] == '1' || Matric[n1][m1 + 1] == '2' || \
   Matric[n1][m1 + 1] == '3' || Matric[n1][m1 + 1] == '4' || \
   Matric[n1][m1 + 1] == '5' || Matric[n1][m1 + 1] == '6' || \
   Matric[n1][m1 + 1] == '7' || Matric[n1][m1 + 1] == '8' || \
   Matric[n1][m1 + 1] == '9')

#define HG                                                           \
  (Matric[n1 - 1][m1 - 1] == '1' || Matric[n1 - 1][m1 - 1] == '2' || \
   Matric[n1 - 1][m1 - 1] == '3' || Matric[n1 - 1][m1 - 1] == '4' || \
   Matric[n1 - 1][m1 - 1] == '5' || Matric[n1 - 1][m1 - 1] == '6' || \
   Matric[n1 - 1][m1 - 1] == '7' || Matric[n1 - 1][m1 - 1] == '8' || \
   Matric[n1 - 1][m1 - 1] == '9')

#define HD                                                           \
  (Matric[n1 - 1][m1 + 1] == '1' || Matric[n1 - 1][m1 + 1] == '2' || \
   Matric[n1 - 1][m1 + 1] == '3' || Matric[n1 - 1][m1 + 1] == '4' || \
   Matric[n1 - 1][m1 + 1] == '5' || Matric[n1 - 1][m1 + 1] == '6' || \
   Matric[n1 - 1][m1 + 1] == '7' || Matric[n1 - 1][m1 + 1] == '8' || \
   Matric[n1 - 1][m1 + 1] == '9')

#define BG                                                           \
  (Matric[n1 + 1][m1 - 1] == '1' || Matric[n1 + 1][m1 - 1] == '2' || \
   Matric[n1 + 1][m1 - 1] == '3' || Matric[n1 + 1][m1 - 1] == '4' || \
   Matric[n1 + 1][m1 - 1] == '5' || Matric[n1 + 1][m1 - 1] == '6' || \
   Matric[n1 + 1][m1 - 1] == '7' || Matric[n1 + 1][m1 - 1] == '8' || \
   Matric[n1 + 1][m1 - 1] == '9')

#define BD                                                           \
  (Matric[n1 + 1][m1 + 1] == '1' || Matric[n1 + 1][m1 + 1] == '2' || \
   Matric[n1 + 1][m1 + 1] == '3' || Matric[n1 + 1][m1 + 1] == '4' || \
   Matric[n1 + 1][m1 + 1] == '5' || Matric[n1 + 1][m1 + 1] == '6' || \
   Matric[n1 + 1][m1 + 1] == '7' || Matric[n1 + 1][m1 + 1] == '8' || \
   Matric[n1 + 1][m1 + 1] == '9')

char Matric[100][100];   // matrice principale
char Matric1[100][100];  // matrice de contole pour la generation de grille
char Matric3[100][100];  // matrice utilisee par l'algorithme de djikstra
char T[20];              // tableau pour stocker le mot recuperee par le joueur
int /*m:nombre de colonne,n:nombre de ligne */ m, n,
    choix /*choix de la direction */, /*position actuelle dans la matrice */ n1,
    m1;

void recopiematrice(int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= m; j++) {
      Matric3[i][j] = Matric[i][j];
    }
  }
}
// fonction pour faire un compte a rebours au debut du jeu
void countdown(int seconds) {
  for (int i = seconds; i > 0; i--) {
    cout << "Début du jeu dans " << i << "..." << endl;
#ifdef _WIN32
    Sleep(1000);  // Pause de 1 seconde (Windows)
#endif
  }
  cout << "C'est parti ! Bonne chance !" << endl;
}

// fonction pour compter le nombre de murs dans la matrice
int combienDeUn(int n, int m) {
  int count = 0;  // Compteur initialisé à 0
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (Matric[i][j] == '1') {
        count++;  // Incrémenter le compteur si le caractère est '1'
      }
    }
  }
  return count;
}

// Menu du jeu
void menu() {
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
// remplir la matrice d'une facon aleatoire
void remplirMatrice(int n, int m) {
  srand(time(0));  // Initialisation de la graine aléatoire
  int range = 30;  // 26 lettres + 4 pour le chiffre '1'

  for (int i = 0; i < n; i++) {
    bool hasOne = false;  // Vérifie si la ligne contient au moins un '1'

    for (int j = 0; j < m; j++) {
      int randomValue = rand() % range;  // Génère une valeur entre 0 et 29

      // Génération des caractères aléatoires
      if (randomValue < 4) {
        Matric[i][j] = '1';  // Cas pour '1'
        hasOne = true;       // Marque qu'il y a un '1' dans cette ligne
      } else {
        Matric[i][j] = 'A' + (randomValue - 4);  // Cas pour 'A' à 'Z'
      }
    }

    // Si la ligne n'a pas de '1', force l'ajout d'un '1'
    if (!hasOne) {
      int randomColumn = rand() % m;  // Choisir une colonne aléatoire
      Matric[i][randomColumn] = '1';
    }
  }
}

// affiche la grille et remplace les '1' qui sont dans la meme ligne que le
// point d'arrivee par des espaces
void afficheMatrice(char Matri[][100], int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j == m - 1 && Matri[i][j] == '1') {
        cout << " ";
      }

      else {
        cout << " " << Matri[i][j] << " ";  // Affichage du caractère
      }
    }

    // Vérification si le dernier élément de la ligne est '1'

    cout << endl;  // Retour à la ligne après chaque ligne de la matrice
  }
}

void afficheMatrice1(char Matri[][100], int n, int m, int N1, int M1) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j == m - 1 && Matri[i][j] == '1') {
        cout << " ";
      }
      else if (i == N1 && j == M1) {
        // Mise en évidence en rouge (ANSI) ou avec des crochets
        cout << "\033[1;31m[" << Matri[i][j] << "]\033[0m ";
      }
      else {
        cout << " " << Matri[i][j] << " ";
      }
    }
    cout << endl; // Retour à la ligne après chaque ligne
  }
}
void remplirMatriceN1(int n, int m, vector<string> motsSelectionnes,
                      int &khrouj) {
  int randomValue;
  srand(time(0));  // Initialisation de la graine aléatoire
  int range = 30;  // 26 lettres (A-Z) + 4 pour le chiffre '1'

  for (int i = 0; i < n; i++) {
    string motCourant = motsSelectionnes[i];
    for (int j = 0; j < motCourant.length(); j++) {
      Matric[i][j] = motCourant[j];
      // cout << Matric[i][j] << " ";
    }
    //  cout << endl;
  }

  for (int i = 0; i < n; i++) {
    bool hasOne = false;  // Vérifie si la ligne contient au moins un '1'

    for (int j = 0; j < m; j++) {
      if (!isalpha(Matric[i][j]))  // Remplir uniquement les cases vides
      {
        randomValue = rand() % range;  // Génère une valeur entre 0 et 29

        // Génération des caractères aléatoires
        if (randomValue < 4) {
          Matric[i][j] = '1';  // Cas pour '1'
          hasOne = true;       // Marque qu'il y a un '1' dans cette ligne
        } else {
          Matric[i][j] = 'A' + (randomValue - 4);  // Cas pour 'A' à 'Z'
        }
      }
    }

    // Si la ligne n'a pas de '1', on force l'ajout d'un '1' quelque part, '1'
    // represente un mur
    if (!hasOne) {
      int randomColumn = motsSelectionnes[i].length() +
                         (rand() % (m - motsSelectionnes[i].length()));
      Matric[i][randomColumn] = '1';
    }
  }

  for (int i = 0; i < n; i++) {
    Matric[i][m] = '1';
  }
  // Ajouter un `*` à une ligne aléatoire à la dernière colonne
  khrouj = rand() % n;
  Matric[khrouj][m] = '*';  // `m` étant la dernière colonne après les données
  Matric[khrouj][m - 1] = 'A' + m;
  recopiematrice(n,
                 m);  // on recopie la matrice pour ne pas modifier la matrice a
                      // chaque utilisation de l'algorithme djikstra
}

void remplirMatriceN3(int n, int m, vector<string> motsSelectionnes,
                      int &khrouj) {
  srand(time(0));  // Initialisation de la graine aléatoire
  int range = 30;  // 26 lettres (A-Z) + 4 pour le chiffre '1'

  // Initialisation d'une matrice du jeu (labyrinthe)
  remplirMatrice(n, m);

  // Placement des mots d'une maniere aleatoire dans la matrice du jeu
  for (int rep = 0; rep < motsSelectionnes.size(); rep++) {
    string mot = motsSelectionnes[rep];
    int k = mot.length();  // longueur de chaque mot selectionnee
    int c = 0;
    while (c < k) {
      int row = rand() % n;
      int col = rand() % m;

      // Vérifier si la case est disponible, si la case est remplie avec un
      // caractere, on chereche une autre case libre
      while (Matric1[row][col] == '1') {
        row = rand() % n;
        col = rand() % m;
      }

      Matric[row][col] = mot[c];  // Placement du caractère
      Matric1[row][col] =
          '1';  // Marquer la case comme occupée dans la matrice de controle
      c++;
    }
  }
  for (int i = 0; i < n; i++) {
    Matric[i][m] = '1';
  }
  // Ajouter un `*` à une ligne aléatoire à la dernière colonne
  khrouj = rand() % n;
  Matric[khrouj][m] = '*';  // `m` étant la dernière colonne après les données
  Matric[khrouj][m - 1] = 'A' + m;
  recopiematrice(n, m);
}

void remplirMatriceN2(int n, int m, vector<string> motsSelectionnes,
                      int &khrouj) {
  // Initialisation d'une matrice du jeu (labyrinthe)
  remplirMatrice(n, m);

  // **Placement des mots avec inversion**
  int totalMots = motsSelectionnes.size();
  for (int i = 0; i < totalMots; i++) {
    string motCourant = motsSelectionnes[i];
    int longueurMot = motCourant.length();
    int milieu = longueurMot / 2;

    // Ligne normale
    int rowNormale = i % n;
    // Ligne inversée
    int rowInverse = (n - 1 - i) % n;

    // **Placer la première moitié du mot
    for (int j = 0; j < milieu; j++) {
      Matric[rowNormale][j] = motCourant[j];
    }

    // **Placer la deuxième moitié dans la ligne inverse**
    for (int j = milieu; j < longueurMot; j++) {
      Matric[rowInverse][m - longueurMot + j] =
          motCourant[j];  // Mettre à la fin de la ligne inverse
    }
  }

  // Ajouter un `*` à une ligne aléatoire à la dernière colonne
  khrouj = rand() % n;
  Matric[khrouj][m] = '*';

  recopiematrice(n, m);
  /*
        cout << "ok" << endl;

        // Affichage de la matrice Matric
        cout << "Matrice principale : " << endl;
        afficheMatrice(Matrice,n + 1, m + 1);
    */
  // Affichage de la matrice Matric1
}

// remplir les cases utilisées pour être réutilisées avec d’autres mots:
void remplirMatrice2(int n, int m, int khrouj) {
  srand(time(0));  // Initialisation de la graine aléatoire
  int range = 30;  // 26 lettres + 4 pour le chiffre '1'

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (connb)  // Vérifie si la case contient '2', '3', ..., '9'
      {
        int randomValue = rand() % range;  // Génère une valeur entre 0 et 29

        // Génération des caractères aléatoires
        if (randomValue < 4) {
          Matric[i][j] = '1';  // Cas pour '1'
        } else {
          Matric[i][j] = 'A' + (randomValue - 5);  // Cas pour 'A' à 'Z'
        }
      }
    }
  }
  // on recopie la matrice pour l'utiliser avec djikstra
  recopiematrice(n, m);
}
// affichage du mot a la fin du jeu :
void afficheTab(char T[], int mac, int step) {
  cout << "mot courant: ";
  for (int i = 0; i < mac; i++) {
    cout << T[i];
  }
  cout << endl;
  cout << "avec nb step= : " << step << endl;
}
// affichage du mot en cour du jeu :
void afficheTab1(char T[], int mac) {
  cout << "mot courant: ";
  for (int i = 0; i < mac; i++) {
    cout << T[i];
  }
  cout << endl;
}

// affichage du resultat final lorsque le joueur atteint '*'
void CompMot1(string verif, int &Score, int long1, int niveau, int Tab[],
              int step, vector<string> &motsSelectionnes) {
  bool motTrouve = false;
  int totalChemin = 0;

  // Recherche du mot dans le vecteur
  for (int i = 0; i < motsSelectionnes.size(); i++) {
    if (motsSelectionnes[i] == verif) {
      motTrouve = true;

      // Supprimer le mot trouvé (Décalage des éléments)
      for (int j = i; j < motsSelectionnes.size() - 1; j++) {
        motsSelectionnes[j] = motsSelectionnes[j + 1];
      }
      motsSelectionnes.pop_back();  // Réduire la taille du vecteur
      break;
    }
  }

  if (motTrouve) {
    // Calcul du chemin total parcouru
    for (int i = 0; i < verif.length(); i++) {
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
  cout << "\033[1;36m========================================\033[0m\n" << endl;

  cout << "\033[1;33m🏆 Score final : \033[1;34m" << Score << "\033[0m" << endl;
  cout << "\033[1;35m📊 Niveau atteint : \033[1;34m" << niveau << "\033[0m"
       << endl;
  cout << "\033[1;36m📝 Mot recherché : \033[1;32m" << verif << "\033[0m"
       << endl;
  cout << "\033[1;34m🔢 Chemin parcouru : \033[1;33m" << totalChemin
       << "\033[0m" << endl;
  cout << "\033[1;34m🚀 Chemin optimal : \033[1;33m" << step << "\033[0m"
       << endl;

  if (motTrouve) {
    if (step <= totalChemin) {
      cout << "\n\033[1;32m✅ Bravo ! Tu as trouvé le mot avec le chemin "
              "optimal !\033[0m"
           << endl;
    } else {
      cout << "\n\033[1;33m⚠️ Bien joué ! Mais tu aurais pu trouver un chemin "
              "plus court.\033[0m"
           << endl;
    }
  } else {
    cout << "\n\033[1;31m❌ Dommage... Le mot n'a pas été trouvé.\033[0m"
         << endl;
  }

  // 🔍 Afficher les mots restants 🔍
  cout << "\n\033[1;36mMots restants : \033[0m";
  if (motsSelectionnes.empty()) {
    cout << "\033[1;32mAucun, tous les mots ont été trouvés ! 🎉\033[0m"
         << endl;
  } else {
    for (const auto &mot : motsSelectionnes) {
      cout << mot << " ";
    }
    cout << "\033[0m" << endl;
  }

  cout << "\n\033[1;36mMerci d'avoir joué ! À bientôt ! 🎮\033[0m" << endl;
  cout << "\033[1;36m========================================\033[0m\n" << endl;
}
// si on a chois touts notre chance : CompMot2( Score,  niv, T1, step);
void CompMot2(int &Score, int niveau, int Tab[], int step) {
  bool motTrouve = false;
  int totalChemin = Tab[0];

  // Calcul du score
  int bonusNiveau = 30 * niveau;

  int bonusChemin = (step <= totalChemin) ? (niveau * 20) : 0;

  Score += bonusNiveau + bonusChemin;

  // ✅ Affichage des résultats finaux ✅
  cout << "\n\033[1;36m========================================\033[0m" << endl;
  cout << "\033[1;32m🎉 Fin du jeu ! Résultats 🎉\033[0m" << endl;
  cout << "\033[1;36m========================================\033[0m\n" << endl;

  cout << "\033[1;33m🏆 Score final : \033[1;34m" << Score << "\033[0m" << endl;
  cout << "\033[1;35m📊 Niveau atteint : \033[1;34m" << niveau << "\033[0m"
       << endl;

  cout << "\033[1;34m🔢 Chemin parcouru : \033[1;33m" << step
       << "\033[0m" << endl;
  cout << "\033[1;34m🚀 Chemin optimal : \033[1;33m" << totalChemin << "\033[0m"
       << endl;

  cout << "\n\033[1;36mMerci d'avoir joué ! À bientôt ! 🎮\033[0m" << endl;
  cout << "\033[1;36m========================================\033[0m\n" << endl;
}
// comparaison du mot selectionne par le joueur avec les mots du dictionnaire:
void CompMot(string verif, int &Score, int long1, int niveau, int Tab[],
             int step, vector<string> &motsSelectionnes) {
  bool motTrouve = false;
  int totalChemin = 0;

  // Recherche du mot avec une boucle simple
  for (int i = 0; i < motsSelectionnes.size(); i++) {
    // yrlawej al kelma fel vecteur
    if (motsSelectionnes[i] == verif) {
      motTrouve = true;

      // Supprimer le mot en décalant les éléments suivants
      for (int j = i; j < motsSelectionnes.size() - 1; j++) {
        motsSelectionnes[j] = motsSelectionnes[j + 1];
      }
      motsSelectionnes.pop_back();  // Réduire la taille du vecteur

      break;  // Sortir de la boucle après avoir trouvé le mot
    }
  }
  // ken l9aha bch ye7seb el score
  if (motTrouve) {
    // Calcul du chemin total parcouru
    for (int i = 0; i < verif.length(); i++) {  // bch yra a9ser chemain
      totalChemin += Tab[i];
    }

    // Calcul du score
    int bonusNiveau = 30 * niveau;
    int bonusLongueur = long1;
    // macro pour calculer le bonus du chemin optimal
    int bonusChemin = (step <= totalChemin) ? (niveau * 20) : 0;
    // formule de calcul du score :
    Score += bonusNiveau + bonusLongueur + bonusChemin;

    // Affichage si le mot a été trouvé dans le dictionnaire
    cout << "✅ Bravo ! Tu as trouvé le mot " << verif << " !" << endl;
    cout << "🔢 Chemin parcouru : " << totalChemin << endl;
    cout << "🚀 Chemin optimal : " << step << endl;

    if (step <= totalChemin) {
      cout << "🏆 Excellent ! Tu as trouvé le mot avec le chemin optimal !"
           << endl;
    } else {
      cout << "⚠️ Tu aurais pu trouver un chemin plus court." << endl;
    }
  } else {
    cout << "❌ Dommage... Le mot " << verif << " n'est pas dans le vecteur."
         << endl;
  }
}

// choisir des mots a partir du dictionnaire et les mettre en fonction de la
// taille de la grille

void lireEtAfficherMots(const string &nomFichier, int nbligne, int m,
                        int &khrouj, int niv1) {
  char Mot[m];
  int index;
  char TAB[nbligne];
  string atwelklema;
  int i = 0;

  vector<string> mots;  // Vecteur pour stocker tous les mots du fichier
  string mot;           // Variable pour stocker chaque mot

  ifstream fichier(nomFichier);  // Ouvrir le fichier en lecture

  if (!fichier) {
    cerr << "Erreur : Impossible d'ouvrir le fichier !" << endl;
    return;
  }

  // Lire tous les mots du fichier et les stocker dans le vecteur
  while (fichier >> mot) {
    mots.push_back(mot);
  }

  fichier.close();  // Fermer le fichier
  // Vérifier si le fichier contient au moins 10 mots
  if (mots.size() < 10) {
    cerr << "Erreur : Le fichier contient moins de 10 mots !" << endl;
    return;
  }

  // Initialiser le générateur de nombres aléatoires
  srand(static_cast<unsigned int>(time(0)));

  while (i < nbligne) {
    int index = rand() % mots.size();
    if (mots[index].length() <= m - 1) {
      motsSelectionnes[i] = mots[index];
      cout << "Mot sélectionné : " << motsSelectionnes[i] << endl;
      i++;
    }
  }

  atwelklema =
      motsSelectionnes[0];  // Initialiser le premier mot comme le plus long

  for (int i = 1; i < nbligne; i++) {
    if (motsSelectionnes[i].length() > atwelklema.length()) {
      atwelklema =
          motsSelectionnes[i];  // Mettre à jour si un mot plus long est trouvé
    }
    //   std::this_thread::sleep_for(std::chrono::seconds(1)); // Pause d'une
    //   seconde
  }

  int k = atwelklema.length();
  // std::this_thread::sleep_for(std::chrono::seconds(4));

  cout << "le mot le plus long est :  " << atwelklema << "  avec un nombre de "
       << k << " characteres" << endl;
  if (niv1 == 1)
  // remplir la grille en fonction du niveau de difficulte :
  {
    remplirMatriceN1(nbligne, m, motsSelectionnes, khrouj);
  }

  else if (niv1 == 2) {
    remplirMatriceN2(nbligne, m, motsSelectionnes, khrouj);
  } else {
    remplirMatriceN3(nbligne, m, motsSelectionnes, khrouj);
  }
}

// creation d'une structure Node contenant un deplacement x,y et un cout:
struct Node {
  int x, y, cost;
  bool operator>(const Node &other) const { return cost > other.cost; }
};

// les 8 directions disponible pour le deplacement dans la grille :
const int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

// pour trouver l'occurence du caractere actuel dans le mot, si trouve on
// execute djikstra pour trouver le chemin le plus court vers le mot
vector<pair<int, int>> trouverOccurrences(char lettre, int n, int m) {
  vector<pair<int, int>> positions;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (Matric3[i][j] == lettre) {
        positions.push_back({i, j});
      }
    }
  }
  return positions;
}

vector<pair<int, int>> dijkstra(int startX, int startY, int endX, int endY,
                                int n, int m) {
  priority_queue<Node, vector<Node>, greater<Node>> pq;
  vector<vector<int>> dist(n, vector<int>(m, 1e9));
  vector<vector<pair<int, int>>> prev(n, vector<pair<int, int>>(m, {-1, -1}));

  pq.push({startX, startY, 0});
  dist[startX][startY] = 0;

  while (!pq.empty()) {
    Node current = pq.top();
    pq.pop();
    int x = current.x, y = current.y, cost = current.cost;

    if (x == endX && y == endY) break;

    for (int i = 0; i < 8; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      // bch nekhdmou all matrice 3
      if (nx >= 0 && nx < n && ny >= 0 && ny < m && Matric3[nx][ny] != '1') {
        int newCost = cost + 1;
        if (newCost < dist[nx][ny]) {
          dist[nx][ny] = newCost;
          prev[nx][ny] = {x, y};
          pq.push({nx, ny, newCost});
        }
      }
    }
  }

  vector<pair<int, int>> path;
  for (int x = endX, y = endY; x != -1 && y != -1; tie(x, y) = prev[x][y]) {
    path.push_back({x, y});
  }
  reverse(path.begin(), path.end());
  return path;
}

void direction(int n, int m, int n1, int m1, int max, int mloul, char loul,
               int niv) {  // cette fonction contient tout le logique du jeu
  T[0] = loul;
  char rec, mot, pt;
  int j = 0, i = 0, step = 0, mac = 16, Score = 0, k = 0, t = 1, lon = 0,
      o = m1, p = n1;
  bool test = 0, vizita = 0;
  int lost = 0;
  vector<string> motsCorrespondants;
  j++;

  if (j == 1) {
    i = mloul;
  } else {
    i = 0;
  }
  step = 0;
  // on boucle jusqu'a le joueur trouve le point d'arrive '*' ou il atteint le
  // nombre max de sanctions : condition de sortie
  while (i < mac) {
    // on prend le premier caractere (position de depart) et on execute djikstra
    // qui va travailler sur une autre matrice
    if (i == 1 && vizita == 0 && kk != n) {
      // bch netakdou li nodkhlou ken awel el haref w ken el kelma mwjouda fel
      // vecteur
      vizita = 1;
      char c = Matric[n1][m1];
      p = n1;
      o = m1;

      // cout << "Lettre sélectionnée : " << c << endl;

      // Réinitialiser les variables pour garantir un nouveau mot à chaque
      // exécution
      motsCorrespondants.clear();
      int kk = 0;  // Réinitialiser l'index du mot sélectionné

      for (string mot : motsSelectionnes) {
        if (mot[0] == c) {
          // test ok, on trouve un mot qui commence par la lettre selectionnee
          // dans le dictionnaire
          test = 1;
          motsCorrespondants.push_back(mot);
        }
      }

      if (motsCorrespondants.empty()) {
        cout << "Aucun mot trouvé avec la lettre " << c << endl;
        for (int i = 0; i < m; i++) {  // cout infini
          T1[i] = 3000;
          cout << T1[i] << endl;
        }
      } else {
        // Vérification de kk avant d'accéder à un élément
        if (kk >= motsCorrespondants.size()) {
          cout << "Erreur : kk dépasse la taille de motsCorrespondants."
               << endl;
        }

        // Sélectionner un nouveau mot
        string motChoisi = motsCorrespondants[kk];
        // cout << "Mot choisi : " << motChoisi << endl;

        vector<pair<int, int>> positions = {{p, o}};
        int i12 = 0;

        int maxIterations = 100;  // Pour éviter boucle infinie
        t = 1;                    // Réinitialiser t pour un nouveau mot
        while (t < motChoisi.length() && maxIterations > 0) {
          maxIterations--;

          vector<pair<int, int>> positionsMot =
              trouverOccurrences(motChoisi[t], n, m);

          if (positionsMot.empty()) {
            cout << "Impossible de trouver un chemin vers " << motChoisi[t]
                 << endl;
            t++;
            continue;
          }

          vector<pair<int, int>> chemin = dijkstra(
              p, o, positionsMot[0].first, positionsMot[0].second, n, m);

          if (chemin.empty()) {
            // cout << "Aucun chemin trouvé vers la lettre " << motChoisi[t] <<
            // "." << endl;
          } else {
            // cout << "Chemin trouvé :" << endl;
            for (const auto &coord : chemin) {
              int x = coord.first;
              int y = coord.second;

              // cout << "(" << x << ", " << y << ") ";
              lon++;
              p = x;
              o = y;
            }
            lon--;
            // cout << endl;
            Matric3[p][o] = '1';
          }

          T1[i12] = lon;
          i12++;
          lon = 0;
          t++;
        }

        if (maxIterations == 0) {
          cout << "Erreur : boucle infinie détectée !" << endl;
          return;
        }

        // cout << "Les longueurs des plus courts chemins sont :" << endl;
        for (int i = 0; i < i12; i++) {
          // cout << T1[i] << endl;
        }

        // Réinitialiser `t` et mettre à jour la matrice
        t = 1;
        Matric[n1][m1] = static_cast<char>((0 + 2) + '0');
      }
    }

    if (k == 0) {
      cout << "Vous etes actuellement à la position : "
           << "(" << n1 << "," << m1 << ")" << endl;
      afficheTab1(T, mac);
      k++;
      Matric[n1][m1] = '2';
    }
    cout << "Choisissez une option (entre 1 et 8) : " << endl;
    menu();
    afficheMatrice1(Matric, n, m+1,n1,m1);
    cin >> choix;

    // Validation de l'entrée (entre 1 et 8)
    while (choix < 1 || choix > 8) {
      cout << "Oups ! Veuillez entrer une valeur entre 1 et 8 : ";
      menu();
      afficheMatrice1(Matric, n, m+1,n1,m1);
      cin >> choix;
    }

    switch (choix) {
      case 1:  // Haut
        if (n1 - 1 >= 0) {
          if (H) {
            lost++;
            cout << "Vous avez choisi de monter (Haut).\nMais il y a un mur.\n";
          } else {
            if (kk == n) {
              n1 -= 1;
              step++;
              T[i] = Matric[n1][m1];
              i++;
              if (i != 1) {
                int step1 = step;
                if (step > 9) {
                  step1 = step % 10;
                }
                Matric[n1][m1] = static_cast<char>((step1 + 2) + '0');
              }

            } else {
              n1 -= 1;
              step++;

              do {
                cout << "Tu veux prendre la valeur (" << Matric[n1][m1]
                     << ") ? Si oui, tape Y. Sinon, tape N : ";
                cin >> rec;

                if (conYO) {
                  cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                }
              } while (conYO);
              // verification de l'input de l'utilisateur
              if (rec == 'Y' || rec == 'y') {
                T[i] = Matric[n1][m1];
                i++;
                if (i != 1) {
                  int step1 = step;

                  if (step > 9) {
                    step1 = step % 10;
                  }
                  Matric[n1][m1] = static_cast<char>((step1 + 2) + '0');
                }
              }
              cout << "Vous êtes maintenant dans la case :  (" << n1 << ","
                   << m1 << ")" << endl;

              do {
                cout << "Tu veux valider ce mot ? Taper Y ou N : " << endl;
                cin >> rec;

                if (conYO) {
                  cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                }
              } while (conYO);

              if (rec == 'Y' || rec == 'y') {
                // si le joueur valide le mot, on compare et on calcule le
                // score. Puis on remplace les cases utilisees par des lettres
                // aleatoires.
                string kelma(T, i);  // on stocke le mot du joueur

                for (int k = 0; k < i; k++) {
                  T[k] = ' ';
                }

                cout << "Tu as le mot " << kelma << endl;

                CompMot(kelma, Score, i, niv, T1, step, motsSelectionnes);

                cout << "Tu as un Score de  " << Score << endl;

                /*std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause
                 * de 3 secondes*/
                vizita = 0;
                i = 0;
                kk++;
                remplirMatrice2(
                    n, m,
                    khrouj);  // lena bch nabiw el klem eli hazineh w fared el
                              // wakt nabiwah fel matrice ta3 djiktra
                step = 0;
              }
            }
          }
        }
        // si le mouvement est faux :
        else {
          lost++;
          cout << "Mouvement impossible (hors de la matrice).\n";
          cout << "tu as : " << lost << "  Sanctions" << endl;
        }
        break;

      case 2:  // Bas
        if (n1 + 1 < n) {
          if (B) {
            lost++;
            cout << "Vous avez choisi de descendre (Bas).\nMais il y a un "
                    "mur.\n";
          } else {
            if (kk == n) {
              n1 += 1;
              step++;
              T[i] = Matric[n1][m1];
              i++;
              if (i != 1) {
                int step1 = step;
                if (step > 9) {
                  step1 = step % 10;
                }
                Matric[n1][m1] = static_cast<char>((step1 + 2) + '0');
              }

            }

            else {
              n1 += 1;
              step++;

              do {
                cout << "Tu veux prendre la valeur (" << Matric[n1][m1]
                     << ") ? Si oui, tape Y. Sinon, tape N : ";
                cin >> rec;

                if (conYO) {
                  cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                }
              } while (conYO);

              if (rec == 'Y' || rec == 'y') {
                T[i] = Matric[n1][m1];
                i++;
                if (i != 1) {
                  int step1 = step;
                  if (step > 9) {
                    step1 = step % 10;
                  }
                  Matric[n1][m1] = static_cast<char>((step1 + 2) + '0');
                }
              }
              cout << "Vous êtes maintenant dans la case :  (" << n1 << ","
                   << m1 << ")" << endl;

              do {
                cout << "Tu veux valider ce mot ? Taper Y ou N: " << endl;
                cin >> rec;

                if (conYO) {
                  cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                }
              } while (conYO);

              if (rec == 'Y' || rec == 'y') {
                string kelma(T, i);

                for (int k = 0; k < i; k++) {
                  T[k] = ' ';
                }
                cout << "Tu as le mot " << kelma << endl;

                CompMot(kelma, Score, i, niv, T1, step, motsSelectionnes);

                cout << "Tu as un Score de  " << Score << endl;

                /*std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause
                 * de 3 secondes*/
                step = 0;
                vizita = 0;
                i = 0;
                kk++;
                remplirMatrice2(n, m, khrouj);
              }
            }
          }
        } else {
          lost++;
          cout << "Mouvement impossible (hors de la matrice).\n";
          cout << "tu as : " << lost << "  Sanctions" << endl;
        }
        break;

      case 3:  // Gauche
        if (m1 - 1 >= 0) {
          if (G) {
            lost++;
            cout << "Vous avez choisi de bouger à gauche.\nMais il y a un "
                    "mur.\n";
          } else {
            if (kk == n) {
              m1 -= 1;
              step++;
              T[i] = Matric[n1][m1];
              i++;
              if (i != 1) {
                int step1 = step;
                if (step > 9) {
                  step1 = step % 10;
                }
                Matric[n1][m1] = static_cast<char>((step1 + 2) + '0');
              }

            }

            else {
              m1 -= 1;
              step++;

              do {
                cout << "Tu veux prendre la valeur (" << Matric[n1][m1]
                     << ") ? Si oui, tape Y. Sinon, tape N : ";
                cin >> rec;

                if (conYO) {
                  cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                }
              } while (conYO);

              if (rec == 'Y' || rec == 'y') {
                T[i] = Matric[n1][m1];
                i++;
                if (i != 1) {
                  int step1 = step;
                  if (step > 9) {
                    step1 = step % 10;
                  }
                  Matric[n1][m1] = static_cast<char>((step1 + 2) + '0');
                }
              }

              cout << "Vous êtes maintenant dans la case :  (" << n1 << ","
                   << m1 << ")" << endl;

              do {
                cout << "Tu veux valider ce mot ? Taper Y ou N: " << endl;
                cin >> rec;

                if (conYO) {
                  cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                }
              } while (conYO);

              if (rec == 'Y' || rec == 'y') {
                string kelma(T, i);

                for (int k = 0; k < i; k++) {
                  T[k] = ' ';
                }

                cout << "Tu as le mot " << kelma << endl;

                CompMot(kelma, Score, i, niv, T1, step, motsSelectionnes);

                cout << "Tu as un Score de  " << Score << endl;

                /*std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause
                 * de 3 secondes*/
                step = 0;
                vizita = 0;
                kk++;
                i = 0;
                remplirMatrice2(n, m, khrouj);
              }
            }
          }
        }

        else {
          lost++;
          cout << "Mouvement impossible (hors de la matrice).\n";
          cout << "tu as : " << lost << "  Sanctions" << endl;
        }
        break;

      case 4:  // Droite
        if (m1 + 1 < m || Matric[n1][m1 + 1] != '*') {
          if (D) {
            lost++;
            cout << "Vous avez choisi de bouger à droite.\nMais il y a un "
                    "mur.\n";
          } else {
            if (kk == n) {
              m1 += 1;
              step++;
              T[i] = Matric[n1][m1];
              i++;
              if (i != 1) {
                int step1 = step;
                if (step > 9) {
                  step1 = step % 10;
                }
                Matric[n1][m1] = static_cast<char>((step1 + 2) + '0');
              }

            } else {
              m1 += 1;
              step++;

              do {
                cout << "Tu veux prendre la valeur (" << Matric[n1][m1]
                     << ") ? Si oui, tape Y. Sinon, tape N : ";
                cin >> rec;

                if (conYO) {
                  cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                }
              } while (conYO);

              if (rec == 'Y' || rec == 'y') {
                T[i] = Matric[n1][m1];
                i++;
                if (i != 1) {
                  int step1 = step;
                  if (step > 9) {
                    step1 = step % 10;
                  }
                  Matric[n1][m1] = static_cast<char>((step1 + 2) + '0');
                }
              }

              cout << "Vous êtes maintenant dans la case :  (" << n1 << ","
                   << m1 << ")" << endl;
              do {
                cout << "Tu veux valider ce mot ? Taper Y ou N : " << endl;
                cin >> rec;

                if (conYO) {
                  cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                }
              } while (conYO);

              if (rec == 'Y' || rec == 'y') {
                string kelma(T, i);

                for (int k = 0; k < i; k++) {
                  T[k] = ' ';
                }

                cout << "Tu as le mot " << kelma << endl;

                CompMot(kelma, Score, i, niv, T1, step, motsSelectionnes);

                cout << "Tu as un Score de  " << Score << endl;

                /*std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause
                 * de 3 secondes*/
                step = 0;
                vizita = 0;
                i = 0;
                kk++;
                remplirMatrice2(n, m, khrouj);
              }
            }
          }
        } else if (Matric[n1][m1 + 1] == '*') {
          m1 += 1;
        } else {
          lost++;
          cout << "Mouvement impossible (hors de la matrice).\n";
          cout << "tu as : " << lost << "  Sanctions" << endl;
        }
        break;

      case 5:  // Diagonale Haut-Gauche
        if (n1 - 1 >= 0 && m1 - 1 >= 0) {
          if (HG) {
            lost++;
            cout << "Vous avez choisi de monter en diagonale "
                    "(Haut-Gauche).\nMais il y a un mur.\n";
          } else {
            if (kk == n) {
              n1 -= 1;
              m1 -= 1;
              step++;
              T[i] = Matric[n1][m1];
              i++;
              if (i != 1) {
                int step1 = step;
                if (step > 9) {
                  step1 = step % 10;
                }
                Matric[n1][m1] = static_cast<char>((step1 + 2) + '0');
              }

            } else {
              n1 -= 1;
              m1 -= 1;
              step++;

              do {
                cout << "Tu veux prendre la valeur (" << Matric[n1][m1]
                     << ") ? Si oui, tape Y. Sinon, tape N : ";
                cin >> rec;

                if (conYO) {
                  cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                }
              } while (conYO);

              if (rec == 'Y' || rec == 'y') {
                T[i] = Matric[n1][m1];
                i++;
                if (i != 1) {
                  int step1 = step;
                  if (step > 9) {
                    step1 = step % 10;
                  }
                  Matric[n1][m1] = static_cast<char>((step1 + 2) + '0');
                }
              }

              cout << "Vous êtes maintenant dans la case :  (" << n1 << ","
                   << m1 << ")" << endl;

              do {
                cout << "Tu veux valider ce mot ? Taper Y ou N: " << endl;
                cin >> rec;

                if (conYO) {
                  cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                }
              } while (conYO);

              if (rec == 'Y' || rec == 'y') {
                string kelma(T, i);

                for (int k = 0; k < i; k++) {
                  T[k] = ' ';
                }

                cout << "Tu as le mot " << kelma << endl;

                CompMot(kelma, Score, i, niv, T1, step, motsSelectionnes);

                cout << "Tu as un Score de  " << Score << endl;

                /*std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause
                 * de 3 secondes*/
                step = 0;
                vizita = 0;
                kk++;
                i = 0;
                remplirMatrice2(n, m, khrouj);
              }
            }
          }
        }

        else {
          lost++;
          cout << "Mouvement impossible (hors de la matrice).\n";
          cout << "tu as : " << lost << "  Sanctions" << endl;
        }
        break;

      case 6:  // Diagonale Haut-Droite
        if (n1 - 1 >= 0 && m1 + 1 < m && Matric[n1 - 1][m1 + 1] != '*') {
          if (HD) {
            lost++;
            cout << "Vous avez choisi de monter en diagonale "
                    "(Haut-Droite).\nMais il y a un mur.\n";
          } else {
            if (kk == n) {
              n1 -= 1;
              m1 += 1;
              step++;
              T[i] = Matric[n1][m1];
              i++;
              if (i != 1) {
                int step1 = step;
                if (step > 9) {
                  step1 = step % 10;
                }
                Matric[n1][m1] = static_cast<char>((step1 + 2) + '0');
              }

            } else {
              n1 -= 1;
              m1 += 1;
              step++;

              do {
                cout << "Tu veux prendre la valeur (" << Matric[n1][m1]
                     << ") ? Si oui, tape Y. Sinon, tape N : ";
                cin >> rec;

                if (conYO) {
                  cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                }
              } while (conYO);

              if (rec == 'Y' || rec == 'y') {
                T[i] = Matric[n1][m1];
                i++;
                if (i != 1) {
                  int step1 = step;
                  if (step > 9) {
                    step1 = step % 10;
                  }
                  Matric[n1][m1] = static_cast<char>((step1 + 2) + '0');
                }
              }

              cout << "Vous êtes maintenant dans la case :  (" << n1 << ","
                   << m1 << ")" << endl;

              do {
                cout << "Tu veux valider ce mot ? Taper Y ou N: " << endl;
                cin >> rec;

                if (conYO) {
                  cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                }
              } while (conYO);

              if (rec == 'Y' || rec == 'y') {
                string kelma(T, i);

                for (int k = 0; k < i; k++) {
                  T[k] = ' ';
                }

                cout << "Tu as le mot " << kelma << endl;

                CompMot(kelma, Score, i, niv, T1, step, motsSelectionnes);

                cout << "Tu as un Score de  " << Score << endl;

                /*std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause
                 * de 3 secondes*/
                step = 0;
                vizita = 0;
                i = 0;
                kk++;
                remplirMatrice2(n, m, khrouj);
              }
            }
          }
        } else if (Matric[n1 - 1][m1 + 1] == '*') {
          n1 -= 1;
          m1 += 1;
        }

        else {
          lost++;
          cout << "Mouvement impossible (hors de la matrice).\n";
          cout << "tu as : " << lost << "  Sanctions" << endl;
        }
        break;

      case 7:  // Diagonale Bas-Gauche
        if (n1 + 1 < n && m1 - 1 >= 0) {
          if (BG) {
            lost++;
            cout << "Vous avez choisi de descendre en diagonale "
                    "(Bas-Gauche).\nMais il y a un mur.\n";
          } else {
            if (kk == n) {
              n1 += 1;
              m1 -= 1;
              step++;
              T[i] = Matric[n1][m1];
              i++;
              if (i != 1) {
                int step1 = step;
                if (step > 9) {
                  step1 = step % 10;
                }
                Matric[n1][m1] = static_cast<char>((step1 + 2) + '0');
              }

            } else {
              n1 += 1;
              m1 -= 1;
              step++;

              do {
                cout << "Tu veux prendre la valeur (" << Matric[n1][m1]
                     << ") ? Si oui, tape Y. Sinon, tape N : ";
                cin >> rec;

                if (conYO) {
                  cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                }
              } while (conYO);

              if (rec == 'Y' || rec == 'y') {
                T[i] = Matric[n1][m1];
                i++;
                if (i != 1) {
                  int step1 = step;
                  if (step > 9) {
                    step1 = step % 10;
                  }
                  Matric[n1][m1] = static_cast<char>((step1 + 2) + '0');
                }
              }

              cout << "Vous êtes maintenant dans la case :  (" << n1 << ","
                   << m1 << ")" << endl;

              do {
                cout << "Tu veux valider ce mot ? Taper Y ou N : " << endl;
                cin >> rec;

                if (conYO) {
                  cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                }
              } while (conYO);

              if (rec == 'Y' || rec == 'y') {
                string kelma(T, i);

                for (int k = 0; k < i; k++) {
                  T[k] = ' ';
                }

                cout << "Tu as le mot " << kelma << endl;

                CompMot(kelma, Score, i, niv, T1, step, motsSelectionnes);

                cout << "Tu as un Score de  " << Score << endl;

                /*std::this_thread::sleep_for(std::chrono::seconds(4)); // Pause
                 * de 3 secondes*/
                step = 0;
                vizita = 0;
                i = 0;
                kk++;
                remplirMatrice2(n, m, khrouj);
              }
            }
          }
        } else {
          lost++;
          cout << "Mouvement impossible (hors de la matrice).\n";
          cout << "tu as : " << lost << "  Sanctions" << endl;
        }
        break;

      case 8:  // Diagonale Bas-Droite
        if (n1 + 1 < n && m1 + 1 < m && Matric[n1 + 1][m1 + 1] != '*') {
          if (BD) {
            lost++;
            cout << "Vous avez choisi de descendre en diagonale "
                    "(Bas-Droite).\nMais il y a un mur.\n";
          } else {
            if (kk == n) {
              n1 += 1;
              m1 += 1;
              step++;
              T[i] = Matric[n1][m1];
              i++;
              if (i != 1) {
                int step1 = step;
                if (step > 9) {
                  step1 = step % 10;
                }
                Matric[n1][m1] = static_cast<char>((step1 + 2) + '0');
              }

            }

            else {
              if (kk == n) {
                n1 += 1;
                m1 += 1;
                step++;

                T[i] = Matric[n1][m1];
                i++;
                if (i != 1) {
                  int step1 = step;
                  if (step > 9) {
                    step1 = step % 10;
                  }
                  Matric[n1][m1] = static_cast<char>((step1 + 2) + '0');
                }

              } else {
                n1 += 1;
                m1 += 1;
                step++;

                do {
                  cout << "Tu veux prendre la valeur (" << Matric[n1][m1]
                       << ") ? Si oui, tape Y. Sinon, tape N : ";
                  cin >> rec;

                  if (conYO) {
                    cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                  }
                } while (conYO);

                if (rec == 'Y' || rec == 'y') {
                  T[i] = Matric[n1][m1];
                  i++;
                  if (i != 1) {
                    int step1 = step;
                    if (step > 9) {
                      step1 = step % 10;
                    }
                    Matric[n1][m1] = static_cast<char>((step1 + 2) + '0');
                  }
                }

                cout << "Vous êtes maintenant dans la case :  (" << n1 << ","
                     << m1 << ")" << endl;

                do {
                  cout << "Tu veux valider ce mot ? Taper Y ou N : " << endl;
                  cin >> rec;

                  if (conYO) {
                    cout << "Entrée invalide. Veuillez taper Y ou N.\n";
                  }
                } while (conYO);

                if (rec == 'Y' || rec == 'y' && kk != n) {
                  string kelma(T, i);

                  for (int k = 0; k < i; k++) {
                    T[k] = ' ';
                  }
                  cout << "Tu as le mot " << kelma << endl;

                  CompMot(kelma, Score, i, niv, T1, step, motsSelectionnes);

                  cout << "Tu as un Score de  " << Score << endl;

                  /*std::this_thread::sleep_for(std::chrono::seconds(4)); //
                   * Pause de 3 secondes*/
                  step = 0;
                  vizita = 0;
                  i = 0;
                  kk++;
                  remplirMatrice2(n, m, khrouj);
                }
              }
            }
          }
        } else if (Matric[n1 + 1][m1 + 1] == '*') {
          n1 += 1;
          m1 += 1;
        } else {
          lost++;
          cout << "Mouvement impossible (hors de la matrice).\n";
          cout << "tu as : " << lost << "  Sanctions" << endl;
        }
        break;

      default:
        cout << "Aucun mouvement valide sélectionné.\n";
        break;
    }

    if (niv == 1) {
      if (lost >= (m + n)) {
        i = 200;
        cout << "Tu as perdu " << endl;
      }
    } else if (niv == 2) {
      // pythagore
      if (lost >= (sqrt(pow(m, 2) + pow(n, 2)))) {
        i = 200;
        cout << "Tu as perdu " << endl;
      }
    } else {
      if (lost >= m) {
        i = 200;
        cout << "Tu as perdu" << endl;
      }
    }
    // 9bal ma t3awed etloopi lena nchoufou ken wselna ll nejma ken ey bch
    // nmchiw nehsbou el score w baed kel w namlou kel ada ama lena rahou rbeh
    // nehsboulou el socre el lekher w nojhrjou
    if (kk == n && vizita1 == 0) {
      cout << "pas de mot il faut sortire vide avec le nb de Step nminmale  "
              "bon chance"
           << endl;
      // bch netakdou li nodkhlou ken awel el haref w ken el kelma mwjouda fel
      // vecteur
      vizita1 = 1;
      char c = Matric[n1][m1];
      p = n1;
      o = m1;

      // cout << "Lettre sélectionnée : " << c << endl;

      // Réinitialiser les variables pour garantir un nouveau mot à chaque
      // exécution
      motsCorrespondants.clear();
      vector<pair<int, int>> positions = {{p, o}};
      int i12 = 0;

      t = 1;

      vector<pair<int, int>> positionsMot =
          trouverOccurrences('*', n + 1, m + 1);

      if (positionsMot.empty()) {
        cout << "Impossible de trouver un chemin vers " << '*' << endl;
        t++;
        continue;
      }

      vector<pair<int, int>> chemin = dijkstra(
          p, o, positionsMot[0].first, positionsMot[0].second, n + 1, m + 1);

      if (chemin.empty()) {
        // cout << "Aucun chemin trouvé vers la lettre " << motChoisi[t] << "."
        // << endl;
      } else {
        // cout << "Chemin trouvé :" << endl;
        for (const auto &coord : chemin) {
          int x = coord.first;
          int y = coord.second;

          // cout << "(" << x << ", " << y << ") ";
          lon++;
          p = x;
          o = y;
        }
        lon--;
      }

      T1[0] = lon;

      cout << "le plus coure chemain et" << endl;
      cout << T1[i] << endl;

      // Réinitialiser `t` et mettre à jour la matrice
      t = 1;
      Matric[n1][m1] = static_cast<char>((0 + 2) + '0');
    }

    if (Matric[n1][m1] == '*' && kk != n) {
      string kelma(T, i);

      cout << "Victoire!" << endl;

      CompMot1(kelma, Score, i, niv, T1, step, motsSelectionnes);

      cout << "Score Final: " << Score << endl;
      // on met une valeur de i grande pour sortir de la boucle
      i = 222;
      /*std::this_thread::sleep_for(std::chrono::seconds(4));*/  // Pause de 3
                                                                 // secondes
    }

    if (Matric[n1][m1] == '*' && kk == n) {
      string kelma(T, i);
      cout << "Victoire!" << endl;
      CompMot2( Score, niv, T1, step);
      cout << "Score Final: " << Score << endl;
      // on met une valeur de i grande pour sortir de la boucle
      i = 222;
      /*std::this_thread::sleep_for(std::chrono::seconds(4));*/  // Pause de 3
                                                                 // secondes
    }
  }
}

#endif