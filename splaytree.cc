
#include "splaytree.h"
#include <iostream>

using std::cout;
using std::endl;


#define DEBUG
#define CALL cout << __PRETTY_FUNCTION__ << endl;

void splaytree::add(child c, splaytree* child ){

    if(c == left){
        _l = child;
    }
    else if(c == right){
        _r = child;
    }
    if(child != NULL){
        child->_p = this;
    }

}

void splaytree::take_care_of_great_grand_parents(splaytree* g, splaytree* gg, splaytree* x) {
    // We should all take good care of our great grandparents!

    if(gg == NULL){
        x->_p = NULL;
    }else{
        if (g == gg->_l) {
            gg->add(left, x);
        } else {
            gg->add(right, x);
        }
    }
}

splaytree::splaytree(int d){

    _d = d;
    _l = NULL;
    _r = NULL;
    _p = NULL;
}

splaytree* splaytree::insert(splaytree* v){

    if(v->_d <= _d ){
        if(_l == NULL){
            _l = v;
            v->_p = this;
        }
        else{
            _l->insert(v);
        }
    }
    else{
        if(_r == NULL){
            _r = v;
            v->_p = this;
        }
        else{
            _r->insert(v);
        }
    }

    return splay(v);
}

splaytree* splaytree::l_zig(splaytree* x){
#ifdef DEBUG
    CALL
#endif

        splaytree* p = x->_p;
    splaytree* a = x->_l;
    splaytree* b = x->_r;
    splaytree* c = p->_r;

    x->_p = p->_p;

    x->add(left, a);
    x->add(right, p);
    p->add(left, b);
    p->add(right, c);

    return x;
}

splaytree* splaytree::r_zig(splaytree* x){
#ifdef DEBUG
    CALL
#endif

        splaytree* p = x->_p;
    splaytree* a = p->_l;
    splaytree* b = x->_l;
    splaytree* c = x->_r;

    x->_p = p->_p;

    x->add(left, p);
    x->add(right, c);
    p->add(left, a);
    p->add(right, b);

    return x;
}

splaytree* splaytree::l_zigzig(splaytree* x){
#ifdef DEBUG
    CALL
#endif
        splaytree* p = x->_p;
    splaytree* g = p->_p;
    splaytree* gg = g->_p;

    splaytree* a = x->_l;
    splaytree* b = x->_r;
    splaytree* c = p->_r;
    splaytree* d = g->_r;


    take_care_of_great_grand_parents(g, gg, x);

    x->add(left, a);
    x->add(right, p);

    p->add(left, b);
    p->add(right, g);

    g->add(left, c);
    g->add(right, d);

    return x;
}

splaytree* splaytree::r_zigzig(splaytree* x){
#ifdef DEBUG
    CALL
#endif
        splaytree* p = x->_p;
    splaytree* g = p->_p;
    splaytree* gg = g->_p;

    splaytree* a = g->_l;
    splaytree* b = p->_l;
    splaytree* c = x->_l;
    splaytree* d = x->_r;

    take_care_of_great_grand_parents(g, gg, x);

    x->add(left, p);
    x->add(right, d);

    p->add(left, g);
    p->add(right, c);

    g->add(left, a);
    g->add(right, b);

    return x;
}

splaytree* splaytree::l_zigzag(splaytree* x){
#ifdef DEBUG
    CALL
#endif
        splaytree* p = x->_p;
    splaytree* g = p->_p;
    splaytree* gg = g->_p;

    splaytree* a = p->_l;
    splaytree* b = x->_l;
    splaytree* c = x->_r;
    splaytree* d = g->_r;

    take_care_of_great_grand_parents(g, gg, x);

    x->add(left, p);
    x->add(right, g);

    p->add(left, a);
    p->add(right, b);

    g->add(left, c);
    g->add(right, d);

    return x;
}

splaytree* splaytree::r_zigzag(splaytree* x){
#ifdef DEBUG
    CALL
#endif
        splaytree* p = x->_p;
    splaytree* g = p->_p;
    splaytree* gg = g->_p;

    splaytree* a = g->_l;
    splaytree* b = x->_l;
    splaytree* c = x->_r;
    splaytree* d = p->_r;

    take_care_of_great_grand_parents(g, gg, x);

    x->add(left, g);
    x->add(right, p);

    g->add(left, a);
    g->add(right, b);

    p->add(left, c);
    p->add(right, d);

    return x;
}

splaytree* splaytree::splay(splaytree* x){

    if(x->_p == NULL){
        return x;
    }
    else if(x == x->_p->_l && x->_p->_p == NULL){
        x = l_zig(x);
        return splay(x);
    }
    else if(x == x->_p->_r && x->_p->_p == NULL){
        x = r_zig(x);
        return splay(x);
    }
    else if(x == x->_p->_l && x->_p == x->_p->_p->_l){
        x = l_zigzig(x);
        return splay(x);
    }
    else if(x == x->_p->_r && x->_p == x->_p->_p->_r){
        x = r_zigzig(x);
        return splay(x);
    }
    else if(x == x->_p->_r && x->_p == x->_p->_p->_l){
        x = l_zigzag(x);
        return splay(x);
    }
    else if(x == x->_p->_l && x->_p == x->_p->_p->_r){
        x = r_zigzag(x);
        return splay(x);
    }
    return x;
}

void splaytree::print(){

    if(_l != NULL){
        _l->print();
    }

    cout << _d << " ";

    if(_r != NULL){
        _r->print();
    }
}



