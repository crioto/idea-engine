PROJECT_NAME=render-screen
OBJ = $(BUILD_DIRECTORY)/render-screen/render-screen.o \
			$(BUILD_DIRECTORY)/render-screen/Events.o

render-screen:
	@echo $(BUILD_DIRECTORY)
render-screen: render-screen-dirs $(BIN_DIRECTORY)/render-screen

$(BIN_DIRECTORY)/render-screen: $(OBJ)
	$(CC) $(LDFLAGS) -L$(LIB_DIRECTORY) -lidea-engine $(OBJ) -o $@

$(BUILD_DIRECTORY)/render-screen/render-screen.o: render-screen.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIRECTORY)/render-screen/Events.o: Events.cpp Events.hpp
	$(CC) $(CXXFLAGS) -c $< -o $@

render-screen-dirs:
	@mkdir -p $(BIN_DIRECTORY)
	@mkdir -p $(BUILD_DIRECTORY)/render-screen

clean:
	@rm -f $(BUILD_DIRECTORY)/render-screen/*.o
	@rm -f $(BIN_DIRECTORY)/render-screen

mrproper: clean
	@rm -rf $(BUILD_DIRECTORY)/render-screen
