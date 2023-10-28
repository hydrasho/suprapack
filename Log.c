/* Log.c generated by valac 0.56.13, the Vala compiler
 * generated from Log.vala, do not modify */

#include <stdlib.h>
#include <string.h>
#include <glib.h>

#define BLANK "                                                  "
#define BOLD "\033[;1m"
#define COM "\033[;2m"
#define INV "\033[;7m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define GREY "\033[37m"
#define WHITE "\033[39m"
#define CYAN "\033[96m"
#define PURPLE "\033[35m"
#define NONE "\033[0m"
#if !defined(VALA_EXTERN)
#if defined(_MSC_VER)
#define VALA_EXTERN __declspec(dllexport) extern
#elif __GNUC__ >= 4
#define VALA_EXTERN __attribute__((visibility("default"))) extern
#else
#define VALA_EXTERN extern
#endif
#endif

VALA_EXTERN void print_info (const gchar* msg,
                 const gchar* prefix);
VALA_EXTERN void print_update (const gchar* msg);
VALA_EXTERN void print_error (const gchar* msg);

void
print_info (const gchar* msg,
            const gchar* prefix)
{
	g_return_if_fail (prefix != NULL);
	if (msg == NULL) {
		g_print ("\033[33;1m[%s]\033[0m\n", prefix);
	} else {
		g_print ("\033[33;1m[%s]\033[0m: %s\n", prefix, msg);
	}
}

void
print_update (const gchar* msg)
{
	g_return_if_fail (msg != NULL);
	g_print ("\033[93;1m[Update]\033[0m: %s\n", msg);
}

void
print_error (const gchar* msg)
{
	g_return_if_fail (msg != NULL);
	g_print ("\033[91;1m[Error]\033[0m: %s\n", msg);
	exit (1);
}

