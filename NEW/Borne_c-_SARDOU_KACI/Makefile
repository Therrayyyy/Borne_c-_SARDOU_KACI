TARGET = borne
CC = g++
CFLAGS = -Wall -O -g 

# Répertoires d'inclusion et bibliothèques
INCLDIRS = -Iinclude
LIBDIRS = 
LIBS64 = -lsmartcardcpp_borne_x64 -lpcsclite

# Liste des fichiers source
SRCS = src/baseclient.cpp src/bouton.cpp src/generateur_save.cpp src/lecteurcarte.cpp src/main.cpp src/prise.cpp src/voyant.cpp

# Génération des fichiers objets
OBJS = ${SRCS:.cpp=.o} 

# Règle principale pour générer l'exécutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLDIRS) $(LIBDIRS) -o $@ $(OBJS) $(LIBS64)

# Règle pour compiler les fichiers objets
%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLDIRS) -c $< -o $@

# Génération des dépendances
depend:
	$(CC) -MM $(SRCS) $(INCLDIRS) > Makefile.dep

# Nettoyage des fichiers objets
clean:
	rm -f $(OBJS) core

# Nettoyage complet
veryclean: clean
	rm -f $(TARGET) a.out *.*~

