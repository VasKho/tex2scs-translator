#pragma once

#include "sc_scn_tex_list_command.h"

class ScSCnTexNRelCommand : public ScSCnTexListCommand
{
public:
  ScScnTexCommandResult Complete(
      ScSCnCommandsHistory & history, ScSCnPrefixTree & tree, ScScnTexCommandParams const & params) override;
};
