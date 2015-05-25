#pragma once
#ifndef FEATURE_H
#define FEATURE_H

#include "common.h"
#include "node.h"
#include <sstream>
#include <memory>

namespace Morph {

#define FEATURE_MACRO_STRING_WORD "%w"
#define FEATURE_MACRO_WORD 1
#define FEATURE_MACRO_STRING_POS "%p"
#define FEATURE_MACRO_POS 2
#define FEATURE_MACRO_STRING_LENGTH "%l"
#define FEATURE_MACRO_LENGTH 3
#define FEATURE_MACRO_STRING_BEGINNING_CHAR "%bc"
#define FEATURE_MACRO_BEGINNING_CHAR 4
#define FEATURE_MACRO_STRING_ENDING_CHAR "%ec"
#define FEATURE_MACRO_ENDING_CHAR 5
#define FEATURE_MACRO_STRING_BEGINNING_CHAR_TYPE "%bt"
#define FEATURE_MACRO_BEGINNING_CHAR_TYPE 6
#define FEATURE_MACRO_STRING_ENDING_CHAR_TYPE "%et"
#define FEATURE_MACRO_ENDING_CHAR_TYPE 7
#define FEATURE_MACRO_STRING_FEATURE1 "%f1"
#define FEATURE_MACRO_FEATURE1 8

#define FEATURE_MACRO_STRING_SPOS "%sp"
#define FEATURE_MACRO_SPOS 11
#define FEATURE_MACRO_STRING_FORM "%sf"
#define FEATURE_MACRO_FORM 12
#define FEATURE_MACRO_STRING_FORM_TYPE "%sft"
#define FEATURE_MACRO_FORM_TYPE 13
#define FEATURE_MACRO_STRING_FUNCTIONAL_WORD "%f"
#define FEATURE_MACRO_FUNCTIONAL_WORD  14
#define FEATURE_MACRO_STRING_BASE_WORD "%ba"
#define FEATURE_MACRO_BASE_WORD  15

//#define FEATURE_MACRO_STRING_HAVE_TOPIC "%ht"
//#define FEATURE_MACRO_HAVE_TOPIC 16
#define FEATURE_MACRO_STRING_DEVOICE  "%devoice"
#define FEATURE_MACRO_DEVOICE  17
#define FEATURE_MACRO_STRING_LONGER  "%longer"
#define FEATURE_MACRO_LONGER  19
#define FEATURE_MACRO_STRING_NUMSTR  "%numstr"
#define FEATURE_MACRO_NUMSTR  20

#define FEATURE_MACRO_STRING_LEFT_WORD "%Lw"
#define FEATURE_MACRO_LEFT_WORD 101
#define FEATURE_MACRO_STRING_LEFT_POS "%Lp"
#define FEATURE_MACRO_LEFT_POS 102
#define FEATURE_MACRO_STRING_LEFT_LENGTH "%Ll"
#define FEATURE_MACRO_LEFT_LENGTH 103
#define FEATURE_MACRO_STRING_LEFT_BEGINNING_CHAR "%Lbc"
#define FEATURE_MACRO_LEFT_BEGINNING_CHAR 104
#define FEATURE_MACRO_STRING_LEFT_ENDING_CHAR "%Lec"
#define FEATURE_MACRO_LEFT_ENDING_CHAR 105
#define FEATURE_MACRO_STRING_LEFT_BEGINNING_CHAR_TYPE "%Lbt"
#define FEATURE_MACRO_LEFT_BEGINNING_CHAR_TYPE 106
#define FEATURE_MACRO_STRING_LEFT_ENDING_CHAR_TYPE "%Let"
#define FEATURE_MACRO_LEFT_ENDING_CHAR_TYPE 107

#define FEATURE_MACRO_STRING_LEFT_SPOS "%Lsp"
#define FEATURE_MACRO_LEFT_SPOS 111
#define FEATURE_MACRO_STRING_LEFT_FORM "%Lsf"
#define FEATURE_MACRO_LEFT_FORM 112
#define FEATURE_MACRO_STRING_LEFT_FORM_TYPE "%Lsft"
#define FEATURE_MACRO_LEFT_FORM_TYPE 113

#define FEATURE_MACRO_STRING_LEFT_FUNCTIONAL_WORD "%Lf"
#define FEATURE_MACRO_LEFT_FUNCTIONAL_WORD  114

#define FEATURE_MACRO_STRING_LEFT_BASE_WORD "%Lba"
#define FEATURE_MACRO_LEFT_BASE_WORD  115

#define FEATURE_MACRO_STRING_LEFT_PREFIX "%Lprefix"
#define FEATURE_MACRO_LEFT_PREFIX  116
#define FEATURE_MACRO_STRING_LEFT_SUFFIX "%Lsuffix"
#define FEATURE_MACRO_LEFT_SUFFIX  117
#define FEATURE_MACRO_STRING_LEFT_DUMMY "%Ldummy"
#define FEATURE_MACRO_LEFT_DUMMY 118
#define FEATURE_MACRO_STRING_LEFT_LONGER "%Llonger"
#define FEATURE_MACRO_LEFT_LONGER 119
#define FEATURE_MACRO_STRING_LEFT_NUMSTR "%Lnumstr"
#define FEATURE_MACRO_LEFT_NUMSTR 120

//------ RIGHT ------
#define FEATURE_MACRO_STRING_RIGHT_WORD "%Rw"
#define FEATURE_MACRO_RIGHT_WORD 201
#define FEATURE_MACRO_STRING_RIGHT_POS "%Rp"
#define FEATURE_MACRO_RIGHT_POS 202
#define FEATURE_MACRO_STRING_RIGHT_LENGTH "%Rl"
#define FEATURE_MACRO_RIGHT_LENGTH 203
#define FEATURE_MACRO_STRING_RIGHT_BEGINNING_CHAR "%Rbc"
#define FEATURE_MACRO_RIGHT_BEGINNING_CHAR 204
#define FEATURE_MACRO_STRING_RIGHT_ENDING_CHAR "%Rec"
#define FEATURE_MACRO_RIGHT_ENDING_CHAR 205
#define FEATURE_MACRO_STRING_RIGHT_BEGINNING_CHAR_TYPE "%Rbt"
#define FEATURE_MACRO_RIGHT_BEGINNING_CHAR_TYPE 206
#define FEATURE_MACRO_STRING_RIGHT_ENDING_CHAR_TYPE "%Ret"
#define FEATURE_MACRO_RIGHT_ENDING_CHAR_TYPE 207

#define FEATURE_MACRO_STRING_RIGHT_SPOS "%Rsp"
#define FEATURE_MACRO_RIGHT_SPOS 211
#define FEATURE_MACRO_STRING_RIGHT_FORM "%Rsf"
#define FEATURE_MACRO_RIGHT_FORM 212
#define FEATURE_MACRO_STRING_RIGHT_FORM_TYPE "%Rsft"
#define FEATURE_MACRO_RIGHT_FORM_TYPE 213

#define FEATURE_MACRO_STRING_RIGHT_FUNCTIONAL_WORD "%Rf"
#define FEATURE_MACRO_RIGHT_FUNCTIONAL_WORD  214
#define FEATURE_MACRO_STRING_RIGHT_BASE_WORD "%Rba"
#define FEATURE_MACRO_RIGHT_BASE_WORD  215

#define FEATURE_MACRO_STRING_RIGHT_PREFIX "%Rprefix"
#define FEATURE_MACRO_RIGHT_PREFIX  216
#define FEATURE_MACRO_STRING_RIGHT_SUFFIX "%Rsuffix"
#define FEATURE_MACRO_RIGHT_SUFFIX  217

#define FEATURE_MACRO_STRING_RIGHT_DUMMY "%Rdummy"
#define FEATURE_MACRO_RIGHT_DUMMY  218
#define FEATURE_MACRO_STRING_RIGHT_LONGER "%Rlonger"
#define FEATURE_MACRO_RIGHT_LONGER  219
#define FEATURE_MACRO_STRING_RIGHT_NUMSTR "%Rnumstr"
#define FEATURE_MACRO_RIGHT_NUMSTR 220

//----- middle  ----- (left middle right) の並び
#define FEATURE_MACRO_STRING_MIDDLE_WORD "%Mw"
#define FEATURE_MACRO_MIDDLE_WORD 301
#define FEATURE_MACRO_STRING_MIDDLE_POS "%Mp"
#define FEATURE_MACRO_MIDDLE_POS 302
#define FEATURE_MACRO_STRING_MIDDLE_LENGTH "%Ml"
#define FEATURE_MACRO_MIDDLE_LENGTH 303
#define FEATURE_MACRO_STRING_MIDDLE_BEGINNING_CHAR "%Mbc"
#define FEATURE_MACRO_MIDDLE_BEGINNING_CHAR 304
#define FEATURE_MACRO_STRING_MIDDLE_ENDING_CHAR "%Mec"
#define FEATURE_MACRO_MIDDLE_ENDING_CHAR 305
#define FEATURE_MACRO_STRING_MIDDLE_BEGINNING_CHAR_TYPE "%Mbt"
#define FEATURE_MACRO_MIDDLE_BEGINNING_CHAR_TYPE 306
#define FEATURE_MACRO_STRING_MIDDLE_ENDING_CHAR_TYPE "%Met"
#define FEATURE_MACRO_MIDDLE_ENDING_CHAR_TYPE 307

#define FEATURE_MACRO_STRING_MIDDLE_SPOS "%Msp"
#define FEATURE_MACRO_MIDDLE_SPOS 311
#define FEATURE_MACRO_STRING_MIDDLE_FORM "%Msf"
#define FEATURE_MACRO_MIDDLE_FORM 312
#define FEATURE_MACRO_STRING_MIDDLE_FORM_TYPE "%Msft"
#define FEATURE_MACRO_MIDDLE_FORM_TYPE 313

#define FEATURE_MACRO_STRING_MIDDLE_FUNCTIONAL_WORD "%Mf"
#define FEATURE_MACRO_MIDDLE_FUNCTIONAL_WORD  314
#define FEATURE_MACRO_STRING_MIDDLE_BASE_WORD "%Mba"
#define FEATURE_MACRO_MIDDLE_BASE_WORD  315

#define FEATURE_MACRO_STRING_MIDDLE_PREFIX "%Mprefix"
#define FEATURE_MACRO_MIDDLE_PREFIX  316
#define FEATURE_MACRO_STRING_MIDDLE_SUFFIX "%Msuffix"
#define FEATURE_MACRO_MIDDLE_SUFFIX  317

#define FEATURE_MACRO_STRING_MIDDLE_DUMMY "%Mdummy"
#define FEATURE_MACRO_MIDDLE_DUMMY  318
#define FEATURE_MACRO_STRING_MIDDLE_LONGER "%Mlonger"
#define FEATURE_MACRO_MIDDLE_LONGER  319
#define FEATURE_MACRO_STRING_MIDDLE_NUMSTR "%Mnumstr"
#define FEATURE_MACRO_MIDDLE_NUMSTR 320


// TODO: トピック数はファイルから読み込み時に決定する
#define TOPIC_NUM 50
#define NUM_OF_FUKUGOUJI 39

//char* hukugouji[];

class FeatureTemplate {//{{{
    bool is_unigram;
    bool is_bigram;
    bool is_trigram;
    std::string name;
    std::vector<unsigned int> features;
  public:
    FeatureTemplate(std::string &in_name, std::string &feature_string, bool in_is_unigram);
    bool get_is_unigram() {
        return is_unigram;
    }

    unsigned int interpret_macro(std::string &macro);
    std::string &get_name() {
        return name;
    }
    std::vector<unsigned int> *get_features() {
        return &features;
    }
};//}}}

class FeatureTemplateSet {
    std::vector<FeatureTemplate *> templates;
  public:
    FeatureVector* set_weight;
    bool open(const std::string &template_filename);
    FeatureTemplate *interpret_template(std::string &template_string, bool is_unigram);
    std::vector<FeatureTemplate *> *get_templates() {
        return &templates;
    }
};

class FeatureSet {
  friend int main(int argc, char** argv);
    FeatureTemplateSet *ftmpl;
    FeatureVector* weight;
  public: 
    static std::vector<double>* topic;
    static bool use_total_sim;
    std::vector<std::string> fset;
    FeatureSet(FeatureTemplateSet *in_ftmpl);
    FeatureSet(const FeatureSet& f){
        fset = f.fset;
    };
    ~FeatureSet();
    double calc_inner_product_with_weight();
    void extract_unigram_feature(Node *node);
    void extract_topic_feature(Node *node);
    void extract_bigram_feature(Node *l_node, Node *r_node);

    // N-gram に一般化する？
    void extract_trigram_feature(Node *l_node, Node *m_node, Node *r_node);

    bool append_feature(FeatureSet *in);
    void minus_feature_from_weight(std::unordered_map<std::string, double> &in_feature_weight);
    void plus_feature_from_weight(std::unordered_map<std::string, double> &in_feature_weight);
    void minus_feature_from_weight(std::unordered_map<std::string, double> &in_feature_weight, size_t factor);
    void plus_feature_from_weight(std::unordered_map<std::string, double> &in_feature_weight, size_t factor);
    inline std::vector<std::string>& get_fset(){return fset;};
    bool print();

    std::string str();
    std::string binning(double x){//{{{
        // 完全に0, 0.01 以下，0.05以下, 0.1 以下, 0.2以下, 0.3以下, 0.4, 0.5, 0.6, 0.7,0.8,0.9,それ以上, の１３通り x 符号
        
        if(x == 0.0)
            return std::string("0");
        else if (x <= -1.0)
            return std::string("-1.0");
        else if (x <= -0.9)
            return std::string("-0.9");
        else if (x <= -0.8)
            return std::string("-0.8");
        else if (x <= -0.7)
            return std::string("-0.7");
        else if (x <= -0.6)
            return std::string("-0.6");
        else if (x <= -0.5)
            return std::string("-0.5");
        else if (x <= -0.4)
            return std::string("-0.4");
        else if (x <= -0.3)
            return std::string("-0.3");
        else if (x <= -0.2)
            return std::string("-0.2");
        else if (x <= -0.1)
            return std::string("-0.1");
        else if (x <= -0.05)
            return std::string("-0.05");
        else if (x <= -0.01)
            return std::string("-0.01");
        else if (x <= 0.01)
            return std::string("0.01");
        else if (x <= 0.05)
            return std::string("0.05");
        else if (x <= 0.1)
            return std::string("0.1");
        else if (x <= 0.2)
            return std::string("0.2");
        else if (x <= 0.3)
            return std::string("0.3");
        else if (x <= 0.4)
            return std::string("0.4");
        else if (x <= 0.5)
            return std::string("0.5");
        else if (x <= 0.6)
            return std::string("0.6");
        else if (x <= 0.7)
            return std::string("0.7");
        else if (x <= 0.7)
            return std::string("0.7");
        else if (x <= 0.8)
            return std::string("0.8");
        else if (x <= 0.9)
            return std::string("0.9");
        else 
            return std::string("1.0");
    }//}}}

  private:
};

}

#endif
