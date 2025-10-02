CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

Target = main

SRCS = SRCS = main.cpp RockPaperScissors.cpp NumGuessing.cpp Dictionary.cpp ContinueMenu.cpp Utility.cpp

OBJS    = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	-rm -f $(OBJS) $(TARGET) *.d
