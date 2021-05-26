#include "SpyPointerGroup.h"
#include "SpyPointer.h"

SpyPointerGroup::SpyPointerGroup(std::ofstream &flux, int nb_char_for_each_var){
    m_output_fic = &flux;
    m_firt_log_done = false;
    m_nb_char_for_each_var = nb_char_for_each_var;
    *m_output_fic << "Infos :" << std::endl << "NBCharForEachVar : " << m_nb_char_for_each_var << std::endl;
    *m_output_fic << "Data :" << std::endl;
}

SpyPointerGroup::~SpyPointerGroup(){
}

const void SpyPointerGroup::makeLog(){
    if (!m_firt_log_done){
        m_firt_log_done = true;
        *m_output_fic << std::endl;
    }
    for (int i=0; i < m_spy_list.size(); i++){
        int cursor_pos_bf_edit, cursor_pos_af_edit;
        cursor_pos_bf_edit = m_output_fic->tellp();
        *m_output_fic << (m_spy_list[i]->getValue());
        cursor_pos_af_edit = m_output_fic->tellp();
        if (cursor_pos_af_edit - cursor_pos_bf_edit < m_nb_char_for_each_var){
            for(int i(0);i < m_nb_char_for_each_var - (cursor_pos_af_edit - cursor_pos_bf_edit); i++){
                *m_output_fic << " ";
            }
            *m_output_fic << "|";
            std::flush(*m_output_fic);
        }

    }
    *m_output_fic << std::endl;
}

void  SpyPointerGroup::addSpyPointer(SpyPointer *spy_pointer, std::string name){
    if (!m_firt_log_done){
        m_spy_list.push_back(spy_pointer);
    }
    int cursor_pos_bf_edit, cursor_pos_af_edit;
        cursor_pos_bf_edit = m_output_fic->tellp();
        *m_output_fic << name;
        cursor_pos_af_edit = m_output_fic->tellp();
        if (cursor_pos_af_edit - cursor_pos_bf_edit < m_nb_char_for_each_var){
            for(int i(0);i < m_nb_char_for_each_var - (cursor_pos_af_edit - cursor_pos_bf_edit); i++){
                *m_output_fic << " ";
            }
            *m_output_fic << "|";
            std::flush(*m_output_fic);
        }

}
