PROJECT_NAME=animation
OBJ = $(BUILD_DIRECTORY)/animation/animation.o \
			$(BUILD_DIRECTORY)/animation/Events.o

animation:
	@echo $(BUILD_DIRECTORY)
animation: animation-dirs $(BIN_DIRECTORY)/animation

$(BIN_DIRECTORY)/animation: $(OBJ)
	$(CC) $(LDFLAGS) -L$(LIB_DIRECTORY) -lidea-engine $(OBJ) -o $@

$(BUILD_DIRECTORY)/animation/animation.o: animation.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIRECTORY)/animation/Events.o: Events.cpp Events.hpp
	$(CC) $(CXXFLAGS) -c $< -o $@


animation-dirs:
	@mkdir -p $(BIN_DIRECTORY)
	@mkdir -p $(BUILD_DIRECTORY)/animation

clean:
	@rm -f $(BUILD_DIRECTORY)/animation/*.o
	@rm -f $(BIN_DIRECTORY)/animation

mrproper: clean
	@rm -rf $(BUILD_DIRECTORY)/animation
