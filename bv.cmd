cl /AL /Lp /c vv.c
del /F \dos\sq2\sar.exe
msdos \c600\binb\link vv.obj,vv.exe,NUL,PHAPI.LIB GRAPHICS.LIB /NOD:LLIBCE LLIBCEP.LIB LLIBPE.LIB,PROTMODE;
msdos \c600\run286\bin\bind286 vv.exe
copy /Y vv.exe \dos\SQ2\sar.exe
del /F vv.exe vv.obj
dosbox
