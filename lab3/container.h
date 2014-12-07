#ifndef CONTAINER_H
#define CONTAINER_H

#include "item.h"

namespace adventure {

    class Container : public Item {
    public:
        Container();
        virtual ~Container();

        virtual int hold_weight() = 0;
        virtual int hold_volume() = 0;
        virtual bool add(Item &) = 0;
        virtual bool remove(Item &) = 0;


    protected:
        int hold_weight_;
        int hold_volume_;

        // objects


    };


}


#endif