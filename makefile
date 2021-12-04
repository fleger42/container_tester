MINE = ft_container

REAL = std_container

CXX = clang++

CXXFLAGS = -Wall -Werror -Wextra

HEADER = -I ./copied_hpp_file/

SRCS = main_file/main.cpp

MINE_OBJ = $(SRCS:cpp=o)

REAL_OBJ = std_main.o

VALUE = 0
$(SET_VALUE):
		$(VALUE) = 1
all: $(MINE) $(REAL)

$(MINE): $(MINE_OBJ)
	@echo "\n"
	@echo "\033[0;32mCompiling program with my container..."
	@$(CXX) $(CXXFLAGS) ${HEADER} -o $(MINE) $(MINE_OBJ)
	@echo "\n\033[0mDone !"

$(REAL): $(REAL_OBJ)
	@echo "\n"
	@echo "\033[0;32mCompiling program with real container..."
	@$(CXX) $(CXXFLAGS) ${HEADER} -o $(REAL) std_main.o
	@echo "\n\033[0mDone !"

std_main.o:
	@${CXX} -D ACCESS=std ${HEADER} ${CXXFLAGS} -c ${SRCS} -o std_main.o

%.o: %.cpp
	@printf "\033[0;33mGenerating objects... %-33.33s\r" $@
ifeq ($(VALUE), 0)
	@${CXX} -D ACCESS=ft ${HEADER} ${CXXFLAGS} -c $< -o $@
else
	@${CXX} -D ACCESS=std ${HEADER} ${CXXFLAGS} -c $< -o std_main.o
endif

clean:
	@echo "\nRemoving binaries..."
	@rm -f $(MINE_OBJ) $(REAL_OBJ)
	@echo "\033[0m"

fclean:
	@echo "\nDeleting objects..."
	@rm -f $(MINE_OBJ) $(REAL_OBJ)
	@echo "\nDeleting executable..."
	@rm -f $(MINE) $(REAL)
	@echo "\033[0m"

re: fclean all

.PHONY: clean fclean re test norm