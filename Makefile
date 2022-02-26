##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## wtf?
##

LOCATION = src

FILES = $(LOCATION)/main.cpp\
		$(LOCATION)/Components/GenericComponent.cpp\
		$(LOCATION)/NanoTekSpiceError.cpp\
		$(LOCATION)/Execution.cpp\
		$(LOCATION)/LogicGates/*.cpp

SRC =  $(FILES)

OBJ = $(SRC:.c=.o)

NAME = nanotekspice

CFLAGS = -Wall -Wextra -std=c++20

all:    $(NAME)

$(NAME): 	$(OBJ)
			g++ $(OBJ) $(CFLAGS) -o $(NAME) -I include;
			@make clean

clean:
		find -regex ".*/.*\.o" -delete;

fclean: clean;
		find -regex "./$(NAME)" -delete;
		find -regex ".*/$(TEST_NAME)-.*" -delete;

re: fclean
	@make $(NAME)

.PHONY: all clean
