CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

SRC = src/main.cpp \
      src/entities/Entity.cpp \
      src/entities/Player.cpp

game: $(SRC)
	@$(CXX) $(CXXFLAGS) $(SRC) -o game

tests/test_entity_player: tests/test_entity_player.cpp \
                          src/entities/Entity.cpp \
                          src/entities/Player.cpp
	@$(CXX) $(CXXFLAGS) $^ -o tests/test_entity_player

tests/test_entity_enemy: tests/test_entity_enemy.cpp \
                          src/entities/Entity.cpp \
                          src/entities/Enemy.cpp
	@$(CXX) $(CXXFLAGS) $^ -o tests/test_entity_enemy

TEST_BINS = tests/test_entity_player \
			tests/test_entity_enemy

tests: $(TEST_BINS)
	@echo TEST 1: -- test_entity_player ---
	@./tests/test_entity_player
	@echo TEST 2: --- test_entity_enemy ---
	@./tests/test_entity_enemy

clean:
#     linux / git bash: rm -f game.exe tests/test_entity_player.exe
	@del /f /q game.exe tests\test_entity_player.exe
