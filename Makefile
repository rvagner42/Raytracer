# **************************************************************************** #
#                                                                              #
#                                                            .:.               #
#    Makefile                                           .+:  :+:  :+.          #
#                                                      +:+   +:+   :+:         #
#    By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:        #
#                                                      +#+   '+'   +#+         #
#    Created:  2015/12/11 18:59:19 by rvagner           +#+,     ,+#+          #
#    Modified: 2015/12/12 18:51:02 by rvagner             '*+###+*'            #
#                                                                              #
# **************************************************************************** #

NAME = raytracer

SRC = main.cpp \
	Camera.cpp \
	Object.cpp \
	Pixel.cpp \
	Point.cpp \
	Process.cpp\
	Ray.cpp \
	Sphere.cpp \
	Vector.cpp \

SRC_DIR = Sources/

INC = Includes/

SDL_INC = -I/Volumes/Data/nfs/zfs-student-3/users/rvagner/.brew/include -D_THREAD_SAFE
SDL_LIB = -L/Volumes/Data/nfs/zfs-student-3/users/rvagner/.brew/lib

OBJ = $(SRC:.cpp=.o)

CC = clang++

FLAGS = -Wall -Werror -Wextra

LIB = -lSDL2

all: $(NAME)

$(NAME):
	@echo "Sources -> objets ... \c"
	@$(CC) $(FLAGS) -c $(addprefix $(SRC_DIR), $(SRC)) -I ./$(INC) $(SDL_INC)
	@echo "[\033[1;32mok\033[0m]"
	@echo "Objets -> $(NAME) ... \c"
	@$(CC) $(OBJ) -o $(NAME) $(SDL_LIB) $(LIB) -I ./$(INC) $(SDL_INC)
	@echo "[\033[1;32mok\033[0m]"
	@echo "Compilation terminée !"
	@mkdir Objets
	@mv $(OBJ) Objets

clean:
	@/bin/rm -rf Objets
	@echo "Les fichiers .o ont correctement étés supprimés !"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "L'exécutable a correctement été supprimé !"

re: fclean all

test: re
	@./$(NAME)
