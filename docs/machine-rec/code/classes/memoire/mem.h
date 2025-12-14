#ifndef __MEM_H__
#define __MEM_H__

#include "../inode/inode.h"
#include <stdint.h>

typedef class hdd_p{
    public:
        virtual ~hdd_p() = default;

        virtual uint get_taille() = 0;
        virtual void modifier_logiciel(int depart_modif, bloc_mem int_list) = 0;
        virtual void ajouter_logiciel() = 0;
        virtual inode_logiciel lire_logiciel() = 0;
}* hdd;

hdd init_hdd();

void free_hdd();

#endif