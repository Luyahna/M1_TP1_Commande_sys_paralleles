# M1_TP1_Commande_sys_paralleles
Multithreading C \
Thème : Fournisseurs / Boulangers

# Présentation 
Soit un système composé de trois processus boulangers et d’un processus fournisseur. Chaque boulanger pétrit continuellement son pain et le cuit. Pour pouvoir pétrir le pain, trois ingrédients sont nécessaires : la farine, l’eau et la levure. Un des processus boulangers détient la farine, le deuxième processus l’eau et le troisième la levure. Le processus fournisseur a un approvisionnement infini des trois ingrédients. Le fournisseur place deux ingrédients distincts sur la table de sorte que le boulanger qui possède le troisième ingrédient peut pétrir son pain, le cuire puis signaler au fournisseur la fin de son opération. Le fournisseur remet sur la table deux autres ingrédients et ainsi le cycle se répète.

# Cahier des charges partie 1 
- Fournir un fichier .c, .h et un makefile en partant de zéro. \
  \
- Un thread représentant le fournisseur qui distribue de manière aléatoire les ingrédients aux boulangers. A chaque envoi, le thread doit préciser quels ingrédients ont été envoyés et vers quel boulanger. Le fournisseur doit se mettre en attente tant qu’il n’a pas reçu de validation de fin de travail de la part d’un des boulangers. \
  \
- Trois threads, représentants chacun des boulangers, qui doivent indiquer quand ils ont reçu les ingrédients quand c’est à leur tour et indiquer qu’ils sont en attente sinon. Ils doivent également indiquer quand ils ont terminé leur pain et prévenir le fournisseur qui peut alors renvoyer de nouveaux ingrédients. L’action de pétrir le pain dure 0.3s et de le cuire 0.7s. \
  \
- On considère que le programme se termine lorsque un total de 5 pains (tous boulangers confondus) ont été pétris et cuits et que le fournisseur a été averti pour la dernière fois. \
  \
- Les threads doivent être synchronisés.

# Cahier des charges partie 2 (Bonus)
Il s’agit de modifier l’implémentation précédente afin que plusieurs boulangers puissent travailler en même temps car le fournisseur n’attend plus leur retour pour approvisionner mais approvisionne en continu dans trois buffers de taille 5 (paires d’ingrédients) alloués à chaque boulanger. Si l’un (ou plus) des buffers est plein et que le fournisseur souhaite y mettre une paire d’ingrédient, il doit jeter les ingrédients et en générer des nouveaux (ainsi de suite jusqu’à ce qu’il puisse remplir un buffer). Les boulangers viennent se servir dans leur buffer respectif dans le cas ou la paire d’ingrédient qu’il leur manque y est. Sinon ils se mettent en attente. La condition d’arrêt de l’algorithme est à 10 pains dans ce cas.

