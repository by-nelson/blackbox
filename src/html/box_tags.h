#ifndef BOX_TAGS_H
#define BOX_TAGS_H

#include <string.h>
#include "../mem/box_array.h"

typedef enum {

    box_a = 0,
    box_abbr,
    box_address,
    box_area,
    box_article,
    box_aside,
    box_audio,
    box_b,
    box_base,
    box_bdi,
    box_bdo,
    box_blockquote,
    box_body,
    box_br,
    box_button,
    box_canvas,
    box_caption,
    box_cite,
    box_code,
    box_col,
    box_colgroup,
    box_data,
    box_datalist,
    box_dd,
    box_del,
    box_details,
    box_dfn,
    box_dialog,
    box_div,
    box_dl,
    box_dt,
    box_em,
    box_embed,
    box_fieldset,
    box_figcaption,
    box_figure,
    box_footer,
    box_form,
    box_h1,
    box_h2,
    box_h3,
    box_h4,
    box_h5,
    box_h6,
    box_head,
    box_header,
    box_hr,
    box_html,
    box_i,
    box_iframe,
    box_img,
    box_input,
    box_ins,
    box_kbd,
    box_label,
    box_legend,
    box_li,
    box_link,
    box_main,
    box_map,
    box_mark,
    box_meta,
    box_meter,
    box_nav,
    box_noscript,
    box_object,
    box_ol,
    box_opgroup,
    box_option,
    box_output,
    box_p,
    box_param,
    box_picture,
    box_pre,
    box_progress,
    box_q,
    box_rp,
    box_rt,
    box_ruby,
    box_s,
    box_samp,
    box_script,
    box_section,
    box_select,
    box_small,
    box_source,
    box_span,
    box_strong,
    box_style,
    box_sub,
    box_summary,
    box_sup,
    box_svg,
    box_table,
    box_tbody,
    box_td,
    box_template,
    box_textarea,
    box_tfoot,
    box_th,
    box_thead,
    box_time,
    box_title,
    box_tr,
    box_track,
    box_u,
    box_ul,
    box_var,
    box_video,
    box_box_wbr

} box_html_tags;


extern int box_html_tag_id(char* string);

#endif
