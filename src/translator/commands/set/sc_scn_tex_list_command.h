#pragma once

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#include "../sc_scn_tex_command.h"

class ScSCnTexListCommand : public ScSCnTexCommand
{
protected:
  uint8_t const MAX_PARAMS = 3;
  uint8_t const COMMAND_TYPE_POS = 1;
  uint8_t const REL_PARAM_POS = 2;

  uint8_t const MAX_REL_ATTRS = 5;
  uint8_t const EDGE_ATTR_POS = 0;
  uint8_t const BEGIN_BRACKET_POS = 1;
  uint8_t const END_BRACKET_POS = 2;
  uint8_t const REL_MODIFIER_ATTR_POS = 3;
  uint8_t const REL_ATTR_POS = 4;
  uint8_t const MAX_REL_ATTRS_WITH_REl_MODIFIER = 4;

  std::unordered_map<std::string, std::vector<std::string>> m_setTypes = {
    { "scnrelfromlist",      { "=>", "", "", ":" } },
    { "scnrelfromset",       { "=>", "{", "}", ":" } },
    { "scnrelfromvector",    { "=>", "<", ">", ":" } },
    { "scnreltolist",        { "<=", "", "", ":" } },
    { "scnreltoset",         { "<=", "{", "}", ":" } },
    { "scnreltovector",      { "<=", "<", ">", ":" } },
    { "scnrelbothlist",      { "<=>", "", "", ":" } },
    { "scnrelbothset",       { "<=>", "{", "}", ":" } },
    { "scnrelbothvector",    { "<=>", "<", ">", ":" } },
    { "scnhaselementlist",   { "->", "", "", ":" } },
    { "scnhaselementset",    { "->", "{", "}", ":" } },
    { "scnhaselementvector", { "->", "<", ">", ":" } },
    { "scnhassubstruct",     { "->", "[*", "*]", ":" } },
    { "scnhassubset",        { "->", "{", "}", ":" } },

    { "scnsubstruct",        { "=>", "[*", "*]", ":", "включение*" } },

    { "scnsubdividing",      { "=>", "{", "}", ":", "разбиение*" } },
    { "scnsdclass",          { "->", "", "", ":", "класс объектов исследования'" } },
    { "scnsdrelation",       { "->", "", "", ":", "исследуемое отношение'" } },
  };

  std::unordered_set<std::string> m_ignoredTypes = {
      "SCn"
  };

  std::unordered_map<std::string, std::vector<std::string>> m_elementTypes = {
    { "scnrelfrom",          { "=>", ":" } },
    { "scnrelto",            { "<=", ":" } },
    { "scnsuperset",         { "=>", ":", "включение*" } },
    { "scnsubset",           { "<=", ":", "включение*" } },
    { "scnvarrelfrom",       { "_=>", "::" } },
    { "scnvarrelto",         { "_<=", "::" } },
    { "scnrelboth",          { "<=>", ":" } },
    { "scneq",               { "<=>", ":" } },
    { "scniselement",        { "<-", ":" } },
    { "scniselementrole",    { "<-", ":" } },
    { "scnhaselement",       { "->", ":" } },
    { "scnhaselementrole",   { "->", ":" } },
    { "scnisvarelement",     { "_<-", "::" } },
    { "scnisvarelementrole", { "_<-", "::" } },
    { "scnhasvarelementrole",{ "_->", "::" } },

    { "scneqfile",           { "<=>", ":", "семантическая эквивалентность*" } },
    { "scneqimage",          { "<=>", ":", "семантическая эквивалентность*" } },
    { "scnidtftext",         { "=>", ":", "идентификатор*" } },
    { "scntext",             { "=>", ":", "идентификатор*" } },
    { "scnnote",             { "=>", ":", "примечание*" } },
    { "scnidtf",             { "=>", ":", "идентификатор*" } },
    { "scnexplanation",      { "=>", ":", "пояснение*" } },
    { "scnidtfdef",          { "=>", ":", "пояснение*" } },

    { "scnsdmainclasssingle",{ "->", ":", "максимальный класс объектов исследования'" } },
  };

  std::unordered_set<std::string> m_fileTypes = {
    "scnfileimage", "scnfileitem", "scnfilelong", "scnfilescgitem", "scnfileclass",
    "scnidtftext", "scntext",
    "scnnote", "scnidtf", "scnexplanation", "scnidtfdef"
  };

  std::unordered_set<std::string> m_urlTypes = {
    "scneqfile", "scneqimage",
  };
};
