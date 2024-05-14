# BSQ 42
Vas-tu trouver le plus grand carré ?

Le code est améliorable, ceci est une version fonctionelle et normée.

## Trouver le plus grand carré de la map
programme `bsq`:
```sh
./bsq foo
```

## Générer une map
script Perl `board.pl`:
```sh
./board.pl [TAILLE_LINES] [NOMBRE_LINES] [DENSITE] > foo
```

## Commandes make
Compiler le projet:
```sh
make
```
Supprimer les fichiers .o:
```sh
make clean
```
Supprimer le programme et les fichiers .o:
```sh
make fclean
```