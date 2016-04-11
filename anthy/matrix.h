/* 疎行列を扱うためのコード */
#ifndef _matrix_h_included_
#define _matrix_h_included_

#ifndef EXPORT_API
#define EXPORT_API
#endif // EXPORT_API


struct matrix_image {
  /* number of 'int elements */
  int size;
  /* array of 'int */
  int *image;
};

struct sparse_matrix;
struct sparse_array;

/* 行列を構成するAPI */
EXPORT_API struct sparse_matrix *anthy_sparse_matrix_new(void);
EXPORT_API void anthy_sparse_matrix_set(struct sparse_matrix *m, int row, int column,
			     int value, void *ptr);
EXPORT_API int anthy_sparse_matrix_get_int(struct sparse_matrix *m, int row, int column);
EXPORT_API void anthy_sparse_matrix_make_matrix(struct sparse_matrix *m);
/* 行列イメージを構築するAPI(配列はhost byte order) */
EXPORT_API struct matrix_image *anthy_matrix_image_new(struct sparse_matrix *s);
/* 行列イメージにアクセスするAPI(配列はnetwork byte order) */
EXPORT_API int anthy_matrix_image_peek(int *im, int row, int col);

#endif
