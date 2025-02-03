#include "extract.hpp"

namespace fs = std::filesystem;

Extract::Extract(){
  this->version = "extract 2.0 - <https://github.com/terroo/extract>";
}

void Extract::extract(const std::string& path, std::string verbose = "") const {
  if(!fs::exists(path)){
    std::cerr << "File not found.\n";
    std::exit(66);
  }

  const std::vector<std::string> ext = { 
    "tar.bz2","tar.gz","tar.xz",
    "lzma","bz2","rar","gz","tar",
    "tbz2","tgz","zip","Z","7z",
    "xz","exe","deb","rpm"
  };

  const std::vector<std::string> comm = {
    "tar x" + verbose + "jf " + path,
    "tar x" + verbose + "zf " + path,
    "tar x" + verbose + "Jf " + path,
    "unlzma ${2:+-v} " + path,
    "bunzip2 " + path,
    "rar x " + path,
    "gunzip ${2:+-v} " + path,
    "tar x" + verbose + "f " + path,
    "tar x" + verbose + "jf " + path,
    "tar x" + verbose + "zf " + path,
    "unzip " + path,
    "uncompress " + path,
    "7z e " + path,
    "unxz ${2:+-v} " + path  + " || xz -dv " + path,
    "cabextract " + path,
    "ar " + verbose + "x " + path + " || dpkg-deb -xv " + path,
    "tar x" + verbose + "f " + path + " || rpm2cpio " + path + " | cpio -idmv"
  };

  size_t pos = path.find('.');

  if (pos != std::string::npos) {

    std::string target = path.substr(pos + 1);
     
    auto it = std::find(ext.begin(), ext.end(), target);

    if(it != ext.end()){
      size_t pos = std::distance(ext.begin(), it);
      const std::string the_null = comm[pos] + " > /dev/null 2>&1";
      int exec = std::system(the_null.c_str());

      if(exec != 0){
        std::cerr << "Failed to unpack: '" << target << "'." << std::endl;
        std::exit(1);
      }

    }else{
      std::cerr << "Invalid filetype." << std::endl;
      std::exit(1);
    }
  }else{
    std::cerr << "Invalid extension." << std::endl;
    std::exit(1);
  }
}

void Extract::help(){
  std::cout << "Usage: extract [options] file\n";
  std::cout << std::setw(1) << "Options:\n";
  std::cout << std::setw(1) << "\t-h,--help     Show this help\n";
  std::cout << std::setw(1) << "\t--version     Print version and exit\n";
  std::cout << std::setw(1) << "\t-v,--verbose  Decompress verbose mode\n";
  std::cout << std::setw(1) << "\t-l,--list     Lists commands to compress and uncompress\n";
}

void Extract::list(){
  std::cout << 
    "┌─────────┬────────────────────────────┬────────────────────┐\n"
    "│  MIME   │           COMPRESS         │     UNCOMPRESS     │\n"
    "├─────────┼────────────────────────────┼────────────────────┤\n"
    "│ tar.bz2 │ tar cvjf file file.tar.bz2 │ tar xjf file       │\n"
    "├─────────┼────────────────────────────┼────────────────────┤\n"
    "│ tar.gz  │ tar cvzf file file.tar.gz  │ tar xzf file       │\n"
    "├─────────┼────────────────────────────┼────────────────────┤\n"
    "│ tar.xz  │ tar xJf file.tar.xz        │ tar xJf file       │\n"
    "├─────────┼────────────────────────────┼────────────────────┤\n"
    "│ lzma    │ unlzma  file               │ unlzma -z file     │\n"
    "├─────────┼────────────────────────────┼────────────────────┤\n"
    "│ bz2     │ bunzip2 file               │ bunzip2 -z file    │\n"
    "├─────────┼────────────────────────────┼────────────────────┤\n"
    "│ rar     │ rar x file                 │ rar a files        │\n"
    "├─────────┼────────────────────────────┼────────────────────┤\n"
    "│ gz      │ gunzip file                │ gzip -v file       │\n"
    "├─────────┼────────────────────────────┼────────────────────┤\n"
    "│ tar     │ tar xf file                │ tar cf file        │\n"
    "├─────────┼────────────────────────────┼────────────────────┤\n"
    "│ tbz2    │ tar jcvf file.tbz2 file    │ tar xjf file       │\n"
    "├─────────┼────────────────────────────┼────────────────────┤\n"
    "│ tgz     │ tar zcvf file.tgz file     │ tar xzf file       │\n"
    "├─────────┼────────────────────────────┼────────────────────┤\n"
    "│ zip     │ zip file                   │ unzip file         │\n"
    "├─────────┼────────────────────────────┼────────────────────┤\n"
    "│ Z       │ compress file              │ uncompress file.Z  │\n"
    "├─────────┼────────────────────────────┼────────────────────┤\n"
    "│ 7z      │ 7z a file.7z file          │ 7z e file          │\n"
    "├─────────┼────────────────────────────┼────────────────────┤\n"
    "│ xz      │ xz file                    │ xz -d file || unxz │\n"
    "├─────────┼────────────────────────────┼────────────────────┤\n"
    "│ deb     │dpkg-deb -b dir/ file.deb   │ ar vx file         │\n"
    "├─────────┼────────────────────────────┼────────────────────┤\n"
    "│ rpm     │ rpmbuild -ba file.spec     │ tar xvf file       │\n"
    "├─────────┴────────────────────────────┴────────────────────┤\n"
    "│    extract 2.0 - Marcos Oliveira - terminalroot.com       │\n"
    "└───────────────────────────────────────────────────────────┘" << std::endl;
}
