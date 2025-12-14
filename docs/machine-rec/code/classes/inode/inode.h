#ifndef __INODE_H__
#define __INODE_H__

#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>


typedef struct bloc_mem_s* bloc_mem;

typedef struct inode_logiciel_s* inode_logiciel;
typedef struct inode_principal_s* inode_principal;

/*
*/
bloc_mem cree_bloc_mem();

/*
*/
void ajouter_bit_bloc(bloc_mem* bl, bool bit);

/*
*/
bool est_vide_bloc(bloc_mem bl);

/*
*/
bool acceder_tete_bloc(bloc_mem bl);

/*
*/
bloc_mem acceder_queue_bloc(bloc_mem bl);

/*
*/
void free_bloc(bloc_mem bl);


/*
*/
inode_logiciel cree_logiciel (char nom);

/*
*/
bool logiciel_vide(inode_logiciel log);

/*
*/
void ajouter_bit(inode_logiciel log, bool entier);

/*
*/
void reintialiser_etat_logiciel(inode_logiciel log);

/*
*/
bool acceder_bit_n(inode_logiciel log, int n);

/*
*/
bool continuer_lecture_logiciel(inode_logiciel log);

/*
*/
void free_position_actuelle_logiciel(inode_logiciel log);

/*
*/
void free_log(inode_logiciel log);





/*
*/
inode_principal cree_dep_mem();

/*
*/
bool aucun_logiciel(inode_principal in);

/*
*/
void ajouter_logiciel(inode_principal in, inode_logiciel log);

/*
*/
void reintialiser_etat_inode(inode_principal in);

/*
*/
inode_logiciel lire_nieme_logiciel(inode_principal in, int n);

/*
*/
inode_logiciel continuer_lecture_inode(inode_principal in);

/*
*/
void free_position_actuelle_inode(inode_principal in);

/*
*/
void free_in(inode_principal in);

#endif