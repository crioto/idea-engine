CC=g++
CXXLIBS=
CXXINCLUDES=
CXXFLAGS=-g -I include -std=gnu++14
LDFLAGS=-lsdl2 -lsdl2_image -lsdl2_ttf
BINARY=game
OUTPUT_DIRECTORY=bin
BUILD_DIRECTORY=build
SOURCE_DIR=src
INCLUDE_DIR=include
CONFIGFILE=config.make

include $(CONFIGFILE)

all: game

game: directories
game: $(OUTPUT_DIRECTORY)/$(BINARY)

directories:
	@mkdir -p $(OUTPUT_DIRECTORY)
	@mkdir -p $(BUILD_DIRECTORY)

clean:
	-rm -f $(OUTPUT_DIRECTORY)/$(BINARY)
	-rm -f $(BUILD_DIRECTORY)/main.o
	-rm -f $(BUILD_DIRECTORY)/Engine.o

mrproper: clean
	-rm -f $(CONFIGFILE)
	-rm -rf $(OUTPUT_DIRECTORY)
	-rm -rf $(BUILD_DIRECTORY)

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
				$(BUILD_DIRECTORY)/Seed.o \
				$(BUILD_DIRECTORY)/main.o


$(BUILD_DIRECTORY)/Engine.o: $(SOURCE_DIR)/Engine.cpp $(INCLUDE_DIR)/Engine.hpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIRECTORY)/Scene.o: $(SOURCE_DIR)/Scene.cpp $(INCLUDE_DIR)/Scene.hpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIRECTORY)/Object.o: $(SOURCE_DIR)/Object.cpp $(INCLUDE_DIR)/Object.hpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIRECTORY)/Level.o: $(SOURCE_DIR)/Level.cpp $(INCLUDE_DIR)/Level.hpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIRECTORY)/Texture.o: $(SOURCE_DIR)/Texture.cpp $(INCLUDE_DIR)/Texture.hpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIRECTORY)/Resources.o: $(SOURCE_DIR)/Resources.cpp $(INCLUDE_DIR)/Resources.hpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIRECTORY)/Console.o: $(SOURCE_DIR)/Console.cpp $(INCLUDE_DIR)/Console.hpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIRECTORY)/ConsoleCommand.o: $(SOURCE_DIR)/ConsoleCommand.cpp $(INCLUDE_DIR)/ConsoleCommand.hpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIRECTORY)/Event.o: $(SOURCE_DIR)/Event.cpp $(INCLUDE_DIR)/Event.hpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIRECTORY)/EventBase.o: $(SOURCE_DIR)/EventBase.cpp $(INCLUDE_DIR)/EventBase.hpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIRECTORY)/Building.o: $(SOURCE_DIR)/Building.cpp $(INCLUDE_DIR)/Building.hpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIRECTORY)/Simulation.o: $(SOURCE_DIR)/Simulation.cpp $(INCLUDE_DIR)/Simulation.hpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIRECTORY)/Seed.o: $(SOURCE_DIR)/Seed.cpp $(INCLUDE_DIR)/Seed.hpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIRECTORY)/main.o: $(SOURCE_DIR)/main.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(OUTPUT_DIRECTORY)/$(BINARY): $(OBJECT_FILES) 
	$(CC) $(LDFLAGS) $(OBJECT_FILES) -o $@
