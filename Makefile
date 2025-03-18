# Компилятор
CXX = g++

# Флаги компиляции
CXXFLAGS = -Wall -Wextra -std=c++23 -I.

# Исходные файлы
SRCS = main.cpp Graph.cpp utils.cpp validation.cpp

# Объектные файлы
OBJS = $(SRCS:.cpp=.o)

# Исполняемый файл
TARGET = main

# Тестовый файл
TESTS = tests.cpp
# Исходные файлы
SRCST = Graph.cpp utils.cpp validation.cpp
# Объектные файлы тестов
OBJST = $(SRCST:.cpp=.o)
# Исполняемый файл
TEST = test

# Правило по умолчанию
all: $(TARGET)

# Сборка исполняемого файла
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Правило для компиляции .cpp файлов в .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка
clean:
	rm -f $(OBJS) $(TARGET)

# Запуск тестов
$(TEST):
	$(CXX) $(CXXFLAGS) -o $(TEST) $(TESTS) $(OBJST)
check: $(TEST)
	./$(TEST)
	
.PHONY: all clean test