#include "inode.h"
#include <assert.h>
#include <stdlib.h>

struct bloc_mem_s{
    bool bit;
    struct bloc_mem_s* suite;
};


struct inode_logiciel_s{
    char nom;
    int taille;
    bloc_mem debut;
    bloc_mem fin;
    bloc_mem position_act;
};

struct liste_inodes_s{
    inode_logiciel tete;
    struct liste_inodes_s* queue;
};
typedef struct liste_inodes_s* liste_inodes;

struct inode_principal_s{
    int nombre_inodes;
    liste_inodes debut;
    liste_inodes fin;
    liste_inodes position_act;
};




bloc_mem cree_bloc_mem(){
    return NULL;
}

void ajouter_bit_bloc(bloc_mem* bl, bool bit){
    bloc_mem res = malloc(sizeof(struct bloc_mem_s));
    assert(res != NULL);
    res->bit = bit;
    res->suite = *bl;
    *bl = res; 
}

bool est_vide_bloc(bloc_mem bl){
    return bl == NULL;
}

bool acceder_tete_bloc(bloc_mem bl){
    assert(bl != NULL);
    return bl->bit;
}

bloc_mem acceder_queue_bloc(bloc_mem bl){
    assert(bl != NULL);
    return bl->suite;
}

void free_bloc(bloc_mem bl){
    if (bl != NULL){
        free_bloc(bl->suite);
        free(bl);
    }
}




inode_logiciel cree_logiciel(char nom){
    inode_logiciel log = malloc(sizeof(struct inode_logiciel_s));
    assert(log != NULL);

    log->nom = nom;
    log->taille = 0;
    log->debut = cree_bloc_mem();
    log->fin = log->debut;
    log->position_act = log->debut;

    return log;
}

bool logiciel_vide(inode_logiciel log){
    assert(log != NULL);
    return log->taille == 0;
}

void ajouter_bit(inode_logiciel log, bool entier){
    assert(log != NULL);

    ajouter_bit_bloc(&(log->fin), entier);

    if (log->taille == 0){
        log->debut = log->fin;
        log->position_act = log->debut;
    }
    log->taille += 1;

}

void reintialiser_etat_logiciel(inode_logiciel log){
    assert(log != NULL);
    log->position_act = log->debut;
}

bool acceder_bit_n_aux(inode_logiciel log, int n){
    switch (n) {
        case 0 :
            return log->position_act->bit;
        default:
            log->position_act = log->position_act->suite;
            return acceder_bit_n_aux(log, n-1);
    }
}




bool acceder_bit_n(inode_logiciel log, int n){
    assert(log != NULL && 0 <= n && n < log->taille);

    log->position_act = log->debut;
    bool res = acceder_bit_n_aux(log, n);
    log->position_act = log->debut;

    return res;
}

bool continuer_lecture_logiciel(inode_logiciel log){
    assert(log != NULL && log->position_act != NULL);
    bool ret = log->position_act->bit;
    log->position_act = log->position_act->suite;
    return ret;
}

bloc_mem trouve_dernier_log(bloc_mem debut){
    if(debut == NULL){
        return NULL;
    }
    else if (debut->suite == NULL){
        return debut;
    }
    else{
        return trouve_dernier_log(debut->suite);
    }
}

int taille_bloc(bloc_mem bl){
    if(bl == NULL){
        return 0;
    }
    else{
        return 1 + taille_bloc(bl->suite);
    }
}

void free_position_actuelle_logiciel(inode_logiciel log){
    assert(log != NULL);
    if (log->position_act == NULL){
        log->position_act = log->debut;
    }
    else if (log->fin != NULL){
        log->taille -= taille_bloc(log->position_act);
        free_bloc(log->position_act);
        log->fin = trouve_dernier_log(log->debut);
        log->position_act = log->debut;
    }
}

void free_log(inode_logiciel log){
    if(log != NULL){
        free_bloc(log->debut);
        free(log);
    }
}







liste_inodes cree_liste_log(){
    return NULL;
}

void ajouter_log_liste(liste_inodes* ll, inode_logiciel log){
    liste_inodes res = malloc(sizeof(struct liste_inodes_s));
    assert(res != NULL);
    res->tete = log;
    res->queue = *ll;
    *ll = res; 
}

inode_logiciel acceder_tete_log(liste_inodes ll){
    assert(ll != NULL);
    return ll->tete;
}

liste_inodes acceder_queue_log(liste_inodes ll){
    assert(ll != NULL);
    return ll->queue;
}

void free_inode_liste(liste_inodes ll){
    if (ll != NULL){
        free_inode_liste(ll->queue);
        free(ll);
    }
}






inode_principal cree_dep_mem(){
    inode_principal res = malloc(sizeof(struct inode_principal_s));
    assert(res != NULL);

    res->nombre_inodes = 0;
    res->debut = NULL;
    res->position_act = NULL;
    res->fin = NULL;

    return res;
}

bool aucun_logiciel(inode_principal in){
    assert(in != NULL);
    return in->debut = NULL;
}

void ajouter_logiciel(inode_principal in, inode_logiciel log){
    assert(in != NULL);

    ajouter_log_liste(&(in->fin), log);

    if (in->nombre_inodes == 0){
        in->debut = in->fin;
        in->position_act = in->debut;
    }
    in->nombre_inodes += 1;
}

inode_logiciel parcours_inode_lecture_aux(inode_principal in, int n){
    switch (n){
        case 0:
            return in->position_act->tete;
        default:
            in->position_act = in->position_act->queue;
            return lire_nieme_logiciel(in, n-1);
    }
}

inode_logiciel lire_nieme_logiciel(inode_principal in, int n){
    assert(in != NULL && 0 <= n && n < in->nombre_inodes);

    in->position_act = in->debut;
    inode_logiciel res = parcours_inode_lecture_aux(in, n);
    in->position_act = in->debut;

    return res;
}

void reintialiser_etat_inode(inode_principal in){
    assert(in != NULL);
    in->position_act = in->debut;
}

bool lecture_possible_inode(inode_principal in){
    assert(in != NULL);
    return in->position_act == NULL;
}

inode_logiciel continuer_lecture_inode(inode_principal in){
    assert(in != NULL);
    if(lecture_possible_inode(in)){
        inode_logiciel res = in->position_act->tete;
        in->position_act = in->position_act->queue;
        return res;
    }
    return NULL;
}

liste_inodes trouve_dernier_in(liste_inodes debut){
    if(debut == NULL){
        return NULL;
    }
    else if (debut->queue == NULL){
        return debut;
    }
    else{
        return trouve_dernier_in(debut->queue);
    }
}

int taille_lst_in(liste_inodes lst_inode){
    if(lst_inode == NULL){
        return 0;
    }
    else{
        return 1 + taille_lst_in(lst_inode->queue);
    }
}


void free_position_actuelle_inode(inode_principal in){
    assert(in != NULL);
    if (in->position_act == NULL){
        in->position_act = in->debut;
    }
    else if (in->fin != NULL){
        in->nombre_inodes -= taille_lst_in(in->position_act);
        free_inode_liste(in->position_act);
        in->fin = trouve_dernier_in(in->debut);
        in->position_act = in->debut;
    }
}

void free_in(inode_principal in){
    if (in != NULL){
        free_inode_liste(in->debut);
        free(in);
    }
}
