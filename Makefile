NAME= miniRT
SRC_PATH= work
SRC_B_PATH= work_bonus
HDR_PATH= headers
HDR_B_PATH= headers_bonus
OBJ_PATH= obj
OGL_PATH= ./minilibx_opengl_20191021
MMS_PATH= ./minilibx_mms_20200219
SRC_NAME=	main.c\
	error.c\
	first_parsing.c\
	camera.c\
	parsing_RT.c\
	color.c\
	raytracing.c\
	mlx_configue.c\
	vector_1.c\
	vector_2.c\
	vector_3.c\
	image.c\
	check.c\
	phong.c\
	list.c\
	list1.c\
	shading.c\
	plan.c\
	sphere.c\
	triangle.c\
	cylindre.c\
	square.c\
	bmp.c\
	translation.c\
	rotation.c\
	button_key.c\
	get_next_line.c\
	get_next_line_utils.c\
	ft_compare_end.c\
	ft_charSplit.c\
	ft_count.c\
	ft_samestr.c\
	ft_stringdel.c\
	ft_free_split.c\
	ft_calloc.c\
	ft_charCount.c\
	ft_lstsize.c\
	ft_list.c\
	add_list_back.c\
	convert_to_double.c\
	my_power.c\
	ft_atoi.c\
	ft_split.c\
	ft_isdigit.c\
	ft_strdup.c\
	ft_strlen.c\
	rot.c\
	
SRC_B_NAME= main_bonus.c\
	error_bonus.c\
	first_parsing_bonus.c\
	camera_bonus.c\
	parsing_RT_bonus.c\
	color_bonus.c\
	raytracing_bonus.c\
	mlx_configue_bonus.c\
	vector_1_bonus.c\
	vector_2_bonus.c\
	vector_3_bonus.c\
	image_bonus.c\
	check_bonus.c\
	phong_bonus.c\
	list_bonus.c\
	list1_bonus.c\
	shading_bonus.c\
	plan_bonus.c\
	sphere_bonus.c\
	triangle_bonus.c\
	cylindre_bonus.c\
	square_bonus.c\
	bmp_bonus.c\
	translation_bonus.c\
	rotation_bonus.c\
	button_key_bonus.c\
	get_next_line_bonus.c\
	get_next_line_utils_bonus.c\
	ft_compare_end_bonus.c\
	ft_charSplit_bonus.c\
	ft_count_bonus.c\
	ft_samestr_bonus.c\
	ft_stringdel_bonus.c\
	ft_free_split_bonus.c\
	ft_calloc_bonus.c\
	ft_charCount_bonus.c\
	ft_lstsize_bonus.c\
	ft_list_bonus.c\
	add_list_back_bonus.c\
	convert_to_double_bonus.c\
	my_power_bonus.c\
	ft_atoi_bonus.c\
	ft_split_bonus.c\
	ft_isdigit_bonus.c\
	ft_strdup_bonus.c\
	ft_strlen_bonus.c\
	rot_bonus.c\
	key_press_bonus.c\
	rotation_key_bonus.c\
	objects_mov_bonus.c \
	key_bonus.c\
	
HDR_NAME= use.h \
    objects.h \
    get_next_line.h \
    minirt.h \
	
HDR_B_NAME= use.h \
    objects.h \
    get_next_line.h \
    minirt.h \


OBJ_NAME= $(SRC_NAME:.c=.o)
OBJ_B_NAME= $(SRC_B_NAME:.c=.o)
OBJ= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJ_B= $(addprefix $(OBJ_PATH)/,$(OBJ_B_NAME))
SRC= $(addprefix $(SRC_PATH)/,$(SRC_NAME))
SRC_B= $(addprefix $(SRC_B_PATH)/,$(SRC_B_NAME))
HDR= $(addprefix $(HDR_PATH)/,$(HDR_NAME))
HDR_B= $(addprefix $(HDR_B_PATH)/,$(HDR_B_NAME))

FLAGS= -Wall -Wextra -Werror
LMLX_FLAG= -L ./minilibx_opengl_20191021 libmlx.a -L ./minilibx_mms_20200219 libmlx.dylib -framework OpenGL -framework AppKit
IMLX_FLAG= -I /usr/local/include
H_FLAG= -I headers
H_B_FLAG= -I headers_bonus
#***************************************************************************** #
COMP= gcc  
all: ogl mms $(NAME) 
$(NAME) :  $(OBJ) 
	@cp ./minilibx_opengl_20191021/libmlx.a .
	@cp ./minilibx_mms_20200219/libmlx.dylib .
	@$(COMP) $(H_FLAG) $(LMLX_FLAG) $(IMLX_FLAG)  $(OBJ) -o $@
	@clear
	@echo "            Made by : \033[1;91mZdnaya\033[m"
	@echo "          _       _______ _____    "
	@echo "         (_)     (_) ___ \_   _|   "
	@echo "  _ __ ___  _ _ __  _| |_/ / | |   "
	@echo " | '_ ' _ \| | '_ \| |    /  | |   "
	@echo " | | | | | | | | | | | |\ \  | |   "
	@echo " |_| |_| |_|_|_| |_|_\_| \_| \_/   "
	@echo "Compilation of $(NAME):  \033[1;32mOK\033[m"

bonus : ogl mms $(OBJ_B)
	@cp ./minilibx_opengl_20191021/libmlx.a .
	@cp ./minilibx_mms_20200219/libmlx.dylib .
	@$(COMP) $(H_B_FLAG)  $(LMLX_FLAG) $(IMLX_FLAG)  $(OBJ_B) -o $(NAME)
	@clear
	@echo "            Made by : \033[1;91mZdnaya\033[m"
	@echo "          _       _______ _____    "
	@echo "         (_)     (_) ___ \_   _|   "
	@echo "  _ __ ___  _ _ __  _| |_/ / | |   "
	@echo " | '_ ' _ \| | '_ \| |    /  | |   "
	@echo " | | | | | | | | | | | |\ \  | |   "
	@echo " |_| |_| |_|_|_| |_|_\_| \_| \_/   "
	@echo "Compilation of $(NAME):  \033[1;32mOK\033[m"

ogl:
	@make -sC $(OGL_PATH)
mms:
	@make -sC $(MMS_PATH)

$(OBJ_PATH)/%.o:  $(SRC_PATH)/%.c $(HDR)
	@mkdir -p $(OBJ_PATH) 
	@$(COMP) $(FLAGS) $(H_FLAG)  -o $@ -c $<
$(OBJ_PATH)/%.o:  $(SRC_B_PATH)/%.c $(HDR_B) 
	@mkdir -p $(OBJ_PATH) 
	@$(COMP) $(FLAGS) $(H_B_FLAG)  -o $@ -c $<
clean:
	@rm -rf $(OBJ_PATH)
	@echo "\033[1;33m>> all objects files are deleted.\033[0m" 
fclean: clean
	@rm -rf $(NAME)
	@rm -rf libmlx.a
	@rm -rf libmlx.dylib
	@make clean -sC $(OGL_PATH)
	@make clean -sC $(MMS_PATH)
	@echo "\033[0;31m>> $(NAME) && all obbjects are deleted.\033[0m" 
re : fclean all