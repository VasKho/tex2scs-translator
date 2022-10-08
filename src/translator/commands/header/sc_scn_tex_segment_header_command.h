#pragma once

#include "sc_scn_tex_struct_header_command.h"

class ScSCnTexSegmentHeaderCommand : public ScSCnTexStructHeaderCommand
{
public:
  ScScnTexCommandResult Complete(
      ScSCnCommandsHistory & history, ScSCnPrefixTree & tree, ScScnTexCommandParams const & params) override;
};
