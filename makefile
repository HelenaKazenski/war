# Author: Helena Kazenski
# email: hkazenski@butler.edu
# Class: CS341
# Section: 02

# Honor pledge:
# I pledge that I have neither given nor received any help on this assignment.
# I pledge that all work is my own, and not copied from any other source.

# hkazenski

project_2: card.o deck.o standardDeck.o nonStandardDeck.o war.o main.o
	g++ card.o deck.o standardDeck.o nonStandardDeck.o war.o main.o -o project_2

card.o: card.cpp card.h
	g++ -c card.cpp -o card.o
	
deck.o: deck.cpp deck.h card.h
	g++ -c deck.cpp -o deck.o

standardDeck.o: standardDeck.cpp standardDeck.h  deck.h card.h
	g++ -c standardDeck.cpp -o standardDeck.o

nonStandardDeck.o: nonStandardDeck.cpp nonStandardDeck.h deck.h card.h
	g++ -c nonStandardDeck.cpp -o nonStandardDeck.o

war.o: war.cpp war.h standardDeck.h card.h
	g++ -c war.cpp -o war.o

main.o: main.cpp standardDeck.h nonStandardDeck.h deck.h card.h
	g++ -c main.cpp -o main.o

run:
	project_2
	
clean:
	rm -f *.o project_2

# valgrind --leak-check=full project_2
