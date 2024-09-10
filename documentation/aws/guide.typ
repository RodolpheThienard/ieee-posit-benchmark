= Guide d'utilisation RacEr sur AWS

== Mise en route du serveur et connexion
- Aller sur le site AWS et sélectionner instances.
- Sélectionner l'instance à démarrer et faire "État de l'instance" puis "Démarrer l'instance"
#image("images/connexion1.png")

- Copier l'adresse IP de l'instance visible en dessous (DNS IPv4 public)
#image("images/connexion2.png")

- Se connecter à l'aide d'un terminal en utilisant la commande suivante : 
```sh ssh centos@IPV4``` et remplacer l'IPV4 par celle obtenue dans AWS, ici ``.


== Compilation et exécution<compilation>

Pour faire fonctionner une application il faut faire 2 compilations.
La première consiste à compiler la partie qui sera exécutée sur le device (FPGA) avec les coeurs Posit et la seconde est de compiler la partie hôte depuis laquelle le code sera lancé.

- Emplacement du code du device : ``
- Commande de compilation du kernel : `make main.riscv`
- Sortie d'exemple attendue : 
#image("images/compilation1.png")



- Emplacement du code de l'hôte : ``
- Commande de compilation et d'exécution du programme : `make regression`. Pour sélectionner quelle code sera exécuté lors de la régression, il faut commenter ou dé-commenter les applications choisies.

#image("images/compilation2.png")


== Application custom
Pour faire un portage ou pour le développement d'une application, utiliser la documentation disponible dans `documentation/racer/documentation.pdf`

Pour la compilation d'une application custom, faire une copie des fichiers dans les emplacements comme pour la partie précédante et compiler de la même manière. 

Il est conseillé d'utiliser le dossier custom, `custom_kernel` disponible dans le repertoire.
Modifier les noms "custom_kernel" aux endroits suivants :
- nom de dossier
- fichier custom_kernel.c
  - nom de la fonction
  - nom du fichier
- Makefile
  - KERNEL_NAME
  - OBJECT_FILES

Il faut ensuite mettre le kernel dans le dossier où sont les kernels et le compiler voir le @compilation

Pour la partie de l'hôte, faire la même chose en utilisant le dossier `custom_main`
Modifier les noms "custom_main" aux endroits suivants :
- nom des fichiers
- nom de la fonction
- modifier le nom de la fonction kernel appelée dans la fonction : `RacEr_mc_kernel_enqueue`
