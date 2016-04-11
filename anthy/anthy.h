/*
 * Anthy library interface
 * Anthy is a KanaKanji conversion engine (Library for Japanese Input Method)
 *
 * please read doc/LIB file in source package.
 *
 * Most of declarations are public interface.
 * So, be careful if you want to modify this file.
 *
 * $Id: anthy.h,v 1.6 2002/03/05 02:45:32 gniibe Exp $
 */
#ifndef _anthy_h_included_
#define _anthy_h_included_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef EXPORT_API
#define EXPORT_API
#endif // EXPORT_API



/* Data types */
struct anthy_conv_stat {
  int nr_segment;
};

struct anthy_segment_stat {
  int nr_candidate;
  int seg_len;
};

struct anthy_prediction_stat {
  int nr_prediction;
};

typedef struct anthy_context *anthy_context_t;



/* constants */
#define NTH_UNCONVERTED_CANDIDATE -1
#define NTH_KATAKANA_CANDIDATE -2
#define NTH_HIRAGANA_CANDIDATE -3
#define NTH_HALFKANA_CANDIDATE -4
/* encoding constants */
#define ANTHY_COMPILED_ENCODING 0
#define ANTHY_EUC_JP_ENCODING 1
#define ANTHY_UTF8_ENCODING 2
/* reconvert mode */
#define ANTHY_RECONVERT_AUTO 0
#define ANTHY_RECONVERT_DISABLE 1
#define ANTHY_RECONVERT_ALWAYS 2

/* Configuration */
EXPORT_API extern int anthy_init(void);
EXPORT_API extern void anthy_quit(void);
EXPORT_API extern void anthy_conf_override(const char *, const char *);
EXPORT_API extern int anthy_set_personality(const char *);



/* Context management */
EXPORT_API extern anthy_context_t anthy_create_context(void);
EXPORT_API extern void anthy_reset_context(anthy_context_t);
EXPORT_API extern void anthy_release_context(anthy_context_t);



/* Conversion control */
EXPORT_API extern int anthy_set_string(anthy_context_t, const char *);
/* nth,resize ie. +1,-1 */
EXPORT_API extern void anthy_resize_segment(anthy_context_t, int, int);
EXPORT_API extern int anthy_get_stat(anthy_context_t, struct anthy_conv_stat *);
EXPORT_API extern int anthy_get_segment_stat(anthy_context_t, int, struct anthy_segment_stat *);
/* context,nth segment,nth candidate,buffer,buffer len */
EXPORT_API extern int anthy_get_segment(anthy_context_t, int, int, char *, int);
/* ��ʸ�ᤴ�Ȥ˥��ߥåȤ��� */
EXPORT_API extern int anthy_commit_segment(anthy_context_t, int, int);

/* Prediction */
#define HAS_ANTHY_PREDICTION
EXPORT_API extern int anthy_set_prediction_string(anthy_context_t, const char*);
EXPORT_API extern int anthy_get_prediction_stat(anthy_context_t, struct anthy_prediction_stat *);
/* context, nth prediction, buffer, buffer len*/
EXPORT_API extern int anthy_get_prediction(anthy_context_t, int, char*, int);
#define HAS_ANTHY_COMMIT_PREDICTION
EXPORT_API extern int anthy_commit_prediction(anthy_context_t, int);

/* Etc */
EXPORT_API extern void anthy_print_context(anthy_context_t);

EXPORT_API extern const char *anthy_get_version_string (void);
typedef void (*anthy_logger)(int level, const char *);
EXPORT_API extern void anthy_set_logger(anthy_logger , int level);

/* experimental and unstable */
#define HAS_ANTHY_CONTEXT_SET_ENCODING
EXPORT_API extern int anthy_context_set_encoding(anthy_context_t ac, int encoding);
#define HAS_ANTHY_SET_RECONVERSION_MODE
EXPORT_API extern int anthy_set_reconversion_mode(anthy_context_t ac, int mode);

#ifdef __cplusplus
}
#endif

#endif
