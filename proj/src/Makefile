# name of the program (Minix service)
PROG=proj

.PATH: ${.CURDIR}/Controller/
.PATH: ${.CURDIR}/Controller/Keyboard
.PATH: ${.CURDIR}/Controller/Mouse
.PATH: ${.CURDIR}/Controller/Timer
.PATH: ${.CURDIR}/Controller/Video
.PATH: ${.CURDIR}/Model/
.PATH: ${.CURDIR}/Viewer/

# source code files to be compiled
SRCS = main.c graphic.c keyboard.c kbc.c timer.c mouse.c model.c utils.c

# additional compilation flags
# "-Wall -Wextra -Werror -I . -std=c11 -Wno-unused-parameter" are already set
CFLAGS += -pedantic

# list of library dependencies (for Lab 2, only LCF library)
DPADD += ${LIBLCF}
LDADD += -llcf

# include LCOM's makefile that does all the "heavy lifting"
.include <minix.lcom.mk>