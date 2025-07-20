# Variáveis
CXX = g++
CXXFLAGS = -Wall -g -std=c++17
SOURCES = src/main.cpp src/mainwindow.cpp src/monitor.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXEC = cpu-monitor

# Regra para compilar os arquivos .cpp
$(EXEC): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXEC) -g

# Como gerar os arquivos .o a partir dos arquivos .cpp
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza dos arquivos intermediários (ajustado para Windows)
clean:
	del /f *.o $(EXEC)
