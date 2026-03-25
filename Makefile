CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

SRC = src/main.cpp \
      src/entities/Entity.cpp \
      src/entities/Player.cpp \
	  src/entities/Enemy.cpp \
	  src/actions/BasicAttack.cpp

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

tests/test_basic_attack: tests/test_basic_attack.cpp \
						  src/entities/Entity.cpp \
                          src/entities/Player.cpp \
                          src/entities/Enemy.cpp \
						  src/actions/BasicAttack.cpp
	@$(CXX) $(CXXFLAGS) $^ -o tests/test_basic_attack

TEST_BINS = tests/test_entity_player \
			tests/test_entity_enemy \
			tests/test_basic_attack

BINS = 	game.exe \
		tests\test_entity_player.exe \
		tests\test_entity_enemy.exe \
		tests\test_basic_attack.exe

tests: $(TEST_BINS)
	@echo TEST 1: -- test_entity_player ---
	@./tests/test_entity_player
	@echo TEST 2: --- test_entity_enemy ---
	@./tests/test_entity_enemy
	@echo TEST 3: --- test_basic_attack ---
	@./tests/test_basic_attack

clean:
#     linux / git bash: rm -f $(BINS)
	@del /f /q $(BINS) 2>nul
