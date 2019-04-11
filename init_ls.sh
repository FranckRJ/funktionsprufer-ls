#!/bin/bash

getProgFiles="true"
makeTests="true"
progPath="../ft_ls"
progPathIsCustom="false"

function print_help
{
read -r -d '' HELP_TEXT << EOM
DESCRIPTION:
Recupere et compile ft_ls pour les tests de test-ls.

LISTE DES COMMANDES:
<chemin_vers_ls>          Specifie le chemin vers ls (le dossier contenant
                          le Makefile et les sources etc).
                          Ne peut etre specifie qu'une seule fois, autrement une erreur se produit.
--nogetls                 Ne recupere pas les fichiers du dossier ls.
--nomake                  N'execute pas make a la fin du script.
-h / --help               Affiche cette page d'aide.
EOM

echo "$HELP_TEXT"
}

for param in "$@"; do
	if [[ "$param" =~ ^--.* ]]; then
		if [[ "$param" == "--nogetls" ]]; then
			getProgFiles="false"
		elif [[ "$param" == "--nomake" ]]; then
			makeTests="false"
		elif [[ "$param" == "--help" ]]; then
			print_help
			exit 0
		else
			echo "Erreur: parametre $param inconnu. Utilisez --help pour afficher l'aide."
			exit 0
		fi
	elif [[ "$param" =~ ^-.* ]]; then
		if [[ "$param" == "-h" ]]; then
			print_help
			exit 0
		else
			echo "Erreur: parametre $param inconnu. Utilisez --help pour afficher l'aide."
			exit 0
		fi
	fi
done

for param in "$@"; do
	if [[ ! "$param" =~ ^-.* ]]; then
		if [[ "$progPathIsCustom" == "false" ]]; then
			progPath="$param"
			progPathIsCustom="true"
		else
			echo "Trop d'arguments, le chemin de ls ne peut etre initialise qu'une fois. Utilisez --help pour afficher l'aide."
			exit 0
		fi
	fi
done

if [[ "$getProgFiles" == "true" ]]; then
	rm -rf "ft_ls"
	cp -R "${progPath}" "ft_ls"
	make -C ft_ls re
fi
if [[ "$makeTests" == "true" ]]; then
	make -j4 re
fi
