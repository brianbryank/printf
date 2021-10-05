#ifndef HEADER
#define HEADER
#include <stdarg.h>

/*macro*/
#define BUF_LENGTH 1024



/*structs*/

/**
 * struct buf_type - contains buffer and count of chars so far
 * @count_c: number of chars put in buffer so far
 * @buffer: buffer
 * @buf_index: where to start inserting new string/char
 */
typedef struct buf_type
{
	char buffer[BUF_LENGTH];
	int count_c;
	int buf_index;
} buf_type;

/**
 * struct valid - check if formatting is valid
 * @type: type
 * @conversion_check:function to check if a conversion string is valid
 */
typedef struct valid
{
	char type;
	int (*conversion_check)(char *);
} valid;

/**
 * struct m_string -  valid format
 * @type: type of format
 * @make_s:make the string, fill the buffer
 */
typedef struct m_string
{
	char type;
	void (*make_s)(char *, va_list, buf_type *buf);
} m_string;


/*functions prototypes*/

/* in print.c*/
int _printf(const char *format, ...);
void error_format(const char *format);
int no_conversion(char);

/*in buffer_functions1.c*/
void _flush(char *buffer);
buf_type *fill_buffer(buf_type *buf, const char *s, int s_length);
void print_buffer(char *buffer, int length);
buf_type *fill_char_buffer(buf_type *buf, char c);

/*in format-handlers.c*/
void fill_format(const char *format);
char *grab_format(const char *s);

/* get_validity_func.c */
int (*get_validity_func(char c))(char *s);

/*in unihelper.c*/
int no_conversion(char c);
int _is_digit(char c);
char *_strncpy(char *dest, const char *src, int n);
int _strlen(const char *);
int _isdflag(char *c);

/* in unihelper2.c */
int give_precision(char *, char);
int give_width(char *, char);
char *get_result(char *, char *, int p, int w, int slen, int flen, int mlen);

/*in numbershelper.c */
int _nlen(unsigned int);
void reverse_array(char *, int);
char *base_conv(unsigned int, int, char *);

/*in unihelper3.c*/
void make_no_conversion(char *conv, buf_type *buf);

/*in get_mstring_func.c */
void (*get_mstring_func(char))(char *, va_list vl, buf_type *buf);

/*in chars.c*/
int conversion_char(char *s);
void make_char(char *s, va_list vl, buf_type *buf);

/*in strings.c*/
int conversion_string(char *s);
void make_string(char *s, va_list vl, buf_type *buf);

/*in percent.c*/
int conversion_percent(char *s);
void make_percent(char *s, va_list vl, buf_type *buf);

/* decimal.c */
int conversion_di(char *s);
void make_decimal(char *s, va_list vl, buf_type *buf);

/*unsigned.c */
int conversion_u(char *s);
void make_unsigned(char *s, va_list vl, buf_type *buf);
char *_utoa(unsigned int);

/*octal.c */
int conversion_o(char *s);
void make_octal(char *s, va_list vl, buf_type *buf);
char *octorbi(unsigned int, int);

/*binary.c*/
int conversion_b(char *s);
void make_binary(char *s, va_list vl, buf_type *buf);

/* hex. */
int conversion_h(char *s);
void make_hex(char *s, va_list vl, buf_type *buf);
char *hex(unsigned int);
void reverse_array(char *a, int n);

/* heX */
void make_heX(char *s, va_list vl, buf_type *buf);
char *heX(unsigned int);

/*in bigS.c*/
void _hexa(char n, char *nb);
void convert_S(char *, buf_type *);
int conversion_S(char *s);
void make_S(char *s, va_list vl, buf_type *buf);

/* reverse.c */
void rev_string(char *s);
int conversion_r(char *s);
void make_rev(char *s, va_list vl, buf_type *buf);
char *_strdup(char *str);

/* rot13.c */
int conversion_R(char *s);
void make_rot13(char *s, va_list vl, buf_type *buf);
char *rot13(char *s);
#endif
