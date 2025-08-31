## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = projet-finale

projet_finale_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
         user.c user.h \
        utilisateur.c utilisateur.h \
        ut.c ut.h \
        gestionEts.c   gestionEts.h \
        ficheDonneur.c  ficheDonneur.h \
        don1.c don1.h

projet_finale_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

