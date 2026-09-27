# Nombre de tours
### Cas du PGCD(1071,462)
Apres la compilation de mon programme a travers la commande(`clang++ -std=c++17 -Wall c2-exo18_main.cpp -o programme`) et apres son execution (`./programme`) on obtient:
- *PAR LA METHODE DE SOUSTRACTION* le message suivant :
```
Par la methode de soustraction, le PGCD(1071,462)est egale a21Ce resultat a ete trouve apres11tours.
```
avec la methode de soustraction on a effectue 11 tours 
- *PAR LA METHODE DE DIVISION L'AGORITHME D'EUCLIDE* le message suivant :
```
Par la methode de divisions, le PGCD(1071,462)est egale a21Ce resultat a ete trouve apres3tours.
```
avec la methode de l'algorithme d'Euclide on a effectue 3 tours 

### Cas du PGCD(1000000,1)
- *PAR LA METHODE DE SOUSTRACTION* le message suivant :
```
Par la methode de soustraction, le PGCD(1000000,1)est egale a1Ce resultat a ete trouve apres999999tours.
```
avec la methode de soustraction on a effectue 999999 tours 

- *PAR LA METHODE DE DIVISION L'AGORITHME D'EUCLIDE* le message suivant :
```
Par la methode de divisions, le PGCD(1000000,1)est egale a1Ce resultat a ete trouve apres1tours.
```
avec la methode de l'algorithme d'Euclide on a effectue 1 tour. 

# Conclusion
On remarque que les deux methodes utilisees pour determiner le PGDC de deux nombres produisent le meme resultat; Aussi que la soustraction quand il s'agit de nombre proche, est gerable mais quand l'ecart est grand entre les deux nombres elle devient peu performante car elle doit repete l'opration de soustraction autant de fois ppour rapprocher au maximum les deux nombres. Tandis que l'algorithme d'Euclide qui est beaucoup plus efficace car il remplace juste le plus grand nombre avec le reste de la division ce qui permet d'etre plus perfomant et rapide que la soustraction.