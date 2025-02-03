cmake_minimum_required(VERSION 3.10)

# Nome do projeto e definição do executável
project(extract)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Adiciona os arquivos-fonte ao executável
add_executable(extract src/main.cpp src/extract.cpp)

# Define diretório de instalação
set(PREFIX "/usr" CACHE PATH "Installation prefix")
set(MANDIR "${PREFIX}/share/man" CACHE PATH "Man page directory")

# Configuração de instalação
install(TARGETS extract DESTINATION ${PREFIX}/bin)
install(FILES script/extract.1 DESTINATION ${MANDIR}/man1)
