#ifndef _textdict_h_included_
#define _textdict_h_included_

#ifndef EXPORT_API
#define EXPORT_API
#endif // EXPORT_API


struct textdict;

EXPORT_API struct textdict *anthy_textdict_open(const char *fn, int create);
EXPORT_API void anthy_textdict_close(struct textdict *td);
/**/
EXPORT_API void anthy_textdict_scan(struct textdict *td, int offset, void *ptr,
			 int (*fn)(void *, int, const char *, const char *));
EXPORT_API int anthy_textdict_insert_line(struct textdict *td,
			       int offset, const char *line);
EXPORT_API int anthy_textdict_delete_line(struct textdict *td, int offset);

#endif
