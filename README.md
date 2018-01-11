____
# Migale PE Packer (weak version)
### Date      : 
### Revision  : 1.1
### Author    : cv.dev.cpp@gmail.com
### Protection: Beemeal Source Shadow (V1.0.0) 
____

## __Project description__
This project demonstrates how to implement a simple PE packer.
The principle is as follows:
- add a new section at the end of the PE
- set this new sections rights as executable (suspicious for most antivirus heuristic engines ;-))
- redirect the entry point of the PE toward the first opcode of this new section
- recompute the size of code field

This project permits to show many tricky aspects about PE manipulation, this could
serve as material for security students project. 
