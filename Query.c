/* Query.c generated by valac 0.56.13, the Vala compiler
 * generated from Query.vala, do not modify */

#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <glib/gstdio.h>
#include <glib-object.h>

#if !defined(VALA_EXTERN)
#if defined(_MSC_VER)
#define VALA_EXTERN __declspec(dllexport) extern
#elif __GNUC__ >= 4
#define VALA_EXTERN __attribute__((visibility("default"))) extern
#else
#define VALA_EXTERN extern
#endif
#endif

#define _g_free0(var) (var = (g_free (var), NULL))

#define TYPE_PACKAGE (package_get_type ())
typedef struct _Package Package;

struct _Package {
	gchar* name;
	gchar* author;
	gchar* version;
	gchar* description;
	gchar* binary;
	gchar* dependency;
	gchar* installed_files;
};

VALA_EXTERN gchar* LOCAL;

VALA_EXTERN gboolean query_is_exist (const gchar* name_pkg);
VALA_EXTERN GType package_get_type (void) G_GNUC_CONST ;
VALA_EXTERN Package* package_dup (const Package* self);
VALA_EXTERN void package_free (Package* self);
VALA_EXTERN void package_copy (const Package* self,
                   Package* dest);
VALA_EXTERN void package_destroy (Package* self);
G_DEFINE_AUTO_CLEANUP_CLEAR_FUNC (Package, package_destroy)
VALA_EXTERN void query_get_from_pkg (const gchar* name_pkg,
                         Package* result);
VALA_EXTERN void package_init_from_file (Package *self,
                             const gchar* info_file);

static const gchar*
string_to_string (const gchar* self)
{
	const gchar* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}

gboolean
query_is_exist (const gchar* name_pkg)
{
	const gchar* _tmp0_;
	const gchar* _tmp1_;
	const gchar* _tmp2_;
	gchar* _tmp3_;
	gchar* _tmp4_;
	gboolean _tmp5_;
	gboolean result;
	g_return_val_if_fail (name_pkg != NULL, FALSE);
	_tmp0_ = LOCAL;
	_tmp1_ = string_to_string (_tmp0_);
	_tmp2_ = string_to_string (name_pkg);
	_tmp3_ = g_strconcat (_tmp1_, "/", _tmp2_, "/info", NULL);
	_tmp4_ = _tmp3_;
	_tmp5_ = g_file_test (_tmp4_, G_FILE_TEST_EXISTS);
	_g_free0 (_tmp4_);
	result = _tmp5_;
	return result;
}

void
query_get_from_pkg (const gchar* name_pkg,
                    Package* result)
{
	Package pkg = {0};
	const gchar* _tmp0_;
	const gchar* _tmp1_;
	const gchar* _tmp2_;
	gchar* _tmp3_;
	gchar* _tmp4_;
	g_return_if_fail (name_pkg != NULL);
	_tmp0_ = LOCAL;
	_tmp1_ = string_to_string (_tmp0_);
	_tmp2_ = string_to_string (name_pkg);
	_tmp3_ = g_strconcat (_tmp1_, "/", _tmp2_, "/info", NULL);
	_tmp4_ = _tmp3_;
	package_init_from_file (&pkg, _tmp4_);
	_g_free0 (_tmp4_);
	*result = pkg;
	return;
}

