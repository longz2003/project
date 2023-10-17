PLAYER = bnl_player/Player.cpp
BUSINESS = bnl_business/Business.cpp bnl_business/Lemon.cpp bnl_business/Newspaper_stand.cpp bnl_business/Convenience_store.cpp bnl_business/A_Lemon.cpp bnl_business/A_Newspaper.cpp bnl_business/A_Convenience.cpp
GAME = bnl_game_engine/Game_engine.cpp

all: $(PLAYER) $(MENU) $(BUSINESS) $(GAME)
	g++ $(PLAYER) main.cpp $(BUSINESS) $(GAME) -o buy_in_large

test: test/businesstest test/atest test/testastore

test/businesstest: bnl_business/Business.cpp bnl_business/Business.h bnl_business/Lemon.h bnl_business/Lemon.cpp bnl_business/Newspaper_stand.cpp bnl_business/Convenience_store.cpp
	g++ business_test.cpp bnl_business/Business.cpp bnl_business/Lemon.cpp bnl_business/Newspaper_stand.cpp bnl_business/Convenience_store.cpp -o test/businesstest

test/atest: bnl_business/Business.cpp bnl_business/Lemon.h bnl_business/Lemon.cpp bnl_business/A_Lemon.h bnl_business/A_Lemon.cpp bnl_business/Newspaper_stand.h bnl_business/Newspaper_stand.cpp bnl_business/A_Newspaper.h bnl_business/A_Newspaper.cpp Atest.cpp
	g++ bnl_business/Business.cpp bnl_business/Lemon.h bnl_business/Lemon.cpp bnl_business/A_Lemon.h bnl_business/A_Lemon.cpp bnl_business/Newspaper_stand.cpp bnl_business/A_Newspaper.cpp Atest.cpp -o test/atest

test/testastore: bnl_business/Business.cpp bnl_business/Business.h bnl_business/Convenience_store.h bnl_business/Convenience_store.cpp bnl_business/A_Convenience.h bnl_business/A_Convenience.cpp convenience_test.cpp
	g++ bnl_business/Business.cpp bnl_business/Business.h bnl_business/Convenience_store.h bnl_business/Convenience_store.cpp bnl_business/A_Convenience.h bnl_business/A_Convenience.cpp convenience_test.cpp -o test/testastore 

businesstest:
	./test/businesstest

atest:
	./test/atest

testastore:
	./test/testastore

clean:
	rm -rf test/*

run:
	./buy_in_large