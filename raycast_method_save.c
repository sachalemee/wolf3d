/*
// DEBUG
#include <stdio.h>
    dprintf(2, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    dprintf(2, "win size = %u;%u\n", win_size.x, win_size.y);
    dprintf(2, "ray_data.wall_tex_abscissa = %lf\n", ray_data.wall_tex_abscissa);
    dprintf(2, "band_width = %lf\n", band_width);
    dprintf(2, "wall_texture_rect = w:%i;h:%i;l:%i;t:%i\n", wall_texture_rect.width, wall_texture_rect.height, wall_texture_rect.left, wall_texture_rect.top);
    dprintf(2, "sprite_scale = %f;%f\n", sprite_scale.x, sprite_scale.y);
    dprintf(2, "ray_data.walldist = %lf\n", ray_data.walldist);
    dprintf(2, "wall_sprite = %p\n", wall_sprite);
    dprintf(2, "band_texture_rect = w:%i;h:%i;l:%i;t:%i\n", band_texture_rect.width, band_texture_rect.height, band_texture_rect.left, band_texture_rect.top);
    dprintf(2, "band_coords = %lu;%i\n", band_x, top_band);
    dprintf(2, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
*/


/*
// sfVertexArray raycast
    sfVector2u win_size = sfRenderWindow_getSize(win);
    double wall_height = (double)win_size.y / ray_data.walldist;
    int top_band = round((double)((-1 * wall_height + (double)win_size.y) / 2));
    sfColor color_vertex = sfColor_fromRGB(100, 240, 220);
    sfVertex vertex = {0};
    sfRenderStates wall_states = {
        sfBlendAlpha,
        sfTransform_Identity,
        NULL,
        NULL
    };

    UNUSED(wall_sprite);
    sfVertexArray *vertex_array = sfVertexArray_create();
    vertex = (sfVertex){(sfVector2f){(float)band_x, (float)top_band}, sfWhite, (sfVector2f){491, 0}};
    sfVertexArray_append(vertex_array, vertex);
    color_vertex = sfColor_fromRGB(232, 240, 100);
    vertex = (sfVertex){(sfVector2f){(float)band_x, (float)top_band + wall_height},
        color_vertex, (sfVector2f){491, 900}};
    sfVertexArray_append(vertex_array, vertex);
    sfVertexArray_setPrimitiveType(vertex_array, sfLines);

    sfRenderWindow_drawVertexArray(win,
        vertex_array, &wall_states);
    sfVertexArray_destroy(vertex_array);
*/