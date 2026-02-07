SRCS = maintask.cpp Library.cpp Book.cpp User.cpp Student.cpp Staff.cpp Author.cpp Librarian.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

CXX = g++
CXXFLAGS = -std=c++20 -Wall -g

# Uncomment the following line to enable sanitizers
# CXXFLAGS += -fsanitize=address,leak,undefined

ifeq ($(OS),Windows_NT)
	EXEC = LibrarySystem.exe
	RM = del
else
	EXEC = LibrarySystem
	RM = rm -f
endif

all: $(EXEC)
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

-include $(DEPS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -MMD -MP -c $<

clean:
	$(RM) $(EXEC) $(OBJS) $(DEPS)
