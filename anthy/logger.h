/* デバッグやエラーのメッセージの出力 */
#ifndef _logger_h_included_
#define _logger_h_included_

#ifndef EXPORT_API
#define EXPORT_API
#endif // EXPORT_API


EXPORT_API void anthy_do_set_logger(void (*)(int , const char*), int lv);
EXPORT_API void anthy_log(int lv, const char *, ...);

#endif
