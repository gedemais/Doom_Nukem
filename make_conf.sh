#!/bin/bash

grep "o " $1 | cut -b 3- > $2 # Chope les noms d'objets dans le .obj

echo "# Format : example|{0, 0, 0}|[0, 0, 0]|true/false|(path/img.xpm)" > tmp
echo "#          nom     position  vitesse   static/not texture_path" >> tmp
echo "# champ vide : valeur inchangee / 0 0 0" >> tmp
cat $2 | sed -e 's/$/|{}|[]|true|()/' >> tmp

cat tmp > $2 # rajoute un pipe a la fin de la ligne
