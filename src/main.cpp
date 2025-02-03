#include "extract.hpp"

int main(int argc, char **argv){
  auto e = std::make_unique<Extract>();

  if(argc > 1){
    const std::string param = argv[1];
    if(param == "--version"){
      std::cout << e->version << std::endl;
    }else if(param == "-l" || param == "--list"){
      e->list();
    }else{
      if(argc > 2){
        const std::string v = argv[2];
        if(v == "-v" || v == "--verbose"){
          e->extract(argv[1], "v");
        }else{
          std::cerr << "Use: 'extract --help' for more information.\n";
          return EXIT_FAILURE;
        }
      }else{
        e->extract(argv[1], "");
      }
    }
  }else{
    e->help();
  }

  return EXIT_SUCCESS;
}
