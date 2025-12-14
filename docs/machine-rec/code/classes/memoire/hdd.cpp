#include "mem.h"

class hdd_c : public hdd_p {
    private :
        inode_principal fiche_mem;
        unsigned long taille;
    public :
        hdd_c();

        uint get_taille() override;
        void modifier_logiciel(int depart_modif, bloc_mem int_list) override;
        void ajouter_logiciel() override;
        inode_logiciel lire_logiciel() override;      

};

hdd_c::hdd_c(){
    fiche_mem = cree_dep_mem();
    taille = 16777216;
}

uint hdd_c::get_taille(){
    return taille;
}

int long get_taille(bloc_mem logiciel){
    if(est_vide_bloc(logiciel)){
        return 0;
    }
    else{
        return 1 + get_taille(get_s)
    }
}

