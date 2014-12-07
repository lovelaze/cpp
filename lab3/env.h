#ifndef ENV_H
#define ENV_H

#include <string>
#include "character.h"
#include "item.h"

namespace adventure {

    class Env {

    public:
        Env();
        virtual ~Env();

        virtual void directions() = 0;
        virtual void neighbor(int direction) = 0;
        virtual void description() = 0;
        virtual bool enter(Character &) = 0;
        virtual bool leave(Character &) = 0;
        virtual bool pick_up(Item &) = 0;
        virtual bool drop(Item &) = 0;


    protected:
        std::string description_;

    };


}



#endif