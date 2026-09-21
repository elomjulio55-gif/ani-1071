# Compilations
- *Pour la compilation avec clang++* j'ai utilise la commande : `clang++ -std=c++17 -Wall c1-demo3_reponse.cpp -o prog_clpp`
- le code de sortie (`echo $LASTEXITCODE`) apres le lancement du programme (`./prog_clpp`) est : 
```
0
```
- Et le resultat apres compilation est :
```
message 1
message 2
message 3
message 4
```
- *Pour la compilation avec g++* j'ai utilise la commande : `g++ -std=c++17 -Wall c1-demo3_reponse.cpp -o prog_gpp`
- le code de sortie(`echo $LASTEXITCODE`) apres le lancement du programme(`./prog_gpp`)  est : 
```
0
```
- Et le resultat apres compilation est :
```
message 1
message 2
message 3
message 4
```
# Comparaison
- Pour determiner la taille des executable j'ai simplement urilise la commande: `dir prog_clpp.exe, prog_gpp.exe` j'ai obtenu comme resultat :
```
Répertoire : C:\Users\Utilisateur\ani-1071\chapitre-01\demo3-le_meme_source_deux_compilateurs


Mode                 LastWriteTime         Length Name                                                                                                    
----                 -------------         ------ ----                                                                                                    
-a----         9/21/2026   3:44 AM          72581 prog_clpp.exe                                                                                           
-a----         9/21/2026   3:45 AM          73662 prog_gpp.exe  
```
# Conclusion
On peut voir que la compilation g++ est plus lourde (73662 octets) par rapport a la compilation en clang++(72581 octets). De ce fait on comprend que le langage C++ ne garantit pas la taille de l'executable mais garantit par contre le resultat du programme (si ton programme est correcte et rspecte les regles du standart C++)