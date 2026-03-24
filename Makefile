CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

SRC = src/main.cpp \
      src/entities/Entity.cpp \
      src/entities/Player.cpp

game: $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o game

tests/test_entity_player: tests/test_entity_player.cpp \
                          src/entities/Entity.cpp \
                          src/entities/Player.cpp
	$(CXX) $(CXXFLAGS) $^ -o tests/test_entity_player

tests: tests/test_entity_player
	@echo "--- test_entity_player ---"
	@./tests/test_entity_player

clean:
	rm -f game tests/test_entity_player
