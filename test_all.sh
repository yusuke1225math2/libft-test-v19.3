# run this file from .. with ./tests/test_all.sh
alias ccw='cc -Werror -Wall -Wextra'
ccwtest() {
  local use_valgrind=0
  local target=""
  local arg
  for arg in "$@"; do
    case "$arg" in
      -v) use_valgrind=1 ;;
      *) if [ -n "$target" ]; then
           echo "usage: ccwtest [-v] <file.c> [-v]" >&2
           return 1
         fi
         target="$arg" ;;
    esac
  done
  if [ -z "$target" ]; then
    echo "usage: ccwtest [-v] <file.c> [-v]" >&2
    return 1
  fi
  set -- "$target"
  make && cc -g -fsanitize=address -Werror -Wall -Wextra -lbsd tests/utils.c "tests/test_$1" libft.a && ASAN_OPTIONS=allocator_may_return_null=1 ./a.out || return
  if [ "$use_valgrind" -eq 1 ]; then
    valgrind --leak-check=full ./a.out
  fi
}
ccwtest ft_isalpha.c
ccwtest ft_isdigit.c
ccwtest ft_isalnum.c
ccwtest ft_isascii.c
ccwtest ft_isprint.c
ccwtest ft_strlen.c
ccwtest ft_memset.c
ccwtest ft_bzero.c
ccwtest ft_memcpy.c
ccwtest ft_memmove.c
ccwtest ft_strlcpy.c
ccwtest ft_strlcat.c
ccwtest ft_toupper.c
ccwtest ft_tolower.c
ccwtest ft_strchr.c
ccwtest ft_strrchr.c
ccwtest ft_strncmp.c
ccwtest ft_memchr.c
ccwtest ft_memcmp.c
ccwtest ft_strnstr.c
ccwtest ft_atoi.c
ccwtest ft_calloc.c
ccwtest ft_strdup.c
ccwtest ft_substr.c
ccwtest ft_strjoin.c
ccwtest ft_strtrim.c
ccwtest ft_split.c
ccwtest ft_itoa.c
ccwtest ft_strmapi.c
ccwtest ft_striteri.c
ccwtest ft_putchar_fd.c
ccwtest ft_putstr_fd.c
ccwtest ft_putendl_fd.c
ccwtest ft_putnbr_fd.c
ccwtest ft_lstnew.c
ccwtest ft_lstadd_front.c
ccwtest ft_lstsize.c
ccwtest ft_lstlast.c
ccwtest ft_lstadd_back.c
ccwtest ft_lstdelone.c
ccwtest ft_lstclear.c
ccwtest ft_lstiter.c
ccw -g -fsanitize=address tests/test_ft_lstmap.c tests/utils.c \
	libft.a -Wl,--wrap=ft_lstnew && ./a.out
