#pragma once

#include <utility>
#include <unordered_map>
#include <fstream>
#include <filesystem>
#include <iostream>

#include "filesystem/sc_file_system.h"

#include "commands/sc_scn_tex_command.h"

#include "SCnTexLexer.h"
#include "SCnTexParser.h"

using ScSCnTexCommands = std::unordered_map<std::string, ScSCnTexCommand *>;

class ScSCnTex2SCsTranslator
{
public:
  bool Run(std::string const & workDirectoryPath, std::string const & targetDirectoryPath);

private:
  std::unordered_set<std::string> m_extensions = {".tex"};
  size_t m_filesCount;
  size_t m_fileNumber;

  void TranslateFiles(
      std::string const & nestedDirectoryPath,
      ScDirectory startDirectory,
      ScDirectory const & startTargetDirectory);

  bool TranslateFile(std::string const & filePath, ScDirectory const & targetDirectory);

  std::string TranslateText(std::string const & filePath);

  void DumpIdentifiers(ScDirectory const & targetDirectory);
};
