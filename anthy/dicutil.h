/*
 * Interface for personal dictionary
 */
#ifndef _dicutil_h_included_
#define _dicutil_h_included_

#ifdef __cplusplus
extern "C" {
#endif

/* �֤��� / anthy_priv_dic_add_entry*/
/* OK / ñ�줬��Ͽ�Ǥ��� */
#define ANTHY_DIC_UTIL_OK 0
/* ���� / ��Ͽ�˼��Ԥ��� */
#define ANTHY_DIC_UTIL_ERROR -1
/* Ʊ��ñ�줬��Ͽ���Ƥ��ä������٤������� */
#define ANTHY_DIC_UTIL_DUPLICATE -2
/* ����¸�ߤ��ʤ� */
#define ANTHY_DIC_UTIL_INVALID -3

#ifndef EXPORT_API
#define EXPORT_API
#endif // EXPORT_API


EXPORT_API void anthy_dic_util_init(void);
EXPORT_API void anthy_dic_util_quit(void);
EXPORT_API void anthy_dic_util_set_personality(const char *);
EXPORT_API const char *anthy_dic_util_get_anthydir(void);
#define HAS_ANTHY_DICUTIL_SET_ENCODING
EXPORT_API int anthy_dic_util_set_encoding(int );

EXPORT_API void anthy_priv_dic_delete(void);
EXPORT_API int anthy_priv_dic_select_first_entry(void);
EXPORT_API int anthy_priv_dic_select_next_entry(void);
EXPORT_API int anthy_priv_dic_select_entry(const char *);/* not implemented */

EXPORT_API char *anthy_priv_dic_get_index(char *buf, int len);
EXPORT_API int anthy_priv_dic_get_freq(void);
EXPORT_API char *anthy_priv_dic_get_wtype(char *buf, int len);
EXPORT_API char *anthy_priv_dic_get_word(char *buf, int len);

EXPORT_API int anthy_priv_dic_add_entry(const char *yomi, const char *word,
			     const char *wt, int freq);

/* experimental and unstable /usr/share/dict/words����ñ���õ�� */
#define HAS_ANTHY_DIC_SEARCH_WORDS_FILE
EXPORT_API char *anthy_dic_search_words_file(const char *word);

#ifdef __cplusplus
}
#endif

#endif
