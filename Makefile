# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fwerner <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:25:16 by fwerner           #+#    #+#              #
#    Updated: 2019/01/12 09:25:45 by fwerner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test-ls
CFLAGS = -Wall -Wextra --std=c++14
SRCS = $(wildcard *.cpp)
SRCS += $(wildcard funktionsprufer/*.cpp)
TPPS = $(wildcard *.tpp)
TPPS += $(wildcard funktionsprufer/*.tpp)
INCLUDES = $(wildcard *.hpp)
INCLUDES += $(wildcard funktionsprufer/*.hpp)
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	g++ $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp $(INCLUDES) $(TPPS)
	g++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all
