#include <stdio.h>
#include <stdlib.h>
typedef struct neoud
{
    int donnee;
    struct neoud *gauche,*droite;
}neoud;

neoud* creeNeoud(int donne){
    neoud* neoud = malloc(sizeof(*neoud));

    neoud->donnee=donne;
    neoud->gauche=neoud->droite=NULL;
    return neoud;
}
neoud *creeArbre(neoud* neoud){
    return NULL;
}
neoud* insererElement(neoud* racine,int donnee){
    if (racine == NULL)
    {
    return creeNeoud(donnee);
    }
    if (donnee < racine->donnee)
    {
        racine->gauche = insererElement(racine->gauche, donnee);
    }else if (donnee >racine->donnee)
    {
        racine->droite = insererElement(racine->droite, donnee);
    }
    return racine;
    
    
    
}
void supprimerArbre(neoud *racine){
    if (racine != NULL)
    {
        supprimerArbre(racine->gauche);
        supprimerArbre(racine->droite);
        free(racine);
    }
    
}
int hauteurArbre(neoud* racine){
    if (racine == NULL)
    {
        return 0;
    }
    int hauteurgauche = hauteurArbre(racine->gauche);
    int hauteurdroit = hauteurArbre(racine->droite);
    return (hauteurgauche > hauteurdroit ? hauteurdroit : hauteurgauche);  
}
int tailleArbre(neoud *racine){
    if (racine == NULL)
    {
        return 0;
    }
    return tailleArbre(racine->gauche) + tailleArbre(racine->droite)+1;
}
int nombreNeoudInterne(neoud* racine){
    if(racine == NULL || (racine->gauche == NULL && racine->droite == NULL))
    return 0;
    return nombreNeoudInterne(racine->gauche) + nombreNeoudInterne(racine->droite)+1;
}
int nombreNeoudExterne(neoud* racine){
    if (racine == NULL) return 0;
    if (racine->gauche == NULL && racine->droite)
    {
        return 1;
    }
    return nombreNeoudExterne(racine->gauche)+nombreNeoudExterne(racine->droite);    
}
void parcoursPrefixe(neoud* racine){
    if (racine != NULL)
    {
      printf("%d",racine->donnee);
      parcoursPrefixe(racine->gauche);
      parcoursPrefixe(racine->droite);
    }
    
}
void parcoursInfixe(neoud* racine){
    if (racine != NULL)
    {
        parcoursInfixe(racine->gauche);
        printf("%d",racine->donnee);
        parcoursInfixe(racine->droite);
    }
}
void parcoursPostfixe(neoud* racine){
    if (racine != NULL)
    {
        parcoursPostfixe(racine->gauche);
        parcoursPostfixe(racine->droite);
        printf("%d",racine->donnee);
    } 
}
int rechercherElement (neoud* racine,int donnee){
    if (racine == NULL) return 0;
    if (donnee == racine->donnee) return 1;
    if ( donnee < racine->donnee) return rechercherElement(racine->gauche,donnee);
    else rechercherElement(racine->droite,donnee); 
}
neoud* pluspetitElement(neoud* racine){
    neoud* current = racine;
    while (current && current->gauche != NULL)
    {
        current = current->gauche;
    }
    return current;
}
neoud* plusGrandElement(neoud* racine){
        neoud* current = racine;
        while (current && current->droite !=NULL)
              current =current->droite;
        return current;
}
neoud* supprimerElement(neoud* racine,int donnee){
    if(racine == NULL) return racine;
    if(donnee < racine->donnee) racine->gauche = supprimerElement(racine->gauche,donnee);
  else if(donnee > racine->donnee) racine->droite = supprimerElement(racine->droite,donnee);
  else
  {
    if (racine->gauche == NULL)
    {
        neoud* temp =racine->droite;
        free(racine);
        return temp;
    }else if (racine->droite == NULL)
    {
        neoud* temp = racine->gauche;
        free(racine);
        return temp;
    }
    neoud* temp = pluspetitElement(racine->droite);
    racine->donnee = temp->donnee;
    racine->droite = supprimerElement(racine->droite,temp->donnee);
        
  }
  return racine;
}
void afficherArbre(neoud* racine, int espace,int niveau){
    if(racine == NULL)
    return;
espace += 10;
afficherArbre(racine->droite, espace, niveau + 1);
printf("\n");
int i;
for (i = 10; i < espace; i++){
    printf(" ");
}
printf("%d\n", racine->donnee);
afficherArbre(racine->gauche, espace, niveau + 1);
}
int main(){
    neoud* racine = creeArbre(racine);
    racine = insererElement(racine, 50);
    racine = insererElement(racine, 30);
    racine = insererElement(racine, 20);
    racine = insererElement(racine, 40);
    racine = insererElement(racine, 70);
    racine = insererElement(racine, 60);
    racine = insererElement(racine, 80);
    printf("parcour Infixe:");
    parcoursInfixe(racine);
    printf("\n");
    printf("hautaur de l'arbre :%d\n",hauteurArbre(racine));
    printf("Taille de l'arbre :%d\n",tailleArbre(racine));
    printf("Nombre de neoude internes : %d\n", nombreNeoudInterne(racine));
    printf("Nombre de neoudes Externes : %d\n", nombreNeoudExterne(racine));
    printf("le plus petit element :%d\n", pluspetitElement(racine)->donnee);
    printf("le plus grand element :%d\n", plusGrandElement(racine)->donnee);
    if(rechercherElement(racine,40))
    printf("Element 40 trouve dans l'arbre.\n");
else 
    printf("Element 40 non trouve dans l'arbre.\n");
printf("l'Affichage de l'arbre binaire: \n");
afficherArbre(racine, 0, 0);
supprimerElement(racine, 70);
printf("affichage de l'arbre binaaire apres la supression de 70:\n");
afficherArbre(racine, 0, 0);
supprimerArbre(racine);
return 0;
   
}
