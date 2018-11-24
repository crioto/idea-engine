export CC=g++
export CXXLIBS=
export CXXINCLUDES=
export CXXFLAGS=-g -I $(CURDIR)/include -std=gnu++14 -Wall
export LDFLAGS=-lsdl2 -lsdl2_image -lsdl2_ttf
export BINARY=idea-engine
export LIB_DIRECTORY=$(CURDIR)/lib
# Top directory for example projects
export APP_DIRECTORY=examples
export BIN_DIRECTORY=$(CURDIR)/bin
export BUILD_DIRECTORY=$(CURDIR)/build
SOURCE_DIR=src
INCLUDE_DIR=include
CONFIGFILE=make.config

include $(CONFIGFILE)

all: lib examples

lib: directories
lib: $(LIB_DIRECTORY)/$(BINARY).$(EXT)

include make.examples

directories:
	@mkdir -p $(LIB_DIRECTORY)
	@mkdir -p $(BUILD_DIRECTORY)

clean: examples-clean
	-rm -f $(LIB_DIRECTORY)/$(BINARY)*
	-rm -f $(BUILD_DIRECTORY)/main.o
	-rm -f $(BUILD_DIRECTORY)/Engine.o
	-rm -f $(BUILD_DIRECTORY)/Scene.o
	-rm -f $(BUILD_DIRECTORY)/Object.o
	-rm -f $(BUILD_DIRECTORY)/Level.o
	-rm -f $(BUILD_DIRECTORY)/Texture.o
	-rm -f $(BUILD_DIRECTORY)/Resources.o
	-rm -f $(BUILD_DIRECTORY)/Console.o
	-rm -f $(BUILD_DIRECTORY)/ConsoleCommand.o
	-rm -f $(BUILD_DIRECTORY)/Event.o
	-rm -f $(BUILD_DIRECTORY)/EventBase.o
	-rm -f $(BUILD_DIRECTORY)/Building.o
	-rm -f $(BUILD_DIRECTORY)/Simulation.o
	-rm -f $(BUILD_DIRECTORY)/Seed.o

mrproper: clean examples-mrproper
	-rm -f $(CONFIGFILE)
	-rm -f make.examples
	-rm -rf $(LIB_DIRECTORY)
	-rm -rf $(BIN_DIRECTORY)
	-rm -rf $(BUILD_DIRECTORY)
	-rm -rf $(EXAMPLES_DIRECTORY)

OBJECT_FILES = $(BUILD_DIRECTORY)/Engine.o \
			   $(BUILD_DIRECTORY)/Scene.o \
			   $(BUILD_DIRECTORY)/Object.o \
			   $(BUILD_DIRECTORY)/Level.o \
			   $(BUILD_DIRECTORY)/Texture.o \
			   $(BUILD_DIRECTORY)/Resources.o \
			   $(BUILD_DIRECTORY)/Console.o \
			   $(BUILD_DIRECTORY)/ConsoleCommand.o \
			   $(BUILD_DIRECTORY)/Event.o \
			   $(BUILD_DIRECTORY)/EventBase.o \
			   $(BUILD_DIRECTORY)/Building.o \
			   $(BUILD_DIRECTORY)/Simulation.o \
			   $(BUILD_DIRECTORY)/Seed.o
#			   $(BUILD_DIRECTORY)/main.o


$(BUILD_DIRECTORY)/Engine.o: $(SOURCE_DIR)/Engine.cpp $(INCLUDE_DIR)/Engine.hpp
	$(CC) $(CXXFLAGS) -c -fPIC $< -o $@

$(BUILD_DIRECTORY)/Scene.o: $(SOURCE_DIR)/Scene.cpp $(INCLUDE_DIR)/Scene.hpp
	$(CC) $(CXXFLAGS) -c -fPIC $< -o $@

$(BUILD_DIRECTORY)/Object.o: $(SOURCE_DIR)/Object.cpp $(INCLUDE_DIR)/Object.hpp
	$(CC) $(CXXFLAGS) -c -fPIC $< -o $@

$(BUILD_DIRECTORY)/Level.o: $(SOURCE_DIR)/Level.cpp $(INCLUDE_DIR)/Level.hpp
	$(CC) $(CXXFLAGS) -c -fPIC $< -o $@

$(BUILD_DIRECTORY)/Texture.o: $(SOURCE_DIR)/Texture.cpp $(INCLUDE_DIR)/Texture.hpp
	$(CC) $(CXXFLAGS) -c -fPIC $< -o $@

$(BUILD_DIRECTORY)/Resources.o: $(SOURCE_DIR)/Resources.cpp $(INCLUDE_DIR)/Resources.hpp
	$(CC) $(CXXFLAGS) -c -fPIC $< -o $@

$(BUILD_DIRECTORY)/Console.o: $(SOURCE_DIR)/Console.cpp $(INCLUDE_DIR)/Console.hpp
	$(CC) $(CXXFLAGS) -c -fPIC $< -o $@

$(BUILD_DIRECTORY)/ConsoleCommand.o: $(SOURCE_DIR)/ConsoleCommand.cpp $(INCLUDE_DIR)/ConsoleCommand.hpp
	$(CC) $(CXXFLAGS) -c -fPIC $< -o $@

$(BUILD_DIRECTORY)/Event.o: $(SOURCE_DIR)/Event.cpp $(INCLUDE_DIR)/Event.hpp
	$(CC) $(CXXFLAGS) -c -fPIC $< -o $@

$(BUILD_DIRECTORY)/EventBase.o: $(SOURCE_DIR)/EventBase.cpp $(INCLUDE_DIR)/EventBase.hpp
	$(CC) $(CXXFLAGS) -c -fPIC $< -o $@

$(BUILD_DIRECTORY)/Building.o: $(SOURCE_DIR)/Building.cpp $(INCLUDE_DIR)/Building.hpp
	$(CC) $(CXXFLAGS) -c -fPIC $< -o $@

$(BUILD_DIRECTORY)/Simulation.o: $(SOURCE_DIR)/Simulation.cpp $(INCLUDE_DIR)/Simulation.hpp
	$(CC) $(CXXFLAGS) -c -fPIC $< -o $@

$(BUILD_DIRECTORY)/Seed.o: $(SOURCE_DIR)/Seed.cpp $(INCLUDE_DIR)/Seed.hpp
	$(CC) $(CXXFLAGS) -c -fPIC $< -o $@

#$(BUILD_DIRECTORY)/main.o: $(SOURCE_DIR)/main.cpp
#	$(CC) $(CXXFLAGS) -c -fPIC $< -o $@

$(LIB_DIRECTORY)/$(BINARY).$(EXT): $(OBJECT_FILES) 
	$(CC) $(LDFLAGS) $(OBJECT_FILES) -shared -o $@

make.examples:
	@echo "Did you forgot to run ./configure?"

make.config:
	@echo "Did you forgot to run ./configure?"
