/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define P5_COLONNES (20)
#define P5_LIGNES (20)

#define J1_JETON ('O')
#define J2_JETON ('X')
#define J3_JETON ('&')


#define ACT_ERR (0)
#define ACT_JOUER (1)
#define ACT_NOUVELLE_SAISIE (2)
#define ACT_QUITTER (3)

#define STATUT_OK (0)
#define STATUT_GAGNE (1)
#define STATUT_EGALITE (2)

struct position {
    int colonne;
    int ligne;
};

 void affiche_grille(int coord1,int coord2);
 void calcule_position(int, struct position *,int coord1,int coord2);
 unsigned calcule_nb_jetons_depuis_vers(struct position *, int, int, char, int coord1, int coord2);
 unsigned calcule_nb_jetons_depuis(struct position *, char, int, int);
  void rotationgrille (int x , int y, int large, int sens,int coord1,int coord2);
    void saisieUtilisateur(int coord1,int coord2);

 int coup_valide(int,int coord1,int coord2);
 int demande_action(int *);
 int grille_complete(int coord1,int coord2);
 void initialise_grille(int coord1,int coord2);
 int position_valide(struct position *,int coord1,int coord2);
 int statut_jeu(struct position *pos, char,int coord1,int coord2);
 unsigned umax(unsigned, unsigned);
 int vider_tampon(FILE *);
 void saisirCoordonnees(int* coord1, int* coord2);
 char grille[P5_COLONNES][P5_LIGNES];
    char grillerotation[10][10];
  char grillerotationbis[10][10];
  
  
  
  void descgrille (int coord1,int coord2)
 {

 int j,i,k;
 //int tempgrille[large][large];
 
 
 //printf(" donnee sont %d %d %d \n",x,y,large);
 for (k=0 ;k<coord2;++k){
  for (i=coord2-2 ;i>=0;--i){
     for (j=0 ;j<coord1;++j)
     {
         
         
        // printf(" |%c",grille[j][i]);
         if (grille[j][i+1]==' ' && grille[j][i] !='W' && grille[j][i] !=' ')
         {  grille[j][i+1]= grille[j][i];
           grille[j][i]=' ';}
         
     }
     //printf("|\n");
 }
 }
 

 }
  
  
 
 void rotationgrille (int x , int y, int large, int sens,int coord1,int coord2)
 {

 int j,i;
 int tempgrille[large][large];
 
 
 //printf(" donnee sont %d %d %d \n",x,y,large);
 
 /* for (i=0 ;i<coord2;++i){
     for (j=0 ;j<coord1;++j)
     {
         
         
         printf(" |%c",grille[j][i]);
         
     }
     printf("|\n");
 }*/
 
 
 for (i=0 ;i<large;++i){
     for (j=0 ;j<large;++j)
     {
         grillerotation[j][i] =grille[(x+j-1)][coord2-(y+i)];
         
         /*printf(" a xx%cxx (%d) (%d)",grille[x+j-1][coord2-(y+i)],x+j-1,coord2-(y+i));
         printf("b yy%cyy",grillerotation[j][i]);*/
     }
  //   printf("\n grille rotation\n");
 }

 
       for (i=0 ; i<large;++i)
     {
         for (j=0 ; j<large;++j)
         {
             if (sens==0) 
                 grillerotationbis[j][i]= grillerotation[large-1-j][i] ;
            else
                grillerotationbis[j][i]=grillerotation[j][large-1-i];
             //  printf(" |%c",grillerotationbis[j][i]);
         }
         // printf("|\n");
     }
     // printf("\n");
     //printf(" fin 1 ere boucledonnee sont %d %d %d",i,j,large);
   
for (i=0 ;i<large;++i)
 {
     for (j=0  ;j<large;++j)
     {
         grille[(x+j-1)][coord2-(y+i)]=grillerotationbis[i][j];
        // printf("DDD%cDDD",grillerotationbis[i][j]);
     }
 }
 }
    void saisieUtilisateur(int coord1,int coord2) {
    int x, y, large,sens;
        sens=0;
        while (1) {
            printf("Entrez la ligne (entre 0 et %d) : ",coord1);
            scanf("%d", &x);

                if (x >0 && x <= coord1) {
            break;
        }       else {
            printf("La valeur de x doit être entre 0 et %d.\n",coord1);
        }
    }

    while (1) {
        printf("Entrez la valeur de y (entre 0 et %d) : ",coord2);
        scanf("%d", &y);

                if (y >= 0 && y <= coord2) {
            break;
        }       else {
            printf("La valeur de y doit être entre 0 et 8.\n");
        }
    }

    while (1) {
        printf("Entrez la valeur de large (3 ou 5) : ");
        scanf("%d", &large);

        if (large == 3 || large == 5) {
            break;
        } else {
            printf("La valeur de large doit être 3 ou 5.\n");
        }
    }
      while (1) {
        printf("Entrez le sens : horaire (0) ou antihoraire (1) : ");
        scanf("%d", &sens);

        if (sens == 0|| sens == 1) {
            break;
        } else {
            printf("La valeur de sens doit etre de 0 ou 1\n");
        }
    }
 
 
rotationgrille(x,y,large,sens,coord1,coord2);
}



 void saisirCoordonnees(int* coord1, int* coord2) {
    int valide = 0;
    
    while (!valide) {
        printf("Entrez la première coordonnée (entre 8 et 10) : ");
        scanf("%d", coord1);
        
        printf("Entrez la deuxième coordonnée (entre 6 et 8) : ");
        scanf("%d", coord2);
        
        if ((*coord1 >= 8 && *coord1 <= 10) && (*coord2 >= 6 && *coord2 <= 8)) {
            valide = 1;
        } else {
            printf("Coordonnées invalides. Veuillez réessayer.\n");
        }
    }
}

 void affiche_grille(int coord1,int coord2) {
    /*
     * Affiche la grille pour le ou les joueurs.
     */

    int col;
    int lgn;

    putchar('\n');

    for (col = 1; col <= coord1; ++col)
        printf("  %d ", col);

    putchar('\n');
    putchar('+');

    for (col = 1; col <= coord1; ++col)
        printf("---+");

    putchar('\n');

    for (lgn = 0; lgn < coord2; ++lgn) {
        putchar('|');

        for (col = 0; col < coord1; ++col)
            if (isalpha(grille[col][lgn]))
                printf(" %c |", grille[col][lgn]);
            else
                printf(" %c |", ' ');

        putchar('\n');
        putchar('+');

        for (col = 1; col <= coord1; ++col)
            printf("---+");

        putchar('\n');
    }

    for (col = 1; col <= coord1; ++col)
        printf("  %d ", col);

    putchar('\n');
}

 void calcule_position(int coup, struct position *pos,int coord1,int coord2) {
    /*
     * Traduit le coup joué en un numéro de colonne et de ligne.
     */

    int lgn;

    pos->colonne = coup;

    for (lgn = coord2 - 1; lgn >= 0; --lgn)
        if (grille[pos->colonne][lgn] == ' ') {
            pos->ligne = lgn;
            break;
        }
}

   unsigned calcule_nb_jetons_depuis_vers(struct position *pos, int dpl_hrz, int dpl_vrt, char jeton,int coord1, int coord2) {
    /*
     * Calcule le nombre de jetons adajcents identiques depuis une position donnée en se
     * déplaçant de `dpl_hrz` horizontalement et `dpl_vrt` verticalement.
     * La fonction s'arrête si un jeton différent ou une case vide est rencontrée ou si
     * les limites de la grille sont atteintes.
     */

    struct position tmp;
    unsigned nb = 1;

    tmp.colonne = pos->colonne + dpl_hrz;
    tmp.ligne = pos->ligne + dpl_vrt;

    while (position_valide(&tmp,coord1,coord2)) {
        if (grille[tmp.colonne][tmp.ligne] == jeton)
            ++nb;
        else
            break;

        tmp.colonne += dpl_hrz;
        tmp.ligne += dpl_vrt;
    }

    return nb;
}

 unsigned calcule_nb_jetons_depuis(struct position *pos, char jeton,int coord1,int coord2) {
    /*
     * Calcule le nombre de jetons adjacents en vérifant la colonne courante,
     * de la ligne courante et des deux obliques courantes.
     * Pour ce faire, la fonction calcule_nb_jeton_depuis_vers() est appelé à
     * plusieurs reprises afin de parcourir la grille suivant la vérification
     * à effectuer.
     */

    unsigned max;

    max = calcule_nb_jetons_depuis_vers(pos, 0, 1, jeton, coord1, coord2);
    max = umax(max, calcule_nb_jetons_depuis_vers(pos, 1, 0, jeton, coord1, coord2) +
                        calcule_nb_jetons_depuis_vers(pos, -1, 0, jeton, coord1, coord2) - 1);
    max = umax(max, calcule_nb_jetons_depuis_vers(pos, 1, 1, jeton, coord1, coord2) +
                        calcule_nb_jetons_depuis_vers(pos, -1, -1, jeton, coord1, coord2) - 1);
    max = umax(max, calcule_nb_jetons_depuis_vers(pos, 1, -1, jeton, coord1, coord2) +
                        calcule_nb_jetons_depuis_vers(pos, -1, 1, jeton, coord1, coord2) - 1);

    return max;
}

 int coup_valide(int col,int coord1,int coord2) {
    /*
     * Si la colonne renseignée est inférieure ou égal à zéro
     * ou que celle-ci est supérieure à la longueur du tableau
     * ou que la colonne indiquée est saturée
     * alors le coup est invalide.
     */

    if (col <= 0 || col > coord1 || grille[col - 1][0] != ' ')
        return 0;

    return 1;
}

 int demande_action(int *coup) {
    /*
     * Demande l'action à effectuer au joueur courant.
     * S'il entre un chiffre, c'est qu'il souhaite jouer.
     * S'il entre la lettre « Q » ou « q », c'est qu'il souhaite quitter.
     * S'il entre autre chose, une nouvelle saisie sera demandée.
     */

    char c;
    int ret = ACT_ERR;

    if (scanf("%d", coup) != 1) {
        if (scanf("%c", &c) != 1) {
            fprintf(stderr, "Erreur lors de la saisie\n");
            return ret;
        }

        switch (c) {
        case 'Q':
        case 'q':
            ret = ACT_QUITTER;
            break;
        default:
            ret = ACT_NOUVELLE_SAISIE;
            break;
        }
    } else
        ret = ACT_JOUER;

    if (!vider_tampon(stdin)) {
        fprintf(stderr, "Erreur lors de la vidange du tampon.\n");
        ret = ACT_ERR;
    }

    return ret;
}

 int grille_complete(int coord1,int coord2) {
    /*
     * Détermine si la grille de jeu est complète.
     */

    unsigned col;
    unsigned lgn;

    for (col = 0; col < coord1; ++col)
        for (lgn = 0; lgn < coord2; ++lgn)
            if (grille[col][lgn] == ' ')
                return 0;

    return 1;
}

 void initialise_grille(int coord1,int coord2) {
    /*
     * Initalise les caractères de la grille.
     */

    unsigned col;
    unsigned lgn;

    for (col = 0; col < coord1; ++col)
        for (lgn = 0; lgn < coord2; ++lgn) {
            if ((col == 0 && lgn == 0) ||
                (col == coord1 - 1 && lgn == 0) ||
                (col == 0 && lgn == coord2 - 1) ||
                (col == coord1 - 1 && lgn == coord2 - 1)) {
                grille[col][lgn] = 'W';
               
            } else {
                grille[col][lgn] = ' ';
            }
        }
        
        
        
   
        
        
        
}

 int position_valide(struct position *pos,int coord1,int coord2) {
    /*
     * Vérifie que la position fournie est bien comprise dans la grille.
     */

    int ret = 1;

    if (pos->colonne >= coord1 || pos->colonne < 0)
        ret = 0;
    else if (pos->ligne >= coord2 || pos->ligne < 0)
        ret = 0;

    return ret;
}

 int statut_jeu(struct position *pos, char jeton,int coord1,int coord2) {
    /*
     * Détermine s'il y a lieu de continuer le jeu ou s'il doit être
     * arrêté parce qu'un joueur a gagné ou que la grille est complète.
     */

    if (grille_complete(coord1,coord2))
        return STATUT_EGALITE;
    else if (calcule_nb_jetons_depuis(pos, jeton, coord1, coord2) >= 5)
        return STATUT_GAGNE;

    return STATUT_OK;
}

 unsigned umax(unsigned a, unsigned b) {
    /*
     * Retourne le plus grand des deux arguments.
     */

    return (a > b) ? a : b;
}

 int vider_tampon(FILE *fp) {
    /*
     * Vide les données en attente de lecture du flux spécifié.
     */

    int c;

    do
        c = fgetc(fp);
    while (c != '\n' && c != EOF);

    return ferror(fp) ? 0 : 1;
}

int main(void) {
    int statut;
    int coord1;
    int coord2;
    char jeton = J1_JETON;
    saisirCoordonnees(&coord1,&coord2);
    initialise_grille(coord1,coord2);
    affiche_grille(coord1,coord2);
    while (1) {
        struct position pos;
        int nbplayer;
        int action;
        int coup;
        int rotation;
        int P;
        int x;
        int y;
        int large;
        printf("A votre tour, joueur %d : ", (jeton == J1_JETON) ? 1 : 2);

        action = demande_action(&coup);
        
        if (action == ACT_ERR)
            return EXIT_FAILURE;
        else if (action == ACT_QUITTER)
            return 0;
        else if (action == ACT_NOUVELLE_SAISIE || !coup_valide(coup,coord1,coord2)) {
            fprintf(stderr, "Vous ne pouvez pas jouer ici\n");
            continue;
        }

        
        
        calcule_position(coup - 1, &pos,coord1,coord2);
        grille[pos.colonne][pos.ligne] = jeton;
        affiche_grille(coord1,coord2);
        
         saisieUtilisateur(coord1,coord2);
    printf("affichage apres rotation :\n");
         affiche_grille(coord1,coord2);
         descgrille(coord1,coord2);
         affiche_grille(coord1,coord2);
        
        
        
        statut = statut_jeu(&pos, jeton,coord1,coord2);

        if (statut != STATUT_OK)
            break;

        jeton = (jeton == J1_JETON) ? J2_JETON : J1_JETON;
    }

    if (statut == STATUT_GAGNE)
        printf("Le joueur %d a gagné !\n", (jeton == J1_JETON) ? 1 : 2);
    else if (statut == STATUT_EGALITE)
        printf("match nul, bien joué aux deux !\n");

    return 0;
}









