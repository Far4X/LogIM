#include "SpyPointer.h"

SpyPointer::SpyPointer(int *var, std::string name, SpyPointerGroup &group){
    m_int_watched_var = var;
    m_group = &group;
    m_group->addSpyPointer(this, name);
    m_type = 0;
}

SpyPointer::SpyPointer(float *var, std::string name, SpyPointerGroup &group){
    m_float_watched_var = var;
    m_group = &group;
    m_group->addSpyPointer(this, name);
    m_type = 1;
}

SpyPointer::SpyPointer(long *var, std::string name, SpyPointerGroup &group){
    m_long_watched_var = var;
    m_group = &group;
    m_group->addSpyPointer(this, name);
    m_type = 2;
}

SpyPointer::SpyPointer(double *var, std::string name, SpyPointerGroup &group){
    m_double_watched_var = var;
    m_group = &group;
    m_group->addSpyPointer(this, name);
    m_type = 3;
}


//Destructors

SpyPointer::~SpyPointer(){

}

//Other funcs

SpyPointerGroup SpyPointer::getGroup(){
    return *m_group;
}

std::string SpyPointer::getValue(){
    switch (m_type)
    {
    case 0 :
        return std::to_string(*m_int_watched_var);

    case 1 :
        return std::to_string(*m_float_watched_var);

    case 2 :
        return std::to_string(*m_long_watched_var);

    case 3 :
        return std::to_string(*m_double_watched_var);
    
    default:
        return "ERROR";
    }
}