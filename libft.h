/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apickett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:04:25 by apickett          #+#    #+#             */
/*   Updated: 2018/05/08 04:15:36 by apickett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

#ifndef LIBFT_H
# define LIBFT_H
# define STRSPLIT_VARS int x = 0; int y; int z = 0; char **table;
# define STRTRIM unsigned int x = 0; unsigned int y = 0; unsigned int z;

# define FAC(n) FAC ## n
# define FAC0 1
# define FAC1 1
# define FAC2 2
# define FAC3 6
# define FAC4 24
# define FAC5 120
# define FAC6 720
# define FAC7 5040
# define FAC8 40320
# define FAC9 362880
# define FAC10 3628800
# define FAC11 39916800
# define FAC12 479001600
# define FAC13 6227020800
# define FAC14 87178291200
# define FAC15 137674368000
# define FAC16 20922789888000
# define FAC17 355687428096000
# define FAC18 6402373705728000

# define PCAT(a, ...) a ## __VA_ARGS__
# define CAT(a, ...) EXP(PCAT(a, __VA_ARGS__))
# define EXP(...) EXP1(EXP1(EXP1(EXP1(__VA_ARGS__))))
# define EXP1(...) EXP2(EXP2(EXP2(EXP2(__VA_ARGS__))))
# define EXP2(...) EXP3(EXP3(EXP3(EXP3(__VA_ARGS__))))
# define EXP3(...) __VA_ARGS__

# define NOT(x) (EXP(!(x)))
# define OR(...) (EXP(INFIX_OP(||, __VA_ARGS__)))
# define AND(...) (EXP(INFIX_OP(&&, __VA_ARGS__)))
# define DO(...) EXP(INFIX_OP(;, __VA_ARGS__);)

# define ASM __asm__
# define ASMV __asm__ volatile
# define BREAK break
# define CONTINUE continue
# define GOTO(label) EXP(goto label)
# define DECL(type_, name) EXP(type_ name)
# define VAR(type_, name, value) EXP(type_ name = value)
# define TERN(cond, a, b) (EXP(cond ? a : b))
# define SWITCH(exp, ...) EXP(switch (exp) { DO(__VA_ARGS__)})
# define CASE(lit, ...) EXP(case lit : { DO(__VA_ARGS__)})
# define DEFAULT(...) EXP(default : { DO(__VA_ARGS__)})
# define IF(cond, ...) EXP(if (cond) { DO(__VA_ARGS__) })
# define ELSEIF(cond, ...) EXP(else if (cond) { DO(__VA_ARGS__) })
# define ELSE(...) EXP(else { DO(__VA_ARGS__) })
# define WHILE(cond, ...) EXP(while (cond) { DO(__VA_ARGS__) })
# define DOWHILE(cond, ...) EXP(do { DO(__VA_ARGS__) } while (cond))
# define FOR(i, c, u, ...) EXP(for (i; c; u) { DO(__VA_ARGS__) })
# define LOOP(...) EXP(for (;;) { DO(__VA_ARGS__) })

# define RET(ret) EXP(return (ret))
# define RETIF(ret, cond) EXP(if (cond) RET(ret))
# define NULLIF(cond) EXP(RETIF(NULL, cond))
# define NULLCHECK(...) EXP(RETIF(NULL, (NOT(AND(__VA_ARGS__)))))
# define RNULLCHECK(ret, ...) EXP(RETIF(ret, (NOT(AND(__VA_ARGS__)))))
# define FREE(...) EXP(APPLY(free, __VA_ARGS__))
# define CHKALLOC(...) EXP(IF(NOT(AND(__VA_ARGS__)), CHKALLOC2(__VA_ARGS__)))
# define CHKALLOC2(...) FREE(__VA_ARGS__), RET(NULL)

# define ISSPACE(c) (c == ' ' || c == '\t' || c == '\n' ISSPACE2(c)
# define ISSPACE2(c) || c == '\r' || c == '\v' || c == '\f')
# define ISDIGIT(c) (c >= '0' && c <= '9')
# define ABS(x) ((x) < 0 ? -(x) : (x))

# define POW(n, e) POW ## e (n)
# define POW1(n) (n)
# define POW2(n) (n*n)
# define POW3(n) (n*n*n)
# define POW4(n) (n*n*n*n)
# define POW5(n) (n*n*n*n*n)
# define POW6(n) (n*n*n*n*n*n)
# define POW7(n) (n*n*n*n*n*n*n)
# define POW8(n) (n*n*n*n*n*n*n*n)
# define POW9(n) (POW8(n)*POW1(n))
# define POW10(n) (POW8(n)*POW2(n))
# define POW11(n) (POW8(n)*POW3(n))
# define POW12(n) (POW8(n)*POW4(n))
# define POW13(n) (POW8(n)*POW5(n))
# define POW14(n) (POW8(n)*POW6(n))
# define POW15(n) (POW8(n)*POW7(n))
# define POW16(n) (POW8(n)*POW8(n))
# define POW17(n) (POW16(n)*POW1(n))
# define POW18(n) (POW16(n)*POW2(n))
# define POW19(n) (POW16(n)*POW3(n))
# define POW20(n) (POW16(n)*POW4(n))
# define POW21(n) (POW16(n)*POW5(n))
# define POW22(n) (POW16(n)*POW6(n))
# define POW23(n) (POW16(n)*POW7(n))
# define POW24(n) (POW16(n)*POW8(n))
# define POW25(n) (POW24(n)*POW1(n))
# define POW26(n) (POW24(n)*POW2(n))
# define POW27(n) (POW24(n)*POW3(n))
# define POW28(n) (POW24(n)*POW4(n))
# define POW29(n) (POW24(n)*POW5(n))
# define POW30(n) (POW24(n)*POW6(n))
# define POW31(n) (POW24(n)*POW7(n))
# define POW32(n) (POW24(n)*POW8(n))
# define POW33(n) (POW32(n)*POW1(n))
# define POW34(n) (POW32(n)*POW2(n))
# define POW35(n) (POW32(n)*POW3(n))
# define POW36(n) (POW32(n)*POW4(n))
# define POW37(n) (POW32(n)*POW5(n))
# define POW38(n) (POW32(n)*POW6(n))
# define POW39(n) (POW32(n)*POW7(n))
# define POW40(n) (POW32(n)*POW8(n))
# define POW41(n) (POW40(n)*POW1(n))
# define POW42(n) (POW40(n)*POW2(n))
# define POW43(n) (POW40(n)*POW3(n))
# define POW44(n) (POW40(n)*POW4(n))
# define POW45(n) (POW40(n)*POW5(n))
# define POW46(n) (POW40(n)*POW6(n))
# define POW47(n) (POW40(n)*POW7(n))
# define POW48(n) (POW40(n)*POW8(n))
# define POW49(n) (POW48(n)*POW1(n))
# define POW50(n) (POW48(n)*POW2(n))
# define POW51(n) (POW48(n)*POW3(n))
# define POW52(n) (POW48(n)*POW4(n))
# define POW53(n) (POW48(n)*POW5(n))
# define POW54(n) (POW48(n)*POW6(n))
# define POW55(n) (POW48(n)*POW7(n))
# define POW56(n) (POW48(n)*POW8(n))
# define POW57(n) (POW56(n)*POW1(n))
# define POW58(n) (POW56(n)*POW2(n))
# define POW59(n) (POW56(n)*POW3(n))
# define POW60(n) (POW56(n)*POW4(n))
# define POW61(n) (POW56(n)*POW5(n))
# define POW62(n) (POW56(n)*POW6(n))
# define POW63(n) (POW56(n)*POW7(n))

typedef enum	e_bool
{
	false,
	true
}				t_bool;

#endif

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(char const *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_isprime(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);
char				*ft_itoa(int n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dest, void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *str, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *src);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *str);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, unsigned int h);
char				*ft_strndup(const char *s1, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
char				*ft_strrchr(const char *str, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *str, const char *sub_str);
char				*ft_strsub(char const *s1, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
