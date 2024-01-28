OBJS = agi.obj agi_v2.obj agi_v3.obj agi_v4.obj checks.obj cli.obj console.obj cycle.obj \
	font.obj getopt.obj getopt1.obj global.obj graphics.obj id.obj \
	inv.obj keyboard.obj logic.obj lzw.obj main.obj menu.obj motion.obj objects.obj \
	op_cmd.obj op_dbg.obj op_test.obj patches.obj picture.obj \
	rand.obj savegame.obj silent.obj sound.obj sprite.obj text.obj view.obj words.obj \
	daudio.obj fileglob.obj path.obj

CC = cl
MEM = /AL
ZOPT = /Od
OPT = /Ot
CPU = /G2
OS = /Lp
DEBUG =  /Zi
INCLUDES = -Iinclude -I.

CFLAGS =  $(MEM) $(CPU) $(OPT)  $(OS) $(DEBUG) -D__MSDOS__  $(INCLUDES)
ZCFLAGS = $(MEM) $(CPU) $(ZOPT) $(OS) $(DEBUG) -D__MSDOS__  $(INCLUDES)

psar.exe: $(OBJS) pharvid.obj
	LINK.EXE @plink.txt
#	msdos msc7\cvpack sar.exe
	BIND286.EXE sar.exe
	copy /Y sar.exe \dos\sq2
	dosbox
	del /F sar.exe pcvid.obj


sar.exe: $(OBJS) pcvid.obj
	LINK.EXE @linkfile.txt
	copy /Y sar.exe \dos\sq2
	dosbox
	del /F sar.exe pcvid.obj


#menu.obj: menu.c
#	$(CC) $(CFLAGS) /c menu.c

op_cmd.obj: op_cmd.c
	$(CC) /c $(ZCFLAGS) op_cmd.c

# sound.c(616) : fatal error C1001: Internal Compiler Error
#                (compiler file '@(#)regMD.c:1.100', line 1017)
#                Contact Microsoft Product Support Services
sound.obj: sound.c
	$(CC) /c $(ZCFLAGS) sound.c

daudio.obj: dummy.c
	$(CC) $(CFLAGS) /c /Fodaudio.obj dummy.c

pcvid.obj: nullvid.c
	$(CC) $(CFLAGS) /c /Fopcvid.obj pccga.c

pharvid.obj: nullvid.c
	$(CC) $(CFLAGS) /c /Fopcvid.obj pharcga.c

