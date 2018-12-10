PROJECT_NAME=game-console
OBJ = $(BUILD_DIRECTORY)/game-console/game-console.o \
			$(BUILD_DIRECTORY)/game-console/Events.o

game-console:
	@echo $(BUILD_DIRECTORY)
game-console: game-console-dirs $(BIN_DIRECTORY)/game-console

$(BIN_DIRECTORY)/game-console: $(OBJ)
	$(CC) $(LDFLAGS) -L$(LIB_DIRECTORY) -lidea-engine $(OBJ) -o $@

$(BUILD_DIRECTORY)/game-console/game-console.o: game-console.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIRECTORY)/game-console/Events.o: Events.cpp Events.hpp
	$(CC) $(CXXFLAGS) -c $< -o $@


game-console-dirs:
	@mkdir -p $(BIN_DIRECTORY)
	@mkdir -p $(BUILD_DIRECTORY)/game-console

clean:
	@rm -f $(BUILD_DIRECTORY)/game-console/*.o
	@rm -f $(BIN_DIRECTORY)/game-console

mrproper: clean
	@rm -rf $(BUILD_DIRECTORY)/game-console
