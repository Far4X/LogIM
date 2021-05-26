#ifndef SPYPOINTER
#define SPYPOINTER

#include "SpyPointerGroup.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>


//TODo remove <iostream>
//  And add a constructor for SpyPointer without group

class SpyPointer{
    public :
        SpyPointer(int *var, std::string name, SpyPointerGroup &group);
        SpyPointer(float *var, std::string name, SpyPointerGroup &group);
        SpyPointer(long *var, std::string name, SpyPointerGroup &group);
        SpyPointer(double *var, std::string name, SpyPointerGroup &group);
        ~SpyPointer();

        SpyPointerGroup getGroup();
        std::string getValue();


    private :
        int *m_int_watched_var;
        float *m_float_watched_var;
        long *m_long_watched_var;
        double *m_double_watched_var;
        class SpyPointerGroup *m_group; 
        char m_type;       
};

#endif