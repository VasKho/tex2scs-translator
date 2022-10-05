#include "sc_scn_tex_begin_list_command.h"

/// 0: begin 1: <command_name> 2: <relation>?
ScScnTexCommandResult ScSCnTexBeginListCommand::Complete(
    ScSCnCommandsHistory & history,
    ScSCnPrefixTree & tree,
    ScScnTexCommandParams const & params)
{
  std::string const & relationSetType = params.at(1);

  auto const & ignItem = m_ignoredTypes.find(relationSetType);
  if (ignItem != m_ignoredTypes.cend())
    return "";

  std::string const & name = params.at(0);

  if (relationSetType == "scnitemize")
    return "<ul>";
  else if (relationSetType == "scnnumerize")
    return "<ol>";
  else if (relationSetType == "scnindent")
    return SCsStream()
      .Row([]() -> SCsStream { return {"(*"}; })
      .AddTab()
      .SetDoubleSemicolons()
      .SetLastCommandName(name);

  std::string relIdtf = params.size() > 2 ? params.at(2) : "";

  auto const & item = m_setTypes.find(relationSetType);
  if (item != m_setTypes.cend())
  {
    return SCsStream()
      .Row([&item, &tree, &relIdtf](SCsStream &stream) {
        std::string const & edge = item->second[0];
        std::string const & beginBracket = item->second[1];

        if (relIdtf.empty())
          relIdtf = item->second.size() == 4 ? item->second[3] : "";

        stream.Formatted([&tree, &edge, &beginBracket, &relIdtf]() -> SCsStream {
          if (relIdtf.empty())
            return { edge, " ", beginBracket };
          else
            return { edge, " ", tree.Add(relIdtf), ": ", beginBracket };
        });
      })
      .AddTab()
      .SetLastCommandName(name);
  }

  return "";
}
