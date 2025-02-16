NAME = run_ex00

OBJS =  ScalarConverter.o main.o

FILES = ScalarConverter.cpp main.cpp

CXX = c++

RM = rm -rf

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all :  $(NAME)

%.o: %.cpp ScalarConverter.hpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME) :  $(OBJS) $(FILES)
	@echo "------>making the ex00<------"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "--------->ex00 Done<---------"

clean:
	@echo " remove $(OBJS)"
	@$(RM) $(OBJS)

fclean:  clean
	@echo " clean --> $(NAME)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean