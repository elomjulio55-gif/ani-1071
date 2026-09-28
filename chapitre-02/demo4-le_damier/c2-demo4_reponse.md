# L'expression
`(x/4 + y/2 % 2 == 0 ? '#': ' ');`
## Explications
A partir de l'enonce et des informations indiquees on peut comprendre que il y a 16 lignes(2*8) comprenant chacunes 32 caracteres(4*8) sachant qu'un caractere peut etre un "#" ou un espace (' ').
- x ici designe le numero du caractere (de 0 a 31) et y le numero de la ligne (de 0 a 15)
- x/4 va permettre de determiner le numero de la colonne corcerne par le numero du caractere:
par exemple: comme on sait que dans chaque case il ya 4 caracters sur la largeur c'est a dire que dans la case 1 on a les carcteres 0 1 2 3 4 dans la case 2 on a 5 6 7 8 ...etc En faisant x/4 retourne uniquement des valeurs entiere allant de 0 a 7
-y/2 va permettre de determiner plus tot la ligne
Maintenant pour savoir dequel caractere il s'agitil faudrait effectuer une somme des cordonnes colonne + ligne et si le resultat est *pair* alors il s'agit d'un "#" dans le cas contraire il s'agit d'un espace ' ' D'ou l'expression `(x/4 + y/2 % 2 == 0 ? '#': ' ');`
## Le resultat du programme 
apres compilation et execution on obtient:
```
####    ####    ####    ####    
####    ####    ####    ####    
    ####    ####    ####    ####
    ####    ####    ####    ####
####    ####    ####    ####    
####    ####    ####    ####    
    ####    ####    ####    ####
    ####    ####    ####    ####
####    ####    ####    ####    
####    ####    ####    ####    
    ####    ####    ####    ####
    ####    ####    ####    ####
####    ####    ####    ####    
####    ####    ####    ####    
    ####    ####    ####    ####
    ####    ####    ####    ####
    ```