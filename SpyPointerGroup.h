#ifndef SPYPOINTERGR
#define SPYPOINTERGR

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


class SpyPointerGroup{
    public :
        const void makeLog();
        void addSpyPointer(class SpyPointer *spy_pointer, std::string name);

        SpyPointerGroup(std::ofstream &flux, int nb_char_for_each_var);
        ~SpyPointerGroup();


    private :
        
        std::ofstream *m_output_fic;
        std::vector<class SpyPointer*> m_spy_list;
        bool m_firt_log_done;
        int m_nb_char_for_each_var;

};

#endif