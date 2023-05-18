SRC	=		000_basic_multithreading.cpp \
			001_shared_data.cpp \
			002_mutexes.cpp \
			003_passing_arguments.cpp \
			004_lock_guard.cpp \
			005_threads_with_callable_objects.cpp \
			006_calculating_PI_exercise.cpp \
			007_promises_and_futures_function_args.cpp \
			008_promises_and_futures_lambda_expr_for_promise.cpp \
			009_promises_and_futures_with_exception.cpp
BIN		=	$(SRC:.cpp=)
FLAGS	=	-Wextra -Werror -Wall -pthread

RED		=	\e[0;31m
GREEN	=	\e[0;32m
RESET	=	\e[0m

all: $(BIN)
	@echo

%: %.cpp
	@printf "$(GREEN)█ $(RESET)"
	@g++ $(FLAGS) $< -o $@

clean :
	@printf "$(RED)█ █ █ █ █ █ █ █ █ █$(RESET)\n"
	@rm -f $(BIN)

fclean: clean

re: fclean all

.PHONY: all clean fclean re