CXX ?= g++

CXXFLAGS ?= -std=c++17 -Wall -Wextra
CPPFLAGS += -I./include

SFML_PREFIX := $(shell brew --prefix sfml 2>/dev/null)

ifneq ($(SFML_PREFIX),)
CPPFLAGS += -I$(SFML_PREFIX)/include
LDFLAGS += -L$(SFML_PREFIX)/lib
endif

LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

SRCDIR = src
OBJDIR = obj
TARGET = pvz.out

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))
HEADERS := $(wildcard include/*.hpp)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS)
	@mkdir -p $(OBJDIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(OBJDIR) $(TARGET)
