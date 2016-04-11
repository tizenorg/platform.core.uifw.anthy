/* mmapを抽象化する */
#ifndef _filemap_h_included_
#define _filemap_h_included_

#ifndef EXPORT_API
#define EXPORT_API
#endif // EXPORT_API


/* メモリ上にmapされたファイルのハンドル */
struct filemapping;

EXPORT_API struct filemapping *anthy_mmap(const char *fn, int wr);
EXPORT_API void *anthy_mmap_address(struct filemapping *m);
EXPORT_API int anthy_mmap_size(struct filemapping *m);
EXPORT_API int anthy_mmap_is_writable(struct filemapping *m);
EXPORT_API void anthy_munmap(struct filemapping *m);

#endif
