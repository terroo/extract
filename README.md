# `extract`
Automatically recognizes and extracts various types of mime formats from compressed files. If it is installed, otherwise it says **Failed to unpack: '[type]'.** and you will need to install the appropriate software later

---

## Dependencies
+ C++ compiler: [GNU GCC](https://gcc.gnu.org/) or [Clang/LLVM](https://clang.llvm.org/)
+ [CMake](https://cmake.org/)

Example on Ubuntu:
```bash
sudo apt install build-essential cmake
```

---

## Instalation
```sh
git clone https://github.com/terroo/extract
cd extract
cmake -B build .
cmake --build build/
sudo cmake --install build/
```

---

## Usage
+ Show the help:
```sh
extract --help
```
> Or only: `extract -h`

+ Show the manual:
```sh
man extract
```

+ Extract file:
> Example to *tbz2*
```sh
extract file.tbz2
```

+ Extract file in verbose mode:
> Example to *lzma*
```sh
extract file.tbz2 --verbose 
```
> Or only: `extract file.tbz2 -v`. The verbose needs to be the last command!

+ Lists commands to compress and uncompress:
```sh
extract --list
```
> Or only: `extract -l`

---

## Notice
If the decompressor is not installed, there will be output: **Failed to unpack: '[type]'.** To resolve, install the appropriate software.

---

## License
Copyright © 2018 Free Software Foundation, Inc. License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.

---

## Uninstalation
```sh
git clone https://github.com/terroo/extract
cd extract
cmake -B build .
cmake --build build/
cd build/
sudo xargs rm < install_manifest.txt
```
