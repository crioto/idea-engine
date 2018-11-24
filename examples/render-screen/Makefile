PROJECT_NAME=render-screen

render-screen:
	@echo $(BUILD_DIRECTORY)
render-screen: render-screen-dirs $(BIN_DIRECTORY)/render-screen

$(BIN_DIRECTORY)/render-screen: $(BUILD_DIRECTORY)/render-screen/render-screen.o
	$(CC) $(LDFLAGS) -L$(LIB_DIRECTORY) -lidea-engine $(BUILD_DIRECTORY)/render-screen/render-screen.o -o $@

$(BUILD_DIRECTORY)/render-screen/render-screen.o: render-screen.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

render-screen-dirs:
	@mkdir -p $(BIN_DIRECTORY)
	@mkdir -p $(BUILD_DIRECTORY)/render-screen

clean:
	@rm -f $(BUILD_DIRECTORY)/render-screen/*.o
	@rm -f $(BIN_DIRECTORY)/render-screen

mrproper: clean
	@rm -rf $(BUILD_DIRECTORY)/render-screen
