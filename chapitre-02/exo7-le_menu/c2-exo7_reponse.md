# Resultat
pour l'affichage du menu, apres compilation et execution du programme on obtient:
```
----MENU----
1. Nouvelle partie
2. Charger
3. Options
4. Quitter
Selectionez une option : 
```
- Si j'entre le chiffre 3 le resultat du programme est:
```
Selectionez une option : 3
-> Bienvenue dans les options
```
- Si j'entre un chiffre ne figurant pas dans le menu (par exemple 6) le resultat du programme est:
```
Selectionez une option : 6
Choix non disponible
```
### Ce qui change
En retirant le break du *case 1* et en relancant le programme on obtient :
```
----MENU----
1. Nouvelle partie
2. Charger
3. Options
4. Quitter
Selectionez une option : 1
-> Nouvelle partie lancee
-> Chargement de la sauvegarde en cours
```
On remarque directement que les instructions se sont enchainees et ce sont arretees au *case 2*. Ce qui a change c'est que avant quand on selctionnais une option (par exemple 1) on se limitait au bloc d'instruction la concernant puis on sortait du programme. Mais avec l'absence de *break* dans le *case 1*, on traite le *case 1*, le *case 2* puis on sors du programme parcequ'il y a un Break.