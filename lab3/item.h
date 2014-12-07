#ifndef ITEM_H
#define ITEM_H

namespace adventure {

    class Item {

    public:

        Item();
        virtual ~Item();


        virtual int weight() = 0;
        virtual int volume() = 0;
        virtual int price() = 0;

    protected:

        int weight_;
        int volume_;
        int price_;

    };
}


#endif