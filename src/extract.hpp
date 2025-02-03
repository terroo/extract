#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <filesystem>
#include <algorithm>

class Extract {
  public:
    Extract();
    void help();
    std::string version;
    void list();
    void extract(const std::string&, std::string) const;
};
