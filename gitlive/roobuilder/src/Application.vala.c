/* Application.vala.c generated by valac, the Vala compiler
 * generated from Application.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <glib/gstdio.h>
#include <json-glib/json-glib.h>
#include <gtk/gtk.h>
#include <gio/gio.h>
#include <stdio.h>


#define TYPE_APP_SETTINGS (app_settings_get_type ())
#define APP_SETTINGS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_APP_SETTINGS, AppSettings))
#define APP_SETTINGS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_APP_SETTINGS, AppSettingsClass))
#define IS_APP_SETTINGS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_APP_SETTINGS))
#define IS_APP_SETTINGS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_APP_SETTINGS))
#define APP_SETTINGS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_APP_SETTINGS, AppSettingsClass))

typedef struct _AppSettings AppSettings;
typedef struct _AppSettingsClass AppSettingsClass;
typedef struct _AppSettingsPrivate AppSettingsPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define TYPE_BUILDER_APPLICATION (builder_application_get_type ())
#define BUILDER_APPLICATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_BUILDER_APPLICATION, BuilderApplication))
#define BUILDER_APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_BUILDER_APPLICATION, BuilderApplicationClass))
#define IS_BUILDER_APPLICATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_BUILDER_APPLICATION))
#define IS_BUILDER_APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_BUILDER_APPLICATION))
#define BUILDER_APPLICATION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_BUILDER_APPLICATION, BuilderApplicationClass))

typedef struct _BuilderApplication BuilderApplication;
typedef struct _BuilderApplicationClass BuilderApplicationClass;
typedef struct _BuilderApplicationPrivate BuilderApplicationPrivate;

#define BUILDER_APPLICATION_TYPE_TARGET (builder_application_target_get_type ())
#define _g_option_context_free0(var) ((var == NULL) ? NULL : (var = (g_option_context_free (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _AppSettings {
	GObject parent_instance;
	AppSettingsPrivate * priv;
};

struct _AppSettingsClass {
	GObjectClass parent_class;
};

struct _AppSettingsPrivate {
	gchar* _roo_html_dir;
};

struct _BuilderApplication {
	GtkApplication parent_instance;
	BuilderApplicationPrivate * priv;
	AppSettings* settings;
};

struct _BuilderApplicationClass {
	GtkApplicationClass parent_class;
};

typedef enum  {
	BUILDER_APPLICATION_TARGET_INT32,
	BUILDER_APPLICATION_TARGET_STRING,
	BUILDER_APPLICATION_TARGET_ROOTWIN
} BuilderApplicationTarget;


static gpointer app_settings_parent_class = NULL;
extern BuilderApplication* application;
BuilderApplication* application = NULL;
static gpointer builder_application_parent_class = NULL;
extern gchar* builder_application_opt_compile_project;
gchar* builder_application_opt_compile_project = NULL;
extern gchar* builder_application_opt_compile_target;
gchar* builder_application_opt_compile_target = NULL;
extern gchar* builder_application_opt_compile_skip;
gchar* builder_application_opt_compile_skip = NULL;
extern gchar* builder_application_opt_compile_add;
gchar* builder_application_opt_compile_add = NULL;
extern gchar* builder_application_opt_compile_output;
gchar* builder_application_opt_compile_output = NULL;
extern gchar* builder_application_opt_bjs_compile;
gchar* builder_application_opt_bjs_compile = NULL;
extern gchar* builder_application_opt_bjs_compile_target;
gchar* builder_application_opt_bjs_compile_target = NULL;
extern gboolean builder_application_opt_debug;
gboolean builder_application_opt_debug = FALSE;
extern gboolean builder_application_opt_list_projects;
gboolean builder_application_opt_list_projects = FALSE;
extern gboolean builder_application_opt_list_files;
gboolean builder_application_opt_list_files = FALSE;
extern gchar* builder_application__self;
gchar* builder_application__self = NULL;

GType app_settings_get_type (void) G_GNUC_CONST;
#define APP_SETTINGS_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_APP_SETTINGS, AppSettingsPrivate))
enum  {
	APP_SETTINGS_DUMMY_PROPERTY,
	APP_SETTINGS_ROO_HTML_DIR
};
AppSettings* app_settings_new (void);
AppSettings* app_settings_construct (GType object_type);
static void __lambda8_ (AppSettings* self);
void app_settings_save (AppSettings* self);
static void ___lambda8__g_object_notify (GObject* _sender, GParamSpec* pspec, gpointer self);
AppSettings* app_settings_factory (void);
gchar* builder_application_configDirectory (void);
const gchar* app_settings_get_roo_html_dir (AppSettings* self);
void app_settings_set_roo_html_dir (AppSettings* self, const gchar* value);
static void app_settings_finalize (GObject* obj);
static void _vala_app_settings_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_app_settings_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
GType builder_application_get_type (void) G_GNUC_CONST;
enum  {
	BUILDER_APPLICATION_DUMMY_PROPERTY
};
static GType builder_application_target_get_type (void) G_GNUC_CONST G_GNUC_UNUSED;
BuilderApplication* builder_application_new (gchar** args, int args_length1);
BuilderApplication* builder_application_construct (GType object_type, gchar** args, int args_length1);
BuilderApplication* builder_application_singleton (gchar** args, int args_length1);
static void builder_application_finalize (GObject* obj);

static const GOptionEntry BUILDER_APPLICATION_options[11] = {{"project", (gchar) 0, 0, G_OPTION_ARG_STRING, &builder_application_opt_compile_project, "Compile a project", NULL}, {"target", (gchar) 0, 0, G_OPTION_ARG_STRING, &builder_application_opt_compile_target, "Target to build", NULL}, {"skip-file", (gchar) 0, 0, G_OPTION_ARG_STRING, &builder_application_opt_compile_skip, "For test compiles do not add this (usually used in conjunction with ad" \
"d-file ", NULL}, {"add-file", (gchar) 0, 0, G_OPTION_ARG_STRING, &builder_application_opt_compile_add, "Add this file to compile list", NULL}, {"output", (gchar) 0, 0, G_OPTION_ARG_STRING, &builder_application_opt_compile_output, "output binary file path", NULL}, {"debug", (gchar) 0, 0, G_OPTION_ARG_NONE, &builder_application_opt_debug, "Show debug messages", NULL}, {"list-projects", (gchar) 0, 0, G_OPTION_ARG_NONE, &builder_application_opt_list_projects, "List Projects", NULL}, {"list-files", (gchar) 0, 0, G_OPTION_ARG_NONE, &builder_application_opt_list_files, "List Files (in a project", NULL}, {"bjs", (gchar) 0, 0, G_OPTION_ARG_STRING, &builder_application_opt_bjs_compile, "convert bjs file", NULL}, {"bjs-target", (gchar) 0, 0, G_OPTION_ARG_STRING, &builder_application_opt_bjs_compile_target, "convert bjs file to tareet  : vala / js", NULL}, {NULL}};
const GtkTargetEntry BUILDER_APPLICATION_targetList[5] = {{"INTEGER", (guint) 0, (guint) BUILDER_APPLICATION_TARGET_INT32}, {"STRING", (guint) 0, (guint) BUILDER_APPLICATION_TARGET_STRING}, {"application/json", (guint) 0, (guint) BUILDER_APPLICATION_TARGET_STRING}, {"text/plain", (guint) 0, (guint) BUILDER_APPLICATION_TARGET_STRING}, {"application/x-rootwindow-drop", (guint) 0, (guint) BUILDER_APPLICATION_TARGET_ROOTWIN}};

static void __lambda8_ (AppSettings* self) {
#line 14 "/home/alan/gitlive/roobuilder/src/Application.vala"
	app_settings_save (self);
#line 136 "Application.vala.c"
}


static void ___lambda8__g_object_notify (GObject* _sender, GParamSpec* pspec, gpointer self) {
#line 13 "/home/alan/gitlive/roobuilder/src/Application.vala"
	__lambda8_ ((AppSettings*) self);
#line 143 "Application.vala.c"
}


AppSettings* app_settings_construct (GType object_type) {
	AppSettings * self = NULL;
#line 11 "/home/alan/gitlive/roobuilder/src/Application.vala"
	self = (AppSettings*) g_object_new (object_type, NULL);
#line 13 "/home/alan/gitlive/roobuilder/src/Application.vala"
	g_signal_connect_object ((GObject*) self, "notify", (GCallback) ___lambda8__g_object_notify, self, 0);
#line 11 "/home/alan/gitlive/roobuilder/src/Application.vala"
	return self;
#line 155 "Application.vala.c"
}


AppSettings* app_settings_new (void) {
#line 11 "/home/alan/gitlive/roobuilder/src/Application.vala"
	return app_settings_construct (TYPE_APP_SETTINGS);
#line 162 "Application.vala.c"
}


AppSettings* app_settings_factory (void) {
	AppSettings* result = NULL;
	gchar* setting_file = NULL;
	gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	const gchar* _tmp4_ = NULL;
	gboolean _tmp5_ = FALSE;
	gchar* data = NULL;
	const gchar* _tmp7_ = NULL;
	gchar* _tmp8_ = NULL;
	GObject* _tmp9_ = NULL;
	const gchar* _tmp10_ = NULL;
	GObject* _tmp11_ = NULL;
	GObject* _tmp12_ = NULL;
	AppSettings* _tmp13_ = NULL;
	GError * _inner_error_ = NULL;
#line 21 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp0_ = builder_application_configDirectory ();
#line 21 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp1_ = _tmp0_;
#line 21 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp2_ = g_strconcat (_tmp1_, "/builder.settings", NULL);
#line 21 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp3_ = _tmp2_;
#line 21 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_g_free0 (_tmp1_);
#line 21 "/home/alan/gitlive/roobuilder/src/Application.vala"
	setting_file = _tmp3_;
#line 23 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp4_ = setting_file;
#line 23 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp5_ = g_file_test (_tmp4_, G_FILE_TEST_EXISTS);
#line 23 "/home/alan/gitlive/roobuilder/src/Application.vala"
	if (!_tmp5_) {
#line 202 "Application.vala.c"
		AppSettings* _tmp6_ = NULL;
#line 24 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_tmp6_ = app_settings_new ();
#line 24 "/home/alan/gitlive/roobuilder/src/Application.vala"
		result = _tmp6_;
#line 24 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_g_free0 (setting_file);
#line 24 "/home/alan/gitlive/roobuilder/src/Application.vala"
		return result;
#line 212 "Application.vala.c"
	}
#line 27 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp7_ = setting_file;
#line 27 "/home/alan/gitlive/roobuilder/src/Application.vala"
	g_file_get_contents (_tmp7_, &_tmp8_, NULL, &_inner_error_);
#line 27 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_g_free0 (data);
#line 27 "/home/alan/gitlive/roobuilder/src/Application.vala"
	data = _tmp8_;
#line 27 "/home/alan/gitlive/roobuilder/src/Application.vala"
	if (G_UNLIKELY (_inner_error_ != NULL)) {
#line 27 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_g_free0 (data);
#line 27 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_g_free0 (setting_file);
#line 27 "/home/alan/gitlive/roobuilder/src/Application.vala"
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
#line 27 "/home/alan/gitlive/roobuilder/src/Application.vala"
		g_clear_error (&_inner_error_);
#line 27 "/home/alan/gitlive/roobuilder/src/Application.vala"
		return NULL;
#line 234 "Application.vala.c"
	}
#line 28 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp10_ = data;
#line 28 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp11_ = json_gobject_from_data (TYPE_APP_SETTINGS, _tmp10_, (gssize) -1, &_inner_error_);
#line 28 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp9_ = _tmp11_;
#line 28 "/home/alan/gitlive/roobuilder/src/Application.vala"
	if (G_UNLIKELY (_inner_error_ != NULL)) {
#line 28 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_g_free0 (data);
#line 28 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_g_free0 (setting_file);
#line 28 "/home/alan/gitlive/roobuilder/src/Application.vala"
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
#line 28 "/home/alan/gitlive/roobuilder/src/Application.vala"
		g_clear_error (&_inner_error_);
#line 28 "/home/alan/gitlive/roobuilder/src/Application.vala"
		return NULL;
#line 254 "Application.vala.c"
	}
#line 28 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp12_ = _tmp9_;
#line 28 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp9_ = NULL;
#line 28 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp13_ = G_TYPE_CHECK_INSTANCE_TYPE (_tmp12_, TYPE_APP_SETTINGS) ? ((AppSettings*) _tmp12_) : NULL;
#line 28 "/home/alan/gitlive/roobuilder/src/Application.vala"
	if (_tmp13_ == NULL) {
#line 28 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_g_object_unref0 (_tmp12_);
#line 266 "Application.vala.c"
	}
#line 28 "/home/alan/gitlive/roobuilder/src/Application.vala"
	result = _tmp13_;
#line 28 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_g_object_unref0 (_tmp9_);
#line 28 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_g_free0 (data);
#line 28 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_g_free0 (setting_file);
#line 28 "/home/alan/gitlive/roobuilder/src/Application.vala"
	return result;
#line 278 "Application.vala.c"
}


void app_settings_save (AppSettings* self) {
	gchar* dirname = NULL;
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	gchar* setting_file = NULL;
	gchar* _tmp2_ = NULL;
	gchar* data = NULL;
	gchar* _tmp3_ = NULL;
	GError * _inner_error_ = NULL;
#line 32 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp0_ = g_get_home_dir ();
#line 32 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp1_ = g_strconcat (_tmp0_, "/.Builder", NULL);
#line 32 "/home/alan/gitlive/roobuilder/src/Application.vala"
	dirname = _tmp1_;
#line 33 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp2_ = g_strconcat (dirname, "/builder.settings", NULL);
#line 33 "/home/alan/gitlive/roobuilder/src/Application.vala"
	setting_file = _tmp2_;
#line 34 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp3_ = json_gobject_to_data ((GObject*) self, NULL);
#line 34 "/home/alan/gitlive/roobuilder/src/Application.vala"
	data = _tmp3_;
#line 35 "/home/alan/gitlive/roobuilder/src/Application.vala"
	g_print ("saving application settings\n");
#line 36 "/home/alan/gitlive/roobuilder/src/Application.vala"
	g_file_set_contents (setting_file, data, (gssize) -1, &_inner_error_);
#line 36 "/home/alan/gitlive/roobuilder/src/Application.vala"
	if (G_UNLIKELY (_inner_error_ != NULL)) {
#line 36 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_g_free0 (data);
#line 36 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_g_free0 (setting_file);
#line 36 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_g_free0 (dirname);
#line 36 "/home/alan/gitlive/roobuilder/src/Application.vala"
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
#line 36 "/home/alan/gitlive/roobuilder/src/Application.vala"
		g_clear_error (&_inner_error_);
#line 36 "/home/alan/gitlive/roobuilder/src/Application.vala"
		return;
#line 323 "Application.vala.c"
	}
#line 30 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_g_free0 (data);
#line 30 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_g_free0 (setting_file);
#line 30 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_g_free0 (dirname);
#line 331 "Application.vala.c"
}


const gchar* app_settings_get_roo_html_dir (AppSettings* self) {
	const gchar* result;
	const gchar* _tmp0_ = NULL;
#line 9 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp0_ = self->priv->_roo_html_dir;
#line 9 "/home/alan/gitlive/roobuilder/src/Application.vala"
	result = _tmp0_;
#line 9 "/home/alan/gitlive/roobuilder/src/Application.vala"
	return result;
#line 344 "Application.vala.c"
}


void app_settings_set_roo_html_dir (AppSettings* self, const gchar* value) {
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
#line 9 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp0_ = value;
#line 9 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp1_ = g_strdup (_tmp0_);
#line 9 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_g_free0 (self->priv->_roo_html_dir);
#line 9 "/home/alan/gitlive/roobuilder/src/Application.vala"
	self->priv->_roo_html_dir = _tmp1_;
#line 9 "/home/alan/gitlive/roobuilder/src/Application.vala"
	g_object_notify ((GObject *) self, "roo-html-dir");
#line 361 "Application.vala.c"
}


static void app_settings_class_init (AppSettingsClass * klass) {
#line 3 "/home/alan/gitlive/roobuilder/src/Application.vala"
	app_settings_parent_class = g_type_class_peek_parent (klass);
#line 3 "/home/alan/gitlive/roobuilder/src/Application.vala"
	g_type_class_add_private (klass, sizeof (AppSettingsPrivate));
#line 3 "/home/alan/gitlive/roobuilder/src/Application.vala"
	G_OBJECT_CLASS (klass)->get_property = _vala_app_settings_get_property;
#line 3 "/home/alan/gitlive/roobuilder/src/Application.vala"
	G_OBJECT_CLASS (klass)->set_property = _vala_app_settings_set_property;
#line 3 "/home/alan/gitlive/roobuilder/src/Application.vala"
	G_OBJECT_CLASS (klass)->finalize = app_settings_finalize;
#line 3 "/home/alan/gitlive/roobuilder/src/Application.vala"
	g_object_class_install_property (G_OBJECT_CLASS (klass), APP_SETTINGS_ROO_HTML_DIR, g_param_spec_string ("roo-html-dir", "roo-html-dir", "roo-html-dir", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
#line 378 "Application.vala.c"
}


static void app_settings_instance_init (AppSettings * self) {
#line 3 "/home/alan/gitlive/roobuilder/src/Application.vala"
	self->priv = APP_SETTINGS_GET_PRIVATE (self);
#line 385 "Application.vala.c"
}


static void app_settings_finalize (GObject* obj) {
	AppSettings * self;
#line 3 "/home/alan/gitlive/roobuilder/src/Application.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_APP_SETTINGS, AppSettings);
#line 9 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_g_free0 (self->priv->_roo_html_dir);
#line 3 "/home/alan/gitlive/roobuilder/src/Application.vala"
	G_OBJECT_CLASS (app_settings_parent_class)->finalize (obj);
#line 397 "Application.vala.c"
}


GType app_settings_get_type (void) {
	static volatile gsize app_settings_type_id__volatile = 0;
	if (g_once_init_enter (&app_settings_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (AppSettingsClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) app_settings_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (AppSettings), 0, (GInstanceInitFunc) app_settings_instance_init, NULL };
		GType app_settings_type_id;
		app_settings_type_id = g_type_register_static (G_TYPE_OBJECT, "AppSettings", &g_define_type_info, 0);
		g_once_init_leave (&app_settings_type_id__volatile, app_settings_type_id);
	}
	return app_settings_type_id__volatile;
}


static void _vala_app_settings_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	AppSettings * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, TYPE_APP_SETTINGS, AppSettings);
#line 3 "/home/alan/gitlive/roobuilder/src/Application.vala"
	switch (property_id) {
#line 3 "/home/alan/gitlive/roobuilder/src/Application.vala"
		case APP_SETTINGS_ROO_HTML_DIR:
#line 3 "/home/alan/gitlive/roobuilder/src/Application.vala"
		g_value_set_string (value, app_settings_get_roo_html_dir (self));
#line 3 "/home/alan/gitlive/roobuilder/src/Application.vala"
		break;
#line 424 "Application.vala.c"
		default:
#line 3 "/home/alan/gitlive/roobuilder/src/Application.vala"
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
#line 3 "/home/alan/gitlive/roobuilder/src/Application.vala"
		break;
#line 430 "Application.vala.c"
	}
}


static void _vala_app_settings_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	AppSettings * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, TYPE_APP_SETTINGS, AppSettings);
#line 3 "/home/alan/gitlive/roobuilder/src/Application.vala"
	switch (property_id) {
#line 3 "/home/alan/gitlive/roobuilder/src/Application.vala"
		case APP_SETTINGS_ROO_HTML_DIR:
#line 3 "/home/alan/gitlive/roobuilder/src/Application.vala"
		app_settings_set_roo_html_dir (self, g_value_get_string (value));
#line 3 "/home/alan/gitlive/roobuilder/src/Application.vala"
		break;
#line 446 "Application.vala.c"
		default:
#line 3 "/home/alan/gitlive/roobuilder/src/Application.vala"
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
#line 3 "/home/alan/gitlive/roobuilder/src/Application.vala"
		break;
#line 452 "Application.vala.c"
	}
}


static GType builder_application_target_get_type (void) {
	static volatile gsize builder_application_target_type_id__volatile = 0;
	if (g_once_init_enter (&builder_application_target_type_id__volatile)) {
		static const GEnumValue values[] = {{BUILDER_APPLICATION_TARGET_INT32, "BUILDER_APPLICATION_TARGET_INT32", "int32"}, {BUILDER_APPLICATION_TARGET_STRING, "BUILDER_APPLICATION_TARGET_STRING", "string"}, {BUILDER_APPLICATION_TARGET_ROOTWIN, "BUILDER_APPLICATION_TARGET_ROOTWIN", "rootwin"}, {0, NULL, NULL}};
		GType builder_application_target_type_id;
		builder_application_target_type_id = g_enum_register_static ("BuilderApplicationTarget", values);
		g_once_init_leave (&builder_application_target_type_id__volatile, builder_application_target_type_id);
	}
	return builder_application_target_type_id__volatile;
}


BuilderApplication* builder_application_construct (GType object_type, gchar** args, int args_length1) {
	BuilderApplication * self = NULL;
	gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	const gchar* _tmp3_ = NULL;
	gchar* _tmp4_ = NULL;
	gchar* _tmp5_ = NULL;
	AppSettings* _tmp6_ = NULL;
	GOptionContext* opt_context = NULL;
	GOptionContext* _tmp7_ = NULL;
	GError * _inner_error_ = NULL;
#line 104 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp1_ = g_file_read_link ("/proc/self/exe", &_inner_error_);
#line 104 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp0_ = _tmp1_;
#line 104 "/home/alan/gitlive/roobuilder/src/Application.vala"
	if (G_UNLIKELY (_inner_error_ != NULL)) {
#line 104 "/home/alan/gitlive/roobuilder/src/Application.vala"
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
#line 104 "/home/alan/gitlive/roobuilder/src/Application.vala"
		g_clear_error (&_inner_error_);
#line 104 "/home/alan/gitlive/roobuilder/src/Application.vala"
		return NULL;
#line 493 "Application.vala.c"
	}
#line 104 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp2_ = _tmp0_;
#line 104 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp0_ = NULL;
#line 104 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_g_free0 (builder_application__self);
#line 104 "/home/alan/gitlive/roobuilder/src/Application.vala"
	builder_application__self = _tmp2_;
#line 105 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp3_ = builder_application__self;
#line 105 "/home/alan/gitlive/roobuilder/src/Application.vala"
	g_debug ("Application.vala:105: SELF = %s", _tmp3_);
#line 107 "/home/alan/gitlive/roobuilder/src/Application.vala"
	self = (BuilderApplication*) g_object_new (object_type, "application-id", "org.roojs.app-builder", "flags", G_APPLICATION_FLAGS_NONE, NULL);
#line 112 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp4_ = builder_application_configDirectory ();
#line 112 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp5_ = _tmp4_;
#line 112 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_g_free0 (_tmp5_);
#line 113 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp6_ = app_settings_factory ();
#line 113 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_g_object_unref0 (self->settings);
#line 113 "/home/alan/gitlive/roobuilder/src/Application.vala"
	self->settings = _tmp6_;
#line 114 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp7_ = g_option_context_new ("Application Builder");
#line 114 "/home/alan/gitlive/roobuilder/src/Application.vala"
	opt_context = _tmp7_;
#line 525 "Application.vala.c"
	{
		GOptionContext* _tmp8_ = NULL;
		GOptionContext* _tmp9_ = NULL;
		GOptionContext* _tmp10_ = NULL;
#line 117 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_tmp8_ = opt_context;
#line 117 "/home/alan/gitlive/roobuilder/src/Application.vala"
		g_option_context_set_help_enabled (_tmp8_, TRUE);
#line 118 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_tmp9_ = opt_context;
#line 118 "/home/alan/gitlive/roobuilder/src/Application.vala"
		g_option_context_add_main_entries (_tmp9_, BUILDER_APPLICATION_options, NULL);
#line 119 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_tmp10_ = opt_context;
#line 119 "/home/alan/gitlive/roobuilder/src/Application.vala"
		g_option_context_parse (_tmp10_, &args_length1, &args, &_inner_error_);
#line 119 "/home/alan/gitlive/roobuilder/src/Application.vala"
		if (G_UNLIKELY (_inner_error_ != NULL)) {
#line 119 "/home/alan/gitlive/roobuilder/src/Application.vala"
			if (_inner_error_->domain == G_OPTION_ERROR) {
#line 546 "Application.vala.c"
				goto __catch56_g_option_error;
			}
#line 119 "/home/alan/gitlive/roobuilder/src/Application.vala"
			_g_option_context_free0 (opt_context);
#line 119 "/home/alan/gitlive/roobuilder/src/Application.vala"
			_g_free0 (_tmp0_);
#line 119 "/home/alan/gitlive/roobuilder/src/Application.vala"
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
#line 119 "/home/alan/gitlive/roobuilder/src/Application.vala"
			g_clear_error (&_inner_error_);
#line 119 "/home/alan/gitlive/roobuilder/src/Application.vala"
			return NULL;
#line 559 "Application.vala.c"
		}
	}
	goto __finally56;
	__catch56_g_option_error:
	{
		GError* e = NULL;
		FILE* _tmp11_ = NULL;
		const gchar* _tmp12_ = NULL;
		FILE* _tmp13_ = NULL;
		gchar** _tmp14_ = NULL;
		gint _tmp14__length1 = 0;
		const gchar* _tmp15_ = NULL;
		GOptionContext* _tmp16_ = NULL;
		gchar* _tmp17_ = NULL;
		gchar* _tmp18_ = NULL;
#line 116 "/home/alan/gitlive/roobuilder/src/Application.vala"
		e = _inner_error_;
#line 116 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_inner_error_ = NULL;
#line 123 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_tmp11_ = stdout;
#line 123 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_tmp12_ = e->message;
#line 123 "/home/alan/gitlive/roobuilder/src/Application.vala"
		fprintf (_tmp11_, "error: %s\n", _tmp12_);
#line 124 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_tmp13_ = stdout;
#line 124 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_tmp14_ = args;
#line 124 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_tmp14__length1 = args_length1;
#line 124 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_tmp15_ = _tmp14_[0];
#line 124 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_tmp16_ = opt_context;
#line 124 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_tmp17_ = g_option_context_get_help (_tmp16_, TRUE, NULL);
#line 124 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_tmp18_ = _tmp17_;
#line 124 "/home/alan/gitlive/roobuilder/src/Application.vala"
		fprintf (_tmp13_, "Run '%s --help' to see a full list of available command line options.\n" \
" %s", _tmp15_, _tmp18_);
#line 124 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_g_free0 (_tmp18_);
#line 126 "/home/alan/gitlive/roobuilder/src/Application.vala"
		exit (EXIT_FAILURE);
#line 116 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_g_error_free0 (e);
#line 607 "Application.vala.c"
	}
	__finally56:
#line 116 "/home/alan/gitlive/roobuilder/src/Application.vala"
	if (G_UNLIKELY (_inner_error_ != NULL)) {
#line 116 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_g_option_context_free0 (opt_context);
#line 116 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_g_free0 (_tmp0_);
#line 116 "/home/alan/gitlive/roobuilder/src/Application.vala"
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
#line 116 "/home/alan/gitlive/roobuilder/src/Application.vala"
		g_clear_error (&_inner_error_);
#line 116 "/home/alan/gitlive/roobuilder/src/Application.vala"
		return NULL;
#line 622 "Application.vala.c"
	}
#line 101 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_g_option_context_free0 (opt_context);
#line 101 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_g_free0 (_tmp0_);
#line 101 "/home/alan/gitlive/roobuilder/src/Application.vala"
	return self;
#line 630 "Application.vala.c"
}


BuilderApplication* builder_application_new (gchar** args, int args_length1) {
#line 101 "/home/alan/gitlive/roobuilder/src/Application.vala"
	return builder_application_construct (TYPE_BUILDER_APPLICATION, args, args_length1);
#line 637 "Application.vala.c"
}


static gpointer _g_object_ref0 (gpointer self) {
#line 141 "/home/alan/gitlive/roobuilder/src/Application.vala"
	return self ? g_object_ref (self) : NULL;
#line 644 "Application.vala.c"
}


BuilderApplication* builder_application_singleton (gchar** args, int args_length1) {
	BuilderApplication* result = NULL;
	BuilderApplication* _tmp0_ = NULL;
	BuilderApplication* _tmp3_ = NULL;
	BuilderApplication* _tmp4_ = NULL;
#line 136 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp0_ = application;
#line 136 "/home/alan/gitlive/roobuilder/src/Application.vala"
	if (_tmp0_ == NULL) {
#line 657 "Application.vala.c"
		gchar** _tmp1_ = NULL;
		gint _tmp1__length1 = 0;
		BuilderApplication* _tmp2_ = NULL;
#line 137 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_tmp1_ = args;
#line 137 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_tmp1__length1 = args_length1;
#line 137 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_tmp2_ = builder_application_new (_tmp1_, _tmp1__length1);
#line 137 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_g_object_unref0 (application);
#line 137 "/home/alan/gitlive/roobuilder/src/Application.vala"
		application = _tmp2_;
#line 671 "Application.vala.c"
	}
#line 141 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp3_ = application;
#line 141 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp4_ = _g_object_ref0 (_tmp3_);
#line 141 "/home/alan/gitlive/roobuilder/src/Application.vala"
	result = _tmp4_;
#line 141 "/home/alan/gitlive/roobuilder/src/Application.vala"
	return result;
#line 681 "Application.vala.c"
}


gchar* builder_application_configDirectory (void) {
	gchar* result = NULL;
	gchar* dirname = NULL;
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	const gchar* _tmp2_ = NULL;
	gboolean _tmp3_ = FALSE;
	const gchar* _tmp7_ = NULL;
	gchar* _tmp8_ = NULL;
	gchar* _tmp9_ = NULL;
	gboolean _tmp10_ = FALSE;
	gboolean _tmp11_ = FALSE;
	GError * _inner_error_ = NULL;
#line 147 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp0_ = g_get_home_dir ();
#line 147 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp1_ = g_strconcat (_tmp0_, "/.Builder", NULL);
#line 147 "/home/alan/gitlive/roobuilder/src/Application.vala"
	dirname = _tmp1_;
#line 149 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp2_ = dirname;
#line 149 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp3_ = g_file_test (_tmp2_, G_FILE_TEST_IS_DIR);
#line 149 "/home/alan/gitlive/roobuilder/src/Application.vala"
	if (!_tmp3_) {
#line 710 "Application.vala.c"
		GFile* dir = NULL;
		const gchar* _tmp4_ = NULL;
		GFile* _tmp5_ = NULL;
		GFile* _tmp6_ = NULL;
#line 150 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_tmp4_ = dirname;
#line 150 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_tmp5_ = g_file_new_for_path (_tmp4_);
#line 150 "/home/alan/gitlive/roobuilder/src/Application.vala"
		dir = _tmp5_;
#line 151 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_tmp6_ = dir;
#line 151 "/home/alan/gitlive/roobuilder/src/Application.vala"
		g_file_make_directory (_tmp6_, NULL, &_inner_error_);
#line 151 "/home/alan/gitlive/roobuilder/src/Application.vala"
		if (G_UNLIKELY (_inner_error_ != NULL)) {
#line 151 "/home/alan/gitlive/roobuilder/src/Application.vala"
			_g_object_unref0 (dir);
#line 151 "/home/alan/gitlive/roobuilder/src/Application.vala"
			_g_free0 (dirname);
#line 151 "/home/alan/gitlive/roobuilder/src/Application.vala"
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
#line 151 "/home/alan/gitlive/roobuilder/src/Application.vala"
			g_clear_error (&_inner_error_);
#line 151 "/home/alan/gitlive/roobuilder/src/Application.vala"
			return NULL;
#line 737 "Application.vala.c"
		}
#line 149 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_g_object_unref0 (dir);
#line 741 "Application.vala.c"
	}
#line 153 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp7_ = dirname;
#line 153 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp8_ = g_strconcat (_tmp7_, "/resources", NULL);
#line 153 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp9_ = _tmp8_;
#line 153 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp10_ = g_file_test (_tmp9_, G_FILE_TEST_IS_DIR);
#line 153 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_tmp11_ = !_tmp10_;
#line 153 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_g_free0 (_tmp9_);
#line 153 "/home/alan/gitlive/roobuilder/src/Application.vala"
	if (_tmp11_) {
#line 757 "Application.vala.c"
		GFile* dir = NULL;
		const gchar* _tmp12_ = NULL;
		gchar* _tmp13_ = NULL;
		gchar* _tmp14_ = NULL;
		GFile* _tmp15_ = NULL;
		GFile* _tmp16_ = NULL;
		GFile* _tmp17_ = NULL;
#line 154 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_tmp12_ = dirname;
#line 154 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_tmp13_ = g_strconcat (_tmp12_, "/resources", NULL);
#line 154 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_tmp14_ = _tmp13_;
#line 154 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_tmp15_ = g_file_new_for_path (_tmp14_);
#line 154 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_tmp16_ = _tmp15_;
#line 154 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_g_free0 (_tmp14_);
#line 154 "/home/alan/gitlive/roobuilder/src/Application.vala"
		dir = _tmp16_;
#line 155 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_tmp17_ = dir;
#line 155 "/home/alan/gitlive/roobuilder/src/Application.vala"
		g_file_make_directory (_tmp17_, NULL, &_inner_error_);
#line 155 "/home/alan/gitlive/roobuilder/src/Application.vala"
		if (G_UNLIKELY (_inner_error_ != NULL)) {
#line 155 "/home/alan/gitlive/roobuilder/src/Application.vala"
			_g_object_unref0 (dir);
#line 155 "/home/alan/gitlive/roobuilder/src/Application.vala"
			_g_free0 (dirname);
#line 155 "/home/alan/gitlive/roobuilder/src/Application.vala"
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
#line 155 "/home/alan/gitlive/roobuilder/src/Application.vala"
			g_clear_error (&_inner_error_);
#line 155 "/home/alan/gitlive/roobuilder/src/Application.vala"
			return NULL;
#line 795 "Application.vala.c"
		}
#line 153 "/home/alan/gitlive/roobuilder/src/Application.vala"
		_g_object_unref0 (dir);
#line 799 "Application.vala.c"
	}
#line 159 "/home/alan/gitlive/roobuilder/src/Application.vala"
	result = dirname;
#line 159 "/home/alan/gitlive/roobuilder/src/Application.vala"
	return result;
#line 805 "Application.vala.c"
}


static void builder_application_class_init (BuilderApplicationClass * klass) {
#line 45 "/home/alan/gitlive/roobuilder/src/Application.vala"
	builder_application_parent_class = g_type_class_peek_parent (klass);
#line 45 "/home/alan/gitlive/roobuilder/src/Application.vala"
	G_OBJECT_CLASS (klass)->finalize = builder_application_finalize;
#line 814 "Application.vala.c"
}


static void builder_application_instance_init (BuilderApplication * self) {
#line 98 "/home/alan/gitlive/roobuilder/src/Application.vala"
	self->settings = NULL;
#line 821 "Application.vala.c"
}


static void builder_application_finalize (GObject* obj) {
	BuilderApplication * self;
#line 45 "/home/alan/gitlive/roobuilder/src/Application.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_BUILDER_APPLICATION, BuilderApplication);
#line 98 "/home/alan/gitlive/roobuilder/src/Application.vala"
	_g_object_unref0 (self->settings);
#line 45 "/home/alan/gitlive/roobuilder/src/Application.vala"
	G_OBJECT_CLASS (builder_application_parent_class)->finalize (obj);
#line 833 "Application.vala.c"
}


GType builder_application_get_type (void) {
	static volatile gsize builder_application_type_id__volatile = 0;
	if (g_once_init_enter (&builder_application_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (BuilderApplicationClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) builder_application_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BuilderApplication), 0, (GInstanceInitFunc) builder_application_instance_init, NULL };
		GType builder_application_type_id;
		builder_application_type_id = g_type_register_static (gtk_application_get_type (), "BuilderApplication", &g_define_type_info, 0);
		g_once_init_leave (&builder_application_type_id__volatile, builder_application_type_id);
	}
	return builder_application_type_id__volatile;
}



