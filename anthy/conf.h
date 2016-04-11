/* 設定を取得するためのインタフェース */
#ifndef _conf_h_included_
#define _conf_h_included_

#ifndef EXPORT_API
#define EXPORT_API
#endif // EXPORT_API


EXPORT_API void anthy_do_conf_init(void);
EXPORT_API void anthy_do_conf_override(const char *, const char *);
EXPORT_API void anthy_conf_free(void);

EXPORT_API const char *anthy_conf_get_str(const char *var);

#endif
