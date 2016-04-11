/* 候補の順序を決定するためのモジュール */
#ifndef _ordering_h_included_
#define _ordering_h_included_

#include <anthy/xstr.h>

#ifndef EXPORT_API
#define EXPORT_API
#endif // EXPORT_API


struct segment_list;
struct splitter_context;

/** ordering_contextのwrapper構造体
 */
struct ordering_context_wrapper{
  struct ordering_context *oc;
};

EXPORT_API void anthy_proc_commit(struct segment_list *, struct splitter_context *);

EXPORT_API void anthy_sort_candidate(struct segment_list *c, int nth);
EXPORT_API void anthy_sort_metaword(struct segment_list *seg);

EXPORT_API void anthy_do_commit_prediction(xstr *src, xstr *xs);

/**/
EXPORT_API void anthy_infosort_init(void);
EXPORT_API void anthy_relation_init(void);

#endif
