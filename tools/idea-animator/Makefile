PROJECT_NAME=idea-animator
OBJ = $(BUILD_DIRECTORY)/idea-animator/idea-animator.o \
			$(BUILD_DIRECTORY)/idea-animator/Events.o \
			$(BUILD_DIRECTORY)/idea-animator/GUI.o

idea-animator:
	@echo $(BUILD_DIRECTORY)
idea-animator: idea-animator-dirs $(BIN_DIRECTORY)/idea-animator

$(BIN_DIRECTORY)/idea-animator: $(OBJ)
	$(CC) $(LDFLAGS) -L$(LIB_DIRECTORY) -lidea-engine $(OBJ) -o $@

$(BUILD_DIRECTORY)/idea-animator/idea-animator.o: idea-animator.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIRECTORY)/idea-animator/Events.o: Events.cpp Events.hpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIRECTORY)/idea-animator/GUI.o: GUI.cpp GUI.hpp
	$(CC) $(CXXFLAGS) -c $< -o $@

idea-animator-dirs:
	@mkdir -p $(BIN_DIRECTORY)
	@mkdir -p $(BUILD_DIRECTORY)/idea-animator

clean:
	@rm -f $(BUILD_DIRECTORY)/idea-animator/*.o
	@rm -f $(BIN_DIRECTORY)/idea-animator

mrproper: clean
	@rm -rf $(BUILD_DIRECTORY)/idea-animator
