#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000

void find_in_file(const char *filename, const char *word) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    char line[MAX];
    int line_number = 0;  // Initialiser le compteur de lignes
    int found = 0;  // Variable pour vérifier si le mot a été trouvé

    while (fgets(line, MAX, file) != NULL) {
        line_number++;  // Incrémenter le compteur de lignes
        if (strstr(line, word) != NULL) {
            printf("Ligne %d: %s", line_number, line);  // Afficher le numéro de ligne et la ligne
            found = 1;
        }
    }
    if (!found) {
        printf("Mot '%s' non trouvé dans le fichier '%s'.\n", word, filename);
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename> <word>\n", argv[0]);
        return 1;
    }
    printf("Recherche du mot '%s' dans le fichier '%s'...\n", argv[2], argv[1]);
    find_in_file(argv[1], argv[2]);
    return 0;
}
