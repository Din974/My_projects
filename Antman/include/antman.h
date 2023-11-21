/*
** EPITECH PROJECT, 2021
** antman
** File description:
** antman
*/

#ifndef ANTMAN_H_
#define ANTMAN_H_

typedef struct text_file {
    char *data;
    unsigned char data_match;
    struct text_file *next;
}text_t;

typedef struct ppm_list_s {
    char *nb;
    struct ppm_list_s *next;
} ppm_list_t;

typedef struct ppm_s {
    int i;
    int j;
    int count;
    char *cmp;
} ppm_t;

typedef struct dppm_s {
    int i;
    int count;
    int check;
} dppm_t;

typedef struct html_s {
    char *word;
    char key;
    struct html_s *next;
} html_t;

void compress_lyrics(char *file);
void my_put_in_list(text_t **list, char *new_data, unsigned char letter_match);
int check_filetype(char *filetype);
void antman(char *file, char type);
void compress_ppm(char *file);
void giantman(char *file, char type);
void decompress_ppm(char *file);
void decompress_lyrics(char *file);
char *conv_new_line(char *file);
char *my_strcat_char(char *str, char c);
int contain(char *str, char c);
void compress_html(char *file);
void decompress_html(char *file);
ppm_t check_first_nb(ppm_t ppm, char **tab);
dppm_t get_single_nb(dppm_t dppm, char *file);

#endif /* !ANTMAN_H_ */